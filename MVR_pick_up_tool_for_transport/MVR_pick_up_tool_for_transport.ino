#include <Wire.h>
#include <AFMotor.h>
//set parameters
AF_DCMotor motor1(1); 
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

//pot pin and val numbers match motor numbers
//brown wire = signal
//red wire = 5V
//green wire = ground 
//dial all the way to red wire side = 1023
//dial all the way to green wire side = 0

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
  //Wire.begin(4); //join bus with address as #4 slave
  //Wire.onReceive(receiveEvent);
  //turn motors on and let coast
  motor1.setSpeed(175); //100
  motor2.setSpeed(100);
  motor3.setSpeed(250);
  motor4.setSpeed(250);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  Serial.begin(9600);
}

void loop()
{

//pick up tool and get into transport position
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
        } while (val3 < 560);   //549
        motor3.run(FORWARD);
        motor3.run(RELEASE);
    
      } while (val4 > 380);   //305 is a bit low and 380 is a bit high but the motor moves much faster
      motor4.run(FORWARD);    //236-280 = old value where are was out too far for leverage
      motor4.run(RELEASE);
  
      val2 = analogRead(potPin2);
      do
      {
        val2 = analogRead(potPin2);
        motor2.run(FORWARD); //up
        val2 = analogRead(potPin2);
      } while (val2 < 605);   //610
      motor2.run(BACKWARD);
      motor2.run(RELEASE);
  
      val1 = analogRead(potPin1);
      do
      {
        val1 = analogRead(potPin1);
        motor1.run(FORWARD); //close claw
        val1 = analogRead(potPin1);
      } while (val1 > 19);   //19 is approx tool size
      motor1.run(BACKWARD);
      motor1.run(RELEASE);
  
      val4 = analogRead(potPin4);
      do
      {
        val4 = analogRead(potPin4);
        motor4.run(FORWARD); //pick up tool and bring back to carry
        val4 = analogRead(potPin4);
      } while (val4 < 300); //700
      motor4.run(BACKWARD);
      motor4.run(RELEASE);
      
}
