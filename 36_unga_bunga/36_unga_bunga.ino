#include <Keyboard.h>

int w = A0;
int tw = 2;

int a = A1;
int ta = 7;

int s = A2;
int ts = 7;

int d = A3;
int td = 3;
        
int ctrl = A4;
int tctrl = 20;

int alt = A5;
int talt = 10;
            
int rw;
int ra;
int rs;
int rd;
int rctrl;
int ralt;

bool pw = false;
bool pa = false;
bool ps = false;
bool pctrl = false;
bool palt = false;

void setup(void) {
  Serial.begin(9600);  
  Keyboard.begin(); 
}
 //
void loop(void) {
  rw = analogRead(w);
//  delay(50);
  ra = analogRead(a);
  rs = analogRead(s);
  rd = analogRead(d);
  rctrl = analogRead(ctrl);
  ralt = analogRead(alt);  
 
//  Serial.print(rctrl);     
//  Serial.print("---");     
//  Serial.print(ralt);     
//  Serial.println();
//  Serial.println(rs);     
//  Serial.println(rd);     
      
//  Serial.println(ralt);     
 
  if (rw > tw) {
    if (!pw) {
      pw = true;
     
      Keyboard.press('w');  
    }
  } else {
    if (pw) {
      pw = false;
     
      Keyboard.release('w');  
    }
  }

  if (ra > ta) {
    if (!pa) {
      pa = true;
      Keyboard.press('A');
    }
  } else {
    if (pa) {
      pa = false;
      Keyboard.release('A');    
    }
  } 

  if (rs > ts) {
    if (!ps) {
      ps = true;
      Keyboard.press('D');
    }
  } else {
    if (ps) {
      ps = false;
      Keyboard.release('D'); 
    }
  } 

//  if (rd > td) {
//   Keyboard.press('D');
//  } else {
//    Keyboard.release('D');
//  } 

  if (rctrl > tctrl) {
//    if (!pctrl) {
//      pctrl = true;
      Keyboard.press(' ');   
//    }
  } else {
//    if (pctrl) {
//      pctrl = false;
      Keyboard.release(' ');  
//    }
  } 

  if (ralt > talt) {
//    if (!palt) {
//      palt = true;
      Keyboard.press('E');   
//    }
  } else {
//    if (palt) {
//      palt = false;
      Keyboard.release('E');  
//    }
  }
}
