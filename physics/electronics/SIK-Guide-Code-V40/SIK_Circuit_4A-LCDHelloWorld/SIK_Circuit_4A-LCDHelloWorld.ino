/*
SparkFun Inventor’s Kit
Circuit 4A-HelloWorld

The LCD will display the words "Hello World" and show how many seconds have passed since
the RedBoard was last reset.

This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
This code is completely free for any use.

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40
Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/

#include <LiquidCrystal.h>          //the liquid crystal libarry contains commands for printing to the display

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);   // tell the RedBoard what pins are connected to the display

int buttonpin = 6;

void setup() {                     

  pinMode(buttonpin, INPUT_PULLUP);
  lcd.begin(18, 2);                 //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
  lcd.clear();                      //clear the display
}

int seconds = 0;
int minutes = 0;
int hours = 0;
int totalS = 0;

int buttoncount = 0;
bool buttonReq1 = false;
bool buttonReq2 = false;
bool buttonReq3 = false;


void loop() {

  lcd.setCursor(0,0);               //set the cursor to the 0,0 position (top left corner)
  lcd.print(":/goose/HONK");       //print :/goose/HONK starting at that position

  lcd.setCursor(0,1);               //mvoe the cursor to the first space of the bottom row

  totalS = millis()/1000;
  seconds = (totalS-(60*minutes)-(3600*hours));
  if(seconds >= 60){
    seconds-=60;
    minutes++;
  }
  if(minutes >= 60){
    minutes-=60;
    hours++;
  }
  lcd.print(hours);            //print the number of hours since the last reset
  lcd.print("h ");
  lcd.print(minutes);          //print the number of minutes since the last reset
  lcd.print("m ");
  lcd.print(seconds);         //print the number of seconds that have passed since the last reset
  lcd.print("s ");

  if(digitalRead(buttonpin)==HIGH){
    buttonReq1 = true;
  }
  if(digitalRead(buttonpin)==LOW){
    buttonReq2 = true;
  }
  if(digitalRead(buttonpin)==HIGH && buttonReq2 == true){
    buttoncount++;
    buttonReq1 = false;
    buttonReq2 = false;
    buttonReq3 = false;
  }
  
  lcd.print(buttoncount);
  lcd.print("pushes");
  
}  
