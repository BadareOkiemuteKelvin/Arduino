#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

#include <Keypad.h>

const byte ROWS = 4;  //four rows
const byte COLS = 4;  //four columns

char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte rowPins[ROWS] = { 5, 6, 7, 8 };  //connect to the row pinouts of the keypad
byte colPins[COLS] = { 9, 10, 11, 12 };  //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);




void setup() {

   lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  
  // Print a message on both lines of the LCD.
  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print("PLCC CONTROLLER");
  lcd.setCursor(0,1);   //Set cursor to character 2 on line 0
  lcd.print("COMMAND SENT:");
  Serial.begin(9600); // For debugging
  
}

void loop() {

    char key = keypad.getKey();  // Read the key

  // Print if key pressed
  if (key) {
    lcd.setCursor(13,1);   //Set cursor to character 2 on line 0
    lcd.print(key);
    Serial.print(key);
    delay(1000);
  }
  // Check if data is available
    
}