

#include "uRTCLib.h"
#include <LiquidCrystal_I2C.h>
#include <HX711_ADC.h>
#if defined(ESP8266)|| defined(ESP32) || defined(AVR)
#include <EEPROM.h>
#endif

//pins:
const int HX711_dout = 5; //mcu > HX711 dout pin
const int HX711_sck = 6; //mcu > HX711 sck pin


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display



// uRTCLib rtc;
uRTCLib rtc(0x68);

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

const String Weeks[7] = {"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};


//HX711 constructor:
HX711_ADC LoadCell(HX711_dout, HX711_sck);

const int calVal_calVal_eepromAdress = 0;
unsigned long t = 0;



const int sensor = A0;

int counter = 0;


const int ALARM = 2;
const int LK = 3;
const int MK= 4;
const int RK= 12;

char Menu_index = 0;

 int DAY, MONTH , YEAR , HOUR , MINUTE, DELAYX, RTC_HOUR = 0, RTC_MIN = 0, RTC_DAY = 0, RTC_WEEK = 0, RTC_MON = 0,RTC_YEAR = 0;


float i,weight;

void printf(char x,char y,String Text);// function declaration

void printf(char x,char y,int Number);// function declaration
void printf(char x,char y,double F);// function declaration
void printf(char x,char y,long  int Number);// function declaration

void Welcome(void);
void display_refresher(void);
void toggleAlarm(void);
void SET_MINUTE(void);
void SET_HOUR(void);
void SET_DAY(void);
void SET_MONTH(void);
void SET_YEAR(void);
void SET_DELAY(void);
void RINGALARM(void);
void ringer(void);
void Error(float data);
void SET_RTC_HOUR(void);
