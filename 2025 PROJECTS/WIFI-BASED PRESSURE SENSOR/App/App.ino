#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/* Put your SSID & Password */
const char* ssid = "NodeMCU";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

Adafruit_BMP280 bmp;  // Create BMP280 object for I2C

#define SEALEVELPRESSURE_HPA (1013.25)  // Sea-level pressure in hPa (adjust for your location)

uint8_t LED1pin = D7;
uint8_t LEDpin = D8;

bool LED1status = LOW;

uint8_t LED2pin = D6;
bool LED2status = LOW;


int Pressure = 0;
int Temperature = 0;

void setup() {
  Serial.begin(9600);  // Start serial communication
  pinMode(LED1pin, OUTPUT);
  pinMode(LEDpin, OUTPUT);
  pinMode(LED2pin, OUTPUT);
  digitalWrite(LEDpin,HIGH);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); 

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  server.on("/", handle_OnConnect);
  server.on("/on", handle_led1on);
  server.on("/off", handle_led1off);
  server.on("/led2on", handle_led2on);
  server.on("/led2off", handle_led2off);
  server.onNotFound(handle_NotFound);
  
  server.begin();
  Serial.println("HTTP server started");
  Serial.println(F("BMP280 Test"));

  // Initialize BMP280 (default I2C address is 0x76 or 0x77; try 0x77 if this fails)
  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or I2C address!"));
    while (1);  // Halt if sensor not found
  }

  // Default settings for accurate readings
  bmp.setSampling(
                  Adafruit_BMP280::MODE_NORMAL,     // Operating mode
                  Adafruit_BMP280::SAMPLING_X2,     // Temp. oversampling
                  Adafruit_BMP280::SAMPLING_X16,    // Pressure oversampling
                  Adafruit_BMP280::FILTER_X16,      // Filtering
                  Adafruit_BMP280::STANDBY_MS_500
                  ); // Standby time
}




void loop() {

   server.handleClient();
  if(LED1status)
  {
    digitalWrite(LED1pin, HIGH);
    digitalWrite(LEDpin, HIGH);

  }
  else{
    digitalWrite(LED1pin, LOW);
    digitalWrite(LEDpin, LOW);
    }
  
  if(LED2status)
  {digitalWrite(LED2pin, HIGH);}
  else
  {digitalWrite(LED2pin, LOW);}
  // Read and print temperature
  Temperature = bmp.readTemperature();
  Serial.print(F("Temperature = "));
  Serial.print(Temperature);
  Serial.println(" *C");

  // Read and print pressure (divided by 100 to get hPa)
  Pressure = bmp.readPressure() / 100.0F;
  Serial.print(F("Pressure = "));
  Serial.print(Pressure);
  Serial.println(" hPa");

  if((Temperature>30)||(Pressure>1016)){

    LED1status = true;

  }else{
    LED1status = false;
  }


  // Read and print approximate altitude
  Serial.print(F("Approx Altitude = "));
  Serial.print(bmp.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.println();  // New line for readability
  delay(2000);       // Wait 2 seconds before next reading
}

void handle_OnConnect() {

  Serial.println("GPIO7 Status: OFF | GPIO6 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status,LED2status,Pressure,Temperature)); 
}

void handle_led1on() {
  LED1status = HIGH;
  Serial.println("GPIO7 Status: ON");
  server.send(200, "text/html", SendHTML(true,LED2status,Pressure,Temperature)); 
}

void handle_led1off() {
  LED1status = LOW;
  Serial.println("GPIO7 Status: OFF");
  server.send(200, "text/html", SendHTML(false,LED2status,Pressure,Temperature)); 
}

void handle_led2on() {
  LED2status = HIGH;
  Serial.println("GPIO6 Status: ON");
  server.send(200, "text/html", SendHTML(LED1status,true,Pressure,Temperature)); 
}

void handle_led2off() {
  LED2status = LOW;
  Serial.println("GPIO6 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status,false,Pressure,Temperature)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t led1stat,uint8_t led2stat,long unsigned int Pressure,long unsigned int Temperature){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LED Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #1abc9c;}\n";
  ptr +=".button-on:active {background-color: #16a085;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>WIRELESS PRESSURE MONITORING SYSTEM</h1>\n";
  ptr +="<h3>BY PTI STUDENT M.23 EEED</h3>\n";
  ptr +="<h1>";
  ptr +="Pressure = ";
  ptr +=Pressure;
  ptr +="hPa";    
  ptr +="</h1>";
  ptr +="<h1>";
  ptr +="Temperature = ";
  ptr +=Temperature;
  ptr +=" 'C";
  ptr +="</h1>";
   if(led1stat)
  {ptr +="<p>ALARM STATUS</p><a class=\"button button-on\" >ON</a>\n";}
  else
  {ptr +="<p>ALARM STATUS</p><a class=\"button button-off\" >OFF</a>\n";}



  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}