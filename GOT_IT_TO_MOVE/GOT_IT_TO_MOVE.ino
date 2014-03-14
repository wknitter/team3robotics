int pulsePin0 = 7; //left orange
int pulsePin1 = 6; //left white
int pulsePin2 = 5; //right green
int pulsePin3 = 4; //right black
int ENA = 8;
int ENB = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(pulsePin0, OUTPUT);
  pinMode(pulsePin1, OUTPUT);
  pinMode(pulsePin2, OUTPUT);
  pinMode(pulsePin3, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
}

void loop()
{
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  
  digitalWrite(pulsePin0, HIGH);
  delay(4000);
  digitalWrite(pulsePin0, LOW);
  
  digitalWrite(pulsePin1, HIGH);
  delay(4000);
  digitalWrite(pulsePin1, LOW);
  //digitalWrite(pulsePin0, LOW);
  
  //digitalWrite(pulsePin0, LOW);
  //digitalWrite(pulsePin1, LOW);
  
  digitalWrite(pulsePin2, HIGH);
  delay(4000);
  digitalWrite(pulsePin2, LOW);
  
  digitalWrite(pulsePin3, HIGH);
  delay(4000);
  digitalWrite(pulsePin3, LOW);
  //digitalWrite(pulsePin2, LOW);
  //delay(5000);
}
