#define BLYNK_TEMPLATE_ID "TMPL2rm0sr7ha"
#define BLYNK_TEMPLATE_NAME "VIBRATION"
#define BLYNK_AUTH_TOKEN "8vaTc8K_TUIjK773itcL71uTXJRr27ea"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Home.js";         // WiFi Name
char pass[] = "cugzyp-7tejku-kuGhab";     // WiFi Password

#define SENSOR D9 

BlynkTimer timer;  // Create Blynk Timer instance



// Function to check water level
void checkVibration() {

    int vibration = digitalRead(SENSOR);  // Convert to percentage
    Serial.println(digitalRead(SENSOR));

  if (vibration >= 1) {  // Turn OFF relay when tank is full
    Blynk.virtualWrite(V0, random(0,100));  // Update LED widget
  } else {
    Blynk.virtualWrite(V0, 0);
  }
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(SENSOR, INPUT);

  timer.setInterval(1000, checkVibration);  // Check level every 1 second
}

void loop() {
  Blynk.run();
  timer.run();
}