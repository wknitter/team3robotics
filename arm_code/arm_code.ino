//code for L293D board
#include <AFMotor.h>
//MOTOR12_64KHZ
//MOTOR12_8KHZ
//MOTOR12_2KHZ
//MOTOR12_1KHZ

//MOTOR34_64KHZ
//MOTOR34_8KHZ
//MOTOR34_1KHZ

//motors are numbered 1-4 from top to bottom 
//4 being the bottom base motor
//1 being the top motor that controls the claws

AF_DCMotor motor1(1); //motor on ch 1 with default PWM of 1kHz
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

//AF_DCMotor left_motor(1, MOTOR12_64KHZ); //define motor on channel 1 with 64kHz PWM 

void setup()
{
 Serial.begin(9600);
 
 //turn motor on and let coast
 motor1.setSpeed(200);
 motor2.setSpeed(200);
 motor3.setSpeed(200);
 motor4.setSpeed(200);
 motor1.run(RELEASE);
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE); 
}

void loop()
{
 uint8_t i;
 
 //Serial.print("forward");

 //motor1.run(FORWARD);
 //delay(500);
 
 /*for(i=0; i<255; i++)  //acceleration
 {
   motor1.setSpeed(i);
   delay(10);
 }

 for(i=255; i!=0;i--) //decceleration
 {
   motor1.setSpeed(i);
   delay(10);
 }

 Serial.print("backward");*/

 //motor1.run(BACKWARD);
 //delay(500);
 
 /*for(i=0; i<255; i++)
 {
   motor1.setSpeed(i);
   delay(10);
 }

 Serial.print("done");
 motor1.run(RELEASE);
 delay(500);*/
 
 motor1.run(FORWARD); //close claw
 delay(500);
 motor1.run(BACKWARD); //open claw
 delay(500);
 
 motor2.run(FORWARD); //down
 delay(500);
 motor2.run(BACKWARD); //up
 delay(500);

 motor3.run(FORWARD); //up
 delay(500);
 motor3.run(BACKWARD); //down
 delay(500);

 motor4.run(FORWARD); //forward
 delay(500);
 motor4.run(BACKWARD); //backward
 delay(500); 
}
