#include <Keyboard.h>
#include "Mouse.h"
int w = A0;
int tw = 5;

int mb1 = 2;
int mb2 = 3;

int rmb1 = 0;
int rmb2 = 0;
int rw = 0;

void setup(void) {
  Serial.begin(9600);  
  Keyboard.begin(); 
  pinMode(mb1, INPUT);
  pinMode(mb2, INPUT);
}

void loop(void) {
  rmb1 = digitalRead(mb1);
  rmb2 = digitalRead(mb2);
  rw = analogRead(w);
  if (rw > 970) {
    if (rmb1 == HIGH) {
      Mouse.press(MOUSE_RIGHT);
      delay(20);
      Mouse.release(MOUSE_RIGHT);
    } else if (rmb2 == HIGH) {
      Mouse.press(MOUSE_MIDDLE);
      delay(20);
      Mouse.release(MOUSE_MIDDLE);    
    } else
      Mouse.press(MOUSE_LEFT);
      
      delay(20);
      Mouse.release(MOUSE_LEFT);
    }
  } 
}
