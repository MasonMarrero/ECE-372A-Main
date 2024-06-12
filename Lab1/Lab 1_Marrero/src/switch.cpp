// Author: Mason Marrero  
// Net ID: masonmarrero     
// Date: 9/14/23      
// Assignment: Lab 1
//----------------------------------------------------------------------//
//file to initialize the switch
#include <avr/io.h>
#include "switch.h"

//initialize the switch
void initswitch() {
    DDRA &= ~(1 << DDA0); //set direction for input
    PORTA |= (1 << PORTA0); //enable pull up resistor
}
