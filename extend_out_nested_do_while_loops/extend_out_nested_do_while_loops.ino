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
  motor3.setSpeed(180);
  motor4.setSpeed(150);
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE); 
 
}

void loop()
{
  val4 = analogRead(potPin4);
  if(val4 > 280)
  {
  val4 = analogRead(potPin4);
  do
  {
    val4 = analogRead(potPin4);
    motor4.run(BACKWARD); //out
    val4 = analogRead(potPin4);
    
    val3 = analogRead(potPin3);
    do
    {
      val3 = analogRead(potPin3);
      motor3.run(BACKWARD); //up
      val3 = analogRead(potPin3);
    } while (val3 < 770);   //814
    motor3.run(FORWARD);
    motor3.run(RELEASE);
    
  } while (val4 > 280);   //236
  motor4.run(FORWARD);
  motor4.run(RELEASE);
  
  val2 = analogRead(potPin2);
  do
  {
    val2 = analogRead(potPin2);
    motor2.run(FORWARD); //up
    val2 = analogRead(potPin2);
  } while (val2 < 510);   //573
  motor2.run(BACKWARD);
  motor2.run(RELEASE);
  
  //motor4.run(RELEASE);
  
  /*val1 = analogRead(potPin1);
  do
  {
    val1 = analogRead(potPin1);
    motor1.run(FORWARD); //close claw
    val1 = analogRead(potPin1);
  } while (val1 > 500);   //500 is approx tool size
  motor1.run(BACKWARD);
  motor1.run(RELEASE);*/
  //motor4.run(RELEASE);
  }
  else
  {
    motor4.run(RELEASE);
    motor3.run(RELEASE);
    motor2.run(RELEASE);
    motor1.run(RELEASE);
  }
  
}
    
