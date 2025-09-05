void toggleAlarm(void);

void toggleAlarm(void)
{
      digitalWrite(ALARM,HIGH);
      delay(200);
      digitalWrite(ALARM,LOW);
      delay(200);
}

void ringer(void)
{
      digitalWrite(ALARM,HIGH);
      delay(100);
      digitalWrite(ALARM,LOW);
      delay(100);
}


void RINGALARM(){
    
     DELAYX = EEPROM.read(5);
    if((MINUTE == rtc.minute())&&(HOUR == rtc.hour())&&(rtc.second() == 0)){

      cls();
     
      while(1){

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

  if(weight<49.5){

    counter = counter + 1;


    }else{

        counter = 0;
    }

    if(counter == DELAYX){
      lcd.clear();
      break;
    }
        rtc.refresh();
     printf(0,0,"WAKE UP ALARM!!!");
       if(rtc.hour()>9){
     printf(1,4,rtc.hour());
      }else{
      printf(1,4,"0");
     printf(1,5,rtc.hour());
     }
  
     printf(1,6,":");

  if(rtc.minute()>9){
     printf(1,7,rtc.minute());
  }else{
     printf(1,8,rtc.minute());
      printf(1,7,"0");
  }

  printf(1,9,":");

  if(rtc.second()>9){
     printf(1,10,rtc.second());
  }else{
     printf(1,11,rtc.second());
     printf(1,10,"0");
  }

          ringer();
      }

    }

}


void Welcome(void)
{
  cls();//Clear The Display 
  printf(0,0,"SMART WAKEUP MAT");
  printf(1,4,"SYSTEM");
  toggleAlarm();
  delay(2000);//Cause a delay/pause for 2s(2000ms)
  cls();
}

void CONFIGURATION(void)
{
  cls();
  Menu_index = 0;
  while(1)
  {
  printf(0,0," CONFIGURATIONS ");
  printf(1,0,"<");
  printf(1,15,">");
  if(digitalRead(LK)==1)
  {
    toggleAlarm();
    if(Menu_index>0)
    Menu_index -=1;

  }
 if(digitalRead(RK)==1)
  {
    toggleAlarm();
    if(Menu_index<12)
    Menu_index +=1;

  }
  if(Menu_index==0)
  {  
     printf(1,1,"HOUR-SETTING  ");
  }else if(Menu_index==1)
  {
     printf(1,1,"MINUTE-SETTING");
  }else if(Menu_index==2)
  {
    printf(1,1," DAY-SETTING  ");
  }else if(Menu_index==3)
  {
     printf(1,1," MONTH-SETTING");
  }else if(Menu_index==4)
  {
    printf(1,1," YEAR-SETTING ");

  }else if(Menu_index==5)
  {
    printf(1,1," DELAY-SETTING");

  }else if(Menu_index==6)
  {
    printf(1,1," RTC-HOUR  SET");
    
  }else if(Menu_index==7)
  {
    printf(1,1," RTC-MIN   SET");
    
  }else if(Menu_index==8)
  {
    printf(1,1," RTC-DAY  SET");
    
  }else if(Menu_index==9)
  {
    printf(1,1," RTC-WEEK   SET");
    
  }else if(Menu_index==10)
  {
    printf(1,1," RTC-MON   SET");
    
  }else if(Menu_index==11)
  {
    printf(1,1," RTC-YEAR  SET");
    
  }else if(Menu_index==12)
  {
    printf(1,1,"    BACK      ");

  }
  
 
if((digitalRead(MK)==1)&&(Menu_index==0))
  {
     toggleAlarm();
     SET_HOUR();
 
  }else if((digitalRead(MK)==1)&&(Menu_index==1))
  {
     toggleAlarm();
     SET_MINUTE();
  }else if((digitalRead(MK)==1)&&(Menu_index==2))
  {
     SET_DAY();
  }if((digitalRead(MK)==1)&&(Menu_index==3))
  {
     toggleAlarm();
     SET_MONTH();
  }else if((digitalRead(MK)==1)&&(Menu_index==4))
  {
     toggleAlarm();
     SET_YEAR();
  }else if((digitalRead(MK)==1)&&(Menu_index==5))
  {
     toggleAlarm();
     SET_DELAY();
  }else if((digitalRead(MK)==1)&&(Menu_index==6))
  {
     toggleAlarm();
     SET_RTC_HOUR();
  }else if((digitalRead(MK)==1)&&(Menu_index==7))
  {
     toggleAlarm();
     SET_RTC_MIN();
  }else if((digitalRead(MK)==1)&&(Menu_index==8))
  {
     toggleAlarm();
     SET_RTC_DAY();
  }else if((digitalRead(MK)==1)&&(Menu_index==9))
  {
     toggleAlarm();
     SET_RTC_WEEK();
  }else if((digitalRead(MK)==1)&&(Menu_index==10))
  {
     toggleAlarm();
     SET_RTC_MON();
  }else if((digitalRead(MK)==1)&&(Menu_index==11))
  {
     toggleAlarm();
     SET_RTC_YEAR();
  }else if((digitalRead(MK)==1)&&(Menu_index==12))
  {
    Menu_index = 0;
    toggleAlarm();
    break;
  }
  }
  cls();
}


