
void Diesel(void)
{
   cls();
  SampleRate = EEPROM.read(0);
  SampleTime = EEPROM.read(1);
    printf(0,1,"DIESEL ADULTERATION");
    printf(1,0,"..SCANNING PRODUCT..");
  TIME = SampleTime;
   i = 0;
   LPGSampleSummation = 0.0,LPGSampleMean = 0.0;
   METHANESampleSummation = 0.0,METHANESampleMean = 0.0;
 while(TIME>0)
 {
    if(i<SampleRate)
    {
     LPGSample[i] = map(analogRead(LPG),0,1023,0.0,120.0);
     METHANESample[i] = map(analogRead(METHANE),0,1023,0.0,5000.0);
    i = i + 1;
    }
    TIME = TIME-1;
    delay(1000);
 
 }
  for(i = 0;i<SampleRate;i++)
  {
    LPGSampleSummation = LPGSampleSummation + LPGSample[i];
    METHANESampleSummation = METHANESampleSummation + METHANESample[i];
  }
  LPGSampleMean = LPGSampleSummation/SampleRate;
  METHANESampleMean = METHANESampleSummation/SampleRate;
  cls();
  printf(0,5,"RESULT");
  printf(1,0,"METHANE:");
  printf(1,8,METHANESampleMean);
  printf(1,15,"PPM");
  printf(2,0,"LPG    :");
  printf(2,8,LPGSampleMean);
  printf(2,15,"PPM");
 i = 0;
  delay(5000);
  cls();
  cls();
  if(METHANESampleMean<100)
  {
    printf(0,7,"RESULT");
   printf(1,3,"   PURE DIESEL  ");
   printf(2,3,"    DETECTED    ");
    delay(5000);
  }else
  {
   printf(0,7,"RESULT");
   printf(1,3,"ADULTERATED DIESEL");
   printf(2,4,"   DETECTED     ");
   delay(5000);
  }
  Menu_index = 0;
}