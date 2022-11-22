byte i = 0;
void setup()
{
  randomSeed(analogRead(0));
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
}
void display(short n)
{
  while(n > 0)
  {
    digitalWrite(14-n,HIGH);
    n--;
  }
}
void cleary()
{
  i = 13;
  while(i > 7)
  {
    digitalWrite(i,LOW);
    i--;
  }
}
void loop()
{
  display((short)random(1,7));
  delay(2000);
  cleary();
  delay(1000);
}
