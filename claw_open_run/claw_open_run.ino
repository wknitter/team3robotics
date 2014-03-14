//this sketch runs motor 2 continuously for testing 
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
  //val1 = analogRead(potPin1);
  do
  {
    val1 = analogRead(potPin1);
    Serial.println(val1);
    delay(1000);
    motor1.run(BACKWARD);
  }while(val1<400);
  
  motor1.run(RELEASE);
  //delay(2000);
}
