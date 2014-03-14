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
  motor3.setSpeed(180);
  motor4.setSpeed(150);
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE); 
 
}

void loop()
{
  Serial.println("beginning");
  
  //claw should close last
  //iterations of i,j,k, and l are the number of seconds it polls the pots for
  
  /*Serial.println("loop 2");
  for(j=0;j<100;j++) 
  {
    val2 = analogRead(potPin2);
    Serial.print("pot 2 = ");
    Serial.println(val2);
    if(val2<500) //573
    {
      motor2.run(FORWARD);
    }  
    else
    {
      motor2.run(BACKWARD);
      //delay(10);
      motor2.run(RELEASE);
    }
    //delay(1000);
  }*/
  
  //Serial.println("delay 2");
  //motor2.run(RELEASE);
  //delay(7000);
  
  /*Serial.println("loop 3");
  for(k=0;k<100;k++) 
  {
    val3 = analogRead(potPin3);
    Serial.print("pot 3 = ");
    Serial.println(val3);
    if(val3<800) //814
    {
      motor3.run(BACKWARD); //up
    }  
    else
    {
      motor3.run(FORWARD);
      //delay(200);
      motor3.run(RELEASE);
    }
    //delay(1000);
  }*/
  
  //Serial.println("delay 3");
  //motor3.run(RELEASE);
  //delay(7000);
  
  Serial.println("loop 4");
  for(l=0;l<10;l++) 
  {
    val4 = analogRead(potPin4);
    Serial.print("pot 4 = ");
    Serial.println(val4);
    if(val4>280) //236
    {
      motor4.run(BACKWARD);
    }  
    else
    {
      motor4.run(FORWARD);
      //delay(200);
      motor4.run(RELEASE);
    }
    //delay(1000);
  }
  
  //Serial.println("delay 4");
  //motor4.run(RELEASE);
  //delay(7000);
  
  Serial.println("loop 3");
  for(k=0;k<10;k++) 
  {
    val3 = analogRead(potPin3);
    Serial.print("pot 3 = ");
    Serial.println(val3);
    if(val3<805) //814
    {
      motor3.run(BACKWARD); //up
    }  
    else
    {
      motor3.run(FORWARD);
      //delay(200);
      motor3.run(RELEASE);
    }
    //delay(1000);
  }
  
  Serial.println("loop 2");
  for(j=0;j<10;j++) 
  {
    val2 = analogRead(potPin2);
    Serial.print("pot 2 = ");
    Serial.println(val2);
    if(val2<510) //573
    {
      motor2.run(FORWARD);
    }  
    else
    {
      motor2.run(BACKWARD);
      //delay(10);
      motor2.run(RELEASE);
    }
    //delay(1000);
  }
  
  Serial.println("loop 1");
  for(i=0;i<10;i++) //close claw
  {
    val1 = analogRead(potPin1);
    Serial.print("pot 1 = ");
    Serial.println(val1);
    if(val1>550) //420, 500 is around tool size, 470 is fully closed
    {
      motor1.run(FORWARD);
    }  
    else
    {
      motor1.run(BACKWARD);
      //delay(10);          //run motor in opposite direction for a split second to make clean stop
      motor1.run(RELEASE);
    }
    //delay(1000);
  }
  
  //Serial.println("delay 1");
  //motor1.run(RELEASE);
  //delay(7000);                
  
}
