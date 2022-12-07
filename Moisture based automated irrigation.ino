short moist = A5, pump = 8 ;
void setup()
{
  pinMode(moist,INPUT);
  pinMode(pump,OUTPUT);
}
void loop()
{
  if(analogRead(moist) > 400)
  {
    while(analogRead(moist) > 400)
    {
      digitalWrite(pump,HIGH);
      delay(5000);
      digitalWrite(pump,LOW);
    }
    digitalWrite(pump,LOW);
  }
  digitalWrite(pump,LOW);
  delay(20000);
}