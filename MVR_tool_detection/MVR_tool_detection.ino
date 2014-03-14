#include <Wire.h>
//set parameters
int pingRPin = 22;
int pingFPin = 23;
int pingLPin = 24;
int pingTPin = 25;
int ledPin = 42;  //square 
int led2Pin = 43; //triangle 
int led3Pin = 41; //circle 

int fire, tool, align = 0;
int i = 0;

int tooClose = 10; 
int durationR, durationF, durationL, forwardCm, leftCm, rightCm;
int durationT, topCm;
int distanceR, distanceF, distanceL, distanceT;
int x; //commands for driver slave
int y; //commands for arm slave
int wave = 30;
int rowCount = 0;
int waveCount = 0;
int delayw = 0; 
int delayf = 0;

int val1, val2, val3, val4, val5, val6, val7, val8, val9, val10, val11, val12, val13, val14, val15, val16 = 0;
int sum;
int count;
int total = 0;
int ledPin4 = 36; // LED connected to digital pin 13
int ledPin3 = 34; // LED connected to digital pin 13
int ledPin2 = 32; // LED connected to digital pin 13
int ledPin1 = 30; // LED connected to digital pin 13

//halt x = 0
//foward x = 1
//reverse x = 2
//leftTurn x = 3
//rightTurn x = 4
//turnAround x = 5
//arm startingPosition y = 6
//arm grabTool y = 7
//arm scanTool y = 8
//raise are for oil rig scan y = 9
//insert tool into rig = 10


void setup()
{
   Wire.begin(); //join bus as master
   Serial.begin(9600);
   pinMode(ledPin, OUTPUT);
   pinMode(led2Pin, OUTPUT);
   pinMode(led3Pin, OUTPUT);
   pinMode(ledPin1, OUTPUT); // sets the digital pin as output
   pinMode(ledPin2, OUTPUT); // sets the digital pin as output
   pinMode(ledPin3, OUTPUT); // sets the digital pin as output 
   pinMode(ledPin4, OUTPUT); // sets the digital pin as output
}

void loop()
{
y = 8; 
  Serial.print("y transmitted = ");
  Serial.println(y);
  Wire.beginTransmission(4);
  Wire.write("y is ");
  Wire.write(y);
  Wire.endTransmission();
  y = 8;
  Wire.beginTransmission(4);
  Wire.write(y);
  Wire.endTransmission();
  delay(2000); 
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
  if (total > 56 && total < 99) // >57 && <70
  {
    //triangle
    digitalWrite(led2Pin, HIGH);
    delay(2000);
    digitalWrite(led2Pin, LOW);
    tool = 3;
  }
  else if (total > 45 && total < 57) // >46 && <57
  {
    //circle
    digitalWrite(led3Pin, HIGH);
    delay(2000);
    digitalWrite(led3Pin, LOW);
    tool = 2;
  }
  else if (total > 20 && total < 46) // >30 && <46
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
}
