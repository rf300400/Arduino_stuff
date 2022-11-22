int val;
void setup()
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
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
