/*

*/

#include <Servo.h>          //include the servo library

int therm;
float temp;
float scale = 0.052;
int servoPosition;         //the servo will move to this position

Servo myservo;              //create a servo object

void setup() {
  Serial.begin(9600);
  myservo.attach(10);        //tell the servo object that its servo is plugged into pin 9
  
}

void loop() {

  
  
  therm = analogRead(A0);                     //use analog read to measure the position of the potentiometer (0-1023)

  //temp = therm * scale;
  temp = 0.0483*therm + 0.8506;

  
  servoPosition = map(temp, 0,36,0,180);  //convert the temperature number to a servo position from 0-180
                                                    //Note: its best to avoid driving the little SIK servos all the 
                                                    //way to 0 or 180 degrees it can cause the motor to jitter, which is bad for the servo.

  Serial.print(temp);
  Serial.print(" C, ");
  Serial.print(servoPosition);
  Serial.print(" pos\n");
  Serial.print(therm);
  Serial.print(" V\n");
  
  myservo.write(servoPosition);                      //move the servo to the 10 degree position

  delay(500);
}
