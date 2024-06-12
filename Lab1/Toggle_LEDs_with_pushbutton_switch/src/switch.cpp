#include <avr/io.h>
#include "switch.h"

void initswitch() {

  //set the data direction register to input
  // i'll choose header pin 12 (bit location PB6)

  DDRB &= ~(1<<DDB6); // set direction for input
  PORTB |= (1 << PORTB6);  // enable the pullup resistor for stable input
}
