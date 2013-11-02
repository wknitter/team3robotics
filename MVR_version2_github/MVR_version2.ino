int PinPWM_motor1 = 11; //ch 2 left back
int PinPWN_motor2 = 5; //ch 4 right back
int PinPWM_motor3 = 6; //ch 1 right front
int PinPWM_motor4 = 9; //ch 3 left front

int PinMove_motor1 = 12; //ch 2 left back
int PinMove_motor2 = 4; //ch 4 right back
int PinMove_motor3 = 7; //ch 1 right front
int PinMove_motor4 = 8; //ch 3 left front

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
  halt();
  turnAround();
  halt();
}

void forward()
{
  //to move forward
  analogWrite(PinPWM_motor1, 50);
  analogWrite(PinPWN_motor2, 125);
  analogWrite(PinPWM_motor3, 125);
  analogWrite(PinPWM_motor4, 50);
  
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  digitalWrite(PinMove_motor4, HIGH);
  delay(1450); //time it takes for robot to move 16" forward
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
  delay(1500);
  digitalWrite(PinMove_motor1, HIGH);
  digitalWrite(PinMove_motor2, HIGH);
  digitalWrite(PinMove_motor3, HIGH);
  digitalWrite(PinMove_motor4, HIGH);
  delay(100);
}

void rightTurn()
{
  //turn 90 degrees right
  analogWrite(PinPWM_motor1, 50);
  analogWrite(PinPWN_motor2, 125);
  analogWrite(PinPWM_motor3, 125);
  analogWrite(PinPWM_motor4, 50);
  
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
  analogWrite(PinPWM_motor1, 50);
  analogWrite(PinPWN_motor2, 125);
  analogWrite(PinPWM_motor3, 125);
  analogWrite(PinPWM_motor4, 50);
  
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
  delay(2200); //time it takes to turn 180 degrees
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
