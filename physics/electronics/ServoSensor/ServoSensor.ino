#include <Servo.h>


Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
  
  
}
int angle = 0;

void loop() {

  //int resist = analogRead(A1);
  //Serial.print("Resist: ");
  //Serial.print(resist);
  //Serial.print("\n");

  //angle = map(resist,0,1023,45,90);

  servo.write(5);
  //Serial.print("Angle: ");
  //Serial.print(angle);
  //Serial.print("\n");

  //delay(1000); 
}