void SET_DAY(void)
{
  delay(500);
  cls();
  printf(0,5,"SET DAY     ");
  printf(1,0,"<");
  printf(1,15,">");
  DAY = EEPROM.read(0);

  while(1)
  {
  if((DAY<100)&&(DAY>10))
    {
       printf(1,9," ");
       printf(1,7,DAY);
    }else if((DAY<10)&&(DAY>0))
    {
       printf(1,8,"  ");
       printf(1,7,DAY);
    }else
    {
         printf(1,7,DAY);
    }
   if(digitalRead(LK)==1)
  {
    toggleAlarm();
    DAY = DAY - 1;
    if(DAY<1){
      DAY = 0;
    }
    delay(100);
  }
  if(digitalRead(RK)==1)
  {
    toggleAlarm();
    DAY = DAY + 1;
    if(DAY>30){
      DAY = 30;
    }
    delay(100);

  } 
  if(digitalRead(MK)==1)
  {
    toggleAlarm();
    EEPROM.write(0,DAY);
    SAVE_SUCCESSFULLY();
    cls();
    break;

  }

  }

}

void SET_MONTH(void)
{
  delay(500);
  cls();
  printf(0,4,"SET MONTH    ");
  printf(1,0,"<");
  printf(1,15,">");
  MONTH = EEPROM.read(1);

  while(1)
  {
  if((MONTH<100)&&(MONTH>10))
    {
       printf(1,9," ");
       printf(1,7,MONTH);
    }else if((MONTH<10)&&(MONTH>0))
    {
       printf(1,8,"  ");
       printf(1,7,MONTH);
    }else
    {
         printf(1,7,MONTH);
    }
   if(digitalRead(LK)==1)
  {
    toggleAlarm();
    MONTH = MONTH - 1;
    if(MONTH<1){
      MONTH = 0;
    }
    delay(100);
  }
  if(digitalRead(RK)==1)
  {
    toggleAlarm();
    MONTH = MONTH + 1;
    if(MONTH>12){
      MONTH = 12;
    }
    delay(100);

  } 
  if(digitalRead(MK)==1)
  {
    toggleAlarm();
    EEPROM.write(1,MONTH);
    SAVE_SUCCESSFULLY();
    cls();
    break;

  }

  }

}


void SET_YEAR(void)
{
  delay(500);
  cls();
  printf(0,4," SET YEAR    ");
  printf(1,0,"<");
  printf(1,15,">");
  YEAR = EEPROM.read(2);
  while(1)
  {
    if((YEAR<100)&&(YEAR>10))
    {
       printf(1,9," ");
       printf(1,7,YEAR);
    }else if((YEAR<10)&&(YEAR>0))
    {
       printf(1,8,"  ");
       printf(1,7,YEAR);
    }else
    {
         printf(1,7,YEAR);
    }
 
   if(digitalRead(LK)==1)
  {
    toggleAlarm();
    YEAR = YEAR - 1;
   if(YEAR<1){
      YEAR = 0;
    }
    delay(100);

  }
  if(digitalRead(RK)==1)
  {
    toggleAlarm();
    YEAR = YEAR + 1;
    if(YEAR>99){
      YEAR = 99;
    }
    delay(100);

  }
  if(digitalRead(MK)==1)
  {
    toggleAlarm();
    EEPROM.write(2,YEAR);
    SAVE_SUCCESSFULLY();
    cls();
    break;

  }

  }


}








