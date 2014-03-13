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
int ledPin = 42;  //square rig
int led2Pin = 43; //triangle rig
int led3Pin = 41; //circle rig

int fire, tool;

int tooClose = 10; 
int durationR, durationF, durationL, forwardCm, leftCm, rightCm;
int durationT, topCm;
int distanceR, distanceF, distanceL, distanceT;
int x; //commands for driver slave
int y; //commands for arm slave
int wave = 30;
int rowCount = 0;
int waveCount = 0;
int delayw = 0; 

//halt x = 0
//foward x = 1
//reverse x = 2
//leftTurn x = 3
//rightTurn x = 4
//turnAround x = 5
//arm startingPosition y = 6
//arm grabTool y = 7
//arm scanTool y = 8
//raise are for oil rig scan y = 9


void setup()
{
   Wire.begin(); //join bus as master
   Serial.begin(9600);
   pinMode(ledPin, OUTPUT);
   pinMode(led2Pin, OUTPUT);
   pinMode(led3Pin, OUTPUT);
}

void loop()
{
  delay(1000);
  //raise arm to scanning position
  y = 9;
  Serial.print("y transmitted = ");
  Serial.println(y);
  Wire.beginTransmission(4);
  Wire.write("y is ");
  Wire.write(y);
  Wire.endTransmission();
  y = 9;
  Wire.beginTransmission(4);
  Wire.write(y);
  Wire.endTransmission();
  //digitalWrite(ledPin, HIGH);
  //digitalWrite(led2Pin, HIGH);
  //digitalWrite(led3Pin, HIGH);
  delay(5000);
  //digitalWrite(ledPin, LOW);
  //digitalWrite(led2Pin, LOW);
  //digitalWrite(led3Pin, LOW);
  
  //get to first rig
  x = 1;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(600); //950 is one full wave, needs to be just short of that to be centered with first rig 
  
  x = 0;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(2000); //is 2 seconds long enough to scan rig efficiently?
  
  //take multiple readings to allow it to level out
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  
  if(distanceT < 210)
  {
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
    fire = 1;
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  
  delay(2000);
  
  //get to second rig
  x = 1;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(1500); //need to move about 2 waves from last position to scan first rig 1800
  
  x = 0;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(2000); 
  
  //take multiple readings to allow it to level out
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  
  if(distanceT < 210)
  {
    digitalWrite(led3Pin, HIGH);
    delay(2000);
    digitalWrite(led3Pin, LOW);
    fire = 2;
  }
  else
  {
    digitalWrite(led3Pin, LOW);
  }
  
  delay(2000);
  
  //get to third rig
  x = 1;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(1700); //need to move about 2 waves from last position to scan second rig
  
  x = 0;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(2000); 
  
  //take multiple readings to allow it to level out
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  distanceT = pingTop();
  Serial.println(distanceT);
  
  if(distanceT < 210)
  {
    digitalWrite(led2Pin, HIGH);
    delay(2000);
    digitalWrite(led2Pin, LOW);
    fire = 3;
  }
  else
  {
    digitalWrite(led2Pin, LOW);
  }
  
  delay(2000);
  
  //put back into starting position
  y = 6;
  Serial.print("y transmitted = ");
  Serial.println(y);
  Wire.beginTransmission(4);
  Wire.write("y is ");
  Wire.write(y);
  Wire.endTransmission();
  y = 6;
  Wire.beginTransmission(4);
  Wire.write(y);
  Wire.endTransmission();
  
  delay(1000);
  
  
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
