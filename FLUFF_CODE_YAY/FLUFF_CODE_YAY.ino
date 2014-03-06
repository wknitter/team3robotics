void setup()
{
  Serial.begin(9600);
}

void loop()
{
 //make this into its own little function and call it constantly??
 //also need to move front ping sensor over to edge of bot
 distanceL= pingLeft();
 Serial.print(distanceL);
 
 distanceR = pingRight();
 Serial.print(distanceR);
 
 distanceF = pingForward();
 Serial.println(distanceF); 
 
 if(distanceL<tooClose && distanceR<tooClose && distanceF<tooClose)
 {
   x = 0; //halt, the robot is too close to anything to move safely
    Serial.print("x transmitted = ");
    Serial.print(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
 }
 if (distanceL<tooClose)
 {
   x = 1; //move forward 16"
    Serial.print("x transmitted = ");
    Serial.print(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
   delay(1000); //time it takes to move 16" forward
 }
 else
 {
   x = 0; //halt to indicate opening
    Serial.print("x transmitted = ");
    Serial.print(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
   x = 3; //turn 90 degrees left into opening 
    Serial.print("x transmitted = ");
    Serial.print(x);
    Wire.beginTransmission(2);
    Wire.write("x is ");
    Wire.write(x);
    Wire.endTransmission();
 }
 
 /*Serial.print("x transmitted = ");
 Serial.print(x);
 Wire.beginTransmission(2);
 Wire.write("x is ");
 Wire.write(x);
 Wire.endTransmission();*/
}
