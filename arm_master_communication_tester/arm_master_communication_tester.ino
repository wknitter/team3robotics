#include <Wire.h>
//set parameters
int pingRPin = 22;
int pingFPin = 23;
int pingLPin = 24;
int pingTPin = 25;
int ledPin = 42;  //square rig
int led2Pin = 43; //triangle rig
int led3Pin = 41; //circle rig

int fire = 10;

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

void loop()   //pull up resistors??
{
      /*y = 9;
      Serial.print("y transmitted = ");
      Serial.println(y);
      Wire.beginTransmission(4);
      Wire.write("y is ");
      Wire.write(y);
      Wire.endTransmission();
      Serial.print("check 1");
      
      delay(5000);
      
      x = 1;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(1000);
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(1000);
      Serial.print("check 2");*/
      
      delay(2000);
      
      y = 6;
      Serial.print("y transmitted = ");
      Serial.println(y);
      Wire.beginTransmission(4);
      Wire.write("y is ");
      Wire.write(y);
      Wire.endTransmission();
      Serial.print("check 3");
      
      delay(2000);
      
}