void SET_HOUR(void)
{
  delay(500);
  cls();
  printf(0,4,"SET HOUR    ");
  printf(1,0,"<");
  printf(1,15,">");
  HOUR = EEPROM.read(3);

  while(1)
  {
  if((HOUR<100)&&(HOUR>10))
    {
       printf(1,9," ");
       printf(1,7,HOUR);
    }else if((HOUR<10)&&(HOUR>0))
    {
       printf(1,8,"  ");
       printf(1,7,HOUR);
    }else
    {
         printf(1,7,HOUR);
    }
   if(digitalRead(LK)==1)
  {
    toggleAlarm();
    HOUR = HOUR - 1;
    delay(100);
  }
  if(digitalRead(RK)==1)
  {
    toggleAlarm();
    HOUR = HOUR + 1;
    delay(100);

  } 
  if(digitalRead(MK)==1)
  {
    toggleAlarm();
    EEPROM.write(3,HOUR);
    SAVE_SUCCESSFULLY();
    cls();
    break;

  }

  }

}


void SET_MINUTE(void)
{
  delay(500);
  cls();
  printf(0,0," SET MINUTE    ");
  printf(1,0,"<");
  printf(1,15,">");
  MINUTE = EEPROM.read(4);
  while(1)
  {
    if((MINUTE<100)&&(MINUTE>10))
    {
       printf(1,9," ");
       printf(1,7,MINUTE);
    }else if((MINUTE<10)&&(MINUTE>0))
    {
       printf(1,8,"  ");
       printf(1,7,MINUTE);
    }else
    {
         printf(1,7,MINUTE);
    }
 
   if(digitalRead(LK)==1)
  {
    toggleAlarm();
    MINUTE = MINUTE - 1;
    if(MINUTE<1){
      MINUTE = 0;
    }
    delay(100);

  }
  if(digitalRead(RK)==1)
  {
    toggleAlarm();
    MINUTE = MINUTE + 1;
    if(MINUTE>59){
      MINUTE = 59;
    }
    delay(100);

  }
  if(digitalRead(MK)==1)
  {
    toggleAlarm();
    EEPROM.write(4,MINUTE);
    SAVE_SUCCESSFULLY();
    cls();
    break;

  }

  }


}


void SET_DELAY(void)
{
  delay(500);
  cls();
  printf(0,0," SET DELAY");
  printf(1,0,"<");
  printf(1,15,">");
  DELAYX = EEPROM.read(5);
  while(1)
  {
    if((DELAYX<100)&&(DELAYX>10))
    {
       printf(1,9," ");
       printf(1,7,DELAYX);
    }else if((DELAYX<10)&&(DELAYX>0))
    {
       printf(1,8,"  ");
       printf(1,7,DELAYX);
    }else
    {
         printf(1,7,DELAYX);
    }
 
   if(digitalRead(LK)==1)
  {
    toggleAlarm();
    DELAYX = DELAYX - 1;
     if(DELAYX<1){
      DELAYX = 0;
    }
    delay(100);

  }
  if(digitalRead(RK)==1)
  {
    toggleAlarm();
    DELAYX = DELAYX + 1;
    delay(100);

  }
  if(digitalRead(MK)==1)
  {
    toggleAlarm();
    EEPROM.write(5,DELAYX);
    SAVE_SUCCESSFULLY();
    cls();
    break;

  }

  }


}






