void setup() {
  Serial.begin(9600);
        lcd.begin(16,2);
  pinMode(pumpPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(pumpPin, LOW);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  
  server.on("/", handle_OnConnect);
  server.on("/pumpon", turnOnPump);
  server.on("/pumpoff", turnOffPump);
  server.onNotFound(handle_NotFound);
  
  server.begin();



}