const int ALARM = 3;
const int SENSOR = A1;
const int SMOKE_SENSOR = A0;
const int LED = 10;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ALARM,OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(SENSOR,INPUT);
  pinMode(SMOKE_SENSOR,INPUT);
  Serial.begin(9600);

  digitalWrite(ALARM, LOW);
  digitalWrite(LED, LOW);
}

void FlashLED(int duration);

void FlashLED(int duration){

  digitalWrite(LED,HIGH);
  delay(duration);
  digitalWrite(LED,LOW);
  delay(duration);

}

// the loop function runs over and over again forever
void loop() {

  if(digitalRead(SENSOR)==1){
   // digitalWrite(ALARM,LOW);
    //digitalWrite(LED, HIGH);

  }else{
       // digitalWrite(ALARM,HIGH);
       // FlashLED(50); 
  }

  if(digitalRead(SMOKE_SENSOR)==0){
  
   digitalWrite(ALARM,HIGH);
    FlashLED(50); 

  }else if(digitalRead(SENSOR)==0){
   digitalWrite(ALARM,HIGH);
    FlashLED(50); 
  }else{
     digitalWrite(ALARM,LOW);
     digitalWrite(LED, HIGH);
  }


}
