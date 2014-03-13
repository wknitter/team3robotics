int val1, val2, val3, val4, val5, val6, val7, val8, val9, val10, val11, val12, val13, val14, val15, val16 = 0;
int sum;
int count;
int total = 0;
//int temp;
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
  
  
  
/*if (val2 < 3)
{
  //Serial.print("temp = ");
  //Serial.println(temp);
  //val = 0;
  //val2 = 0;
  //temp = 0;
}
else
{
  val2 = val2 + 1;
  Serial.println("else part");
}*/

do
{
digitalWrite(ledPin1, LOW); // sets the LED on
digitalWrite(ledPin2, LOW); // sets the LED on
digitalWrite(ledPin3, LOW); // sets the LED on
digitalWrite(ledPin4, LOW); // sets the LED on
val1 = analogRead(0); // read analog input pin 0
//Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, LOW); // sets the LED on
 digitalWrite(ledPin2, LOW); // sets the LED on
 digitalWrite(ledPin3, LOW); // sets the LED on
 digitalWrite(ledPin4, HIGH); // sets the LED on
val2 = analogRead(0); // read analog input pin 0
//Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, LOW); // sets the LED on
 digitalWrite(ledPin2, LOW); // sets the LED on
 digitalWrite(ledPin3, HIGH); // sets the LED on
 digitalWrite(ledPin4, LOW); // sets the LED on
 val3 = analogRead(0); // read analog input pin 0
//Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, LOW); // sets the LED on
 digitalWrite(ledPin2, LOW); // sets the LED on
 digitalWrite(ledPin3, HIGH); // sets the LED on
 digitalWrite(ledPin4, HIGH); // sets the LED on
 val4 = analogRead(0); // read analog input pin 0
//Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, LOW); // sets the LED on
 digitalWrite(ledPin2, HIGH); // sets the LED on
 digitalWrite(ledPin3, LOW); // sets the LED on
 digitalWrite(ledPin4, LOW); // sets the LED on
 val5 = analogRead(0); // read analog input pin 0
//Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, LOW); // sets the LED on
 digitalWrite(ledPin2, HIGH); // sets the LED on
 digitalWrite(ledPin3, LOW); // sets the LED on
 digitalWrite(ledPin4, HIGH); //sets the LED on 
  val6 = analogRead(0); // read analog input pin 0
//Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, LOW); // sets the LED on
 digitalWrite(ledPin2, HIGH); // sets the LED on
 digitalWrite(ledPin3, HIGH); // sets the LED on
 digitalWrite(ledPin4, LOW); // sets the LED on
 val7 = analogRead(0); // read analog input pin 0
//Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, LOW); // sets the LED on
 digitalWrite(ledPin2, HIGH); // sets the LED on
 digitalWrite(ledPin3, HIGH); // sets the LED on
 digitalWrite(ledPin4, HIGH); // sets the LED on
 val8 = analogRead(0); // read analog input pin 0
//Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, HIGH); // sets the LED on
 digitalWrite(ledPin2, LOW); // sets the LED on//
 digitalWrite(ledPin3, LOW); // sets the LED on
 digitalWrite(ledPin4, LOW); // sets the LED on
 val9 = analogRead(0); // read analog input pin 0
//Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read
 
 digitalWrite(ledPin1, HIGH); // sets the LED on
 digitalWrite(ledPin2, LOW); // sets the LED on
 digitalWrite(ledPin3, LOW); // sets the LED on
 digitalWrite(ledPin4, HIGH); // sets the LED on
 val10 = analogRead(0); // read analog input pin 0
//Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, HIGH); // sets the LED on
 digitalWrite(ledPin2, LOW); // sets the LED on
 digitalWrite(ledPin3, HIGH); // sets the LED on
 digitalWrite(ledPin4, LOW); // sets the LED on
 val11 = analogRead(0); // read analog input pin 0
//Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, HIGH); // sets the LED on
 digitalWrite(ledPin2, LOW); // sets the LED on
 digitalWrite(ledPin3, HIGH); // sets the LED on
 digitalWrite(ledPin4, HIGH); // sets the LED on
val12 = analogRead(0); // read analog input pin 0
//Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, HIGH); // sets the LED on
 digitalWrite(ledPin2, HIGH); // sets the LED on
 digitalWrite(ledPin3, LOW); // sets the LED on
 digitalWrite(ledPin4, LOW); // sets the LED on
 val13 = analogRead(0); // read analog input pin 0
//Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, HIGH); // sets the LED on
 digitalWrite(ledPin2, HIGH); // sets the LED on
 digitalWrite(ledPin3, LOW); // sets the LED on
 digitalWrite(ledPin4, HIGH); // sets the LED on
 val14 = analogRead(0); // read analog input pin 0
//Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

 digitalWrite(ledPin1, HIGH); // sets the LED on
 digitalWrite(ledPin2, HIGH); // sets the LED on
 digitalWrite(ledPin3, HIGH); // sets the LED on
 digitalWrite(ledPin4, LOW); // sets the LED on
 val15 = analogRead(0); // read analog input pin 0
//Serial.println(val); // prints the value read
//delay(10); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read

digitalWrite(ledPin1, HIGH); // sets the LED on
digitalWrite(ledPin2, HIGH); // sets the LED on
digitalWrite(ledPin3, HIGH); // sets the LED on
digitalWrite(ledPin4, HIGH); // sets the LED on
val16 = analogRead(0); // read analog input pin 0
//delay(500);
//Serial.println(val); // prints the value read
//temp = (temp + val)/val2;
sum = (val1 + val2 + val3 + val4 + val5 + val6 + val7 + val8 + val9 + val10 + val11 + val12 + val13 + val14 + val15 + val16)/16;
//Serial.print("sum = ");
//Serial.println(sum);
count = count + 1;
total = total + sum;
//delay(500); // wait 1s for next reading
//Serial.print(" _ "); // prints the value read
} while (count < 100);

total = total/count;
Serial.print("total = ");
Serial.println(total);
delay(1000);
total = 0;
count = 0;
sum = 0;
val1, val2, val3, val4, val5, val6, val7, val8, val9, val10, val11, val12, val13, val14, val15, val16 = 0;

} 

//val = analogRead(0); // read analog input pin 0
//Serial.print(val); // prints the value read
//Serial.print(" 1 "); // prints a space between the numbers
//delay(100); // wait 1s for next reading
//val2 = analogRead(1); // read analog input pin 0
//Serial.print(val2); // prints the value read
//Serial.print(" 2 "); // prints a space between the numbers
