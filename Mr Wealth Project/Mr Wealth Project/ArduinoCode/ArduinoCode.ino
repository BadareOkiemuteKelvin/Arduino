#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

void Welcome(void);
void ADULTERATION(void);
void Diesel(void);
void GAS_LEAKAGE(void);
void CONFIGURATION(void);
void SAMPLING_RATE(void);
void SAMPLING_TIME(void);
void FACTORY_RESTORE(void);
void SAVE_SUCCESSFULLY(void);


const int LPG = A0;
const int METHANE = A1;
const int dipSensor = A2;


const int ALARM = A5;
const int LK = 5;
const int MK= 4;
const int RK= 3;



void printf(char x,char y,String Text);// function declaration

void printf(char x,char y,int Number);// function declaration
void printf(char x,char y,double F);// function declaration
void printf(char x,char y,long  int Number);// function declaration

void Welcome(void);
void display_refresher(void);
void toggleAlarm(void);

char Menu_index = 0;
int SampleRate = 5;// sample times
int NewSampleRate = 0;// sample times
int SampleTime = 5;
int NewSampleTime = 0;
double LPGSample[10];
double METHANESample[10];
double LPGSampleSummation = 0.0,LPGSampleMean = 0.0;
double METHANESampleSummation = 0.0,METHANESampleMean = 0.0;
double sLPG,sMETHANE = 0.0;
unsigned char i=0,TIME = 0;
int key = 0;




