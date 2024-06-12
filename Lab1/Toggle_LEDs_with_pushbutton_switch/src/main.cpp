// This code for toggling 2 LEDS
// Dale Hetherington
// 9-3-20


#include <Arduino.h>
#include <avr/io.h>
#include "led.h"
#include "switch.h"
#define SHORT_DELAY 100
#define LONG_DELAY 1000

int main() {
  
  // set baud rate for the serial port print function
  Serial.begin(9600);

// Use Arduino library to print to serial port
 Serial.println ("Hello World I am here");
 Serial.println ("I am still here");
// flush out buffer so that entire string will print
 Serial.flush();


//initialize LEDS
initLEDs();  // set direction of LED pins
//initialize switch
initswitch(); // set the switch for input

while (1) {
// if switch is pressed SHORT_DELAY
if (!(PINB & (1 << PINB6))) {

Toggle_LEDs();
  _delay_ms (SHORT_DELAY);

}
// the above if statement checks for switch closed
// if it is open then we go to the else code
else {

Toggle_LEDs();
_delay_ms (LONG_DELAY);
}  
}

return 0;

}
