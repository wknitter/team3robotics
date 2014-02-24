int irLED1 = 12;
int irLED2 = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(irLED1, OUTPUT);
  pinMode(irLED2, OUTPUT);
  Serial.println("Ready to send pulse...");
}

void loop() 
{
  Serial.println("ON");
  digitalWrite(irLED1, HIGH);
  digitalWrite(irLED2, HIGH);
  delay(10000);                //turn both LEDs on for one second
  Serial.println("OFF");
  digitalWrite(irLED1, LOW);
  digitalWrite(irLED2, LOW);
  delay(10000);                //turn them off, this action "takes the photo"
}

