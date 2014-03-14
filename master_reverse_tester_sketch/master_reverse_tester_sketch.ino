#include <Wire.h>
int x;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  x = 2; //reverse
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
}
