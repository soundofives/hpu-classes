#include <Servo.h>


Servo servo;
void setup() {
  Serial.begin(9600);
  servo.attach(9);
  servo.write(5);
  
}
int dr = 0;
int dt = 0;
double drdt = 0;

int arraymag = 120;
int angle = 0;

int count = 0;
int rArray[120];
int tArray[120];
int slope1 = -1;

bool initialize = 1;

//*******************************************************************************
void loop() {


  //SERVO ACTION
  int resist = analogRead(A1);
  
  //SERVO ACTION


  //keep track of how many data points I've captured
  count++;
  if(count == arraymag){
      count = 0;
  }
  //take an analog data point with its corresponding time in microseconds
  int r = resist;
  int t = micros()/100000;
  
  //place the data point in its corresponding location in the array
  rArray[count] = r;
  tArray[count] = t;
  
  
  //calculate drdt


  if(initialize){
    //calculate drdt
    if(count == arraymag-1){
      initialize = 0;
      //reset coubnt
      count = 0;
    }    
  }
  
  if(!initialize){
    
    
      if(count == arraymag-1){
        //dr = rArray[count] - rArray[0];
        //dt = tArray[count] - tArray[0];
        //drdt = (double)dr/(double)dt;
        drdt = 0;
        count = 0;
      } else{
        dr = rArray[count] - rArray[count+1];
        dt = tArray[count] - tArray[count+1];
        drdt = (double)dr/(double)dt;
      }
    
  }

  if(!initialize){
    if(drdt > (double)slope1){
      if(angle < 60){
        angle = angle + 2;
      }
    } else if(drdt < (double)slope1){
      if(angle > 5){
        angle = angle - 2;
      }
    }
  }
  
  
  servo.write(angle);
    //VERBOSE
    //Serial.print("==============\n");
    //Serial.print("Resist: ");
    //Serial.print(resist);
    //Serial.print("\n");
    //Serial.print("Angle: ");
    //Serial.print(angle);
    //Serial.print("\n");
    //Serial.print("drdt: ");
    Serial.print(drdt);
    Serial.print("\n");
    //Serial.print("dr: ");
    //Serial.print(dr);
    //Serial.print("\n");
    //Serial.print("dt: ");
    //Serial.print(dt);
    //Serial.print("\n");
    //    Serial.print("rArray: ");
    //Serial.print(rArray[count]);
    //Serial.print("\n");
    //Serial.print("count: ");
    //Serial.print(count);
    //Serial.print("\n");
    //}
  delay(1);
}

