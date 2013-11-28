//motor one: PWM pin 11, DIR pin 12 front right motor
//motor two: PWM pin 5, DIR pin 4 front left motor
//motor three: PWM pin 6, DIR pin 7 back right motor
//motor four: PWM pin 9, DIR pin 8 back left motor
//ping sensors: pin 13, pin 2

int PinPWM_motor1_rt_ft = 11; //ch 2
int PinPWN_motor2_lt_ft = 5; //ch 4
int PinPWM_motor3_rt_bk = 6; //ch 1
int PinPWM_motor4_lt_bk = 9; //ch 3

int PinMove_motor1_rt_ft = 12; //ch 2
int PinMove_motor2_lt_ft = 4; //ch 4
int PinMove_motor3_rt_bk = 7; //ch 1
int PinMove_motor4_rt_bk = 8; //ch 3

int motor_forward; 
int motor_backward;
int right_turn;
int left_turn;
unsigned long start_time;
int count = 0;
int drive_time;

#define time_forward 5000; //need to measure to it takes to move 16" forward
#define time_backward 5000; //need to measure to it takes to move 16" forward
#define turn_time 1200; //time it takes to make one 90 degree turn

//rt = right, lt = left, ft = front, lt = left

void setup()
{
  Serial.begin(9600);
  pinMode(PinPWM_motor1_rt_ft, OUTPUT); //initialize motor PWM
  pinMode(PinPWN_motor2_lt_ft, OUTPUT);
  pinMode(PinPWM_motor3_rt_bk, OUTPUT);
  pinMode(PinPWM_motor4_lt_bk, OUTPUT);
  pinMode(PinMove_motor1_rt_ft, OUTPUT); //initialize motor DIR  
  pinMode(PinMove_motor2_lt_ft, OUTPUT);
  pinMode(PinMove_motor3_rt_bk, OUTPUT);
  pinMode(PinMove_motor4_rt_bk, OUTPUT);
}

void loop()
{
  analogWrite(PinPWM_motor1_rt_ft, 255);
  analogWrite(PinPWN_motor2_lt_ft, 255);
  analogWrite(PinPWM_motor3_rt_bk, 255);
  analogWrite(PinPWM_motor4_lt_bk, 255);
  start_time = millis();
  
  while(millis() - start_time < drive_time) //check current drain
  {
    if(analogRead(0) > 325) // > 1.46 amps
    break;
  }
  
  switch(count++ & 3)   //switch(count) uncomment selections for conditional movement based upon sensors
  {
    case 0: //forward
    digitalWrite(PinMove_motor1_rt_ft, 1);
    digitalWrite(PinMove_motor2_lt_ft, 1);
    digitalWrite(PinMove_motor3_rt_bk, 1);
    digitalWrite(PinMove_motor4_rt_bk, 1);
    drive_time = time_forward; //comment out after testing driveability
    //delay(1000);
    //count++;
    break;
    
    case 1: //turn right
    analogWrite(PinPWM_motor1_rt_ft, 50);
    analogWrite(PinPWM_motor3_rt_bk, 50);
    
    digitalWrite(PinMove_motor1_rt_ft, 1);
    digitalWrite(PinMove_motor2_lt_ft, 1);
    digitalWrite(PinMove_motor3_rt_bk, 1);
    digitalWrite(PinMove_motor4_rt_bk, 1);
    drive_time = turn_time; //comment out after testing driveability
    //delay(1500);
    //count++;
    break;
    
    case 2: //backward
    digitalWrite(PinMove_motor1_rt_ft, 0);
    digitalWrite(PinMove_motor2_lt_ft, 0);
    digitalWrite(PinMove_motor3_rt_bk, 0);
    digitalWrite(PinMove_motor4_rt_bk, 0);
    drive_time = time_backward; //comment out after testing driveability
    //delay(1000);
    //count++;
    break;
    
    case 3: //turn left
    analogWrite(PinPWN_motor2_lt_ft, 50);
    analogWrite(PinPWM_motor4_lt_bk, 50);
    
    digitalWrite(PinMove_motor1_rt_ft, 1);
    digitalWrite(PinMove_motor2_lt_ft, 1);
    digitalWrite(PinMove_motor3_rt_bk, 1);
    digitalWrite(PinMove_motor4_rt_bk, 1);
    drive_time = turn_time; //comment out after testing driveability
    //delay(1500);
    //count++;
    break;
    
  } //end of switch
  
  analogWrite(PinPWM_motor1_rt_ft, 0);
  analogWrite(PinPWN_motor2_lt_ft, 0);
  analogWrite(PinPWM_motor3_rt_bk, 0);
  analogWrite(PinPWM_motor4_lt_bk, 0);
  delay(500);
  
} //end of loop  
