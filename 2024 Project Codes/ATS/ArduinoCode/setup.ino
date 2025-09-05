void setup()
{

 

    lcd.begin(16,2);
    Serial.begin(9600);
    pinMode(RELAY1,OUTPUT);
    pinMode(RELAY2,OUTPUT);
    pinMode(Buzzer,OUTPUT);
    pinMode(NEPA_PIN,INPUT);
    pinMode(NEPA_INPUT,INPUT);
    pinMode(GEN_INPUT,INPUT);
   Serial.begin(9600);
  // Welcome();//Welcome Note 


}
