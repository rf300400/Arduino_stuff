int i , sdly = 100 , prev , curr;
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
  sequence();
  delay(sdly);
  quadBlink();
  delay(1000);
}
void sequence()
{
  prev = 13 , curr = 12;
  digitalWrite(prev,HIGH);
  delay(sdly);
  while(curr >= 6)
  {
    digitalWrite(prev,LOW);
    digitalWrite(curr,HIGH);
    curr--;
    prev--;
    delay(sdly);
  }
  curr += 2 ;
  digitalWrite(prev,HIGH);
  delay(sdly);
  while(curr < 14)
  {
    digitalWrite(prev,LOW);
    digitalWrite(curr,HIGH);
    curr++;
    prev++;
    delay(sdly);
  }
  digitalWrite(--curr,LOW);
}
void quadBlink()
{
  i = 13 ;
  while(i > 5)
  {
    digitalWrite(i,HIGH);
    i--;
  }
  delay(sdly);
  i = 13;
  while(i > 5)
  {
    digitalWrite(i,LOW);
    i--;
  }
  delay(sdly);
  i = 13;
  while(i > 5)
  {
    digitalWrite(i,HIGH);
    i--;
  }
  delay(sdly);
  i = 13;
  while(i > 5)
  {
    digitalWrite(i,LOW);
    i--;
  }
  delay(sdly);
}
