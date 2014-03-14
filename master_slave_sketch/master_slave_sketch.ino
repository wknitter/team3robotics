/*NOT FOR FINAL USE, THIS IS TEST SKETCH WITH ALL MASTER AND 
SLAVES SKETCHES ARE COMPILED*/


#include <Ping.h>
#include <Wire.h>

int PinPWM_motor1 = 4; //ch 2 left back
int PinPWM_motor2 = 5; //ch 4 right back
int PinPWM_motor3 = 6; //ch 1 right front
int PinPWM_motor4 = 7; //ch 3 left front

int PinMove_motor1 = 46; //ch 2 left back 
int PinMove_motor2 = 47; //ch 4 right back
int PinMove_motor3 = 48; //ch 1 right front
int PinMove_motor4 = 49; //ch 3 left front

//motor1 & motor4 = left
//motor2 & motor3 = right

int pingRPin = 22;
int pingFPin = 23;
int pingLPin = 24;

int tooClose = 10;
int durationR, durationF, durationL, forwardCm, leftCm, rightCm;
int distanceR, distanceF, distanceL;

void setup()
{
  Wire.begin(); //master join i2c bus
  Wire.begin(2); //slave join i2c bus with address 2 
  Serial.begin(9600);
  pinMode(PinPWM_motor1, OUTPUT); //initialize motor PWM
  pinMode(PinPWM_motor2, OUTPUT);
  pinMode(PinPWM_motor3, OUTPUT);
  pinMode(PinPWM_motor4, OUTPUT);
  pinMode(PinMove_motor1, OUTPUT); //initialize motor DIR  
  pinMode(PinMove_motor2, OUTPUT);
  pinMode(PinMove_motor3, OUTPUT);
  pinMode(PinMove_motor4, OUTPUT);
}

void loop()
{
  halt();
  forward();
  halt();
  //reverse();
  //halt();
  //turnAround();
  //halt();
  
  
}

void forward()
{
  //to move forward
  analogWrite(PinPWM_motor1, 50); //Mega:100/ Uno:50/100 (for wood floor at home/for track at school)
  analogWrite(PinPWM_motor2, 125); //Mega:50/ Uno:125/175
  analogWrite(PinPWM_motor3, 125); //Mega:50/ Uno:125/175
  analogWrite(PinPWM_motor4, 50); //Mega:100/ Uno:50/100
  
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  digitalWrite(PinMove_motor4, HIGH);
  //delay(1450); //time it takes for robot to move 16" forward
  delay(3000);
}

void reverse()
{
  //to backup
  analogWrite(PinPWM_motor1, 50);
  analogWrite(PinPWM_motor2, 125);
  analogWrite(PinPWM_motor3, 125);
  analogWrite(PinPWM_motor4, 50);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, LOW);
  /*delay(1500);
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  digitalWrite(PinMove_motor4, HIGH);
  delay(100);*/
}

void rightTurn()
{
  //turn 90 degrees right
  analogWrite(PinPWM_motor1, 100);
  analogWrite(PinPWM_motor2, 175);
  analogWrite(PinPWM_motor3, 175);
  analogWrite(PinPWM_motor4, 100);
  
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, HIGH);
  delay(1125);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  delay(100);
  
  //pause before changing direction to avoid current overdraw
  analogWrite(PinPWM_motor1, 0);
  analogWrite(PinPWM_motor2, 0);
  analogWrite(PinPWM_motor3, 0);
  analogWrite(PinPWM_motor4, 0);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, LOW);
  delay(1500);
}

void leftTurn()
{
  //turn 90 degrees left
  analogWrite(PinPWM_motor1, 100);
  analogWrite(PinPWM_motor2, 175);
  analogWrite(PinPWM_motor3, 175);
  analogWrite(PinPWM_motor4, 100);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  digitalWrite(PinMove_motor4, LOW);
  delay(1150);
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor4, HIGH);
  delay(100);
  
  //pause before changing direction to avoid current overdraw
  analogWrite(PinPWM_motor1, 0);
  analogWrite(PinPWM_motor2, 0);
  analogWrite(PinPWM_motor3, 0);
  analogWrite(PinPWM_motor4, 0);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, LOW);
  delay(1500);
}

void turnAround()
{
  //turn 180 degrees left
  analogWrite(PinPWM_motor1, 50);
  analogWrite(PinPWM_motor2, 125);
  analogWrite(PinPWM_motor3, 125);
  analogWrite(PinPWM_motor4, 50);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  digitalWrite(PinMove_motor4, LOW);
  delay(1800); //time it takes to turn 180 degrees
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor4, HIGH);
  delay(100);
  
  //pause before changing direction to avoid current overdraw
  analogWrite(PinPWM_motor1, 0);
  analogWrite(PinPWM_motor2, 0);
  analogWrite(PinPWM_motor3, 0);
  analogWrite(PinPWM_motor4, 0);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, LOW);
  delay(1000);
}

void halt()
{
  //to stop
  analogWrite(PinPWM_motor1, 0);
  analogWrite(PinPWM_motor2, 0);
  analogWrite(PinPWM_motor3, 0);
  analogWrite(PinPWM_motor4, 0);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, LOW);
  delay(2000);
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
