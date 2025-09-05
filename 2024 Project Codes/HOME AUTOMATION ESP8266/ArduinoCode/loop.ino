
void loop() {
  sensors.requestTemperatures(); 
  temp = sensors.getTempCByIndex(0);


  //print the temperature in Celsius
  Serial.print("LDR RESULT: ");
  Serial.print(analogRead(ldrPin));
  Serial.println(" |  ");


  //print the temperature in Celsius
  Serial.print("Temperature RESULT: ");
  Serial.print(temp);
  Serial.print((char)176);//shows degrees character
  Serial.println("C  |  ");


    //print the temperature in Celsius
  Serial.print("IR RESULT: ");
  Serial.print(digitalRead(pirPin));
  Serial.println(" |  ");

  server.handleClient();
  

  if(temp>31){
       fanStatus = HIGH;
       digitalWrite(fanPin, HIGH);
  }
  if(digitalRead(pirPin)==0){
       bulbStatus = HIGH;
       digitalWrite(bulbPin, HIGH);
  }
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
