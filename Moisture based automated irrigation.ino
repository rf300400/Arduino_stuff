short moist = A5, pump = 8 ;//Moist is the analog pin taking readings from the moisture sensing module.
//pump is the digital pin opening and closing the relay as according to the value of moist.
void setup()
{
  pinMode(moist,INPUT);
  pinMode(pump,OUTPUT);
}
void loop()
{
  if(analogRead(moist) > 400)//Lesser the moisture, higher the readings from the moisture module.
  {
    while(analogRead(moist) > 400)
    {
      digitalWrite(pump,HIGH);
    }//Waters the plant until moisture is high enough.
    digitalWrite(pump,LOW);//Turn off the pump once watering is done.
  }
  digitalWrite(pump,LOW);//Turning off the pump in-cse the pump is on for some reason.
  delay(20000);Waiting 20 before moisture levels are checked again.
}
