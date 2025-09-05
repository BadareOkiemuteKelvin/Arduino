#include <LiquidCrystal_I2C.h>




LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display


const int Relay1 = 11;
const int Relay2 = 12;
const int Buzzer = 10;

int relay1State = 0;
int relay2State = 0;

void setup() {
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  
  // Print a message on both lines of the LCD.
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("Hello world!");
  

  // Initialize serial communication
  Serial.begin(9600); // For debugging


  pinMode(Relay1,OUTPUT);
  digitalWrite(Relay1,LOW);
   pinMode(Relay2,OUTPUT);
  digitalWrite(Relay2,LOW);
   pinMode(Buzzer,OUTPUT);
  digitalWrite(Buzzer,LOW);


}
void loop() {
  

  
  if(Serial.available()>0){

    char data = Serial.read();
    lcd.setCursor(2,1);   //Move cursor to character 2 on line 1
    lcd.print("DATA :");
    lcd.setCursor(11,1);   //Move cursor to character 2 on line 1
    lcd.print(data);

    if(data=='1'){
      digitalWrite(Buzzer,HIGH);
      delay(500);
      relay1State = 1;
      digitalWrite(Buzzer,LOW);
      delay(500);
    }else if(data=='2'){
      digitalWrite(Buzzer,HIGH);
      delay(500);
      relay1State = 0;
      digitalWrite(Buzzer,LOW);
      delay(500);
    }else if(data=='3'){
      digitalWrite(Buzzer,HIGH);, 
      delay(500);
      relay2State = 1;
      digitalWrite(Buzzer,LOW);
      delay(500);
    }else if(data=='4'){
      digitalWrite(Buzzer,HIGH);
      delay(500);
      relay2State = 0;
      digitalWrite(Buzzer,LOW);
      delay(500);
    }


  }

  if(relay1State == 1){
      digitalWrite(Relay1,HIGH);
  }else if(relay1State == 0){

     digitalWrite(Relay1,LOW);
  }
  if(relay2State == 1){
      digitalWrite(Relay2,HIGH);
  }else if(relay2State == 0){

     digitalWrite(Relay2,LOW);
  }

  //delay(1000); // Wait 1 second (actual baud rate is 100 bps, so slow transmission)
}