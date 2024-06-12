// Description: This file implements turnOnLED and initLED to control
// the LEDs.
//----------------------------------------------------------------------//


#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

/* Initialize PD0, PD1, PD2, and PD3 to outputs
*/
void initLED(){
  DDRD |= (1<<PD0) | (1<<PD1) | (1<<PD2) | (1<<PD3);
  //PORTD |= (1 << PORTD0);
  //PORTA |= (1 << PORTA0); //Turn one LED on
  PORTD &= ~((1<<PD0) | (1<<PD1) | (1<<PD2) | (1<<PD3));
}

/* This must be one line of code.
* In this function you will be giving a number "num" which will be represented
* in binary by four LEDs. You must effectively assign the lowest four bits of
* "num" to the appropriate bits of PORTD.
*/
void turnOnLEDWithChar(unsigned char num){
  //PORTD = (PORTD & (0xF0+num)) | (num & (0x0F+num*16)); // sets the first four bits to zero. sets the top four bits of num to
  PORTD = (PORTD & (0xF0)) | (num & (0x0F));
}

