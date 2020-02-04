#include <SoftwareSerial.h>
#include <Keyboard.h>
#include "config.h"

char state = "";
char ctrlKey = KEY_LEFT_CTRL;
char windowKey = KEY_LEFT_GUI;

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
   if (Serial1.available() > 0) {
     state = Serial1.read();
   }
  if(state == '1'){
    lockComputer();
  }
  if(state == '2'){
    unlockComputer();
  }
  state = "";
}

void lockComputer(){
    Keyboard.press(windowKey);
    Keyboard.press('l');
    delay(100);
    Keyboard.releaseAll();
}

void unlockComputer(){
    Keyboard.println();
    delay(100);
    Keyboard.println(COMPUTER_PASSWORD);
    delay(100);
    Keyboard.releaseAll();
}
