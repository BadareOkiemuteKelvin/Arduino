void handle_OnConnect() {
  pumpStatus = LOW;

  toggleBuzzer();
  server.send(200, "text/html", SendHTML(moistureLevel,pumpStatus)); 
}


void toggleBuzzer(){

       digitalWrite(buzzerPin, HIGH);
       delay(500);
       digitalWrite(buzzerPin, LOW);
       delay(500);

}

void printf(char x,char y,String Text);// function declaration
void printf(char x,char y,int Number);// function declaration
void printf(char x,char y,double F);// function declaration
void printf(char x,char y,long int Number);// function declaration

void display_refresher(void);
  char display_refresh = 0;
void display_refresher(void)
{
  display_refresh +=1;
  if(display_refresh>40)
  {
    lcd.begin(16,2);
    display_refresh =0;
  }
  
  
}

void cls(void)
{
  lcd.clear();
}
void printf(char x, char y,String Text)
{
  lcd.setCursor(y,x);
  lcd.print(Text);
}

void printf(char x, char y,int Number)
{
  lcd.setCursor(y,x);
  lcd.print(Number);
}

void printf(char x, char y,long int Number)
{
  lcd.setCursor(y,x);
  lcd.print(Number);
}

void printf(char x, char y,double F)
{
  lcd.setCursor(y,x);
  lcd.print(F);
}



