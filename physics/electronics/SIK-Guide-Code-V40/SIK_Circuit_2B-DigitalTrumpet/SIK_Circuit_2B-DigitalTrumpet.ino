/*
SparkFun Inventor’s Kit
Circuit 2B-ButtonTrumpet

Use 3 buttons plugged to play musical notes on a buzzer.

This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
This code is completely free for any use.

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40
Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/

//set the pins for the button and buzzer
int firstKeyPin = 2;
int secondKeyPin = 3;
int thirdKeyPin = 4;

int buzzerPin = 10;


void setup() {
  //set the button pins as inputs
  pinMode(firstKeyPin, INPUT_PULLUP);
  pinMode(secondKeyPin, INPUT_PULLUP);
  pinMode(thirdKeyPin, INPUT_PULLUP);

  //set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  
  if(digitalRead(firstKeyPin) == LOW && digitalRead(secondKeyPin) == HIGH && digitalRead(thirdKeyPin) == HIGH){        //if the first key is pressed
    tone(buzzerPin, 349);                     //play the frequency for f
  }
  else if(digitalRead(secondKeyPin) == LOW && digitalRead(firstKeyPin) == HIGH && digitalRead(thirdKeyPin) == HIGH){  //if the second key is pressed
    tone(buzzerPin, 494);                     //play the frequency for b
  }
  else if(digitalRead(thirdKeyPin) == LOW && digitalRead(secondKeyPin) == HIGH && digitalRead(firstKeyPin) == HIGH){   //if the third key is pressed
    tone(buzzerPin, 523);                     //play the frequency for C
  }
  else if(digitalRead(firstKeyPin) == LOW && digitalRead(thirdKeyPin) == LOW){   //if the third key is pressed
    tone(buzzerPin, 594);                     //play the frequency for d
  }
  else if(digitalRead(firstKeyPin) == LOW && digitalRead(secondKeyPin) == LOW){   //if the third key is pressed
    tone(buzzerPin, 330);                     //play the frequency for e
  }
  else if(digitalRead(secondKeyPin) == LOW && digitalRead(thirdKeyPin) == LOW){   //if the third key is pressed
    tone(buzzerPin, 440);                     //play the frequency for a
  }
  else{
    noTone(buzzerPin);                        //if no key is pressed turn the buzzer off
  }
}

  /*
  note  frequency
  c     262 Hz
  d     294 Hz
  e     330 Hz
  f     349 Hz
  g     392 Hz
  a     440 Hz
  b     494 Hz
  C     523 Hz
  */

