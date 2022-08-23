int sensorValue = 0;
byte LDR = A5;

void setup ( )
{
  pinMode(LDR,INPUT);
  pinMode(9,OUTPUT);
  Serial.begin (9600);
}

void loop ()
{
  sensorValue = analogRead(LDR)  ;
  Serial.println(sensorValue);
  analogWrite(9 , map (sensorValue , 0,1023 ,0,255));
}
