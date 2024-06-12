#include <avr/io.h>
#include "switch.h"


void initswitch() {
    DDRA &= ~(1 << DDA0); //set direction for input
    PORTA |= (1 << PORTA0); //enable pull up resistor
}

