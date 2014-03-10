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
int ledPin = 42; //square led to show 
int led2Pin = 43; //triangle led that shows delayw = 0

int fire = 10;

int tooClose = 10; //duration = cm*58 = 17.78*58 = 1031.24 (17.78cm = 7in)
//14-17 = wave 76-77 = opening
int durationR, durationF, durationL, forwardCm, leftCm, rightCm;
int durationT, topCm;
int distanceR, distanceF, distanceL, distanceT;
int x;
int wave = 30;
int rowCount = 0;
int waveCount = 0;
int delayw = 0; //900

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
   pinMode(ledPin, OUTPUT);
   pinMode(led2Pin, OUTPUT);
}

void loop()
{
  do
  {
    distanceL= pingLeft();
    Serial.println(distanceL);
    distanceR = pingRight();
    Serial.println(distanceR);
    distanceF = pingForward();
    Serial.println(distanceF);
    delay(100); 
    distanceL= pingLeft();
    Serial.println(distanceL);
    distanceR = pingRight();
    Serial.println(distanceR);
    distanceF = pingForward();
    Serial.println(distanceF);
    delay(100);
    distanceL= pingLeft();
    Serial.println(distanceL);
    distanceR = pingRight();
    Serial.println(distanceR);
    distanceF = pingForward();
    Serial.println(distanceF);
    delay(1000);
    
    if(distanceL<tooClose && distanceR<tooClose && distanceF<tooClose)
    {
      x = 0; //halt, the robot is too close to anything to move safely
    }
    else if (distanceL<wave && distanceF>wave)
    {
      x = 1; //move forward 16"
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(950);
      waveCount = waveCount + 1;
      //digitalWrite(ledPin, HIGH);
      delayw = (880*waveCount); //-900 ?
  
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(1000);
      digitalWrite(ledPin, HIGH);
      delay(1000);
      digitalWrite(ledPin, LOW);
      delay(1000);
    }
    else if (distanceL>wave) //is turning left again because it thinking there is another opening even though it just went through the opening
    {
      //waveCount = 0;
      //delayw = 900;
      
      x = 3; //turn left
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(730);  //750
      rowCount = rowCount + 1;
  
      distanceF = pingForward();
      Serial.println(distanceF);
  
      //if(distanceF>wave)
      //{
      distanceF = pingForward();
      Serial.println(distanceF);
      do
      {
          distanceF = pingForward();
          Serial.println(distanceF);
          //digitalWrite(led2Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
          //delay(500);               // wait for a second
          //digitalWrite(led2Pin, LOW);    // turn the LED off by making the voltage LOW
          //delay(500);
  
          x = 1; //move forward 16"
          Serial.print("x transmitted = ");
          Serial.println(x);
          Wire.beginTransmission(2);
          Wire.write("x is ");
          Wire.write(x);
          Wire.endTransmission();
          delay(200); //900 is too far, 800 is too short
  
          distanceF = pingForward();
          Serial.println(distanceF);
      } while (distanceF > 22);
  
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(1000);
  
      x = 4; //turn right
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(680);
      
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(2000);
      
      //digitalWrite(led2Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
      //delay(5000);               // wait for a second
      //digitalWrite(led2Pin, LOW);    // turn the LED off by making the voltage LOW
      //delay(1000);
      //}
  
      /*else
      {
        distanceF = pingForward();
        Serial.println(distanceF);
        do
        {
          distanceF = pingForward();
          Serial.println(distanceF);
      
          //digitalWrite(led2Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
          //delay(5000);               // wait for a second
          //digitalWrite(led2Pin, LOW);    // turn the LED off by making the voltage LOW
          //delay(1000);
          distanceF = pingForward();
          Serial.println(distanceF);
      
          x = 4; //turn right
          Serial.print("x transmitted = ");
          Serial.println(x);
          Wire.beginTransmission(2);
          Wire.write("x is ");
          Wire.write(x);
          Wire.endTransmission();
          delay(800);
          x = 1; //move forward a bit more to clear opening
          Serial.print("x transmitted = ");
          Serial.println(x);
          Wire.beginTransmission(2);
          Wire.write("x is ");
          Wire.write(x);
          Wire.endTransmission();
          delay(200);
      
          distanceF = pingForward();
          Serial.println(distanceF);
        } while (distanceF<wave);
      }*/
      
      //try decrementing do while or for loop instead of if statement?
      //if(waveCount > 0) 
      //{
        x = 2; //reverse
        Serial.print("x transmitted = ");
        Serial.println(x);
        Wire.beginTransmission(2);
        Wire.write("x is ");
        Wire.write(x);
        Wire.endTransmission();
        delay(delayw); //reverse back to starting position = delayw
        delayw = 0;    //reset delayw back to 900
        waveCount = 0;
  
        x = 0;
        Serial.print("x transmitted = ");
        Serial.println(x);
        Wire.beginTransmission(2);
        Wire.write("x is ");
        Wire.write(x);
        Wire.endTransmission();
        delay(3000);
        //waveCount = 0;
      //}
      //else
      //{
        //digitalWrite(led2Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
        //delay(5000);               // wait for a second
        //digitalWrite(led2Pin, LOW);    // turn the LED off by making the voltage LOW
        //delay(1000);
        //x = 0; //don't need to backup
        //Serial.print("x transmitted = ");
        //Serial.println(x);
        //Wire.beginTransmission(2);
        //Wire.write("x is ");
        //Wire.write(x);
        //Wire.endTransmission();
        //delay(1000);
      //}
    }
    else
    {
      x = 0;
      Serial.print("x transmitted = ");
      Serial.println(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(30000);
    }
    
    //waveCount = 0;
    //delayw = 900;
  
  } while (rowCount <= 3);

delay(10000);

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

//commented out code that did not work:
  /*x = 0;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();*/

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
/*Serial.print("x transmitted = ");
Serial.println(x);
//x = 4;
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();*/
//Serial.println("fuck!!!");

//send arm code out
/*Serial.print("y transmitted = ");
Serial.println(y);
Wire.beginTransmission(4);
Wire.write("y is ");
Wire.write(y);
Wire.endTransmission();*/

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
