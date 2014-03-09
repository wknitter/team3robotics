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
  motor3.setSpeed(250);
  motor4.setSpeed(250);
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE); 
 
}

void loop()
{
  val4 = analogRead(potPin4);
  val3 = analogRead(potPin3);
  val2 = analogRead(potPin2);
  val1 = analogRead(potPin1);
  
  if(val4 < 750 || val3 > 380 || val2 > 350)
  {
    
    Serial.println("test motor 4");
    val4 = analogRead(potPin4);
    do
    {
      val4 = analogRead(potPin4);
      motor4.run(FORWARD); //back
      val4 = analogRead(potPin4);
    } while (val4 < 750);   //814
    motor4.run(BACKWARD);
    motor4.run(RELEASE);
  
    Serial.println("test motor 3");
    val3 = analogRead(potPin3);
    do
    {
      val3 = analogRead(potPin3);
      motor3.run(FORWARD); //down
      val3 = analogRead(potPin3);
    } while (val3 > 380);   //358
    motor3.run(BACKWARD);
    motor3.run(RELEASE);
    
    Serial.println("test motor 2");
    val2 = analogRead(potPin2);
    do
    {
      val2 = analogRead(potPin2);
      motor2.run(BACKWARD); //down
      val2 = analogRead(potPin2);
    } while (val2 > 350);   //305
    motor2.run(FORWARD);
    motor2.run(RELEASE); 
 
    val1 = analogRead(potPin1);
    do
    {
      val1 = analogRead(potPin1);
      motor1.run(BACKWARD); //open claw
      val1 = analogRead(potPin1);
    } while (val1 < 300); //371 to 380
    motor1.run(FORWARD);
    motor1.run(RELEASE);
  
  }
  else
  {
    
    Serial.println("test else statement");
    motor4.run(RELEASE);
    motor3.run(RELEASE);
    motor2.run(RELEASE);
    motor1.run(RELEASE);
    
  }
   
}
