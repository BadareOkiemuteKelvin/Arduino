#include <LiquidCrystal.h>
#include "NewPing.h"
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 100	
int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float TOTAL = 0;
float LS = 0;
const int input = A0;
const int PUMP = 2;

const int Echo_Pin = A4;
const int Trig_Pin = A3;

// NewPing setup of pins and maximum distance.
NewPing sonar(Trig_Pin, Echo_Pin, MAX_DISTANCE);

long unsigned int Level = 0;



void setup()
{
Serial.begin(9600);
lcd.begin(16, 2);
  pinMode(Echo_Pin, INPUT);
  pinMode(Trig_Pin, OUTPUT);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water Flow Meter");
lcd.setCursor(0,1);
lcd.print("****************");
delay(2000);
pinMode(input,INPUT);
pinMode(PUMP,OUTPUT);


}
void loop()
{


X = pulseIn(input, HIGH);
Y = pulseIn(input, LOW);
TIME = X + Y;
FREQUENCY = 1000000/TIME;
WATER = FREQUENCY/7.5;
LS = WATER/60;
Level = sonar.ping_cm();
//digitalWrite(PUMP,HIGH);
  
if(Level<=13.0){
    digitalWrite(PUMP,LOW);
}

if(Level>=18.0){

    digitalWrite(PUMP,HIGH);
}

if(FREQUENCY >= 0)
{
if(isinf(FREQUENCY))
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("VOL. :0.00");
lcd.setCursor(0,1);
lcd.print("TOTAL:");
lcd.print(TOTAL);
lcd.print(" L");
Serial.println(String(0, 6) + "|" + String(Level,6));
//Serial.println(Level);
}
else
{
TOTAL = TOTAL + LS;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("VOL.: ");
lcd.print(WATER);
lcd.print("L/M");
lcd.setCursor(0,1);
lcd.print("TOTAL:");
lcd.print(TOTAL);
lcd.print(" L");
Serial.println(String(WATER, 6) + "|" + String(Level,6));
//Serial.println(Level);
}
}
delay(1000);
}