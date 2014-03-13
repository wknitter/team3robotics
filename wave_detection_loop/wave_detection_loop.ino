//wave detection loop
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  //still need to add waveCount to know where openings were to execute in reverse sequence on trip back
  int waveCount = 0;
  int waveRow = 0;
  int delayw = 0; //delayw = (time to drive 16" forward = 650)*(delayw) = 650*delayw + 100
  //put all of this in a do while loop with a counter as a condition 
 do
 {
  delayw = 0; //reset delayw to 0
  
  distanceL = pingLeft();
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
    delay(650); //this should be the time it takes to drive 16" forward
    x = 0;       //stop in front of wave 
    Serial.print("x transmitted = ");
    Serial.print(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
    delayw = delayw + 1;
    
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
    //waveRow = waveRow + 1;
    
    distanceL = pingLeft();
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
      waveRow = waveRow + 1; //counts the number rows robot has passed through
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
   
   //turn 90 degrees right
   x = 4;
   Serial.print("x transmitted = ");
   Serial.print(x);
   Wire.beginTransmission(2);
   Wire.write("x is ");
   Wire.write(x);
   Wire.endTransmission();
   x = 0;       //stop
   Serial.print("x transmitted = ");
   Serial.print(x);
   Wire.beginTransmission(2);
   Wire.write("x is ");
   Wire.write(x);
   Wire.endTransmission(); 
  
   //reverse back to starting position using delay correlating to waveCount 
   x = 2;
   Serial.print("x transmitted = ");
   Serial.print(x);
   Wire.beginTransmission(2);
   Wire.write("x is ");
   Wire.write(x);
   Wire.endTransmission();
   delayw = delayw*delayx;
   delay(delayw); //delay that correlates to 
   x = 0;       //stop in front of wave 
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
  
  distanceL = pingLeft();
  Serial.print(distanceL);
 
  distanceR = pingRight();
  Serial.print(distanceR);
 
  distanceF = pingForward();
  Serial.println(distanceF);
  
  /*
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
    waveRow = waveRow + 1;
  }
  */
  
 } while(waveRow < 4); 
  
}
