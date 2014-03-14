int pulsePin0 = 7; //left orange IN1
int pulsePin1 = 6; //left white IN2
int pulsePin2 = 5; //right green IN3
int pulsePin3 = 4; //right black IN4
int ENA = 8;
int ENB = 9;

#define CW 2
#define CCW 3 

void setup()
{
  Serial.begin(9600);
  
  //set all digital pins to output
  pinMode(pulsePin0, OUTPUT);
  pinMode(pulsePin1, OUTPUT);
  pinMode(pulsePin2, OUTPUT);
  pinMode(pulsePin3, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop()
{
  if (!digitalRead(CW)) forward(480, 0);
  if (!digitalRead(CCW)) reverse(480, 0);
}
//end of main loop 
  
  

