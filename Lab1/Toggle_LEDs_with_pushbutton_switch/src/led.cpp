#include <avr/io.h>
#include "led.h"

void initLEDs() {

  //set the data direction register to output
  // i'll choose PORTB4 and PORTB5

  DDRB |= (1<<DDB5)  | (1<<DDB4);
  PORTB |= (1 << PORTB4);  // turn on PORTB4 led
}

void Toggle_LEDs(){
  PORTB ^= (1 <<PORTB4) | (1 << PORTB5);
  
}