void SET_RTC_HOUR(void)
{
  delay(500);
  cls();
  printf(0,4,"SET RTC HOUR ");
  printf(1,0,"<");
  printf(1,15,">");

  while(1)
  {
  if((RTC_HOUR<100)&&(RTC_HOUR>10))
    {
       printf(1,9," ");
       printf(1,7,RTC_HOUR);
    }else if((RTC_HOUR<10)&&(RTC_HOUR>0))
    {
       printf(1,8,"  ");
       printf(1,7,RTC_HOUR);
    }else
    {
         printf(1,7,RTC_HOUR);
    }
   if(digitalRead(LK)==1)
  {
    toggleAlarm();
    RTC_HOUR = RTC_HOUR - 1;
    delay(100);
  }
  if(digitalRead(RK)==1)
  {
    toggleAlarm();
    RTC_HOUR = RTC_HOUR + 1;
    delay(100);

  } 
  if(digitalRead(MK)==1)
  {
    toggleAlarm();
     rtc.set(0, RTC_MIN, RTC_HOUR, RTC_WEEK, RTC_DAY, RTC_MON, RTC_YEAR);
    //rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
    SAVE_SUCCESSFULLY();
    cls();
    break;

  }

  }

}




void SET_RTC_MIN(void)
{
  delay(500);
  cls();
  printf(0,4,"SET RTC MIN ");
  printf(1,0,"<");
  printf(1,15,">");

  while(1)
  {
  if((RTC_MIN<100)&&(RTC_MIN>10))
    {
       printf(1,9," ");
       printf(1,7,RTC_MIN);
    }else if((RTC_MIN<10)&&(RTC_MIN>0))
    {
       printf(1,8,"  ");
       printf(1,7,RTC_MIN);
    }else
    {
         printf(1,7,RTC_MIN);
    }
   if(digitalRead(LK)==1)
  {
    toggleAlarm();
    RTC_MIN = RTC_MIN - 1;
    delay(100);
  }
  if(digitalRead(RK)==1)
  {
    toggleAlarm();
    RTC_MIN = RTC_MIN + 1;
    delay(100);

  } 
  if(digitalRead(MK)==1)
  {
    toggleAlarm();
    rtc.set(0, RTC_MIN, RTC_HOUR, RTC_WEEK, RTC_DAY, RTC_MON, RTC_YEAR);
    //rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
    SAVE_SUCCESSFULLY();
    cls();
    break;

  }

  }

}


void SET_RTC_DAY(void)
{
  delay(500);
  cls();
  printf(0,4,"SET RTC DAY ");
  printf(1,0,"<");
  printf(1,15,">");

  while(1)
  {
  if((RTC_DAY<100)&&(RTC_DAY>10))
    {
       printf(1,9," ");
       printf(1,7,RTC_DAY);
    }else if((RTC_DAY<10)&&(RTC_DAY>0))
    {
       printf(1,8,"  ");
       printf(1,7,RTC_DAY);
    }else
    {
         printf(1,7,RTC_DAY);
    }
   if(digitalRead(LK)==1)
  {
    toggleAlarm();
    RTC_DAY = RTC_DAY - 1;
    delay(100);
  }
  if(digitalRead(RK)==1)
  {
    toggleAlarm();
    RTC_DAY = RTC_DAY + 1;
    delay(100);

  } 
  if(digitalRead(MK)==1)
  {
    toggleAlarm();
    rtc.set(0, RTC_MIN, RTC_HOUR, RTC_WEEK, RTC_DAY, RTC_MON, RTC_YEAR);
    //rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
    SAVE_SUCCESSFULLY();
    cls();
    break;

  }

  }

}


void SET_RTC_WEEK(void)
{
  delay(500);
  cls();
  printf(0,4,"SET RTC WEEK ");
  printf(1,0,"<");
  printf(1,15,">");

  while(1)
  {
 
       printf(1,4,Weeks[RTC_WEEK]);
    
   if(digitalRead(LK)==1)
  {
    toggleAlarm();
    if(RTC_WEEK>0){
       RTC_WEEK = RTC_WEEK - 1;
    }
    delay(100);
  }
  if(digitalRead(RK)==1)
  {
    toggleAlarm();
    if(RTC_WEEK<7){
       RTC_WEEK = RTC_WEEK + 1;
    }
    delay(100);
  } 
  if(digitalRead(MK)==1)
  {
    toggleAlarm();
    rtc.set(0, RTC_MIN, RTC_HOUR, RTC_WEEK, RTC_DAY, RTC_MON, RTC_YEAR);
    //rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
    SAVE_SUCCESSFULLY();
    cls();
    break;

  }

  }

}




