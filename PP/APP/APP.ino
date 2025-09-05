
#define BLYNK_AUTH_TOKEN "QXtahxAjAa2-IkvQ5Uu1Ph4wL7MU81Bj"
#define BLYNK_TEMPLATE_ID "TMPL5zpefDl15"
#define BLYNK_TEMPLATE_NAME "IOT WASTE MANAGEMENT SYSTEM"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "GTech Solutions";         // WiFi Name
char pass[] = "1234567zz";     // WiFi Password





#define TRIG D4   // Trigger Pin of Ultrasonic Sensor
#define ECHO D3   // Echo Pin of Ultrasonic Sensor
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

  int tankHeight = 100;  // Adjust based on your tank height in cm
  int level = map(distance, 0, tankHeight, 300, 0);  // Convert to percentage
  Serial.println(level);
  Blynk.virtualWrite(V0,  level);  // Send level to Blynk Gauge

  if (level >= 245) {  // Turn OFF relay when tank is full
    digitalWrite(RELAY, HIGH);  // Relay OFF
    Blynk.virtualWrite(V1, 1);  // Update LED widget
  } else {
    digitalWrite(RELAY, LOW);  // Relay ON
    Blynk.virtualWrite(V1, 0);
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