void Petrol(void)
{
   cls();
  printf(0,0,"Petrol Adulteration");
  printf(1,0,"TIME:");
  printf(1,7,"S");
  printf(2,0,"Samples:");
  printf(3,0,"Scanning....");
   SampleRate = 5;//EEPROM.read(0);
   SampleTime = 5;//EEPROM.read(1);
   TIME = SampleTime;  
   LPGSampleSummation = 0.0,LPGSampleMean = 0.0;
   METHANESampleSummation = 0.0,METHANESampleMean = 0.0;
   i=0;
 while(TIME>0)
 {
    if(i<SampleRate)
    {
     LPGSample[i] = map(analogRead(SENSOR),0,1023,0.0,120.0);
     METHANESample[i] = map(analogRead(SENSOR),0,1023,0.0,5000.0);
    printf(1,6,TIME);
    printf(2,8,analogRead(SENSOR));
    i = i + 1;
    }
    TIME = TIME-1;
    delay(100);
 
 }
  for(i = 0;i<SampleRate;i++)
  {
    LPGSampleSummation = LPGSampleSummation + LPGSample[i];
    METHANESampleSummation = METHANESampleSummation + METHANESample[i];
    Blynk.virtualWrite(V0,METHANESampleMean); 
    Blynk.virtualWrite(V3,LPGSampleSummation); 
  }
  LPGSampleMean = LPGSampleSummation/SampleRate;
  METHANESampleMean = METHANESampleSummation/SampleRate;
  cls();
  printf(0,7,"RESULT");
  printf(1,0,"METHANE:");
  printf(1,8,METHANESampleMean);
  printf(1,15,"PPM");
  printf(2,0,"LPG:");
  printf(2,4,LPGSampleMean);
  printf(2,8,"PPM");
  Blynk.virtualWrite(V0,METHANESampleMean); 

  i = 0;
 delay(5000);
  cls();
  if(METHANESampleMean>1000)
  {
   printf(0,7,"RESULT");
   printf(1,5,"Pure Petrol");
   printf(2,7,"Detected");
   Blynk.virtualWrite(V2,(METHANESampleMean * 255)/5000); 
   delay(5000);
  }else
  {
   printf(0,7,"RESULT");
   printf(1,0,"Adulterated Petrol");
   printf(2,6,"Detected");
   printf(3,5,"Sending SMS...");
   Blynk.virtualWrite(V1,1); 
   Blynk.virtualWrite(V2,(METHANESampleMean * 255)/5000); 
   delay(5000);

  }
  Menu_index = 1;
}