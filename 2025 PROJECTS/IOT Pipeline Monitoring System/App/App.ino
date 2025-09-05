#define BLYNK_TEMPLATE_ID "TMPL26bpIODYz"
#define BLYNK_TEMPLATE_NAME "PIPELINE MONITORING SYSTEM"
#define BLYNK_AUTH_TOKEN "_IDa9-Vge2y89BpbSaAyZlE1s1x-XFEd"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Include NewPing Library
#include "NewPing.h"

char ssid[] = "PTIEEEDPROJECT";         // WiFi Name
char pass[] = "PTIEEEDPROJECT";     // WiFi Password


#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>

long unsigned int Level = 0;



#define MAX_DISTANCE 100	

const int Echo_Pin = D3;
const int Trig_Pin = D4;

#define MQ2_PIN A0      // Analog pin for MQ-2
int sensorValue = 0;     // Raw value from MQ-2
int gasLevelPercent = 0; // Gas concentration percentage

int Pressure = 0;
int Temperature = 0;

Adafruit_BMP280 bmp;  // Create BMP280 object for I2C


BlynkTimer timer;  // Create Blynk Timer instance


// NewPing setup of pins and maximum distance.
NewPing sonar(Trig_Pin, Echo_Pin, MAX_DISTANCE);




// Function to check water level
void checkPipeLine() {

  sensorValue = analogRead(MQ2_PIN);
  
  // Convert sensor value (0-1023) to percentage
  gasLevelPercent = map(sensorValue, 0, 1023, 0, 100);
 
  Temperature = bmp.readTemperature();

  // Read and print pressure (divided by 100 to get hPa)
  Pressure = bmp.readPressure() / 100.0F;

   Level = 100 - sonar.ping_cm();

   Blynk.virtualWrite(V0, Temperature);  // Update LED widget
   Blynk.virtualWrite(V1, gasLevelPercent);  // Update LED widget
   Blynk.virtualWrite(V2, Pressure);  // Update LED widget
   Blynk.virtualWrite(V3, Level);  // Update LED widget
   
   if((Temperature>33)||(gasLevelPercent>70)){
    Blynk.virtualWrite(V4, 1);  // Update LED widget

  Serial.println("AT");  //Once the handshake test is successful, i t will back to OK
  Serial.println("ATD+ +2348101088855;");  //  change ZZ with country code and xxxxxxxxxxx with phone number to dial

   }else{
      Blynk.virtualWrite(V4, 0);  // Update LED widget
       Serial.println("ATH");  //hang up
   }

}



void setup() {
  Serial.begin(9600);  // Start serial communication
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(Echo_Pin, INPUT);
  pinMode(Trig_Pin, OUTPUT);
  pinMode(MQ2_PIN, INPUT);

    // Initialize BMP280 (default I2C address is 0x76 or 0x77; try 0x77 if this fails)
  if (!bmp.begin(0x76)) {
    //Serial.println(F("Could not find a valid BMP280 sensor, check wiring or I2C address!"));
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

timer.setInterval(1000, checkPipeLine);  // Check level every 1 second

}

void loop() {
  Blynk.run();
  timer.run();


}
