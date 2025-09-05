void loop()
{ 
    NEPA_VOLT = getMainVoltage();
      Serial.println(NEPA_VOLT);
   if(NEPA_VOLT>100){
      NEPA_MODE();
   }else{
      GEN_MODE();
   }
 

   

}
