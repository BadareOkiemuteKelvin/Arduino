void setup()
{

    pinMode(LPG,INPUT);
    pinMode(METHANE,INPUT);
    pinMode(dipSensor,INPUT);
    pinMode(ALARM,OUTPUT);
    pinMode(LK,INPUT);
    pinMode(MK,INPUT);
    pinMode(RK,INPUT);
    digitalWrite(ALARM,LOW);
    lcd.begin(20,4);
    Serial.begin(9600);
  //  Welcome();//Welcome Note 
for(char i = 0;i<=5;i++)
{
if(EEPROM.read(i)==0xFF)
{
  EEPROM.write(i,0); 
}
}

 SampleRate = EEPROM.read(0);
 SampleTime = EEPROM.read(1);

}