void SET_RTC_MON(void)
{
  delay(500);
  cls();
  printf(0,4,"SET RTC MON ");
  printf(1,0,"<");
  printf(1,15,">");

  while(1)
  {
  if((RTC_MON<100)&&(RTC_MON>10))
    {
       printf(1,9," ");
       printf(1,7,RTC_MON);
    }else if((RTC_MON<10)&&(RTC_MON>0))
    {
       printf(1,8,"  ");
       printf(1,7,RTC_MON);
    }else
    {
         printf(1,7,RTC_MON);
    }
   if(digitalRead(LK)==1)
  {
    toggleAlarm();
    if(RTC_MON>0){
       RTC_MON = RTC_MON - 1;
    }
    delay(100);
  }
  if(digitalRead(RK)==1)
  {
    toggleAlarm();
    if(RTC_MON<12){
         RTC_MON = RTC_MON + 1;
    }
    delay(100);

  } 
  if(digitalRead(MK)==1)
  {
    toggleAlarm();
    rtc.set(0, RTC_MIN, RTC_HOUR, RTC_WEEK, RTC_DAY, RTC_MON, RTC_YEAR);
    //rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
    SAVE_SUCCESSFULLY();
    cls();
    break;

  }

  }

}

void SET_RTC_YEAR(void)
{
  delay(500);
  cls();
  printf(0,4,"SET RTC YEAR ");
  printf(1,0,"<");
  printf(1,15,">");

  while(1)
  {
  if((RTC_YEAR<100)&&(RTC_YEAR>10))
    {
       printf(1,9," ");
       printf(1,7,RTC_YEAR);
    }else if((RTC_YEAR<10)&&(RTC_YEAR>0))
    {
       printf(1,8,"  ");
       printf(1,7,RTC_YEAR);
    }else
    {
         printf(1,7,RTC_YEAR);
    }
   if(digitalRead(LK)==1)
  {
    toggleAlarm();
    if(RTC_YEAR>0){
       RTC_YEAR = RTC_YEAR - 1;
    }
    delay(100);
  }
  if(digitalRead(RK)==1)
  {
    toggleAlarm();
    if(RTC_YEAR<90){
         RTC_YEAR = RTC_YEAR + 1;
    }
    delay(100);

  } 
  if(digitalRead(MK)==1)
  {
    toggleAlarm();
    rtc.set(0, RTC_MIN, RTC_HOUR, RTC_WEEK, RTC_DAY, RTC_MON, RTC_YEAR);
    //rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
    SAVE_SUCCESSFULLY();
    cls();
    break;

  }

  }

}

void SAVE_SUCCESSFULLY(void)
{
  cls();
  printf(0,2,"CONFIGURATION");
  printf(1,0,"SAVED SUCCESSFULLY");
  delay(1000);
}



void FACTORY_RESTORE(void)
{
   cls();

   EEPROM.write(0, 0);
   EEPROM.write(1, 0);
   EEPROM.write(2, 0);
   EEPROM.write(3, 0);
   EEPROM.write(4, 0);
   DAY = EEPROM.read(0);
   MONTH = EEPROM.read(1);
   YEAR = EEPROM.read(2);
   HOUR = EEPROM.read(3);
   MINUTE = EEPROM.read(4);
   printf(0,0,"SYSTEM RESTORED");
   printf(1,0,"  SUCCESSFULLY ");
   delay(1000);
   Menu_index = 0;
}


void Error(float data){

  if(data<0){
    lcd.clear();
    while(1){
     printf(0,0,"   ERROR - 01   ");
     printf(1,0,"  SENSOR FAILED ");
    }

  }

}