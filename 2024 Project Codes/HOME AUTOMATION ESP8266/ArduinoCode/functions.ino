void handle_OnConnect() {
  fanStatus = LOW;
  socketStatus = LOW;
  bulbStatus = LOW;
  acStatus = LOW;
  pumpStatus = LOW;

  toggleBuzzer();
  server.send(200, "text/html", SendHTML(fanStatus,socketStatus,bulbStatus,acStatus,pumpStatus)); 
}


void toggleBuzzer(){

       digitalWrite(buzzerPin, HIGH);
       delay(500);
       digitalWrite(buzzerPin, LOW);
       delay(500);

}