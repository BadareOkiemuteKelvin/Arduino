void setup() {
  sensors.begin();	// Start up the library
  Serial.begin(9600);
  pinMode(fanPin, OUTPUT);
  pinMode(socketPin, OUTPUT);
   pinMode(bulbPin, OUTPUT);
  pinMode(acPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(pirPin, INPUT);
  pinMode(ldrPin, INPUT);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(fanPin, LOW);
  digitalWrite(socketPin, LOW);
  digitalWrite(bulbPin, LOW);
  digitalWrite(acPin, LOW);
  digitalWrite(pumpPin, LOW);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  server.on("/", handle_OnConnect);
  server.on("/fanon", turnOnFan);
  server.on("/fanoff", turnOffFan);
  server.on("/socketon", turnOnSocket);
  server.on("/socketoff", turnOffSocket);
  server.on("/bulbon", turnOnBulb);
  server.on("/bulboff", turnOffBulb);
  server.on("/acon", turnOnAc);
  server.on("/acoff", turnOffAc);
  server.on("/pumpon", turnOnPump);
  server.on("/pumpoff", turnOffPump);
  server.onNotFound(handle_NotFound);
  
  server.begin();


}