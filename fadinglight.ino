int val;
void setup()
{
  pinMode(9,OUTPUT);
}
void loop()
{
  val = 255;
  while(val > -1)
  {
    analogWrite(9,val);
    delay(50);
    val-=5;
  }
  val = 0;
  while(val < 256)
  {
    analogWrite(9,val);
    delay(50);
    val+=5;
  }
}
