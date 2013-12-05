#include <Wire.h>
#include <AFMotor.h>
//MOTOR12_64KHZ
//MOTOR12_8KHZ
//MOTOR12_2KHZ
//MOTOR12_1KHZ

//MOTOR34_64KHZ
//MOTOR34_8KHZ
//MOTOR34_1KHZ

/*motor on ch 1 with default PWM of 1kHz
  AF_DCMotor motor1(1);
  
  define motor on channel 1 with 64kHz PWM 
  AF_DCMotor left_motor(1, MOTOR12_64KHZ);*/

/*motors are numbered 1-4 from top to bottom 
  4 being the bottom base motor
  1 being the top motor that controls the claws*/

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

//pot pin and val numbers match motor numbers
//brown wire = signal
//red wire = 5V
//green wire = ground 
//dial all the way to red wire side = 1023
//dial all the way to green wire side = 0
int potPin1 = 0;
int potPin2 = 1;
int potPin3 = 2;
int potPin4 = 3;

int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;

void setup()
{
 Serial.begin(9600);
 //Wire.begin(4); //slave join i2c bus with address #4
 //Wire.onReceive(func); //func to be called when slave receives data
 
 //turn motors on and let coast
 motor1.setSpeed(100);
 motor2.setSpeed(100);
 motor3.setSpeed(200);
 motor4.setSpeed(150);
 motor1.run(RELEASE);
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE); 
}

void loop()
{
  uint8_t i;
 
 //pot1();
 //motor1.run(FORWARD); //close claw
 //delay(500);
 //motor1.run(BACKWARD); //open claw
 //delay(500);
 
 
 //motor2.run(FORWARD); //up fully up=610 --->flush=461
 //delay(500);
 //motor2.run(BACKWARD); //down fully down=300
 //delay(500);
 //motor2.run(RELEASE);
 //delay(3000);
 //pot2();

 //motor3.run(FORWARD); //down ---->lowest while motor4 is pointed straight up is 457/458
 //delay(500);
 //motor3.run(BACKWARD); //up --->highest it needs to go up is 22/23
 //delay(500);
 //motor3.run(RELEASE);
 //delay(3000);
 //pot3();

 motor4.run(FORWARD); //back into robot ---->691 is folded all the way back
 delay(500);
 //motor4.run(BACKWARD); //forward away from robot
 //delay(500);
 motor4.run(RELEASE);
 delay(3000);
 pot4();
}
  
void pot1()
{
  //fully closed claw = 3;
  //fully open claw = 370;
  val1 = analogRead(potPin1);
  Serial.println(val1);
  //delay(1000); 
  if(val1 >= 0 && val1 < 15) //if fully closed
 {
   motor1.run(BACKWARD); //open claw
   delay(100);
 }
 else if(val1 < 387 && val1 > 16) //if fully open
 {
   motor1.run(FORWARD); //close claw
   delay(100);
 }
 else
 {
   motor1.run(RELEASE); //stop
   delay(100);
 }
  
}

void pot2()
{
  val2 = analogRead(potPin2);
  Serial.println(val2);
  delay(1000);  
}

void pot3()
{
  val3 = analogRead(potPin3);
  Serial.println(val3);
  delay(1000);  
}

void pot4()
{
  val4 = analogRead(potPin4);
  Serial.println(val4);
  delay(1000);  
}
