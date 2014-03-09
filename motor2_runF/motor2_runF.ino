//this sketch runs motor 2 continuously for testing 
//and calibration purposes
#include <AFMotor.h>

AF_DCMotor motor2(2);

void setup()
{
  Serial.begin(9600);
  motor2.setSpeed(100);
  motor2.run(RELEASE);
}

void loop()
{
  motor2.run(FORWARD); //up
  delay(500);
  motor2.run(RELEASE);
  delay(2000);
}
