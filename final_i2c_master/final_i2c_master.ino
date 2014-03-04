////////////////////////////////////////////////////////////////////////////
//
//Date: March 3, 2014
//
//Engineer: Whitney B Larsen
//
//Description: This sketch is the master code for the Adriuno Mega 2560
//that controls all of the sensors for the robot then sends commands to the
//two slave Arduino Unos accordingly
//
////////////////////////////////////////////////////////////////////////////
#include <Wire.h>

//set parameters
int pingRPin = 22;
int pingFPin = 23;
int pingLPin = 24;
int pingTPin = 25;

int fire = 30; //still need to measure this

int tooClose = 30; //duration = cm*58 = 17.78*58 = 1031.24 (17.78cm = 7in)
//14-17 = wave 76-77 = opening
int wave;
int atTool;
int opening;
int durationR, durationF, durationL, forwardCm, leftCm, rightCm;
int durationT, topCm;
int distanceR, distanceF, distanceL, distanceT;
int x;
int waveDist; // = 16"
int oilRigDist; // =
int oilRig1; //square
int oilRig2; //triangle 
int oilRig3; //circle

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
 //start by waiting 5 seconds after switch is turned on
 delay(5000);
 
 //starting position: drive to check oil rigs for fire 
 //drive forward from starting position
 x = 1;
 Serial.print("x transmitted = ");
 Serial.print(x);
 Wire.beginTransmission(2);
 Wire.write("x is ");
 Wire.write(x);
 Wire.endTransmission();
 delay(1000); //this should be the time it takes to drive to oil rig #1
 x = 0;       //stop in front of oil rig
 Serial.print("x transmitted = ");
 Serial.print(x);
 Wire.beginTransmission(2);
 Wire.write("x is ");
 Wire.write(x);
 Wire.endTransmission();
 
 //check oil rig #1
 distanceT = pingTop();
 Serial.print("Top ping sensor = ");
 Serial.println(distanceT);
 delay(1000);
 if(distanceT < fire)
 {
   //save this oil rig as target and drive to tools to pick up corresponding tool
   //oil rig = square rig
 }
 else
 {
   //move on to check next oil rig
    x = 1;
   Serial.print("x transmitted = ");
   Serial.print(x);
   Wire.beginTransmission(2);
   Wire.write("x is ");
   Wire.write(x);
   Wire.endTransmission();
   delay(1000); //this should be the time it takes to drive to oil rig #2
   x = 0;       //stop in front of oil rig
   Serial.print("x transmitted = ");
   Serial.print(x);
   Wire.beginTransmission(2);
   Wire.write("x is ");
   Wire.write(x);
   Wire.endTransmission();
 
   //check oil rig #2
   distanceT = pingTop();
   Serial.print("Top ping sensor = ");
   Serial.println(distanceT);
   delay(1000);
   if(distanceT < fire)
   {
     //save this oil rig as target and drive to tools to pick up corresponding tool
     //oil rig = triangle rig
   }
   else
   {
     //move on to check next oil rig
      x = 1;
      Serial.print("x transmitted = ");
      Serial.print(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(1000); //this should be the time it takes to drive to oil rig #3
      x = 0;       //stop in front of oil rig
      Serial.print("x transmitted = ");
      Serial.print(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
 
      //check oil rig #3
      distanceT = pingTop();
      Serial.print("Top ping sensor = ");
      Serial.println(distanceT);
      delay(1000);
      if(distanceT < fire)
      {
        //save this oil rig as target and drive to tools to pick up corresponding tool
        //oil rig = circle rig
      }
      else
      {
        //reverse back to starting position
      }
   }
 }
 
 
 
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


















