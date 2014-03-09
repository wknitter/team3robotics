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
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
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
    if(y = 7)
    {
      //sense shape
    }
    else //y = 8
    {
      //pick up tool
    }
  
}
