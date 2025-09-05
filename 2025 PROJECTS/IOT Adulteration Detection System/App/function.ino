
void Welcome(void)
{
  cls();//Clear The Display 
  printf(0,5,"ELECTRONIC");
  printf(1,7,"DIGITAL");
  printf(2,4,"ADULTERATION");
  printf(3,3,"DETECTION DEVICE");
  delay(2000);//Cause a delay/pause for 2s(2000ms)
  cls();
  for(char i = 0; i<1;i++)
  {
  printf(0,0,"WARMING SENSORS");
  printf(1,0,"PLEASE WAIT....");
  printf(1,15,i);
  delay(200);//Cause a delay/pause for 2s(2000ms)
  }

  for(char i = 0;i<1000;i++)
  {
   cls();
   printf(0,0,"USE THE BUTTON TO");
   printf(1,0,"NAVIGATE THE SYSTEM");
   printf(2,0,"PRESS ANY KEY");
   printf(3,0, "TO START");
   delay(1000);//Cause a delay/pause for 2s(2000ms)
   if((digitalRead(leftKey)==1)||(digitalRead(rightKey)==1)||(digitalRead(middleKey)==1))
   {
         break;
   }

  }
  cls();
}


void ADULTERATION(void)
{

  printf(0,0,"(1)-Petrol Test");
  printf(1,0,"(2)-Diesel Test");
  printf(2,0,"(3)-Gas Detector");
  printf(3,0,"(4)-Configuration");
  

  
    if((digitalRead(middleKey)==1)&&(Menu_index==1))
    {
     Petrol();
    }
    if((digitalRead(middleKey)==1)&&(Menu_index==2))
    {
     // Diesel();
    }
    if((digitalRead(middleKey)==1)&&(Menu_index==3))
    {
     // cls();
     // GAS_LEAKAGE();
    }
    if((digitalRead(middleKey)==1)&&(Menu_index==4))
    {
      cls();
      Menu_index = 1;
      CONFIGURATION();
    }


     if((digitalRead(leftKey)==1)){
      if(Menu_index>0){
        Menu_index -= 1;
      }
       
    }
    if((digitalRead(rightKey)==1)){
      if(Menu_index<4){
        Menu_index += 1;
      }
    }

    if(Menu_index==1){
        printf(0,18,"<-");
        printf(1,18,"  ");
        printf(2,18,"  ");
        printf(3,18,"  ");
    }else if(Menu_index==2){
        printf(0,18,"  ");
        printf(1,18,"<-");
        printf(2,18,"  ");
        printf(3,18,"  ");
    }else if(Menu_index==3){
        printf(0,18,"  ");
        printf(1,18,"  ");
        printf(2,18,"<-");
        printf(3,18,"  ");
    }else if(Menu_index==4){
        printf(0,18,"  ");
        printf(1,18,"  ");
        printf(2,18,"  ");
        printf(3,18,"<-");
    }
   
  
  
}





void SAMPLING_RATE(void)
{
  
  cls();
  printf(0,0,"---SAMPLING RATE---");
  printf(1,0,"PREVIOUS VALUE = ");
  SampleRate = EEPROM.read(0);
  printf(1,18,SampleRate);
  printf(2,0,"ENTER NEW VALUE = ");
  printf(3,0,"PRESS \"#\" TO SAVE");
  Menu_index = 3;
  while(1)
  {
    printf(2,19,NewSampleRate);      
    
   if((digitalRead(rightKey)==1)&&(NewSampleRate<100))
   {
    NewSampleRate += 1;
   }
    if((digitalRead(leftKey)==1)&&(NewSampleRate>0))
   {
    NewSampleRate -= 1;
   }
    if((digitalRead(middleKey)==1))
    {
      EEPROM.write(0,NewSampleRate);
      SAVE_SUCCESSFULLY();
      break;
    }
  }

}

void SAMPLING_TIME(void)
{
  cls();

  printf(0,0,"---SAMPLING TIME---");
  printf(1,0,"PREVIOUS VALUE = ");
  SampleTime = EEPROM.read(1);
  printf(1,18,SampleTime);
  printf(2,0,"ENTER NEW VALUE = ");
  printf(3,0,"PRESS \"#\" TO SAVE");
  Menu_index = 3;
  while(1)
  {
   printf(2,19,NewSampleTime);      
    
   if((digitalRead(rightKey)==1)&&(NewSampleTime<100))
   {
    NewSampleTime += 1;
   }
    if((digitalRead(leftKey)==1)&&(NewSampleTime>0))
   {
    NewSampleTime -= 1;
   }
    if((digitalRead(middleKey)==1))
    {
      EEPROM.write(1,NewSampleTime);
      SAVE_SUCCESSFULLY();
      break;
    }

}
}


void SAVE_SUCCESSFULLY(void)
{
  cls();
  printf(0,5,"CONFIGURATION");
  printf(1,2,"SAVED SUCCESSFULLY");
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
   printf(0,5,"SYSTEM RESTORED");
   printf(1,7,"SUCCESSFULLY");
   delay(1000);
   Menu_index = 1;
}
