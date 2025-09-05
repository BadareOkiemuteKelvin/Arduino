
void loop() {
  server.handleClient();
  if(fanStatus)
  {digitalWrite(fanPin, HIGH);}
  else
  {digitalWrite(fanPin, LOW);}
  
  if(socketStatus)
  {digitalWrite(socketPin, HIGH);}
  else
  {digitalWrite(socketPin, LOW);}

  if(bulbStatus)
  {digitalWrite(bulbPin, HIGH);}
  else
  {digitalWrite(bulbPin, LOW);}
  
  if(acStatus)
  {digitalWrite(acPin, HIGH);}
  else
  {digitalWrite(acPin, LOW);}

   if(pumpStatus)
  {digitalWrite(pumpPin, HIGH);}
  else
  {digitalWrite(pumpPin, LOW);}
  

}
