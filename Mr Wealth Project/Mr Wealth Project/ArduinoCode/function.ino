
void Welcome(void)
{
  cls();//Clear The Display 
  printf(1,4,"ADULTERATION");
  printf(2,2,"DETECTION DEVICE");
  toggleAlarm();
  delay(2000);//Cause a delay/pause for 2s(2000ms)
  cls();
  for(char i = 0; i<100;i++)
  {
  printf(1,3,"WARMING SENSORS");
  printf(2,5,"PLEASE WAIT");
  printf(3,10,i);
  delay(200);//Cause a delay/pause for 2s(2000ms)
  }

  for(char i = 0;i<1000;i++)
  {
   cls();
   printf(0,0,"PRESS ANY KEY(S)");
   printf(1,0, "TO START");
   delay(1000);//Cause a delay/pause for 2s(2000ms)
   if(digitalRead(LK)==1||digitalRead(MK)==1||digitalRead(RK)==1)
   {
     toggleAlarm();
     break;
   }

  }
  cls();
}

void ADULTERATION(void)
{
  delay(500);
  cls();
  Menu_index = 0;
  while(1)
  {
  printf(0,4,"ADULTERATION");
  printf(1,0,"< ");
  printf(1,19,">");
  if(digitalRead(LK)==1)
  {
    toggleAlarm();
    if(Menu_index>0)
    Menu_index -=1;

  }
 if(digitalRead(RK)==1)
  {
    toggleAlarm();
    if(Menu_index<4)
    Menu_index +=1;

  }
  if(Menu_index==0)
  {  
     printf(1,5,"PETROLEUM");
  }else if(Menu_index==1)
  {
     printf(1,5," DIESEL  ");
  }else if(Menu_index==2)
  {
     printf(1,5,"KEROSENE ");

  }else if(Menu_index==3)
  {
     printf(1,4,"  BACK   ");
  }
 
if((digitalRead(MK)==1)&&(Menu_index==0))
  {
     Petrol();
     delay(500);
 
  }else if((digitalRead(MK)==1)&&(Menu_index==1))
  {
    Diesel();
    delay(500);

  }else if((digitalRead(MK)==1)&&(Menu_index==2))
  {
   
  }else if((digitalRead(MK)==1)&&(Menu_index==3))
  {
     delay(500);
     break;
  }

   
  }
  Menu_index=0;
  cls();
}

void GAS_LEAKAGE(void)
{
  cls();
  Menu_index = 0;

  while(1)
  {
     sLPG = analogRead(LPG);
    sMETHANE = analogRead(METHANE);
  printf(0,0,"GAS DETECTOR SYS");
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
    if(Menu_index<3)
    Menu_index +=1;

  }
  if(Menu_index==0)
  {  
     printf(1,1,"LPG:");
     printf(1,14,"%");
     if((map(sLPG,0,1023,0,100)<100)&&(map(sLPG,0,1023,0,100)>10))
    {
      printf(1,5,map(sLPG,0,1023,0,100));
      digitalWrite(ALARM,LOW);
    }
    else if(map(sLPG,0,1023,0,100)<10)
    {
      printf(1,6,"  ");
      printf(1,5,map(sLPG,0,1023,0,100));
      digitalWrite(ALARM,LOW);
    }else
    {
       printf(1,5,map(sLPG,0,1023,0,100));
    }
  }else if(Menu_index==1)
  {
       printf(1,1,"MTH:");
       printf(1,9,"%");
    if((map(sMETHANE,0,1023,0,100)<100)&&(map(sMETHANE,0,1023,0,100)>10))
    {
      printf(1,5,map(sMETHANE,0,1023,0,100));
      digitalWrite(ALARM,LOW);
    }
    else if(map(sMETHANE,0,1023,0,100)<10)
    {  
         printf(1,6,"  ");
         printf(1,5,map(sMETHANE,0,1023,0,100));
         digitalWrite(ALARM,LOW);
    }
  }else if(Menu_index==2)
  {
       printf(1,2,"  Back    ");

  }
   
 
   if((map(sMETHANE,0,1023,0,100)>70)||(map(sLPG,0,1023,0,100)>70))
  {
      digitalWrite(ALARM,HIGH);
      delay(10000);
      digitalWrite(ALARM,LOW);
      break;
  }
 
  delay(1000);  
  }
  cls();
  Menu_index = 3;
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
    if(Menu_index<4)
    Menu_index +=1;

  }
  if(Menu_index==0)
  {  
     printf(1,1,"SAMPLING RATE");
  }else if(Menu_index==1)
  {
     printf(1,1,"SAMPLING TIME");
  }else if(Menu_index==2)
  {
    printf(1,1,"FACTORY RESET");
  }else if(Menu_index==3)
  {
    printf(1,1,"    BACK     ");

  }
 
