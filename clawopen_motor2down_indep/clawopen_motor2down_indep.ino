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
  Serial.println("beginning");
  /*
  Serial.println("loop 1");
  //iterations of i are the number of seconds it polls the pots for
  for(i=0;i<20;i++) 
  {
    val1 = analogRead(potPin1);
    Serial.print("pot 1 = ");
    Serial.println(val1);
    if(val1<350) //if(val1<600)    670
    {
      motor1.run(BACKWARD);
    }  
    else
    {
      motor1.run(FORWARD);
      //delay(200);          //run motor in opposite direction for a split second to make clean stop
      motor1.run(RELEASE);
    }
    //delay(1000);
  }
  
  //Serial.println("delay 1");
  //motor1.run(RELEASE);
  //delay(7000);
  */
  Serial.println("loop 2");
  for(j=0;j<20;j++) 
  {
    val2 = analogRead(potPin2);
    Serial.print("pot 2 = ");
    Serial.println(val2);
    if(val2>310) 
    {
      motor2.run(BACKWARD);
    }  
    else
    {
      motor2.run(FORWARD);
      //delay(200);
      motor2.run(RELEASE);
    }
    //delay(1000);
  }
  
  //Serial.println("delay 2");
  //motor2.run(RELEASE);
  //delay(7000);
  
  Serial.println("loop 3");
  for(k=0;k<20;k++) 
  {
    val3 = analogRead(potPin3);
    Serial.print("pot 3 = ");
    Serial.println(val3);
    if(val3>380) 
    {
      motor3.run(FORWARD);
    }  
    else
    {
      motor3.run(BACKWARD);
      //delay(200);
      motor3.run(RELEASE);
    }
    //delay(1000);
  }
  
  //Serial.println("delay 3");
  //motor3.run(RELEASE);
  //delay(7000);
  
  Serial.println("loop 4");
  for(l=0;l<20;l++) 
  {
    val4 = analogRead(potPin4);
    Serial.print("pot 4 = ");
    Serial.println(val4);
    if(val4<800) //814-817
    {
      motor4.run(FORWARD);
    }  
    else
    {
      motor4.run(BACKWARD);
      //delay(200);
      motor4.run(RELEASE);
    }
    //delay(1000);
  }
  
  //Serial.println("delay 4");
  //motor4.run(RELEASE);
  //delay(7000);
  
}
