//const int pingPin = 7;
int pingLPin = 25; //24
int pingRPin = 22;
//wave duration < 1500;
//oil rig fire = 200-209 no fire = 226-229
//opening > 22
//tooClose = 10

void setup() {
  //set up serial communication
  Serial.begin(9600);
}

void loop() {
  long duration, cm;
  
  //send out ping
  pinMode(pingLPin, OUTPUT);
  digitalWrite(pingLPin, LOW);
  delayMicroseconds(200);
  digitalWrite(pingLPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(pingLPin, LOW);
 
  
  //read in pulse length of ping
  pinMode(pingLPin, INPUT);
  duration = pulseIn(pingLPin, HIGH);
  
  //convert time into distance
  cm = microsecondsToCm(duration);
  
  //print to screen
  Serial.print("cm = ");
  Serial.print(cm);
  //Serial.print(duration);
  Serial.println();
  
  delay(1000);
}

long microsecondsToCm(long microseconds) {
  return microseconds / 29 / 2;
}

