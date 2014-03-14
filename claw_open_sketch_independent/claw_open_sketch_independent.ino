#include <AFMotor.h>

AF_DCMotor motor1(1);
int potPin1 = 0;
int val1 = 0;

void setup()
{
  Serial.begin(9600);
  motor1.setSpeed(100);
  motor1.run(RELEASE);
}

void loop()
{
  val1 = analogRead(potPin1);
  Serial.println(val1);
  if(val1<600)
  {
    motor1.run(BACKWARD);
  }
  else
  {
    motor1.run(RELEASE);
  }
}
