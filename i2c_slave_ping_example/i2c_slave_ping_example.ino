////////////////////////////////////////////////////////////////
// MASTER CODE this example, ping goes from slave to master
////////////////////////////////////////////////////////////////
Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop()
{
  Wire.requestFrom(2, 1);    // request 1 bytes from slave device #2

  while(Wire.available())    // slave may send less than requested
  { 
    char c = Wire.read(); // receive a byte as character
    Serial.print(c,DEC);
    Serial.print("\t");    // I tab the data so i can copy and import 
    //to labview and  see it on strip chart, wavegraph etc
  }

  delay(500);
}


////////////////////////////////////////////////////////////////
// SLAVE CODE
////////////////////////////////////////////////////////////////
#include <Wire.h>
const int pingPin = 7;

long duration, cm;

void setup()
{
  Wire.begin(2);                // join i2c bus with address #2
  Wire.onRequest(requestEvent); // register event
}

void loop()
{
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  noInterrupts ();
  cm = microsecondsToCentimeters(duration);
  interrupts ();
  delay(50);
}

long microsecondsToCentimeters(long microseconds)
{
  return (microseconds / 29 / 2);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent()
{
  Wire.write(cm); 
}
