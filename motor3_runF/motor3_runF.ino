//this sketch runs motor 3 continuously for testing 
//and calibration purposes
#include <AFMotor.h>

AF_DCMotor motor3(3);

void setup()
{
  Serial.begin(9600);
  motor3.setSpeed(100);
  motor3.run(RELEASE);
}

void loop()
{
  motor3.run(FORWARD); //down
  delay(500);
  motor3.run(RELEASE);
  delay(2000);
}
