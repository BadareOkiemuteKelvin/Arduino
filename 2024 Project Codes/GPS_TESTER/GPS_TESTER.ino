#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Choose two Arduino pins to use for software serial
int RXPin = 11;
int TXPin = 12;


int GPSBaud = 9600;

// Create a TinyGPS++ object
TinyGPSPlus gps;

// Create a software serial port called "gpsSerial"
SoftwareSerial gpsSerial(RXPin, TXPin);
//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2


String message;
String Text = "#Location";


int runOnce = 0;

void setup()
{
  delay(6000);
  // Start the Arduino hardware serial port at 9600 baud
  Serial.begin(9600);

  // Start the software serial port at the GPS's default baud
  gpsSerial.begin(GPSBaud);

    //Begin serial communication with Arduino and SIM800L
  //mySerial.begin(9600);

  //Serial.println("Initializing..."); 
  delay(1000);

  Serial.print("AT"); //Once the handshake test is successful, it will back to OK
  //updateSerial();
  
  Serial.print("AT+CMGF=1"); // Configuring TEXT mode
  //updateSerial();
  Serial.print("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  //updateSerial();

    Serial.println("AT+CMGS=\"+2347030389919\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
     // mySerial.println("AT+CMGS=\"+2347089349889\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
     //updateSerial();
     Serial.print("Your Vehicle Current Location is "); //text content
     Serial.print("\n");
     Serial.print("Check Map: \n");
     //mySerial.print("http://maps.google.com/?ie=UTF8&hq=&ll=5.7004104,5.7518793&z=5");
     Serial.print("http://maps.google.com/?ie=UTF8&hq=&ll=5.446794,6.195734&z=5");
}

void loop()
{
  // This sketch displays information every time a new sentence is correctly encoded.

      //displayInfo();
  updateSerial();
    

  // If 5000 milliseconds pass and there are no characters coming in
  // over the software serial port, show a "No GPS detected" error
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
   // Serial.println("No GPS detected");
   // while(true);
  }
}

void displayInfo()
{
  if(runOnce==0){

    runOnce = 1;
        //Begin serial communication with Arduino and SIM800L
   mySerial.begin(9600);


  Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  updateSerial();


  }
  if (gps.location.isValid())
  {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
    Serial.print("Altitude: ");
    Serial.println(gps.altitude.meters());

    
  }
  else
  {
    Serial.println("Location: Not Available");
  }
  
  Serial.print("Date: ");
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.println(gps.date.year());
  }
  else
  {
    Serial.println("Not Available");
  }

  Serial.print("Time: ");
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(":");
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(":");
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(".");
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.println(gps.time.centisecond());
  }
  else
  {
    Serial.println("Not Available");
  }

  Serial.println();
  Serial.println();
  delay(1000);
}
void updateSerial()
{
  delay(500);
 // while (Serial.available()) 
 // {
  //  mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  //}
  while(Serial.available()) 
  {
    //Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
    //Serial.write(mySerial.read());
    String sms = Serial.readString();
    //Serial.println(sms);
    int index = sms.indexOf('#');
    message = sms.substring(index);
    //Serial.println("Message is :" + message );
    if(message.startsWith("#")){
     //Serial.println("The system Worked");
     updateSerial();
     Serial.println("AT+CMGS=\"+2347030389919\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
     // mySerial.println("AT+CMGS=\"+2347089349889\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
     updateSerial();
     Serial.print("Your Vehicle Current Location is "); //text content
     Serial.print("\n");
     Serial.print("Check Map: \n");
     mySerial.println("http://maps.google.com/?ie=UTF8&hq=&ll="+String(gps.location.lat(),6)+","+String(gps.location.lng(),6)+"&z=5");
     
     updateSerial();
     Serial.write(26);
   
    }
   
  }

}