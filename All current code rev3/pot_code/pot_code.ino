//brown wire = signal
//red wire = 5V
//green wire = ground 
//dial all the way to red wire side = 1023
//dial all the way to green wire side = 0

int potPin = 0;
int val = 0;

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(potPin);
  Serial.println(val);
  delay(1000);
}


