//arm slave
//use same onReceive command with a compare function as handler
//to determine if arm goes into start position, tool grab mode,
//start position = fully folded mode to satisfy 1' cube dimensions
//tool grab mode = after shape is detected this the sequence that
//actually picks up the tool
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
  Wire.begin(4); //join bus with address as #4 slave
  Wire.onReceive(receiveEvent);
  //turn motors on and let coast
  motor1.setSpeed(100);
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
  delay(100);
}

void receiveEvent(int whichFunc)
{
  while(1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  
    int y = Wire.read();
    Serial.println(y);
    
    if (y == 6)
    {
      //starting position
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
          motor2.run(FORWARD); //up
          val2 = analogRead(potPin2);
        } while (val2 < 605);   //305
        motor2.run(BACKWARD);
        motor2.run(RELEASE);
        /*do
        {
          val2 = analogRead(potPin2);
          motor2.run(BACKWARD); //down
          val2 = analogRead(potPin2);
        } while (val2 > 350);   //305
        motor2.run(FORWARD);
        motor2.run(RELEASE);*/ 
 
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
    
        Serial.println("test else statement in start position loop");
        motor4.run(RELEASE);
        motor3.run(RELEASE);
        motor2.run(RELEASE);
        motor1.run(RELEASE);
    
      }
      
    }
    
    else if (y == 7) 
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
        } while (val3 < 540);   //549
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
      } while (val4 < 750);
      
    }
    
    else if (y == 8)
    {
      //scan tool for shape
      val4 = analogRead(potPin4);
      Serial.println(val4);
  
      if(val4 > 290) //340
      {
        val4 = analogRead(potPin4);
        do
        { 
          val3 = analogRead(potPin3);
          do
          {
            val3 = analogRead(potPin3);
            motor3.run(BACKWARD); //up
            val3 = analogRead(potPin3);
          } while (val3 < 855);   //815
          motor3.run(FORWARD);
          motor3.run(RELEASE);
    
          val4 = analogRead(potPin4);
          motor4.run(BACKWARD); //out
          val4 = analogRead(potPin4);
    
        } while (val4 > 290);   //338 may need to be a higher value since motor moves much faster
        motor4.run(FORWARD);    
        motor4.run(RELEASE);
  
        val2 = analogRead(potPin2);
        do
        {
          val2 = analogRead(potPin2);
          motor2.run(BACKWARD); //down
          val2 = analogRead(potPin2);
        } while (val2 > 500);   //400
        motor2.run(FORWARD);
        motor2.run(RELEASE);
        
      }
      else
      {
        motor4.run(RELEASE);
        motor3.run(RELEASE);
        motor2.run(RELEASE);
        motor1.run(RELEASE);
      }    
    }
    
    else if (y == 9)
    {
      val4 = analogRead(potPin4);
      do
      {
        //val4 = analogRead(potPin4);
        //motor4.run(BACKWARD); //out
        //val4 = analogRead(potPin4);
    
        val3 = analogRead(potPin3);
        do
        {
          val3 = analogRead(potPin3);
          motor3.run(BACKWARD); //up
          val3 = analogRead(potPin3);
        } while (val3 < 640);   //660
        motor3.run(FORWARD);
        motor3.run(RELEASE);
        
        val4 = analogRead(potPin4);
        motor4.run(BACKWARD); //out
        val4 = analogRead(potPin4);
    
      } while (val4 > 525); //525   805
      motor4.run(FORWARD);    
      motor4.run(RELEASE);
    }
    
    else
    {
      //stop all motors
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
    }
  
}
