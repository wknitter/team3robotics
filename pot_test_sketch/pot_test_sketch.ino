//this sketch reads and displays values of POTs for testing and
//calibration purposes

int potPin1 = 0;
int potPin2 = 1;
int potPin3 = 2;
int potPin4 = 3;

int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  val1 = analogRead(potPin1);
  Serial.print("Claw pot = ");
  Serial.println(val1);
  val2 = analogRead(potPin2);
  Serial.print("Motor 2 pot = ");
  Serial.println(val2);
  val3 = analogRead(potPin3);
  Serial.print("Motor 3 pot = ");
  Serial.println(val3);
  val4 = analogRead(potPin4);
  Serial.print("Base motor pot = ");
  Serial.println(val4);
  delay(5000);
}
