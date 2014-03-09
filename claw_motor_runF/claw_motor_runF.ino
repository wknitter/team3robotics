//this sketch opens and closes claw continuously for testing 
//and calibration purposes
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
  motor1.run(FORWARD); //close
  delay(500);
  motor1.run(RELEASE);
  delay(2000);
  val1 = analogRead(potPin1);
  Serial.print("pot 1 = ");
  Serial.println(val1);
}
