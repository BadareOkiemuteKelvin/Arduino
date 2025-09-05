#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

void Welcome(void);

const int RELAY1 = 5;
const int RELAY2 = 4;
const int Buzzer = 3;

const int NEPA_INPUT = A1;
const int GEN_INPUT = A0;

double NEPA_VOLT = 0.0;
double GEN_VOLT = 0.0;

 double max;
 int i;
 unsigned int temp=0;
 double maxpoint = 0;

const int NEPA_PIN = A2;



void printf(char x,char y,String Text);// function declaration

void printf(char x,char y,int Number);// function declaration
void printf(char x,char y,double F);// function declaration
void printf(char x,char y,long  int Number);// function declaration

void Welcome(void);
void display_refresher(void);
void GEN_MODE(void);
void NEPA_MODE(void);
double getNepaVoltage(void);
float getGenVoltage(void);
double getMainVoltage(void);





