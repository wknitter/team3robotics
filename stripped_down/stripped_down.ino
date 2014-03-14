//This is the fully stripped down version, 
//I think i removed everything that wasn't needed 
//I haven't had a chance to test it, If anybody finds
//a problem please let me know and I'll try to fix it.
//const int pingPin = 4;
int distin[9];
int durat[9];
int distcm[9];
int avg;
int delta;
int delta2;
int distcm7;

int stepcount = 0;
int walldist = 600;
int obst_delay = 500; 
int obst_count = 0;
int drive = 0;
int obst_delta = 0;
int corner_obst= 0;
int intersection = 0;

int side_delta;
int walldelta = 0;
int room_corner = 0;

void setup() {
  
  // initialize serial communication:
  Serial.begin(9600);

  delay(500);
  
}
void loop()
{
  stepcount = 0;
  corner_obst=0;
  ping();

  if ((distcm[3] <= 7) || (distcm[5] <= 7)){
    Serial.write(64);
    Serial.write(192);
    delay(500);
    disp_gen();
     ping();
     if((room == 1) && (distcm[7] >= 80)){
       //exited room 1 intersection = 0 turn off cam
       room_one_disable = 1;
       intersection = 0;
       room_corner = 0;
       digitalWrite(10,HIGH);
        delay(2000);
        digitalWrite(10,LOW);
        
    }
    if((room == 3) && (distcm[7] >=150) && (room_3_disable == 1)){
    //room 4
    digitalWrite(10,HIGH);
        delay(2000);
        digitalWrite(10,LOW);
        delay(2000);
        digitalWrite(10,HIGH);
        delay(2000);
        digitalWrite(10,LOW);
         delay(2000);
        digitalWrite(10,HIGH);
        delay(2000);
        digitalWrite(10,LOW);
        delay(2000);
        digitalWrite(10,HIGH);
        delay(2000);
        digitalWrite(10,LOW);
    }
    Serial.write(96); 
    Serial.write(160);
    delay(500);//find time for 90deg turn
    Serial.write(64); 
    Serial.write(192);
  //  delay(10);
   
    //    Serial.write(32); 
    //    Serial.write(160);
    ping();
    if (distcm[4] >= 20){
      obsticle();
    }
 
    obst_count = 0;
  }
  else{ 

    if((distcm[4] >= 15) && (distcm[3] >= 15) && (distcm[2] >= 15))//&& counter = 0
    {
doagain:
      counter = 1;
      walldelta = 0;
      Serial.write(64);
      Serial.write(192);
      delay(1000);
      if(distcm[6] <= 15){
        do{
          Serial.write(42);//
          Serial.write(168);//
          delay(30);
          Serial.write(64);
          Serial.write(192);
          stepcount++;
          ping();
        } 
        while (distcm[6] < 15);
      }
      
      if (stepcount > 15){
        walldist = 1200;
        obst_delay = 800;
        // delta = abs(durat[3] - durat[5]);
        Serial.write(42);
        Serial.write(168);
        delay(180);//120
        
      }
      else{
        // delta = abs(durat[4] - durat[6]);
        Serial.write(42);
        Serial.write(168);
        delay(220);
//        if(room == 1){ 
//       Serial.write(42);
//       Serial.write(168);
//       delay(180);
//       
  //      }
        //delay();//170//190//220
        
      }
      if(corner_obst >= 1 ){
        Serial.write(42);
        Serial.write(168);
        delay(170);
      }
      //delay(2000);
      Serial.write(64);
      Serial.write(192);
      delay(500);
      ping();
      
      Serial.write(42); 
      Serial.write (210);
      delay(500);
      //decrease speed on left motor
      Serial.write(64); 
      Serial.write(192);
      do{ 
        Serial.write(42); 
        Serial.write(210);
        delay(60);
        //decrease speed on left motor
        Serial.write(64); 
        Serial.write(192);

        ping();

  
        delta = abs(durat[3]- durat[5]);

       
      } 
      while (delta >= 80);
      if (corner_obst == 1){
        do{
          Serial.write(42);//
          Serial.write(168);//
          delay(30);
          Serial.write(64);
          Serial.write(192);
          //stepcount++;
          ping();
        } 
        while (distcm[3] > 7);
        goto exit;

      }
do{
          Serial.write(42);//
          Serial.write(168);//
          delay(30);
          Serial.write(64);
          Serial.write(192);
          ping();
} while(distcm[4] > 15);
      Serial.write(42);//42
      Serial.write(175);//168
      delay(obst_delay);
       intersection++;
      if(stepcount > 15){
        // stepcount = 0;
        corner_obst= 1;
        goto doagain;
      }
if(room == 1){
if(distcm[6] <= 15){
        do{
          Serial.write(42);//
          Serial.write(168);//
          delay(30);
          Serial.write(64);
          Serial.write(192);
          ping();
        } 
        while (distcm[6] < 15);
}
}
       squareup();
     
      //digitalWrite(13,HIGH);
      // delay(3000);
      //  digitalWrite(13,LOW);

exit:
      delay(50);
    }
    else {
      if ((durat[4] > 700) || (durat[4] < 350))
      {
        if (durat[4] < 350){
          Serial.write(50); //42
          Serial.write(140);//140
          delay(45);
          //decrease speed on right motor
          Serial.write(64); 
          Serial.write(192);
          //delay(50);
        }
        else{
          Serial.write(21);//21
          Serial.write(178);//168
          delay(45);
          //decrease speed on left motor
          Serial.write(64); 
          Serial.write(192);
          //delay(50);
        }
      }



      // else {
      //      avg = (durat[4]+durat[5])/2;
      //      delta = abs(durat[4]-durat[6]);
      // Serial.println(delta);
      if ((abs(durat[4] - durat[6]) <= 30) ){

        //    Serial.println(" Parallel with wall");  
        Serial.write(47); //42
        Serial.write(175);//168
        // delay(10);
      }

      else if(durat[4] < durat[6]){
        //     Serial.println("correct left");
        //increase speed to right motor
        Serial.write(47);//52
        Serial.write(148);//153
        delay(10);
        //decrease speed on right motor
        Serial.write(47); //52
        Serial.write(175);//178
        //  delay(10);
      }
      else {
        //        Serial.write(64);
        //        Serial.write(192);
        //        delay(1000);
        //        digitalWrite(13,HIGH);
        //        delay(500);
        //        digitalWrite(13,LOW);
        //        delay(500);
        //       Serial.println("correct right");
        // increase speed on left motor
        Serial.write(20); //25
        Serial.write(175);//170
        delay(10);
        //decrease speed on left motor
        Serial.write(47); //52
        Serial.write(175);//178
        //delay(10);
      }
      //}
    }
  }
  //}
}
void ping()
{
  for (int x = 2 ; x <= 7; x++)
  { 
    long duration, inches, cm;
    if(x == 7){//this was added in because pin 7 had a broken connection, 
    //the sensor was moved to pin 11 as a quick fix and never changed

      pinMode(x+4, OUTPUT);
      digitalWrite(x+4, LOW);
      delayMicroseconds(2);
      digitalWrite(x+4, HIGH);
      delayMicroseconds(5);
      digitalWrite(x+4, LOW);

      pinMode(x+4,INPUT);
      duration = pulseIn(x+4, HIGH); 
    }
    else{
      pinMode(x, OUTPUT);
      digitalWrite(x, LOW);
      delayMicroseconds(2);
      digitalWrite(x, HIGH);
      delayMicroseconds(5);
      digitalWrite(x, LOW);

      pinMode(x,INPUT);
      duration = pulseIn(x, HIGH); 
      // convert the time into a distance
   }
    inches = microsecondsToInches(duration);
    cm = microsecondsToCentimeters(duration);
    durat[x] = duration;

    distin[x] = inches;

    distcm[x] = cm;

    delay(1);
  }
  return;
}
long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
void squareup(){
  do{
if((room == 3) && (intersection >= 1)){ 
Serial.write(64);
Serial.write(192);
delay(3000);
if(durat[3] > durat[5]) {
      Serial.write(50);//32
      Serial.write(216);//222//206
      delay(50);
      Serial.write(64); 
      Serial.write(192);

    }
    else{
      Serial.write(78); //96
      Serial.write(178);//160
      delay(50);
      Serial.write(64); 
      Serial.write(192);
    }
    ping();
    delta2 = abs(durat[3]-durat[5]);
 
}
else{
    if(durat[3] > durat[5]) {
      Serial.write(50);//32
      Serial.write(216);//222//206
      delay(50);
      Serial.write(64); 
      Serial.write(192);

    }
    else{
      Serial.write(78); //96
      Serial.write(178);//160
      delay(50);
      Serial.write(64); 
      Serial.write(192);
    }
    ping();
    delta2 = abs(durat[3]-durat[5]);
  } 
  
  }while (delta2 >= 70);
  return;
}

