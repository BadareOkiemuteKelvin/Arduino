#include <SoftwareSerial.h>

// Include NewPing Library
#include "NewPing.h"

//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2

int k = 1;
String message;
String Text = "#Location";

const int RELAY = 9;

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 100	



double LON = 0.0;
double LAT = 0.0;



const int Echo_Pin = 7;
const int Trig_Pin = 8;


// NewPing setup of pins and maximum distance.
NewPing sonar(Trig_Pin, Echo_Pin, MAX_DISTANCE);

long unsigned int Level = 0;



void setup()
{
  delay(6000);
   pinMode(Echo_Pin, INPUT);
  pinMode(Trig_Pin, OUTPUT);
  pinMode(RELAY,OUTPUT);
  digitalWrite(RELAY,LOW);
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
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

void loop()
{
  updateSerial();
}

void updateSerial()
{
  delay(500);
 while (Serial.available()) 
 {
  // mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port

  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
    //Serial.write(mySerial.read());
    String sms = mySerial.readString();
    //Serial.println(sms);
    int index = sms.indexOf('#');
    message = sms.substring(index);
    Serial.println("Message is :" + message );
    if(message.startsWith("#")){
     Serial.println("The system Worked");
     //displayInfo();
     updateSerial();
     Level = sonar.ping_cm();
    // mySerial.println("AT+CMGS=\"+2347030389919\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
    mySerial.println("AT+CMGS=\"+2347068293570\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
    //mySerial.println("AT+CMGS=\"+2347089349889\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
     updateSerial();
     mySerial.print("Tank Level ="); //text content
     mySerial.print(Level); //text content
     mySerial.print("\n");
     mySerial.print("Your Vehicle Current Location is"); //text content
     mySerial.print("\n");
     mySerial.print("Check Map: \n");
     mySerial.print("http://maps.google.com/?ie=UTF8&hq=&ll=5.56946,5.79556&z=5");
     //mySerial.print("http://maps.google.com/?ie=UTF8&hq=&ll="+String(LAT,6)+","+String(LON,6)+"&z=5");
     //mySerial.print("http://maps.google.com/?ie=UTF8&hq=&ll=5.446794,6.195734&z=5");
     updateSerial();
     mySerial.write(26);
    }
   
  }

}





