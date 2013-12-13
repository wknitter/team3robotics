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
  
  //bottom motor fold back as far as possible
  val4 = analogRead(potPin4);
  Serial.println(val4);
  delay(1000);
  if(val4<691)
  {
  motor4.run(FORWARD); //back into robot ---->691 is folded all the way back
  delay(500);
  }
  else
  {
  motor4.run(RELEASE);
  delay(1000);
  }
  
  //motor 3 folds down as far as possible
  val3 = analogRead(potPin3);
  Serial.println(val3);
  delay(1000);
  if(val3<000)
  {
  motor3.run(FORWARD);
  delay(500);
  }
  else
  {
  motor3.run(RELEASE);
  delay(1000);
  }
  
  //motor 2
  val2 = analogRead(potPin2);
  Serial.println(val2);
  delay(1000);
  if(val2<000)
  {
  motor2.run(FORWARD); //up fully up=610 --->flush=461
  delay(500);
  motor2.run(BACKWARD); //down fully down=300
  delay(500);
  }
  else
  {
  motor2.run(RELEASE);
  delay(1000);
  }
  
  //claw opens as far as possible
  val1 = analogRead(potPin1);
  Serial.println(val1);
  delay(1000);
  if(val1<370)
  {
  motor1.run(BACKWARD);
  delay(500);
  }
  else
  {
  motor1.run(RELEASE);
  delay(1000);
  }
}
