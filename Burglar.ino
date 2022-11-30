short sinp = 8 , l = 10 , tri = 2 , ech = 3;//sinp is used to tell us whether the switch is closed or not.
//l is the LED and buzzer variable.
//tri and ech are the trigger and echo variables for HC-SR04
float lck , curr ;//Lck is the locked position. Distance variation of upto 5 cm is allowed before alarm sets off.
//curr is used to measure the current position of the object.
bool sfe = false ;//If switch is pressed while alarm is activated, the alarm is disabled and the item can be removed safely.
void setup()
{
  pinMode(sinp,INPUT);
  pinMode(l,OUTPUT);
  pinMode(tri,OUTPUT);
  pinMode(ech,INPUT);
}
void loop()
{
  sfe = false;
  delay(50);//avoiding switchbounce from the alarm being reset.
  while(digitalRead(sinp) == LOW){}//Security system is not started until button is pressed.
  lck = getDist();
  delay(50);
  curr = getDist();
  delay(50);
  while(curr < (lck + 5.0) && curr > (lck - 5.0))
  {
    if(digitalRead(sinp) == HIGH)
    {
      sfe = true; break;//Alarm disabled.
    }
    curr = getDist();
    delay(50);
  }
  if(sfe != true)//Alarm activated if object is moved and the alarm hasn't been disabled.
  {
    delay(50);//delay to avoid switch bounce.
    while(digitalRead(sinp) == LOW)
    {
      digitalWrite(l,HIGH);//Alarm stays on until the switch is pressed.
    }
    digitalWrite(l,LOW);//Alarm is turned off.
    delay(1000);
  }
}
float getDist()
{
  long dur ;
  float dist ;
  digitalWrite(tri,LOW);
  delayMicroseconds(2);
  digitalWrite(tri,HIGH);
  delayMicroseconds(10);
  digitalWrite(tri,LOW);
  pinMode(ech, INPUT);
  dur = pulseIn(ech,HIGH);
  dist = (((float)dur)/2.0)*0.0343;
  Serial.println(dist);
  return dist;
}
