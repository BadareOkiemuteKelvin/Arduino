#include <SoftwareSerial.h>

// Create serial connection to SIM800A
SoftwareSerial SIM800(3, 2); // RX, TX pins for Arduino

String responce = "";

String Longitude = "";

String Latitude = ""; 

String SIM800_send(String incoming) //Function to communicate with SIM800 module 

{

    SIM800.println(incoming); delay(100); //Print what is being sent to GSM module 

    String result = "";

    while (SIM800.available()) //Wait for result 

    {

    char letter = SIM800.read();

    result = result + String(letter); //combine char to string to get result 

    }

    

return result; //return the result 

}

void setup() {
  Serial.begin(9600);         // Initialize Serial Monitor
  SIM800.begin(9600);         // Initialize SIM800 module


  delay(1000); //wait for serial COM to get ready 

  responce = SIM800_send("ATE1"); //Enable Echo if not enabled by default 

  Serial.print ("Responce:"); Serial.println(responce); 

  delay(1000);

  responce = SIM800_send("AT+CGATT=1"); //Set the SIM800 in GPRS mode 

  Serial.print ("Responce:"); Serial.println(responce); 

  delay(1000);

  responce = SIM800_send("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\" "); //Activate Bearer profile 

  Serial.print ("Responce:"); Serial.println(responce); 

  delay(1000);

  responce = SIM800_send("AT+SAPBR=3,1,\"APN\",\"RCMNET\" "); //Set VPN options => 'RCMNET' 'www'

  Serial.print ("Responce:"); Serial.println(responce); 

  delay(2000);

   

  responce = SIM800_send("AT+SAPBR=1,1"); //Open bearer Profile

  Serial.print ("Responce:"); Serial.println(responce); //Open bearer Profile 

  delay(2000);

  responce = SIM800_send("AT+SAPBR=2,1"); //Get the IP address of the bearer profile 

  Serial.print ("Responce:"); Serial.println(responce); 

  delay(1000);
}

void loop() {
  // Read and display location data from SIM800
  while (SIM800.available()) {
    String locationData = SIM800.readString();
    Serial.println("Location Data: " + locationData);
  }
  delay(10000);  // Retrieve location every 10 seconds
}
