int pot = 0;  //100k pot
int relay = 3;  //5v DPDT relay
int motorPin = 11;

void setup()
{
  Serial.begin(9600);
  pinMode(pot, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(motorPin, OUTPUT);
}

int getPot()
{
  int v;
  v = analogRead(pot);
  v /= 4;
  v = max(v, 90);
  v = min(v, 255);
  return v;
}

int motorForward() 
{
  analogWrite(motorPin, getPot());
  delay(1000);
  digitalWrite(motorPin, LOW);
  delay(1000);
  digitalWrite(relay, LOW);
  Serial.println(getIR());
  delay(1000);
}

void loop()
{
  motorForward();
  motorBackward();
}

