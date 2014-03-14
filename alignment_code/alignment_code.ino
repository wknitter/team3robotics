//this code uses the two ping sensors on the front of the robot to 
//align itself with tools and the rigs
#include <Wire.h>
//set parameters
int pingRPin = 22;
int pingFPin = 23;
int pingLPin = 24;
int pingTPin = 25;
int ledPin = 42;  //square 
int led2Pin = 43; //triangle 
int led3Pin = 41; //circle 

int fire, tool, align = 0;

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

int val1, val2, val3, val4, val5, val6, val7, val8, val9, val10, val11, val12, val13, val14, val15, val16 = 0;
int sum;
int count;
int total = 0;
int ledPin4 = 36; // LED connected to digital pin 13
int ledPin3 = 34; // LED connected to digital pin 13
int ledPin2 = 32; // LED connected to digital pin 13
int ledPin1 = 30; // LED connected to digital pin 13

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
   pinMode(ledPin1, OUTPUT); // sets the digital pin as output
   pinMode(ledPin2, OUTPUT); // sets the digital pin as output
   pinMode(ledPin3, OUTPUT); // sets the digital pin as output 
   pinMode(ledPin4, OUTPUT); // sets the digital pin as output
}

void loop()
{
  do
  {
    
  //sensors = front ping sensor and right ping sensor
  distanceF = pingForward();
  Serial.println(distanceT);
  distanceR = pingRight();
  Serial.println(distanceT);
  distanceF = pingForward();
  Serial.println(distanceT);
  distanceR = pingRight();
  Serial.println(distanceT);
  distanceF = pingForward();
  Serial.println(distanceT);
  distanceR = pingRight();
  Serial.println(distanceT);
  
  //this alignment is for oil rig
  //to align with tool, reserve all the < and >
  
  if(distanceF < 20 && distanceR < 20) // <20 && <20====>(oil rig)   >20 && >20====>(tools)
  {
    //robot is aligned so stop
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000);
    
    align = 1;
  }
  else if(distanceF > 20 && distanceR < 20) // >20 && <20====>(oil rig)   <20 && >20====>(tools)
  {
    delay(1000);
    //robot is too far to the left
    x = 4; //turn right
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(800);
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000);
    x = 1;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(275);
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000);
    x = 3; //turn back left
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(800);
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000);
    
    align = 2;
  }
  else                   // // <20 && >20====>(oil rig)   >20 && <20====>(tools)
  {
    delay(1000);
    //robot is too far to the right
    x = 3; //turn left
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(800);
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000);
    x = 1;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(275);
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000);
    x = 4; //turn back right
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(800);
    x = 0;
    Serial.print("x transmitted = ");
    Serial.println(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000);
    
    align = 2;
  }
  
  distanceF = pingForward();
  Serial.println(distanceT);
  distanceR = pingRight();
  Serial.println(distanceT);
  distanceF = pingForward();
  Serial.println(distanceT);
  distanceR = pingRight();
  Serial.println(distanceT);
  distanceF = pingForward();
  Serial.println(distanceT);
  distanceR = pingRight();
  Serial.println(distanceT);
  
  } while (align != 1);
  
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
