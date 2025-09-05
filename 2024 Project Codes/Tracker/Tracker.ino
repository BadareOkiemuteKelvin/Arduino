#include <SoftwareSerial.h>
#include <TinyGPS++.h>

TinyGPSPlus gps;
SoftwareSerial gpsSerial(11, 12);  // RX, TX for GPS
SoftwareSerial gsmSerial(3, 2);  // RX, TX for GSM

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  gsmSerial.begin(9600);

  delay(10000);  // Give some time for the GSM module to connect to network
  gsmSerial.println("AT");    // Check GSM module
  delay(1000);
  gsmSerial.println("AT+CMGF=1");  // Set SMS to text mode
  delay(1000);
}

void loop() {
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
    
    if (gps.location.isUpdated()) {
      float latitude = gps.location.lat();
      float longitude = gps.location.lng();
      
      Serial.print("Latitude: ");
      Serial.println(latitude, 6);
      Serial.print("Longitude: ");
      Serial.println(longitude, 6);
      
      sendSMS(latitude, longitude);  // Send coordinates as SMS
      delay(10000);  // Send data every 10 seconds (or longer, as needed)
    }
  }
}

void sendSMS(float latitude, float longitude) {
  gsmSerial.println("AT+CMGS=\"+2347030389919\"");  // Replace with your phone number
  delay(1000);
  gsmSerial.print("GPS Coordinates: ");
  gsmSerial.print("Latitude: ");
  gsmSerial.print(latitude, 6);
  gsmSerial.print(", Longitude: ");
  gsmSerial.println(longitude, 6);
  delay(1000);
  gsmSerial.write(26);  // ASCII code for Ctrl+Z to send the message
  delay(1000);
}
