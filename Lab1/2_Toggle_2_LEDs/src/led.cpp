// Author:         
// Net ID:         
// Date:
// Assignment:
//
// Description: c++ Code for initializing LEDS and Toggle LEDS
//------------------------------------------------------------
//

#include <avr/io.h>
#include "led.h"

void initLEDs()  {

    //DDRBBXn set pin direction as output
    DDRB |=  (1<<DDB5) | (1<<DDB4) | (1<<DDH6) | (1<<DDH5) | (1<<DDH4) | (1<<DDH3) | (1<<DDE3) | (1<<DDG5);
    PORTB |= (1<<PORTB4 | 1<<PORTH6);// turn on one LED (PORTB4) and leave the other off.

}
  
    // toggle led PORTB5 and PORTB4 pins
void Toggle_LEDs()  {
        PORTB  ^=  (1 << PORTB4 | 1 << PORTH6) | (1 << PORTB5);

    }
