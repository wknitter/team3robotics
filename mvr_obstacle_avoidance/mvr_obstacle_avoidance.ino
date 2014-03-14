int PinPWM_motor1 = 11; //ch 2 left back
int PinPWN_motor2 = 5; //ch 4 right back
int PinPWM_motor3 = 6; //ch 1 right front
int PinPWM_motor4 = 9; //ch 3 left front

int PinMove_motor1 = 12; //ch 2 left back
int PinMove_motor2 = 4; //ch 4 right back
int PinMove_motor3 = 7; //ch 1 right front
int PinMove_motor4 = 8; //ch 3 left front

int pingFront = 3;
int pingRight = 10;
int pingLeft = 13; 
long durationF, durationR, durationL; //time it takes to receive ping back
int tooClose = 13; //closest distance robot can be to any object in cm (5 inches = 12.7 cm)
//int waveCount1, waveCount2, waveCount3; //grid count variables to save so robot knows its way back across board
//int waveCountMax1, waveCountMax2, waveCountMax3; //max variables waveCount cannot exceed to keep robot from running off the track


//left side = motor1 and motor4
//right side = motor2 and motor3

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
  int distanceFwd = pingForward();
  int distanceRtSd = pingRightSide();
  int distanceLtSd = pingLeftSide();
  if (distanceFwd > tooClose)
  {
    forward();
  }
  else if (distanceRtSd > tooClose)
  {
    rightTurn();
  }
  else if (distanceLtSd > tooClose)
  {
    leftTurn();
  }
  else 
  {
    turnAround();
    forward();
  }
}

long pingForward()
{
  // Send out ping signal from front sensor
  pinMode(pingFront, OUTPUT);
  digitalWrite(pingFront, LOW);
  delayMicroseconds(2);
  digitalWrite(pingFront, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingFront, LOW);
  
  //Get duration it takes to receive echo
  pinMode(pingFront, INPUT);
  durationF = pulseIn(pingFront, HIGH);
  
  //Convert duration into distance (cm)
  return durationF / 29 / 2;
  
  //distance = duration / 29 / 2;
  //return distance;
}

long pingRightSide()
{
  // Send out ping signal from front sensor
  pinMode(pingRight, OUTPUT);
  digitalWrite(pingRight, LOW);
  delayMicroseconds(2);
  digitalWrite(pingRight, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingRight, LOW);
  
  //Get duration it takes to receive echo
  pinMode(pingRight, INPUT);
  durationR = pulseIn(pingRight, HIGH);
  
  //Convert duration into distance (cm)
  return durationR / 29 / 2;
  
  //distance = duration / 29 / 2;
  //return distance;
}

long pingLeftSide()
{
  // Send out ping signal from front sensor
  pinMode(pingLeft, OUTPUT);
  digitalWrite(pingLeft, LOW);
  delayMicroseconds(2);
  digitalWrite(pingLeft, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingLeft, LOW);
  
  //Get duration it takes to receive echo
  pinMode(pingLeft, INPUT);
  durationL = pulseIn(pingLeft, HIGH);
  
  //Convert duration into distance (cm)
  return durationL / 29 / 2;
  
  //distance = duration / 29 / 2;
  //return distance;
}

void forward()
{
  //to move forward
  analogWrite(PinPWM_motor1, 100);
  analogWrite(PinPWN_motor2, 100);
  analogWrite(PinPWM_motor3, 100);
  analogWrite(PinPWM_motor4, 100);
  
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  digitalWrite(PinMove_motor4, HIGH);
  delay(1000); //this should be the time it takes for robot to move 16" forward
}

void reverse()
{
  //to backup
  analogWrite(PinPWM_motor1, 100);
  analogWrite(PinPWN_motor2, 100);
  analogWrite(PinPWM_motor3, 100);
  analogWrite(PinPWM_motor4, 100);
  
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
 
void rightTurn()
{
  //turn 90 degrees right
  analogWrite(PinPWM_motor1, 100);
  analogWrite(PinPWN_motor2, 100);
  analogWrite(PinPWM_motor3, 100);
  analogWrite(PinPWM_motor4, 100);
  
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, HIGH);
  delay(1500);
  
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
  analogWrite(PinPWN_motor2, 100);
  analogWrite(PinPWM_motor3, 100);
  analogWrite(PinPWM_motor4, 100);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  digitalWrite(PinMove_motor4, LOW);
  delay(1500);
  
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
  analogWrite(PinPWM_motor1, 100);
  analogWrite(PinPWN_motor2, 100);
  analogWrite(PinPWM_motor3, 100);
  analogWrite(PinPWM_motor4, 100);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  digitalWrite(PinMove_motor4, LOW);
  delay(2000); //time it takes to turn 180 degrees
  
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





