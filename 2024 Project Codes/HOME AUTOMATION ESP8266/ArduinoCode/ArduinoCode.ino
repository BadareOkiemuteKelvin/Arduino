#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <OneWire.h>
#include <DallasTemperature.h>


/* Put your SSID & Password */
const char* ssid = "HOME AUTOMATION SYSTEM";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

double temp = 0.0;


// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS D0

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);	

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);


uint8_t fanPin = D1;
bool fanStatus = LOW;

uint8_t socketPin = D2;
bool socketStatus = LOW;

uint8_t bulbPin = D3;
bool bulbStatus = LOW;

uint8_t acPin = D4;
bool acStatus = LOW;

uint8_t pumpPin = D5;
bool pumpStatus = LOW;


uint8_t buzzerPin = 21;


uint8_t pirPin = D6;

uint8_t ldrPin = A0;



void handle_OnConnect();
void toggleBuzzer();
String SendHTML(uint8_t fanStatus,uint8_t socketStatus,uint8_t bulbStatus,uint8_t acStatus,uint8_t pumpStatus);


void turnOnFan() {
  fanStatus = HIGH;
  server.send(200, "text/html", SendHTML(true,socketStatus,bulbStatus,acStatus,pumpStatus)); 
}

void turnOffFan() {
  fanStatus = LOW;
  server.send(200, "text/html", SendHTML(false,socketStatus,bulbStatus,acStatus,pumpStatus)); 
}

void turnOnSocket() {
  socketStatus = HIGH;
  server.send(200, "text/html", SendHTML(fanStatus,true,bulbStatus,acStatus,pumpStatus)); 
}

void turnOffSocket() {
  socketStatus = LOW;
  server.send(200, "text/html", SendHTML(fanStatus,false,bulbStatus,acStatus,pumpStatus)); 
}

void turnOnBulb() {
  bulbStatus = HIGH;
  server.send(200, "text/html", SendHTML(fanStatus,socketStatus,true,acStatus,pumpStatus)); 
}

void turnOffBulb() {
  bulbStatus = LOW;
  server.send(200, "text/html", SendHTML(fanStatus,socketStatus,false,acStatus,pumpStatus)); 
}

void turnOnAc() {
  acStatus = HIGH;
  server.send(200, "text/html", SendHTML(fanStatus,socketStatus,bulbStatus,true,pumpStatus)); 
}

void turnOffAc() {
  acStatus = LOW;
  server.send(200, "text/html", SendHTML(fanStatus,socketStatus,bulbStatus,false,pumpStatus)); 
}

void turnOnPump() {
  pumpStatus = HIGH;
  server.send(200, "text/html", SendHTML(fanStatus,socketStatus,bulbStatus,acStatus,true)); 
}

void turnOffPump() {
  pumpStatus = LOW;
  server.send(200, "text/html", SendHTML(fanStatus,socketStatus,bulbStatus,acStatus,false)); 
}



void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}
