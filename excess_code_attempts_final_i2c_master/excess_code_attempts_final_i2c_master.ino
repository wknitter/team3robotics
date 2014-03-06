//for(i=0;i<4;i++) //3 checks for rigs 
//{
  
//}

boolean fireDetected;

//starting position: drive to check oil rigs for fire 
//drive forward from starting position
x = 1;
Serial.print("x transmitted = ");
Serial.print(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();
delay(1000); //this should be the time it takes to drive to oil rig #1 approx 10"
x = 0;       //stop in front of oil rig 
Serial.print("x transmitted = ");
Serial.print(x);
Wire.beginTransmission(2);
Wire.write("x is ");
Wire.write(x);
Wire.endTransmission();

do
{
 //check oil rig
 distanceT = pingTop();
 Serial.print("Top ping sensor = ");
 Serial.println(distanceT);
 delay(1000);
 if(distanceT > fire)
 {
   fireDetected = false;
   x = 1;
   Serial.print("x transmitted = ");
   Serial.print(x);
   Wire.beginTransmission(2);
   Wire.write("x is ");
   Wire.write(x);
   Wire.endTransmission();
   delay(1000); //this should be the time it takes to drive to next oil rig (approx 30")
   x = 0;       //stop in front of oil rig 
   Serial.print("x transmitted = ");
   Serial.print(x);
   Wire.beginTransmission(2);
   Wire.write("x is ");
   Wire.write(x);
   Wire.endTransmission();
 }
 else
 {
   fireDetected = true;
 }
}while(fireDetected == false);




 /*x = 1;
 Serial.print("x transmitted = ");
 Serial.print(x);
 Wire.beginTransmission(2);
 Wire.write("x is ");
 Wire.write(x);
 Wire.endTransmission();
 delay(1000); //this should be the time it takes to drive to oil rig #1
 x = 0;       //stop in front of oil rig
 Serial.print("x transmitted = ");
 Serial.print(x);
 Wire.beginTransmission(2);
 Wire.write("x is ");
 Wire.write(x);
 Wire.endTransmission();
 
 //check oil rig #1
 distanceT = pingTop();
 Serial.print("Top ping sensor = ");
 Serial.println(distanceT);
 delay(1000);
 if(distanceT < fire)
 {
   //save this oil rig as target and drive to tools to pick up corresponding tool
   //oil rig = square rig
 }
 else
 {
   //move on to check next oil rig
    x = 1;
   Serial.print("x transmitted = ");
   Serial.print(x);
   Wire.beginTransmission(2);
   Wire.write("x is ");
   Wire.write(x);
   Wire.endTransmission();
   delay(1000); //this should be the time it takes to drive to oil rig #2
   x = 0;       //stop in front of oil rig
   Serial.print("x transmitted = ");
   Serial.print(x);
   Wire.beginTransmission(2);
   Wire.write("x is ");
   Wire.write(x);
   Wire.endTransmission();
 
   //check oil rig #2
   distanceT = pingTop();
   Serial.print("Top ping sensor = ");
   Serial.println(distanceT);
   delay(1000);
   if(distanceT < fire)
   {
     //save this oil rig as target and drive to tools to pick up corresponding tool
     //oil rig = triangle rig
   }
   else
   {
     //move on to check next oil rig
      x = 1;
      Serial.print("x transmitted = ");
      Serial.print(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
      delay(1000); //this should be the time it takes to drive to oil rig #3
      x = 0;       //stop in front of oil rig
      Serial.print("x transmitted = ");
      Serial.print(x);
      Wire.beginTransmission(2);
      Wire.write("x is ");
      Wire.write(x);
      Wire.endTransmission();
 
      //check oil rig #3
      distanceT = pingTop();
      Serial.print("Top ping sensor = ");
      Serial.println(distanceT);
      delay(1000);
      if(distanceT < fire)
      {
        //save this oil rig as target and drive to tools to pick up corresponding tool
        //oil rig = circle rig
      }
      else
      {
        //reverse back to starting position
      }
   }
 }*/


