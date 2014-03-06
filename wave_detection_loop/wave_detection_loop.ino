//wave detection loop
void setup()
{
  Serial.begin(9600);
}

void setup()
{
  //put all of this in a do while loop with a counter as a condition 
 do
 {
  distanceL= pingLeft();
  Serial.print(distanceL);
 
  distanceR = pingRight();
  Serial.print(distanceR);
 
  distanceF = pingForward();
  Serial.println(distanceF);
 
  if(distanceR>tooClose && distanceF>tooClose && distanceL<wave) //wave is present condition
  { 
    //drive forward 16" code 
    x = 1;
    Serial.print("x transmitted = ");
    Serial.print(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(delayx); //this should be the time it takes to drive 16" forward
    x = 0;       //stop in front of wave 
    Serial.print("x transmitted = ");
    Serial.print(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    
  }
  else if(distanceR>tooClose && distanceF>tooClose && distanceL>wave) //wave is not present condition
  {
    //turn 90 degrees left
    x = 3;
    Serial.print("x transmitted = ");
    Serial.print(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    x = 0;       //stop to face opening 
    Serial.print("x transmitted = ");
    Serial.print(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
  }
  else
  {
    x = 0;       //stop
    Serial.print("x transmitted = ");
    Serial.print(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
  }
  
  distanceL= pingLeft();
  Serial.print(distanceL);
 
  distanceR = pingRight();
  Serial.print(distanceR);
 
  distanceF = pingForward();
  Serial.println(distanceF);
  
  //drive through opening
  if(distanceR>tooClose && distanceF>opening && distanceL>tooClose)
  {
    x = 1;
    Serial.print("x transmitted = ");
    Serial.print(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delay(1000); //this should be the time it takes to drive 21" forward
    x = 0;       //stop in front of wave 
    Serial.print("x transmitted = ");
    Serial.print(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
  }
  
 } while();
  
}
