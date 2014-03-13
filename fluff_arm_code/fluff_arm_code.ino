//turn left
  x = 3;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(680);
  
  //move forward slightly to next tool
  x = 1;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(200);
  
  //turn right back toward tool
  x = 4;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(680);

do
{
  //scan tool
  do
  {
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val1 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val2 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val3 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val4 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val5 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); //sets the LED on 
    val6 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val7 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val8 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on//
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val9 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val10 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val11 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val12 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val13 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val14 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val15 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val16 = analogRead(0); // read analog input pin 0
    
    sum = (val1 + val2 + val3 + val4 + val5 + val6 + val7 + val8 + val9 + val10 + val11 + val12 + val13 + val14 + val15 + val16)/16;
    count = count + 1;
    total = total + sum;
  } while (count < 100);
  
  total = total/count;
  if (total > 57 && total < 70)
  {
    //triangle
    digitalWrite(led2Pin, HIGH);
    delay(2000);
    digitalWrite(led2Pin, LOW);
    tool = 3;
  }
  else if (total > 46 && total < 57)
  {
    //circle
    digitalWrite(led3Pin, HIGH);
    delay(2000);
    digitalWrite(led3Pin, LOW);
    tool = 2;
  }
  else if (total > 30 && total < 46)
  {
    //square
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
    tool = 1;
  }
  else
  {
    //nothing
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(ledPin, LOW);
  }
  
  //turn right
  x = 4;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(680);
  
  //move forward slightly to next tool
  x = 1;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(200);
  
  //turn left back toward tool
  x = 3;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(680);
  
} while (tool != fire);

/*
//scan tool
  do
  {
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val1 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val2 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val3 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val4 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val5 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); //sets the LED on 
    val6 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val7 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val8 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on//
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val9 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val10 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val11 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val12 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val13 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val14 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val15 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val16 = analogRead(0); // read analog input pin 0
    
    sum = (val1 + val2 + val3 + val4 + val5 + val6 + val7 + val8 + val9 + val10 + val11 + val12 + val13 + val14 + val15 + val16)/16;
    count = count + 1;
    total = total + sum;
  } while (count < 100);
  
  total = total/count;
  if (total > 57 && total < 70)
  {
    //triangle
    digitalWrite(led2Pin, HIGH);
    delay(2000);
    digitalWrite(led2Pin, LOW);
    tool = 3;
  }
  else if (total > 46 && total < 57)
  {
    //circle
    digitalWrite(led3Pin, HIGH);
    delay(2000);
    digitalWrite(led3Pin, LOW);
    tool = 2;
  }
  else if (total > 30 && total < 46)
  {
    //square
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
    tool = 1;
  }
  else
  {
    //nothing
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(ledPin, LOW);
  }
  
  //turn right
  x = 4;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(680);
  
  //move forward slightly to next tool
  x = 1;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(200);
  
  //turn left back toward tool
  x = 3;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(680);
  
  //scan tool
  do
  {
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val1 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val2 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val3 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val4 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val5 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); //sets the LED on 
    val6 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val7 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val8 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on//
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val9 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val10 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val11 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val12 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val13 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val14 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val15 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val16 = analogRead(0); // read analog input pin 0
    
    sum = (val1 + val2 + val3 + val4 + val5 + val6 + val7 + val8 + val9 + val10 + val11 + val12 + val13 + val14 + val15 + val16)/16;
    count = count + 1;
    total = total + sum;
  } while (count < 100);
  
  total = total/count;
  if (total > 57 && total < 70)
  {
    //triangle
    digitalWrite(led2Pin, HIGH);
    delay(2000);
    digitalWrite(led2Pin, LOW);
    tool = 3;
  }
  else if (total > 46 && total < 57)
  {
    //circle
    digitalWrite(led3Pin, HIGH);
    delay(2000);
    digitalWrite(led3Pin, LOW);
    tool = 2;
  }
  else if (total > 30 && total < 46)
  {
    //square
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
    tool = 1;
  }
  else
  {
    //nothing
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(ledPin, LOW);
  }
  
  //turn left
  x = 3;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(680);
  
  //drive forward to tool on far left
  x = 1;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(400); //twice as long because twice the distance
  
  //turn right to face tool
  x = 4;
  Serial.print("x transmitted = ");
  Serial.println(x);
  Wire.beginTransmission(2);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  delay(680);
  
  //scan tool
  do
  {
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val1 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val2 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val3 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val4 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val5 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); //sets the LED on 
    val6 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val7 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, LOW); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val8 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on//
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val9 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val10 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val11 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, LOW); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val12 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val13 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, LOW); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val14 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, LOW); // sets the LED on
    val15 = analogRead(0); // read analog input pin 0
    
    digitalWrite(ledPin1, HIGH); // sets the LED on
    digitalWrite(ledPin2, HIGH); // sets the LED on
    digitalWrite(ledPin3, HIGH); // sets the LED on
    digitalWrite(ledPin4, HIGH); // sets the LED on
    val16 = analogRead(0); // read analog input pin 0
    
    sum = (val1 + val2 + val3 + val4 + val5 + val6 + val7 + val8 + val9 + val10 + val11 + val12 + val13 + val14 + val15 + val16)/16;
    count = count + 1;
    total = total + sum;
  } while (count < 100);
  
  total = total/count;
  if (total > 57 && total < 70)
  {
    //triangle
    digitalWrite(led2Pin, HIGH);
    delay(2000);
    digitalWrite(led2Pin, LOW);
    tool = 3;
  }
  else if (total > 46 && total < 57)
  {
    //circle
    digitalWrite(led3Pin, HIGH);
    delay(2000);
    digitalWrite(led3Pin, LOW);
    tool = 2;
  }
  else if (total > 30 && total < 46)
  {
    //square
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
    tool = 1;
  }
  else
  {
    //nothing
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(ledPin, LOW);
  }
*/
