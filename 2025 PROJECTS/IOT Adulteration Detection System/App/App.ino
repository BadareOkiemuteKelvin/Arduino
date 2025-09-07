#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x3F for a 16 chars and 2 line display

#define BLYNK_TEMPLATE_ID "TMPL2_Fi6TW7E"
#define BLYNK_TEMPLATE_NAME "MSCIOTPROJECT"
#define BLYNK_AUTH_TOKEN "5v3BjjmMHZeQ-G79y2OcV3BTGPAug8j5"



#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "MSCIOTPROJECT";         // WiFi Name
char pass[] = "MSCIOTPROJECT";     // WiFi Password

const int  SENSOR  = A0; 

BlynkTimer timer;  // Create Blynk Timer instance

int state = 0;

const int rightKey = D5;
const int middleKey = D8;
const int leftKey = D4;


char Menu_index = 1;
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


// Function to check for adulteration
void Welcome(void);
void ADULTERATION(void);
void Diesel(void);
void GAS_LEAKAGE(void);
void CONFIGURATION(void);
void SAMPLING_RATE(void);
void SAMPLING_TIME(void);
void FACTORY_RESTORE(void);
void SAVE_SUCCESSFULLY(void);
void cls(void);



void App() {

    if(state == 1){
      
     lcd.clear();  
     printf(0,5,"CONNECTED");
     printf(1,4,"SUCCESSFULLY");
     delay(1000);
     lcd.clear(); 
       state = 2;
    }else{
        
    }
   ADULTERATION();

    //int vibration = analogRead(SENSOR);  // Convert to percentage
    //Blynk.virtualWrite(V0, vibration); 
    //lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
    //lcd.print(vibration);

}

void setup() {

  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  state = 1;
  pinMode(middleKey, INPUT);
  pinMode(rightKey, INPUT);
  pinMode(leftKey, INPUT);
  pinMode(SENSOR, INPUT);
  for(char i = 0;i<=5;i++)
  {
  if(EEPROM.read(i)==0xFF)
  {
   EEPROM.write(i,0); 
  }
  }

 SampleRate = EEPROM.read(0);
 SampleTime = EEPROM.read(1);
  Welcome();
  printf(0,0,"CONNECTING TO SERVER");
   printf(1,0,"PLEASE WAIT....");
   Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
   timer.setInterval(1000, App);  // Check level every 1 second
}

void loop() {
  Blynk.run();
  timer.run();
  
}
