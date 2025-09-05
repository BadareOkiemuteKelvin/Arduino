void loop()
{
  printf(0,8,"HOME");
  printf(1,0,"<");
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
     printf(1,4,"ADULTERATION ");
  }else if(Menu_index==1)
  {
     printf(1,4,"GAS LEAKAGE  ");
  }else if(Menu_index==2)
  {
     printf(1,4,"CONFIGURATION");
  }
 
if((digitalRead(MK)==1)&&(Menu_index==0))
  {
    ADULTERATION();
 
  }else if((digitalRead(MK)==1)&&(Menu_index==1))
  {
  
    GAS_LEAKAGE();
  }else if((digitalRead(MK)==1)&&(Menu_index==2))
  {
   CONFIGURATION();
  }
}
