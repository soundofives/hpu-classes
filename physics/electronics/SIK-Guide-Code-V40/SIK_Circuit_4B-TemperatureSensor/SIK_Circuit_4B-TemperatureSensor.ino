/*
SparkFun Inventor’s Kit
Circuit 4B - Temperature Sensor

The LCD will display readings from a temperature sensor in degrees Celsius and Fahrenheit.

This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
This code is completely free for any use.

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40
Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/

#include <LiquidCrystal.h>                  //the liquid crystal libarry contains commands for printing to the display
#include <LcdBarGraph.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);    // tell the RedBoard what pins are connected to the display
LcdBarGraph lbg(&lcd, 16, 8, 0);
LcdBarGraph lbg2(&lcd, 16, 8, 1);

float voltage = 0;                          //the voltage measured from the TMP36
float degreesC = 0;                         //the temperature in Celsius, calcuated from the voltage
float degreesF = 0;                         //the temperature in Farenheit, calcuated from the voltage
float degreesK = 0;

int RedPin = 3;
int GreenPin = 5;
int BluePin = 6;

void setup() {

  Serial.begin(9600);
  lcd.begin(16, 2);                         //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
  lcd.clear();                              //clear the display    

  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
}
int count = 0;

void loop() {

  //if(count%100==0){
   voltage = analogRead(A0) * 0.004882814;   //convert the analog reading, which varies from 0 to 1023, back to a voltage value from 0-5 volts
  //}
  degreesC = (voltage - 0.5) * 100.0;       //convert the voltage to a temperature in degrees Celsius
  degreesF = degreesC * (9.0/5.0) + 32.0;   //convert the voltage to a temperature in dgrees Fahrenheit
  degreesK = degreesC-273.15;
  lcd.clear();                              //clear the LCD

  if(degreesF > -20 && degreesF <= 32){
    magenta();
  } else if(degreesF > 32 && degreesF <= 40){
    blue();
  } else if(degreesF > 40 && degreesF <= 50){
    cyan();
  } else if(degreesF > 50 && degreesF <= 60){
    green();
  } else if(degreesF > 60 && degreesF <= 70){
    yellow();
  } else if(degreesF > 70 && degreesF <= 80){
    orange();
  } else if(degreesF > 80 && degreesF <= 100){
    red();
  } else if(degreesF > 100){
    white();
  }


  lcd.setCursor(0,0);                       //set the cursor to the top left position
  lcd.print("C:");                 //print a label for the data
  lcd.print(degreesC);                      //print the degrees Celsius
  lbg.drawValue(0.5*degreesC, 50);
  
  lcd.setCursor(0,1);                       //set the cursor to the lower left position
  lcd.print("F:");                 //Print a label for the data
  lcd.print(degreesF);                      //print the degrees Fahreheit

  //lcd.setCursor(0,1);                       //set the cursor to the lower left position
  //lcd.print("Deg K: ");                 //Print a label for the data
  //lcd.print(degreesK);                      //print the degrees Fahreheit

  Serial.print(analogRead(A0));
  lbg2.drawValue(0.5*degreesF, 80);
  delay(100);                              
  count++;
}


void white (){
    
    //set the LED pins to values that make red    
    analogWrite(RedPin, 100);
    analogWrite(GreenPin, 100);
    analogWrite(BluePin, 100);
}

void red (){
    
    //set the LED pins to values that make red    
    analogWrite(RedPin, 100);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 0);
}
void orange (){
    
    //set the LED pins to values that make orange
    analogWrite(RedPin, 100);
    analogWrite(GreenPin, 10);
    analogWrite(BluePin, 0);
}
void yellow (){
    
    //set the LED pins to values that make yellow
    analogWrite(RedPin, 100);
    analogWrite(GreenPin, 100);
    analogWrite(BluePin, 0);
}
void green (){
    
    //set the LED pins to values that make green    
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 100);
    analogWrite(BluePin, 0);
}
void cyan (){
    
    //set the LED pins to values that make cyan    
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 100);
    analogWrite(BluePin, 100);
}
void blue (){
    
    //set the LED pins to values that make blue
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 100);
}
void magenta (){
    
    //set the LED pins to values that make magenta   
    analogWrite(RedPin, 100);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 100);
}
void turnOff (){
  
    //set all three LED pins to 0 or OFF
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 0);
}

