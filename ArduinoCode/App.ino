void loop() {
  rtc.refresh();
   printf(0,0,"DATE--->");

  if(rtc.day()>9){
     printf(0,8,rtc.day());
  }else{
     printf(0,9,rtc.day());
     printf(0,8,"0");
  }
  
  printf(0,10,"/");

  if(rtc.month()>9){
     printf(0,11,rtc.month());
  }else{
     printf(0,12,rtc.month());
     printf(0,11,"0");
  }

  printf(0,13,"/");

  if(rtc.year()>9){
     printf(0,14,rtc.year());
  }else{
     printf(0,15,rtc.year());
     printf(0,14,"0");
  }

 if(rtc.hour()>9){
      printf(1,3,rtc.hour());
  }else{
      printf(1,3,"0");
      printf(1,4,rtc.hour());
  }
  
  printf(1,5,":");

  if(rtc.minute()>9){
     printf(1,6,rtc.minute());
  }else{
     printf(1,7,rtc.minute());
      printf(1,6,"0");
  }

  printf(1,8,":");

  if(rtc.second()>9){
     printf(1,9,rtc.second());
  }else{
     printf(1,10,rtc.second());
     printf(1,9,"0");
  }

  if((digitalRead(MK)==1)&&(Menu_index==0))
  {
     toggleAlarm();
    CONFIGURATION();
 
  }


  if(i<2){

    toggleAlarm();
  }

  RINGALARM();

    static boolean newDataReady = 0;
  const int serialPrintInterval = 500; //increase value to slow down serial print activity


  // check for new data/start next conversion:
  if (LoadCell.update()) newDataReady = true;
   
  // get smoothed value from the dataset:
  if (newDataReady) {
    if (millis() > t + serialPrintInterval) {
      i = LoadCell.getData();
      Serial.print("Load_cell output val: ");
      Serial.println(i);
      newDataReady = 0;
      t = millis();
    }
  }
  
  weight = ((i * 50)/1651260);
  Error(weight);
  //printf(1,12,weight);

  /*
  // receive command from serial terminal, send 't' to initiate tare operation:
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    if (inByte == 't') LoadCell.tareNoDelay();
  }

  // check if last tare operation is complete:
  if (LoadCell.getTareStatus() == true) {
    Serial.println("Tare complete");
  }
  */
  
  delay(1000);
}