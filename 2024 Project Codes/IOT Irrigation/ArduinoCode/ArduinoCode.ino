#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(D6, D4, D3, D2, D1, D0);


/* Put your SSID & Password */
const char* ssid = "AUTOMATIC IRRIGATION SYSTEM";  // Enter SSID here
const char* password = "PTI2024EEED8179";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

double temp = 0.0;
double moistureLevel = 0.0;

void printf(char x,char y,String Text);// function declaration

void printf(char x,char y,int Number);// function declaration
void printf(char x,char y,double F);// function declaration
void printf(char x,char y,long  int Number);// function declaration

void Welcome(void);
void display_refresher(void);



uint8_t pumpPin = D5;
bool pumpStatus = LOW;


uint8_t buzzerPin = D8;


uint8_t ldrPin = A0;



void handle_OnConnect();
void toggleBuzzer();
String SendHTML(long unsigned int Level,uint8_t pumpStatus);




void turnOnPump() {
   moistureLevel = 100 - (analogRead(ldrPin) * 100.0)/1024.0;
    
  server.send(200, "text/html", SendHTML(moistureLevel,true)); 
}

void turnOffPump() {
   moistureLevel = 100 - (analogRead(ldrPin) * 100.0)/1024.0;
  pumpStatus = LOW;
  server.send(200, "text/html", SendHTML(moistureLevel,false)); 
}



void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}
