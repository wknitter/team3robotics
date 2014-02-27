/////////////////////////////////////////////////////
//This sketch is to test the sequence to fold the 
//arm back into starting position for one foot cube
//restriction.
/////////////////////////////////////////////////////
/* values from testing (see photo after barclay payment confirmation)
test 1
Claw pot = 1013

Motor 2 pot = 515

Motor 3 pot = 548

Base motor pot = 779

test 2
Claw pot = 1014

Motor 2 pot = 501

Motor 3 pot = 352

Base motor pot = 780

test 3 (after pulling pun away from arm)
Claw pot = 1015

Motor 2 pot = 504

Motor 3 pot = 349

Base motor pot = 786
*/
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
  delay(2000);
  
  //bottom motor fold back as far as possible
  val4 = analogRead(potPin4);
  do
  {
    motor4.run(FORWARD);
  }while(val4 < 733);
  motor4.run(RELEASE);
  Serial.println(val4);
  delay(2000);
  
  //next motor up folds down as far as possible
  val3 = analogRead(potPin3);
  do
  {
    motor3.run(FORWARD);
  }while(val3 > 375);
  motor3.run(RELEASE);
  Serial.println(val3);
  delay(2000);
  
  //next motor up folds down as far as possible
  val2 = analogRead(potPin2);
  do
  {
    motor2.run(BACKWARD);
  }while(val2 < 600);
  motor2.run(RELEASE);
  Serial.println(val2);
  delay(2000);
  
  //claw opens as far as possible
  val1 = analogRead(potPin1);
  do
  {
    motor1.run(BACKWARD);
  }while(val1 < 1010);
  motor1.run(RELEASE);
  Serial.println(val1);
  delay(2000);
  
  
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
