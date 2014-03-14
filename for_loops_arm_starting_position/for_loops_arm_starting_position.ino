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
int i,j,k,l;

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
  //iterations of i are the number of seconds it polls the pots for
  for(i=0;i<1;i++) //open claw
  {
    val1 = analogRead(potPin1);
    Serial.println(val1);
    if(val1<600) //420
    {
      motor1.run(BACKWARD);
    }  
    else
    {
      motor1.run(RELEASE);
    }
    delay(1000);
  }
  
  //motor 2 folds down
  for(j=0;j<1;j++)
  {
    val2 = analogRead(potPin2);
    Serial.print(val2);
    if(val2<0)
    {
      motor2.run(BACKWARD);
    }
    else
    {
      motor2.run(RELEASE);
    }
    delay(1000);
  }
  
  //motor 3 folds down
  for(k=0;k<1;k++)
  {
    val3 = analogRead(potPin3);
    Serial.print(val3);
    if(val3<0)
    {
      motor3.run(FORWARD);
    }
    else
    {
      motor3.run(RELEASE);
    }
    delay(1000);
  }
  
  //motor 4 folds back as far as possible
  for(l=0;l<1;l++)
  {
    val4 = analogRead(potPin4);
    Serial.print(val4);
    if(val4<0)
    {
      motor4.run(FORWARD);
    }
    else
    {
      motor4.run(RELEASE);
    }
    delay(1000);
  }
}
