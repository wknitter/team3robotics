/////////////////////////////////////////////////////
//This sketch is testing the sequence to pick up 
//the tool and carry it for transport.
/////////////////////////////////////////////////////
#include <AFMotor.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int potPin1 = 0;
int potPin2 = 1;
int potPin3 = 2;
int potPin4 = 3;

int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;

void setup()
{
 Serial.begin(9600);
 motor1.setSpeed(100);
 motor2.setSpeed(100);
 motor3.setSpeed(200);
 motor4.setSpeed(150);
 motor1.run(RELEASE);
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE); 
}

void loop()
{
  uint8_t i;
  
  //bottom motor extends out first
  val4 = analogRead(potPin4);
  do
  {
    motor4.run(BACKWARD);
  }while(val4 < 000);
  motor4.run(RELEASE);
  delay(500);
  
  //next motor up folds up slightly
  val3 = analogRead(potPin3);
  do
  {
    motor3.run(BACKWARD);
  }while(val3 < 000);
  motor3.run(RELEASE);
  delay(500);
  
  //next motor up folds up slightly
  val2 = analogRead(potPin2);
  do
  {
    motor2.run(FORWARD);
  }while(val2 < 000);
  motor2.run(RELEASE);
  delay(500);
  
  //claw closes around tool
  val1 = analogRead(potPin1);
  do
  {
    motor1.run(FORWARD);
  }while(val1 < 000);
  motor1.run(RELEASE);
  delay(500);
  
  //bottom motor folds back in to a point
  val4 = analogRead(potPin4);
  do
  {
    motor4.run(FORWARD);
  }while(val4 < 000);
  motor4.run(RELEASE);
  delay(500);
  
}
