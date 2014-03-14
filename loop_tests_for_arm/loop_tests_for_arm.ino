#include <AFMotor.h>

AF_DCMotor motor2(2);

int potPin2 = 1;
int val2 = 0;

void setup()
{
  Serial.begin(9600);
  motor2.setSpeed(100);
  motor2.run(RELEASE);
}

void loop()
{
  //do while loop test
  /*
  val2 = analogRead(potPin2);
  do
  {
    val2 = analogRead(potPin2);
    motor2.run(BACKWARD); //down
    val2 = analogRead(potPin2);
  } while (val2 > 350);   //305
  motor2.run(FORWARD);
  motor2.run(RELEASE);
  */
  
  //while loop test
  /*
  val2 = analogRead(potPin2);
  while(val2 > 400)       //305
  {
    motor2.run(BACKWARD);  //down
    val2 = analogRead(potPin2);
  }
  motor2.run(FORWARD);
  motor2.run(RELEASE);
  */
  
  
  val2 = analogRead(potPin2);
  do
  {
    val2 = analogRead(potPin2);
    motor2.run(FORWARD); //up
    val2 = analogRead(potPin2);
  } while (val2 < 590);   //609
  motor2.run(BACKWARD);
  motor2.run(RELEASE);
  
}
