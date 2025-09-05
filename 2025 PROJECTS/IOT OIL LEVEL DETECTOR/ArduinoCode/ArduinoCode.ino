#define BLYNK_TEMPLATE_ID "TMPL2WBkEPFXs"
#define BLYNK_TEMPLATE_NAME "LATHE MACHINE OIL LEVEL DETECTOR"
#define BLYNK_AUTH_TOKEN "hfV9Bv536P9_HuQajRQnWj8TJf2pfeoN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "FUPREPROJECT2025";         // WiFi Name
char pass[] = "FUPREPROJECT2025";     // WiFi Password



#define TRIG D2   // Trigger Pin of Ultrasonic Sensor
#define ECHO D4   // Echo Pin of Ultrasonic Sensor
#define RELAY D1  // Relay Control Pin
#define ALARM D5  // ALARM Control Pin

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

  if (level < 25) {  // Turn OFF relay when tank is full
    digitalWrite(RELAY, LOW);  // Relay OFF
    Blynk.virtualWrite(V1, 0);  // Update LED widget
  } else {
    digitalWrite(RELAY, HIGH);  // Relay ON
    Blynk.virtualWrite(V1, 1);
  }
  if (level < 50) {  // Turn OFF relay when tank is full
    digitalWrite(ALARM, HIGH);  // Relay ON
    Blynk.virtualWrite(V2, 1);  // Update LED widget
  } else {
    digitalWrite(ALARM, LOW);  // Relay ON
    Blynk.virtualWrite(V2, 0);
  }
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(ALARM, OUTPUT);
  digitalWrite(RELAY, LOW);  // Start with pump ON

  timer.setInterval(1000, checkWaterLevel);  // Check level every 1 second
}

void loop() {
  Blynk.run();
  timer.run();
}
