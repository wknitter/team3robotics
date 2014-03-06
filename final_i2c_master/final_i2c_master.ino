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
boolean fireDetected;

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
int fireRig; //rig that is on fire
int delayx;

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
 delay(1000); //this should be the time it takes to drive to oil rig #1 approx 10"
 x = 0;       //stop in front of oil rig 
 Serial.print("x transmitted = ");
 Serial.print(x);
 Wire.beginTransmission(2);
 Wire.write("x is ");
 Wire.write(x);
 Wire.endTransmission();

 do
 {
  //check oil rig
  distanceT = pingTop();
  Serial.print("Top ping sensor = ");
  Serial.println(distanceT);
  delay(1000);
  fireRig = 0;
  if(distanceT > fire)
  {
    fireDetected = false; // = or ==?
    x = 1;
    Serial.print("x transmitted = ");
    Serial.print(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000); //this should be the time it takes to drive to next oil rig approx 30"
    x = 0;       //stop in front of oil rig 
    Serial.print("x transmitted = ");
    Serial.print(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    fireRig = fireRig + 1;
  }
  else
  {
    //fireDetected = true;
    switch(fireRig)
    {
      case 1:
      //square rig
      fireRig = oilRig1;
      delayx = 000; //time it takes to drive from first rig to tools
      break;
      
      case 2:
      //triangle rig
      fireRig = oilRig2;
      delayx = 000; //time it takes to drive from middle rig to tools
      break;
      
      case 3:
      //circle rig
      fireRig = oilRig3;
      delayx = 000; //time it takes to drive from oil rig closest to the tools to the tools
      break;
      
      default:
      //pick random rig = circle because it is the easiest in that it doesn't need any orientation
      fireRig = oilRig3;
      delayx = 000; //same time as for circle rig
      break;
    }
    fireDetected = true; // = or ==?
  }
 }while(fireDetected == false);
 
 //After oil rig that is on fire is detected, drive forward to the tools
 x = 1;
 Serial.print("x transmitted = ");
 Serial.print(x);
 Wire.beginTransmission(2);
 Wire.write("x is ");
 Wire.write(x);
 Wire.endTransmission();
 delay(delayx); //this should be the time it takes to drive to the tools from specific oil rig
 x = 0;       //stop in front of oil rig 
 Serial.print("x transmitted = ");
 Serial.print(x);
 Wire.beginTransmission(2);
 Wire.write("x is ");
 Wire.write(x);
 Wire.endTransmission();
 
 //
   
 
 
 
 
 
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


