void obsticle(){
  //  if((distcm[4] >= 10) && (distcm[3] >= 5) && (distcm[2] >= 5))//&& counter = 0
  do{

    Serial.write(64);
    Serial.write(192);
    delay(200);
    if(distcm[6] <= 15){
      do{
        Serial.write(42);//
        Serial.write(168);//
        delay(30);
        Serial.write(64);
        Serial.write(192);
        //stepcount++;
        ping();
      } 
      while (distcm[6] < 15);
    }
    if (obst_count <= 1){
      drive = 220;
   
    
    Serial.write(42);
    Serial.write(168);
    delay(170);
    }
    else{
     do{ 
        Serial.write(42); 
        Serial.write(210);
        delay(80);
       //decrease speed on left motor
       Serial.write(64); 
       Serial.write(192);
        ping();

       delta = abs(durat[5]- durat[3]);
       } while(delta > 50);  //delay(2000);
    }

    Serial.write(64);
    Serial.write(192);
    delay(1000);
    //      if (stepcount > 10){
    //        walldist = 1200;
    //        obst_delay = 900;
    //      }

    Serial.write(42); 
    Serial.write(210);
    delay(420);
    //decrease speed on left motor
    Serial.write(64); 
    Serial.write(192);
    //      if(obst_count >= 1){
    ////      do{
    ////          Serial.write(42);//
    ////          Serial.write(168);//
    ////          delay(30);
    ////          Serial.write(64);
    ////          Serial.write(192);
    ////          //stepcount++;
    ////          ping();
    ////        } 
    ////        while (distcm[3] > 6);
    //      }
    //    ping();
    //    if ((distcm[3] <= 5) || (distcm[5] <= 5) && (obst_count >= 1)){
    //      obst_count = 3;
    //      break;
    //   } 
    do{ 
      Serial.write(42); 
      Serial.write(210);
      delay(80);
      //decrease speed on left motor
      Serial.write(64); 
      Serial.write(192);

      ping();
      //      if ((distcm[3] <= 5) || (distcm[5] <= 5) && (obst_count >= 1)){
      //        obst_count = 3;
      //        break;
      //  } 
      if(obst_count >= 1){
        obst_delta = abs(durat[3] - durat[5]);
      }
      else{
        obst_delta = abs(durat[4] - durat[6]);
      }
    } 
    while (obst_delta > 50);
    if ((distcm[3] <= 5) || (distcm[5] <= 5) && (obst_count >= 1)){
      obst_count = 3;
      break;
    }
    if(obst_count >= 1){
      do{
        Serial.write(42);//
        Serial.write(168);//
        delay(30);
        Serial.write(64);
        Serial.write(192);
        //stepcount++;
        ping();
        if (distcm[3] <= 6){ 
          delay(1000);
          //                 digitalWrite(13,HIGH);
          //               delay(1000);
          //               digitalWrite(13,LOW);
          //               delay(3000);
          return;
        } 
      } 
      while (distcm[3] > 6);
    }
    ping();
    if ((distcm[3] <= 5) || (distcm[5] <= 5) && (obst_count >= 1)){
      obst_count = 3;
      break;
    } 
    Serial.write(42);//42//47
    Serial.write(175);//168
    delay(1100);//500
    Serial.write(64);
    Serial.write(192);
    //    digitalWrite(13,HIGH);
    //    delay(500);
    //    digitalWrite(13,LOW);
    //    digitalWrite(13,HIGH);
    //    delay(500);
    //    digitalWrite(13,LOW);

    squareup();

    obst_count++;
  } 
  while (obst_count <= 1);
  //obst_count = 0;


  //  digitalWrite(13,HIGH);
  //  delay(500);
  //  digitalWrite(13,LOW);
  //  digitalWrite(13,HIGH);
  //  delay(500);
  //  digitalWrite(13,LOW);

  delay(1000);//3000
  return;
}




