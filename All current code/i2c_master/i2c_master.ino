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

int tooClose = 10;
int durationR, durationF, durationL, forwardCm, leftCm, rightCm;
int distanceR, distanceF, distanceL;
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
}

void loop()
{
//loop through ping sensors
distanceF = pingForward();
distanceR = pingRight();
distanceL = pingLeft();
if(distanceF<tooClose && distanceR<tooClose && distanceL<tooClose)
{
  x = 2; //reverse
}
else if(distanceF>tooClose && distanceR<tooClose && distanceL<tooClose) 
{
  x = 1; //forward
}
else if(distanceF<tooClose && distanceR<tooClose && distanceL>tooClose)
{
  x = 3; //left turn
}
else if(distanceF<tooClose && distanceR>tooClose && distanceL<tooClose)
{
  x = 4; //right turn
}
else
{
  x = 0; //halt
}

//send drive code out
Wire.beginTransmission(2);
Wire.write(x);
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
