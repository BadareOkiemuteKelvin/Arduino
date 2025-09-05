
void GAS_LEAKAGE(void)
{
  cls();
  printf(0,0,"GAS DETECTOR SYS");
  printf(1,0,"LPG CONC:");
  printf(1,17,"%");
  printf(2,0,"METHANE CONC:");
  printf(2,17,"%");
  printf(3,0,"PRESS \"#\" TO Exit");
  Menu_index = 1;
  while(1)
  {
    sLPG = analogRead(SENSOR);
    sMETHANE = analogRead(SENSOR);
    if((map(sLPG,0,1023,0,100)<100)&&(map(sLPG,0,1023,0,100)>10))
    {
      printf(1,16,"%");
      printf(1,17," ");
      printf(1,14,map(sLPG,0,1023,0,100));
  
    }
    else if(map(sLPG,0,1023,0,100)<10)
    {
      printf(1,15,"%");
      printf(1,16," ");
      printf(1,17," ");
      printf(1,14,map(sLPG,0,1023,0,100));
       
    }else
    {
       printf(1,14,map(sLPG,0,1023,0,100));
       printf(1,17,"%");
    
    }
     if((map(sMETHANE,0,1023,0,100)<100)&&(map(sMETHANE,0,1023,0,100)>10))
    {
      printf(2,16,"%");
      printf(2,17," ");
      printf(2,14,map(sMETHANE,0,1023,0,100));
         
    }
    else if(map(sMETHANE,0,1023,0,100)<10)
    {
      printf(2,15,"%");
      printf(2,16," ");
      printf(2,17," ");
      printf(2,14,map(sMETHANE,0,1023,0,100));
       
    }else
    {
       printf(2,14,map(sMETHANE,0,1023,0,100));
       printf(2,17,"%");
    }
   if((map(sMETHANE,0,1023,0,100)>70)||(map(sLPG,0,1023,0,100)>70))
  {
      break;
  }
 
  delay(1000);  
  }
  cls();
  Menu_index = 1;
}

