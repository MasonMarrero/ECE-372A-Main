// Description: This file implements turnOnLED and initLED to control
// the LEDs.
//----------------------------------------------------------------------//


#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

/* Initialize PA0, PA1, PA2, and PA3 to outputs
*/
void initLED(){
  DDRD |= (1 << DDD0) | (1 << DDD1) | (1 << DDD2) | (1 << DDD3);
  //PORTA |= (1 << PORTA0);
  //PORTA |= (1 << PORTA0); //Turn one LED on
}

/* This must be one line of code.
* In this function you will be giving a number "num" which will be represented
* in binary by four LEDs. You must effectively assign the lowest four bits of
* "num" to the appropriate bits of PORTA.
*/
void turnOnLEDWithChar(unsigned char num){
    PORTD = (PORTD & (0xF0+num)) | (num & (0x0F+num*16)); // sets the first four bits to zero. sets the top four bits of num to
}
