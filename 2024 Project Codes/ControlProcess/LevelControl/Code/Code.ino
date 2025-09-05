#include <LiquidCrystal_I2C.h>


// Include NewPing Library
#include "NewPing.h"

// Hook up HC-SR04 with Trig to Arduino Pin 9, Echo to Arduino pin 10
#define TRIGGER_PIN 9
#define ECHO_PIN 8

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400	

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display


void setup() {
	Serial.begin(9600);
  lcd.init();
  lcd.clear();         
  lcd.backlight();   
}

void loop() {


  lcd.setCursor(0,0); 
  lcd.print("LEVEL CONTROL ");
    // Read the temperature in Celsius
  lcd.setCursor(0,1); 
  lcd.print("L: ");
  lcd.setCursor(2,1); 
  lcd.print(sonar.ping_cm());
  lcd.setCursor(7,1); 
  lcd.print("cm"); // shows degree symbol

	delay(500);
}