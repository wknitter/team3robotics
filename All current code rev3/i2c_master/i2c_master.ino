//master writer
//master does the sensing, sends driver slave a signal to either 
//go forward, backward, right turn, left turn, or turn around 
//4 unique signals
//master also sends arm slave signal to sense the shape, then
//once the shape is verified back to the master, it lights up
//corresponding LED (for MVR) 
//once shape is verified, then master tells arm slave to pick the
//tool up
#include <Wire.h>
//set parameters
int pingRPin = 22;
int pingFPin = 23;
int pingLPin = 24;
int pingTPin = 25;

int fire = 30;

int tooClose = 30; //duration = cm*58 = 17.78*58 = 1031.24 (17.78cm = 7in)
//14-17 = wave 76-77 = opening
int durationR, durationF, durationL, forwardCm, leftCm, rightCm;
int durationT, topCm;
int distanceR, distanceF, distanceL, distanceT;
int x;

//foward = 1
//reverse = 2
//leftTurn = 3
//rightTurn = 4
//turnAround = 5
//halt = 0

void setup()
{
   Wire.begin(); //join bus as master
   Serial.begin(9600);
}

void loop()
{
//this code is for full navigation later
/*
//loop through ping sensors
distanceF = pingForward();
Serial.print(distanceF);
delay(1000);
distanceR = pingRight();
Serial.print(distanceR);
delay(1000);
distanceL = pingLeft();
Serial.println(distanceL);
delay(1000);
if(distanceF<tooClose && distanceR<tooClose && distanceL<tooClose)
{
  x = 2; //reverse
  Serial.print("x = ");
  Serial.println(x);
}
else if(distanceF>tooClose && distanceR<tooClose && distanceL<tooClose) 
{
  x = 1; //forward
  Serial.print("x = ");
  Serial.println(x);
}
else if(distanceF<tooClose && distanceR<tooClose && distanceL>tooClose)
{
  x = 3; //left turn
  Serial.print("x = ");
  Serial.println(x);
}
else if(distanceF<tooClose && distanceR>tooClose && distanceL<tooClose)
{
  x = 4; //right turn
  Serial.print("x = ");
  Serial.println(x);
}
else
{
  x = 0; //halt
  Serial.print("x = ");
  Serial.println(x);
}
*/

//this section is for MVR wave detection

//this section is for MVR wave detection
distanceL= pingLeft();
Serial.print(distanceL);
distanceR = pingRight();
Serial.print(distanceR);
distanceF = pingForward();
Serial.println(distanceF);
delay(100); //this is the delay for the robot to move 16" forward
if(distanceL<tooClose && distanceR<tooClose && distanceF<tooClose)
{
  x = 0; //halt, the robot is too close to anything to move safely
}
if (distanceL<tooClose)
{
  x = 1; //move forward 16"
}
else
{
  x = 0; //halt to indicate opening
}


//this section is for MVR oil rig detection
/*
distanceT= pingTop();
Serial.println(distanceL);
delay(1000);
if (distanceT>fire)
{
  x = 1; //move forward to next rig
}
else
{
  x = 0; //halt to indicate fire
}*/

//send drive code out
Serial.print("x transmitted = ");
Serial.println(x);
//x = 4;
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
//Serial.println("fuck!!!");

//send arm code out
Serial.print("y transmitted = ");
Serial.println(y);
Wire.beginTransmission(4);
Wire.write("y is ");
Wire.write(y);
Wire.endTransmission();
}

int pingForward()
{
  // Send out ping signal from front sensor
  pinMode(pingFPin, OUTPUT);
  digitalWrite(pingFPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingFPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingFPin, LOW);
  
  //Get duration it takes to receive echo
  pinMode(pingFPin, INPUT);
  durationF = pulseIn(pingFPin, HIGH);
  forwardCm = durationF/58;
  //distanceFwd = int(durationF/29);
  return forwardCm;
}

int pingRight()
{
  // Send out ping signal from front sensor
  pinMode(pingRPin, OUTPUT);
  digitalWrite(pingRPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingRPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingRPin, LOW);
  
  //Get duration it takes to receive echo
  pinMode(pingRPin, INPUT);
  durationR = pulseIn(pingRPin, HIGH);
  rightCm = durationR/58;
  return rightCm;
}

int pingLeft()
{
  // Send out ping signal from front sensor
  pinMode(pingLPin, OUTPUT);
  digitalWrite(pingLPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingLPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingLPin, LOW);
  
  //Get duration it takes to receive echo
  pinMode(pingLPin, INPUT);
  durationL = pulseIn(pingLPin, HIGH);
  leftCm = durationL/58;
  return leftCm;
}

int pingTop()
{
  // Send out ping signal from front sensor
  pinMode(pingTPin, OUTPUT);
  digitalWrite(pingTPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingTPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingTPin, LOW);
  
  //Get duration it takes to receive echo
  pinMode(pingTPin, INPUT);
  durationT = pulseIn(pingTPin, HIGH);
  topCm = durationT/58;
  return topCm;
}
