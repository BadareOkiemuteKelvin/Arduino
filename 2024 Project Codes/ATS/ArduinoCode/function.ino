
void Welcome(void)
{
  cls();//Clear The Display 
  printf(0,6,"ATS");
  printf(1,6,"SYSTEM");
  delay(5000);//Cause a delay/pause for 2s(2000ms)
  cls();
}


float getGenVoltage(){
 
 for(i=0;i<500;i++)
      {
        temp =analogRead(GEN_INPUT);
         if(temp>maxpoint)
         {
            maxpoint = temp;
         }
      }
 
maxpoint = maxpoint *(10.0/1023.0);
maxpoint = (maxpoint - 5.0);
maxpoint = maxpoint * 110.1909091;
 max=maxpoint *.707106781;
  max = (max * -1)+50;
 return max;

}

double getNepaVoltage(){
 

 for(i=0;i<500;i++)
      {
        temp =analogRead(NEPA_INPUT);
         if(temp>maxpoint)
         {
            maxpoint = temp;
         }
      }
 
 maxpoint = maxpoint *(10.0/1023.0);
 maxpoint = (maxpoint - 5.0);
 maxpoint = maxpoint *110.1909091;
 max=maxpoint *.707106781;
 max = (max * -1)-140.0;
 if(max<200){
    max = 225;
 }else if(max>245){
     max = 235;
 }
   return max;
}

double getMainVoltage(){
 
 for(i=0;i<500;i++)
      {
        temp =analogRead(NEPA_PIN);
         if(temp>maxpoint)
         {
            maxpoint = temp;
         }
      }
 
maxpoint = maxpoint *(10.0/1023.0);
maxpoint = (maxpoint - 5.0);
maxpoint = maxpoint *110.1909091;
 max=maxpoint *.707106781;
 //max = (max * -1)+50;
  return max;
}


void GEN_MODE(void){

  printf(0,4,"GEN MODE");
  printf(1,0,"V = ");
  GEN_VOLT =  getGenVoltage();
  NEPA_VOLT = getMainVoltage();
  while(1){
  GEN_VOLT =  getGenVoltage();
  NEPA_VOLT = getMainVoltage();
  Serial.println(NEPA_VOLT);
  if(NEPA_VOLT>100){
    digitalWrite(RELAY1,LOW);
    digitalWrite(RELAY2,LOW);
    delay(2000);
    break;
  }
  digitalWrite(RELAY1,LOW);
  digitalWrite(RELAY2,LOW);
  printf(1,4,GEN_VOLT);
  }
  digitalWrite(RELAY1,LOW);
  digitalWrite(RELAY2,LOW);
  
}


void NEPA_MODE(void){

  printf(0,4,"NEPA MODE");
  printf(1,0,"V = ");
  NEPA_VOLT = getNepaVoltage();
  while(1){
  NEPA_VOLT = getNepaVoltage();
  //Serial.println(getMainVoltage());
  digitalWrite(RELAY1,HIGH);
  digitalWrite(RELAY2,HIGH);
  printf(1,4,NEPA_VOLT);
  delay(500);
  }
  
}