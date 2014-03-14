/////////////////////////////////////////////////////////////////
// Photo Transistor Array Program
// Zack Boatwright
//
//This program will take a reading from each phototransistor one
// at a time until it has added all of the values. Once it has
// added them it checks to see which tool it is. The program can
// be modified by changing the initialized variables to new pins.
// It can also be modified to adjust for tool values.
//
/////////////////////////////////////////////////////////////////

//Initialize val for adding the phototransistor values
int val;
//Photo1 through Photo4 are for looping through Multiplexer
int Photo4 = 30;
int Photo3 = 33;
int Photo2 = 34;
int Photo1 = 36;
//Led for MVR
int ledTriangle = 43;
int ledCircle = 41;
int ledRectangle = 42;

void setup()
{
Serial.begin(9600); // sets the serial port to 9600
pinMode(Photo1, OUTPUT); // sets the digital pin as output
pinMode(Photo2, OUTPUT); // sets the digital pin as output
pinMode(Photo3, OUTPUT); // sets the digital pin as output
pinMode(Photo4, OUTPUT); // sets the digital pin as output

pinMode(ledTriangle, OUTPUT); // sets the digital pin as output
pinMode(ledCircle, OUTPUT); // sets the digital pin as output
pinMode(ledRectangle, OUTPUT); // sets the digital pin as output

}
void loop()
{


val = 0;
Serial.println("loop");
//Read Photo Diode 1
digitalWrite(Photo1, LOW);
digitalWrite(Photo2, LOW);
digitalWrite(Photo3, LOW);
digitalWrite(Photo4, LOW);
delay(10); // wait 1s for next reading
val = analogRead(0);

//Read Photo Diode 2 
digitalWrite(Photo1, LOW);
digitalWrite(Photo2, LOW);
digitalWrite(Photo3, LOW);
digitalWrite(Photo4, HIGH);
delay(10); // wait 1s for next reading
val = val + analogRead(0);

//Read Photo Diode 3
digitalWrite(Photo1, LOW);
digitalWrite(Photo2, LOW);
digitalWrite(Photo3, HIGH);
digitalWrite(Photo4, LOW);
delay(10); // wait 1s for next reading
val = val + analogRead(0);

//Read Photo Diode 4
digitalWrite(Photo1, LOW);
digitalWrite(Photo2, LOW);
digitalWrite(Photo3, HIGH);
digitalWrite(Photo4, HIGH);
delay(10); // wait 1s for next reading
val = val + analogRead(0);

//Read Photo Diode 5
digitalWrite(Photo1, LOW);
digitalWrite(Photo2, HIGH);
digitalWrite(Photo3, LOW);
digitalWrite(Photo4, LOW);
delay(10); // wait 1s for next reading
val = val + analogRead(0);

//Read Photo Diode 6
digitalWrite(Photo1, LOW);
digitalWrite(Photo2, HIGH);
digitalWrite(Photo3, LOW);
digitalWrite(Photo4, HIGH);
delay(10); // wait 1s for next reading
val = val + analogRead(0);

//Read Photo Diode 7 
digitalWrite(Photo1, LOW);
digitalWrite(Photo2, HIGH);
digitalWrite(Photo3, HIGH);
digitalWrite(Photo4, LOW);
delay(10); // wait 1s for next reading
val = val + analogRead(0);

//Read Photo Diode 8 
digitalWrite(Photo1, LOW);
digitalWrite(Photo2, HIGH);
digitalWrite(Photo3, HIGH);
digitalWrite(Photo4, HIGH);
delay(10); // wait 1s for next reading
val = val + analogRead(0);

//Read Photo Diode 9
digitalWrite(Photo1, HIGH);
digitalWrite(Photo2, LOW);
digitalWrite(Photo3, LOW);
digitalWrite(Photo4, LOW);
delay(10); // wait 1s for next reading
val = val + analogRead(0);

//Read Photo Diode 10 
digitalWrite(Photo1, HIGH);
digitalWrite(Photo2, LOW);
digitalWrite(Photo3, LOW);
digitalWrite(Photo4, HIGH);
delay(10); // wait 1s for next reading
val = val + analogRead(0);

//Read Photo Diode 11
digitalWrite(Photo1, HIGH);
digitalWrite(Photo2, LOW);
digitalWrite(Photo3, HIGH);
digitalWrite(Photo4, LOW);
delay(10); // wait 1s for next reading
val = val + analogRead(0); 

//Read Photo Diode 12
digitalWrite(Photo1, HIGH);
digitalWrite(Photo2, LOW);
digitalWrite(Photo3, HIGH);
digitalWrite(Photo4, HIGH);
delay(10); // wait 1s for next reading
val = val + analogRead(0);

//Read Photo Diode 13 
digitalWrite(Photo1, HIGH);
digitalWrite(Photo2, HIGH);
digitalWrite(Photo3, LOW);
digitalWrite(Photo4, LOW);
delay(10); // wait 1s for next reading
val = val + analogRead(0);

//Read Photo Diode 14 
digitalWrite(Photo1, HIGH);
digitalWrite(Photo2, HIGH);
digitalWrite(Photo3, LOW);
digitalWrite(Photo4, HIGH);
delay(10); // wait 1s for next reading
val = val + analogRead(0);

//Read Photo Diode 15 
digitalWrite(Photo1, HIGH);
digitalWrite(Photo2, HIGH);
digitalWrite(Photo3, HIGH);
digitalWrite(Photo4, LOW);
delay(10); // wait 1s for next reading
val = val + analogRead(0);

//Read Photo Diode 16 
digitalWrite(Photo1, HIGH);
digitalWrite(Photo2, HIGH);
digitalWrite(Photo3, HIGH);
digitalWrite(Photo4, HIGH);
delay(10); // wait 1s for next reading
val = val + analogRead(0);

//Code to see which tool it is: 

//Triangle Detection
if (val > 1400 && val < 3050) //val > 1400 && val < 3050
{
//Write a HIGH to the Triangle and LOWs for the Rectangle and Circle 
digitalWrite(ledTriangle, HIGH);
digitalWrite(ledRectangle, LOW);
digitalWrite(ledCircle, LOW);
delay(500);
}

//Circle Detecting
else if (val > 1400 && val < 3050) //val > 1400 && val < 3050
{
//Write a HIGH to the Circle and LOWs for the Rectangle and Triangle 
digitalWrite(ledTriangle, LOW);
digitalWrite(ledRectangle, LOW);
digitalWrite(ledCircle, HIGH);
delay(500);
}

//Rectangle Detection
else if (val > 1400 && val < 3050) //val > 1400 && val < 3050
{
//Write a HIGH to the Rectangle and LOWs for the Triangle and Circle 
digitalWrite(ledTriangle, LOW);
digitalWrite(ledRectangle, HIGH);
digitalWrite(ledCircle, LOW);
delay(500);
}

// if doesn't fit criteria lows to everything
else
{ 
digitalWrite(ledRectangle, LOW);
digitalWrite(ledCircle, LOW);
digitalWrite(ledTriangle, LOW);
}

digitalWrite(ledTriangle, LOW);
digitalWrite(ledRectangle, LOW);
digitalWrite(ledCircle, LOW);

Serial.println(val); // prints the value read from phototransistors
//delay(500); 
}
