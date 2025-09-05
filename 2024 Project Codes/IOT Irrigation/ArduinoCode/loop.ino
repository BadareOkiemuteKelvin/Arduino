
void loop() {
 

  printf(0,2,"IRRIGATION SYS");
  printf(1,6,moistureLevel);
  moistureLevel = 100 - (analogRead(ldrPin) * 100.0)/1024.0;

  //print the temperature in Celsius
  Serial.print("MOISTURE RESULT: ");
  Serial.print(moistureLevel);
  Serial.println("%");
  

  if(moistureLevel<24){
    
   pumpStatus = HIGH;

  }else{

     pumpStatus = LOW;
  }



  server.handleClient();
  

 
   
  if(pumpStatus)
  {digitalWrite(pumpPin, HIGH);}
  else
  {digitalWrite(pumpPin, LOW);}
  

}
