// Author:         
// Net ID:         
// Date:
// Assignment:
//
// Description: Main for toggle two LED lights
//--------------------------------------------------------------//
//#include <Arduino.h>
#include <avr/io.h>
#include <Arduino.h>
#include "led.h"


int main() {

    // initialize devices
  initLEDs(); // set up the  toggling




  while(1){    
    
Toggle_LEDs();
_delay_ms (1000);

    }

  return 0;
}