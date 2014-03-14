#include <Ping.h>

int PinPWM_motor1 = 11; //ch 2 left back
int PinPWN_motor2 = 5; //ch 4 right back
int PinPWM_motor3 = 6; //ch 1 right front
int PinPWM_motor4 = 9; //ch 3 left front

int PinMove_motor1 = 12; //ch 2 left back
int PinMove_motor2 = 4; //ch 4 right back
int PinMove_motor3 = 7; //ch 1 right front
int PinMove_motor4 = 8; //ch 3 left front

int pingFrontPin = 3;
int pingBackPin = 10;
int durationF, durationB, forwardCm, backwardCm;
int tooClose;
int distanceFwd, distanceBck;

void setup()
{
  Serial.begin(9600);
  pinMode(PinPWM_motor1, OUTPUT); //initialize motor PWM
  pinMode(PinPWN_motor2, OUTPUT);
  pinMode(PinPWM_motor3, OUTPUT);
  pinMode(PinPWM_motor4, OUTPUT);
  pinMode(PinMove_motor1, OUTPUT); //initialize motor DIR  
  pinMode(PinMove_motor2, OUTPUT);
  pinMode(PinMove_motor3, OUTPUT);
  pinMode(PinMove_motor4, OUTPUT);
}

void loop()
{
  //tooClose = 10;
  distanceFwd = pingForward();

  if(distanceFwd <= 10)
  {
   halt();
   //turnAround();
   //halt();
  }
  else
  {
    forward();
  }
  
  //if(distanceFwd > tooClose){
    //forward();
  //}
  
  //delay(1000);
  
  /*int distanceFwd = pingForward();
  do
  {
    forward();
  } while (distanceFwd > tooClose);
  
  halt();*/
  
  /*int distanceFwd = pingForward();
  if(distanceFwd > tooClose)
  {
    forward();
  }
  else
  {
    halt();
    //turnAround();
    //halt();
  }*/
  /*int distanceBck = pingBackwards();
  if(distanceBck > tooClose)
  {
    reverse();
  }
  else
  {
    halt();
  }*/
  
  
  //halt();
  //forward();
  //halt();
  //reverse();
  //halt();
  //rightTurn();
  //halt();
  //leftTurn();
  //halt();
  //leftTurn();
  //halt();
  //rightTurn();
  //halt();
  //turnAround();
  //halt();
}

void forward()
{
  //to move forward
  analogWrite(PinPWM_motor1, 50); // 50/100 (for wood floor at home/for track at school)
  analogWrite(PinPWN_motor2, 125); // 125/175
  analogWrite(PinPWM_motor3, 125); // 125/175
  analogWrite(PinPWM_motor4, 50); // 50/100
  
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  digitalWrite(PinMove_motor4, HIGH);
  //delay(1450); //time it takes for robot to move 16" forward
  delay(1000);
}

void reverse()
{
  //to backup
  analogWrite(PinPWM_motor1, 50);
  analogWrite(PinPWN_motor2, 125);
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
  analogWrite(PinPWN_motor2, 175);
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
  analogWrite(PinPWN_motor2, 0);
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
  analogWrite(PinPWN_motor2, 175);
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
  analogWrite(PinPWN_motor2, 0);
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
  analogWrite(PinPWN_motor2, 125);
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
  analogWrite(PinPWN_motor2, 0);
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
  analogWrite(PinPWN_motor2, 0);
  analogWrite(PinPWM_motor3, 0);
  analogWrite(PinPWM_motor4, 0);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, LOW);
  delay(1000);
}

int pingForward()
{
  // Send out ping signal from front sensor
  pinMode(pingFrontPin, OUTPUT);
  digitalWrite(pingFrontPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingFrontPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingFrontPin, LOW);
  
  //Get duration it takes to receive echo
  pinMode(pingFrontPin, INPUT);
  durationF = pulseIn(pingFrontPin, HIGH);
  forwardCm = durationF/58;
  //distanceFwd = int(durationF/29);
  return forwardCm;
}

int pingBackwards()
{
  // Send out ping signal from front sensor
  pinMode(pingBackPin, OUTPUT);
  digitalWrite(pingBackPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingBackPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingBackPin, LOW);
  
  //Get duration it takes to receive echo
  pinMode(pingBackPin, INPUT);
  durationB = pulseIn(pingBackPin, HIGH);
  backwardCm = durationB/58;
  //distanceBck = int(durationB/29);
  return backwardCm;
}
