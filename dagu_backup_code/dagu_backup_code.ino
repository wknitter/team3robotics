int PinPWM_motor1 = 11; //ch 2 left back
int PinPWN_motor2 = 5; //ch 4 right back
int PinPWM_motor3 = 6; //ch 1 right front
int PinPWM_motor4 = 9; //ch 3 left front

int PinMove_motor1 = 12; //ch 2 left back
int PinMove_motor2 = 4; //ch 4 right back
int PinMove_motor3 = 7; //ch 1 right front
int PinMove_motor4 = 8; //ch 3 left front

int pingPin = 3;
long duration; //time it takes to receive ping back
int tooClose = 8; //closest distance robot can be to any object in cm (3 inches = 7.62)

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
  // initialize motors to move forward, backward or turn
  analogWrite(PinPWM_motor1, 100);
  analogWrite(PinPWN_motor2, 100);
  analogWrite(PinPWM_motor3, 100);
  analogWrite(PinPWM_motor4, 100);
  
  //forward
  int fowardDist = ping(); //send ping before moving
  if (forwardDist > tooClose)
  {
    forward(); //go ahead and move forward
    /*digitalWrite(PinMove_motor1, HIGH);
    digitalWrite(PinMove_motor2, HIGH);
    digitalWrite(PinMove_motor3, HIGH);
    digitalWrite(PinMove_motor4, HIGH);*/
    delay(1000); //this should be the time it takes for robot to move 16" forward
  }
  else //backup from obstacle
  {
    //backward
    digitalWrite(PinMove_motor1, LOW);
    digitalWrite(PinMove_motor2, LOW);
    digitalWrite(PinMove_motor3, LOW);
    digitalWrite(PinMove_motor4, LOW);
    delay(5000);
  }
  
  //turn 90 degrees
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
  
  //turn 90 degrees other direction
  analogWrite(PinPWM_motor1, 100);
  analogWrite(PinPWN_motor2, 100);
  analogWrite(PinPWM_motor3, 100);
  analogWrite(PinPWM_motor4, 100);
  
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, HIGH);
  delay(1500);
  
  analogWrite(PinPWM_motor1, 0);
  analogWrite(PinPWN_motor2, 0);
  analogWrite(PinPWM_motor3, 0);
  analogWrite(PinPWM_motor4, 0);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, LOW);
  delay(1500);
  
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

long ping()
{
  // Send out ping signal
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  
  //Get duration it takes to receive echo
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  
  //Convert duration into distance (cm)
  return duration / 29 / 2;
}

void forward()
{
  analogWrite(PinPWM_motor1, 100);
  analogWrite(PinPWN_motor2, 100);
  analogWrite(PinPWM_motor3, 100);
  analogWrite(PinPWM_motor4, 100);
  
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  digitalWrite(PinMove_motor4, HIGH);
  //delay(1000); //this should be the time it takes for robot to move 16" forward
}

void reverse()
{
  analogWrite(PinPWM_motor1, 100);
  analogWrite(PinPWN_motor2, 100);
  analogWrite(PinPWM_motor3, 100);
  analogWrite(PinPWM_motor4, 100);
  
  digitalWrite(PinMove_motor1, LOW);
  digitalWrite(PinMove_motor2, LOW);
  digitalWrite(PinMove_motor3, LOW);
  digitalWrite(PinMove_motor4, LOW);
  //delay(1000);
}
  
