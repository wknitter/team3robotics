int val;
int val2;
int temp;
int ledPin4 = 36; // LED connected to digital pin 13
int ledPin3 = 34; // LED connected to digital pin 13
int ledPin2 = 32; // LED connected to digital pin 13
int ledPin1 = 30; // LED connected to digital pin 13

void setup()
{
Serial.begin(9600); // sets the serial port to 9600
pinMode(ledPin1, OUTPUT); // sets the digital pin as output
pinMode(ledPin2, OUTPUT); // sets the digital pin as output
pinMode(ledPin3, OUTPUT); // sets the digital pin as output
pinMode(ledPin4, OUTPUT); // sets the digital pin as output


}
void loop()
{
  
  
  
if (val2 < 3)
{
  Serial.println(temp);
  val = 0;
  val2 = 0;
  temp = 0;
}
else
{
  val2 = val2 + 1;
}


digitalWrite(ledPin1, LOW); // sets the LED on
digitalWrite(ledPin2, LOW); // sets the LED on
digitalWrite(ledPin3, LOW); // sets the LED on
digitalWrite(ledPin4, LOW); // sets the LED on
val = val + analogRead(0); // read analog input pin 0
Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, LOW); // sets the LED on
 digitalWrite(ledPin2, LOW); // sets the LED on
 digitalWrite(ledPin3, LOW); // sets the LED on
 digitalWrite(ledPin4, HIGH); // sets the LED on
 val = val + analogRead(0); // read analog input pin 0
Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, LOW); // sets the LED on
 digitalWrite(ledPin2, LOW); // sets the LED on
 digitalWrite(ledPin3, HIGH); // sets the LED on
 digitalWrite(ledPin4, LOW); // sets the LED on
 val = val + analogRead(0); // read analog input pin 0
Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, LOW); // sets the LED on
 digitalWrite(ledPin2, LOW); // sets the LED on
 digitalWrite(ledPin3, HIGH); // sets the LED on
 digitalWrite(ledPin4, HIGH); // sets the LED on
 val = val + analogRead(0); // read analog input pin 0
Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, LOW); // sets the LED on
 digitalWrite(ledPin2, HIGH); // sets the LED on
 digitalWrite(ledPin3, LOW); // sets the LED on
 digitalWrite(ledPin4, LOW); // sets the LED on
 val = val + analogRead(0); // read analog input pin 0
Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, LOW); // sets the LED on
 digitalWrite(ledPin2, HIGH); // sets the LED on
 digitalWrite(ledPin3, LOW); // sets the LED on
 digitalWrite(ledPin4, HIGH); //sets the LED on 
  val = val + analogRead(0); // read analog input pin 0
Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, LOW); // sets the LED on
 digitalWrite(ledPin2, HIGH); // sets the LED on
 digitalWrite(ledPin3, HIGH); // sets the LED on
 digitalWrite(ledPin4, LOW); // sets the LED on
 val = val + analogRead(0); // read analog input pin 0
Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, LOW); // sets the LED on
 digitalWrite(ledPin2, HIGH); // sets the LED on
 digitalWrite(ledPin3, HIGH); // sets the LED on
 digitalWrite(ledPin4, HIGH); // sets the LED on
 val = val + analogRead(0); // read analog input pin 0
Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, HIGH); // sets the LED on
 digitalWrite(ledPin2, LOW); // sets the LED on//
 digitalWrite(ledPin3, LOW); // sets the LED on
 digitalWrite(ledPin4, LOW); // sets the LED on
 val = val + analogRead(0); // read analog input pin 0
Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read
 
 digitalWrite(ledPin1, HIGH); // sets the LED on
 digitalWrite(ledPin2, LOW); // sets the LED on
 digitalWrite(ledPin3, LOW); // sets the LED on
 digitalWrite(ledPin4, HIGH); // sets the LED on
 val = val + analogRead(0); // read analog input pin 0
Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, HIGH); // sets the LED on
 digitalWrite(ledPin2, LOW); // sets the LED on
 digitalWrite(ledPin3, HIGH); // sets the LED on
 digitalWrite(ledPin4, LOW); // sets the LED on
 val = val + analogRead(0); // read analog input pin 0
Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, HIGH); // sets the LED on
 digitalWrite(ledPin2, LOW); // sets the LED on
 digitalWrite(ledPin3, HIGH); // sets the LED on
 digitalWrite(ledPin4, HIGH); // sets the LED on
val = val + analogRead(0); // read analog input pin 0
Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, HIGH); // sets the LED on
 digitalWrite(ledPin2, HIGH); // sets the LED on
 digitalWrite(ledPin3, LOW); // sets the LED on
 digitalWrite(ledPin4, LOW); // sets the LED on
 val = val + analogRead(0); // read analog input pin 0
Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, HIGH); // sets the LED on
 digitalWrite(ledPin2, HIGH); // sets the LED on
 digitalWrite(ledPin3, LOW); // sets the LED on
 digitalWrite(ledPin4, HIGH); // sets the LED on
 val = val + analogRead(0); // read analog input pin 0
Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, HIGH); // sets the LED on
 digitalWrite(ledPin2, HIGH); // sets the LED on
 digitalWrite(ledPin3, HIGH); // sets the LED on
 digitalWrite(ledPin4, LOW); // sets the LED on
 val = val + analogRead(0); // read analog input pin 0
Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

digitalWrite(ledPin1, HIGH); // sets the LED on
digitalWrite(ledPin2, HIGH); // sets the LED on
digitalWrite(ledPin3, HIGH); // sets the LED on
digitalWrite(ledPin4, HIGH); // sets the LED on
val = val + analogRead(0); // read analog input pin 0
//delay(500);
Serial.println(val); // prints the value read
temp = (temp + val)/val2;
delay(2000); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

} 

//val = analogRead(0); // read analog input pin 0
//Serial.print(val); // prints the value read
//Serial.print(" 1 "); // prints a space between the numbers
//delay(100); // wait 1s for next reading
//val2 = analogRead(1); // read analog input pin 0
//Serial.print(val2); // prints the value read
//Serial.print(" 2 "); // prints a space between the numbers
