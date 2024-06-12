// main program to turn on 3 LEDS in the "Mustang Tail Light sequence"
// Program calls a function to initialize LEDS
// Program then calls a function to do the Mustang sequence

#include <Arduino.h>
#include <avr/io.h>
#include "mustang.h"

int main () {

InitLED();
char i=0;
while (1) {
  if (i < 4){
    Mustang_Tail_LED(i);
    _delay_ms(300);
    i++;
  }
  else{
    i=0;
  }
} 
return(0);
}