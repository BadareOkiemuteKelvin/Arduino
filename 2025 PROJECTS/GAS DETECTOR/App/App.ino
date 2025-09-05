#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD at I2C address 0x27 (change if yours is different)
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define MQ2_PIN A2      // Analog pin for MQ-2
#define BUZZER_PIN A1    // Buzzer pin

int sensorValue = 0;     // Raw value from MQ-2
int gasLevelPercent = 0; // Gas concentration percentage
int threshold = 300;     // Adjust this threshold as needed

void setup() {
  // LCD setup
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gas Detector");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  
  // Buzzer setup
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  delay(2000); // Wait for sensor to warm up
}

void loop() {
  sensorValue = analogRead(MQ2_PIN);
  
  // Convert sensor value (0-1023) to percentage
  gasLevelPercent = map(sensorValue, 0, 1023, 0, 100);

  // Display readings on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gas: ");
  lcd.print(gasLevelPercent);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Value: ");
  lcd.print(sensorValue);

  // Check for high gas concentration
  if (sensorValue > threshold) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(500); // Update every 0.5 sec
}
