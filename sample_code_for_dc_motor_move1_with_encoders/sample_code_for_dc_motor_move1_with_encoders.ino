volatile int rotaryCount = 0;

#define PINA 8
#define PINB 9
#define INTERRUPT 0  // that is, pin 2

#define DIRECTIONA 4
#define MOTORA 5

#define DIRECTIONB 7
#define MOTORB 6

#define TIME_FORWARDS 10000
#define TIME_BACKWARDS 10000
#define TIME_TURN 1200

// Interrupt Service Routine for a change to encoder pin A
void isr ()
{
  boolean up;

  if (digitalRead (PINA))
    up = digitalRead (PINB);
  else
    up = !digitalRead (PINB);

  if (up)
    rotaryCount++;
  else
    rotaryCount--;
}  // end of isr


void setup ()
{
  attachInterrupt (INTERRUPT, isr, CHANGE);   // interrupt 0 is pin 2, interrupt 1 is pin 3
  pinMode (MOTORA, OUTPUT);
  pinMode (DIRECTIONA, OUTPUT);
  pinMode (MOTORB, OUTPUT);
  pinMode (DIRECTIONB, OUTPUT);

}  // end of setup

byte phase;
unsigned long start;
int drive_time;

void loop ()
{

  analogWrite (MOTORA, 200);
  analogWrite (MOTORB, 200);
  start = millis ();
  
  // check current drain
  while (millis () - start < drive_time)
    {
    if (analogRead (0) > 325)  // > 1.46 amps
      break;    
    }
    
  
  switch (phase++ & 3)
    {
    case 0: 
      digitalWrite (DIRECTIONA, 1); 
      digitalWrite (DIRECTIONB, 1); 
      drive_time = TIME_FORWARDS;
      break;
      
    case 1: 
      // turn
      digitalWrite (DIRECTIONA, 1); 
      digitalWrite (DIRECTIONB, 0); 
      drive_time = TIME_TURN;
      break;

    case 2: 
      digitalWrite (DIRECTIONA, 0); 
      digitalWrite (DIRECTIONB, 0); 
      drive_time = TIME_BACKWARDS;
      break;

    case 3: 
      digitalWrite (DIRECTIONA, 0); 
      digitalWrite (DIRECTIONB, 1); 
      drive_time = TIME_TURN;
      break;
      
    } // end of switch
    
  analogWrite (MOTORA, 0);
  analogWrite (MOTORB, 0);
  delay (500);
  
}  // end of loop
