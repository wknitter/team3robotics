#include <Wire.h>
//set parameters
int pingRPin = 22;
int pingFPin = 23;
int pingLPin = 24;
int pingTPin = 25;

int tooClose = 10; //4 inches = 10.16cm
//duration = cm*58 = 17.78*58 = 1031.24 (17.78cm = 7in)
//14-17 = wave 76-77 = opening
int opening = 25; //7.5 inches = 19.05 cm = 1104.9
int fire = 205; //oil rig fire would be about 80 inches away = 203.2 cm
int durationR, durationF, durationL, forwardCm, leftCm, rightCm;
int durationT, topCm;
int distanceR, distanceF, distanceL, distanceT;
int x;
int waveCount;
int circleRig, squareRig, triangleRig;

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
  
//drive forward and check each oil rig first
x = 1; 
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(1000); //this is the time it takes for robot to drive to rig

x = 0; //halt in front of first rig
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();

distanceT = pingTop(); //send ping
Serial.print(distanceT);
if(distanceT>fire) 
{
  //drive to next rig
  x = 1;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(1000); //this is the time it takes for robot to drive to rig
  
  x = 0; //halt in front of second rig
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  
  distanceT = pingTop(); //send ping
  Serial.print(distanceT);
  if(distanceT>fire)
  {
    //drive to next rig
    x = 1;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000); //this is the time it takes for robot to drive to rig
    
    x = 0; //halt in front of third rig
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    
    distanceT = pingTop(); //send ping
    Serial.print(distanceT);
    //if you're at this point it should be known by elimination that this rig is on fire
  }
  else
  {
    //save this rig as being on fire and drive on toward tools
  }
}
else
{
  //save this rig as being on fire and drive on toward tools
}

//tool detection code here

//reverse back to starting position
x = 2;
Serial.print("x transmitted = ");
Serial.println(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(1000); //this is the time that is takes for robot to reverse back to starting position

//this section is for wave detection
distanceL= pingLeft();
Serial.print(distanceL);
distanceR = pingRight();
Serial.print(distanceR);
distanceF = pingForward();
Serial.println(distanceF);
delay(100);
if(distanceL<tooClose && distanceR<tooClose && distanceF<tooClose)
{
  x = 0; //halt, the robot is too close to anything to move safely
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
}
if (distanceL<opening && distanceR>tooClose && distanceF>tooClose)
{
  x = 1; //move forward 16"
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(1000);//time it takes robot to drive 16" forward to next wave
}
if(distanceL>opening && distanceR>tooClose && distanceF>tooClose)
{
  x = 3; //turn 90 degrees left
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
}
if(distanceL>tooClose && distanceR>tooClose && distanceF>tooClose)
{
  x =
}
//delay(1000);

//send drive code out*************************************************************
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
