
#define BLYNK_TEMPLATE_ID "TMPL20VuIwMuf"
#define BLYNK_TEMPLATE_NAME "IOT WATER MANAGEMENT SYSTEM"
#define BLYNK_AUTH_TOKEN "6o0GWr7--uCTZBW4TKo7WT-nLCzl4X_V"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "IOTWATERPROJECT";         // WiFi Name
char pass[] = "IOTWATERPROJECT";     // WiFi Password





#define TRIG D2   // Trigger Pin of Ultrasonic Sensor
#define ECHO D4   // Echo Pin of Ultrasonic Sensor
#define RELAY D1  // Relay Control Pin

BlynkTimer timer;  // Create Blynk Timer instance

BLYNK_WRITE(V1) {
  int relayState = param.asInt();  // Read button value from Blynk app
  digitalWrite(RELAY, relayState); // Turn relay ON (1) or OFF (0)
}

// Function to check water level
void checkWaterLevel() {
  long duration;
  int distance;

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;  // Convert to cm

  int tankHeight = 30;  // Adjust based on your tank height in cm
  int level = map(distance, 0, tankHeight, 100, 0);  // Convert to percentage

  Blynk.virtualWrite(V0,  level);  // Send level to Blynk Gauge

  if (level >= 95) {  // Turn OFF relay when tank is full
    digitalWrite(RELAY, LOW);  // Relay OFF
    Blynk.virtualWrite(V1, 0);  // Update LED widget
  } else {
    digitalWrite(RELAY, HIGH);  // Relay ON
    Blynk.virtualWrite(V1, 1);
  }
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);  // Start with pump ON

  timer.setInterval(1000, checkWaterLevel);  // Check level every 1 second
}

void loop() {
  Blynk.run();
  timer.run();
}