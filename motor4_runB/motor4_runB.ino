//this sketch runs motor 4 continuously for testing 
//and calibration purposes
#include <AFMotor.h>

AF_DCMotor motor4(4);

void setup()
{
  Serial.begin(9600);
  motor4.setSpeed(250); //100 250
  motor4.run(RELEASE);
}

void loop()
{
  motor4.run(BACKWARD); //forward (away) from robot
  delay(500);
  motor4.run(RELEASE);
  delay(2000);
}
