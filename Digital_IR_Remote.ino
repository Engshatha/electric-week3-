#include <IRremote.h>
//Define Pins
int BlueLed = 10;
int GreenLed = 9;
int OrangeLed  = 8;

int RECV_PIN = 3;

//IR Library
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{
  //Set Led Pins
  pinMode(BlueLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(OrangeLed   , OUTPUT);
  
  
  //Enable serial usage and IR signal in
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); 
  Serial.println("Enabled IRin");
}

void loop()
{
  if (irrecv.decode(&results)) {//irrecv.decode(&results) returns true if anything is recieved, and stores info in varible results
    unsigned int value = results.value; //Get the value of "results" as an unsigned int, so we can use switch case
    Serial.println(value);
    switch (value) {
      case 2295: 
      digitalWrite(BlueLed , HIGH);
      delay(500);
      digitalWrite(BlueLed , LOW);
      break;   

      case 34935:
      digitalWrite(GreenLed  , HIGH);
      delay(500);
      digitalWrite(GreenLed  , LOW);
      break;
      
      case 18615:
      digitalWrite(OrangeLed , HIGH);
      delay(500);
      digitalWrite(OrangeLed   , LOW);
      break;
      

      
      case 10455:
      digitalWrite(BlueLed , HIGH);
      delay(500);
      digitalWrite(BlueLed , LOW);
      
      digitalWrite(GreenLed , HIGH);
      delay(500);
      digitalWrite(GreenLed , LOW);
      
      digitalWrite(OrangeLed , HIGH);
      delay(500);
      digitalWrite(OrangeLed , LOW);  
      break;
      
      case 43095:
      digitalWrite(GreenLed , HIGH);
      delay(500);
      digitalWrite(GreenLed , LOW);
      
      digitalWrite(BlueLed , HIGH);
      digitalWrite(OrangeLed , HIGH);
      delay(500);
      digitalWrite(OrangeLed , LOW);
      digitalWrite(BlueLed , LOW);    
      break;
      
      case 26775:
      digitalWrite(OrangeLed   , HIGH);
      delay(500);    
      digitalWrite(GreenLed , HIGH);
      delay(500);
      digitalWrite(BlueLed , HIGH);
      delay(1000);
      digitalWrite(GreenLed , LOW);
      digitalWrite(BlueLed , LOW); 
      digitalWrite(OrangeLed   , LOW);
      break;
    }
    irrecv.resume(); // Receive the next value
  }
}
