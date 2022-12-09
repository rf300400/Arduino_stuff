#include <Servo.h> //Importing servo library
#include <AFMotor.h> //Importing AdaFruit motor library
AF_DCMotor ml(4);
AF_DCMotor mr(3);//Assigning driver ports 3 and 4 fo right and left leg motors
Servo ser;//Creating servo object
short agl , x = A4, y = A5 ; //agl is the angle of the servo, x and y are the analog inputs from the analog joystick.
void setup() 
{
	ser.attach(10);//Assigning pin 10 for the servo motor
  ser.write(90);//Starting angle 90 degrees, ie looking forward.
  ml.setSpeed(0);
  mr.setSpeed(0);//Setting DC motor speeds to 0 at the start.
}
void loop() 
{
  while(analogRead(x) > 900)//Turning towards 180 degrees
  {
    agl++;
    if(agl >= 180)agl = 180;
    ser.write(agl);
    delay(5);
  }
  while(analogRead(x) < 100)//Turning towards 0 degrees
  {
    agl--;
    if(agl <= 0)agl = 0;
    ser.write(agl);
    delay(5);
  }
  while(analogRead(y) < 100)//Accelerating backward
  {
    ml.run(BACKWARD);
    mr.run(BACKWARD);
    ml.setSpeed(200);
    mr.setSpeed(200);
  }
  while(analogRead(y) > 900)//Accelerating forward
  {
    ml.run(FORWARD);
    mr.run(FORWARD);
    ml.setSpeed(200);
    mr.setSpeed(200);
  }
  ml.setSpeed(0);
  mr.setSpeed(0);
}
