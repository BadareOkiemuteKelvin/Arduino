#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include "NewPing.h"




// Hook up HC-SR04 with Trig to Arduino Pin 9, Echo to Arduino pin 10
#define TRIGGER_PIN D2
#define ECHO_PIN D4

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400	

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

  long L_PV = 0,L_SP = 98;

// Wi-Fi credentials
const char* ssid = "home.js";
const char* password = "pYbsox-kaqhir-3joxbu";

// ThingSpeak settings
unsigned long channelID = 2823970; // Replace with your ThingSpeak Channel ID
const char* writeAPIKey = "Y753L7K279VN6872"; // Replace with your ThingSpeak Write API Key

// Create an instance of the WiFiClient
WiFiClient client;

void setup() {




  // Initialize Serial Monitor
  Serial.begin(115200);
  delay(100);
  pinMode(D1,OUTPUT);

  // Connect to Wi-Fi
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi connected!");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Read sensor data (example: temperature)
   L_PV = 100 - ((sonar.ping_median(5) / 2) * 0.0343);
  // Send data to ThingSpeak
  ThingSpeak.setField(1, L_PV); // Field 1 for temperature
  ThingSpeak.setField(2, 1); // Field 1 for temperature
  int status = ThingSpeak.writeFields(channelID, writeAPIKey);

  // Check if data was sent successfully
  if (status == 200) {
    Serial.println("Data sent to ThingSpeak!");
  } else {
    Serial.println("Error sending data to ThingSpeak.");
  }
  Serial.println(L_PV);
  digitalWrite(D1,HIGH);
  delay(500);
  digitalWrite(D1,LOW);
  delay(500);



  // Wait before sending the next data
  delay(20000); // 20 seconds delay
}