if((digitalRead(MK)==1)&&(Menu_index==0))
  {
     SAMPLING_RATE();
 
  }else if((digitalRead(MK)==1)&&(Menu_index==1))
  {
  
    SAMPLING_TIME();
  }else if((digitalRead(MK)==1)&&(Menu_index==2))
  {
   FACTORY_RESTORE();
  }else if((digitalRead(MK)==1)&&(Menu_index==3))
  {
    Menu_index = 0;
    break;
  }
  }
  cls();
}
void SAMPLING_RATE(void)
{
  delay(500);
  cls();
  printf(0,0,"SAMPLING RATE");
  printf(1,0,"<");
  printf(1,15,">");
  SampleRate = EEPROM.read(0);

  while(1)
  {
  if((SampleRate<100)&&(SampleRate>10))
    {
       printf(1,9," ");
       printf(1,7,SampleRate);
    }else if((SampleRate<10)&&(SampleRate>0))
    {
       printf(1,8,"  ");
       printf(1,7,SampleRate);
    }else
    {
         printf(1,7,SampleRate);
    }
   if(digitalRead(LK)==1)
  {
    toggleAlarm();
    SampleRate = SampleRate - 1;
    delay(100);
  }
  if(digitalRead(RK)==1)
  {
    toggleAlarm();
    SampleRate = SampleRate + 1;
    delay(100);

  }
  if(digitalRead(MK)==1)
  {
    toggleAlarm();
    EEPROM.write(0,SampleRate);
    SAVE_SUCCESSFULLY();
    cls();
    break;

  }

  }

}

void SAMPLING_TIME(void)
{
  delay(500);
  cls();
  printf(0,0," SAMPLING TIME ");
  printf(1,0,"<");
  printf(1,15,">");
  SampleTime = EEPROM.read(1);
  while(1)
  {
    if((SampleTime<100)&&(SampleTime>10))
    {
       printf(1,9," ");
       printf(1,7,SampleTime);
    }else if((SampleTime<10)&&(SampleTime>0))
    {
       printf(1,8,"  ");
       printf(1,7,SampleTime);
    }else
    {
         printf(1,7,SampleTime);
    }
 
   if(digitalRead(LK)==1)
  {
    toggleAlarm();
    SampleTime = SampleTime - 1;
    delay(100);

  }
  if(digitalRead(RK)==1)
  {
    toggleAlarm();
    SampleTime = SampleTime + 1;
    delay(100);

  }
  if(digitalRead(MK)==1)
  {
    toggleAlarm();
    EEPROM.write(1,SampleTime);
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
   SampleRate = 5;// sample times
   NewSampleRate = 0;// sample times
   SampleTime = 5;
   NewSampleTime = 0;
   EEPROM.write(1, SampleTime);
   EEPROM.write(0, SampleRate);
   printf(0,0,"SYSTEM RESTORED");
   printf(1,0,"  SUCCESSFULLY ");
   delay(1000);
   Menu_index = 0;
}

void toggleAlarm(void);

void toggleAlarm(void)
{
      digitalWrite(ALARM,HIGH);
      delay(100);
      digitalWrite(ALARM,LOW);
      delay(100);
}