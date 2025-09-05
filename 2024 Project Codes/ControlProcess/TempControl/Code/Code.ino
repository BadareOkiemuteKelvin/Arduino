#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

// Data wire is connected to Arduino Digital Pin 2
#define ONE_WIRE_BUS 7

// Setup a oneWire instance to communicate with any OneWire devices (not just DS18B20)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

// Set the LCD address and dimensions (e.g., 0x27 or 0x3F for a 16x2 LCD)
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  // Start the DallasTemperature library
  sensors.begin();
  
  // Initialize the LCD
  lcd.init();
  lcd.backlight(); // Turn on the backlight
  lcd.print("Temperature:"); // Initial message on LCD
}

void loop() {
  // Request temperature readings from all devices on the bus
  sensors.requestTemperatures(); 
  
  // Get the temperature in Celsius (assuming one sensor at index 0)
  float tempC = sensors.getTempCByIndex(0); 

  // Display temperature on the LCD
  lcd.setCursor(0, 1); // Set cursor to the second line, first column
  lcd.print(tempC);
  lcd.print((char)223); // Degree symbol
  lcd.print("C");
  
  delay(1000); // Wait for 1 second before next reading
}
