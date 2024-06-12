// Author: Mason Marrero  
// Net ID: masonmarrero     
// Date: 9/14/23      
// Assignment: Lab 1
//----------------------------------------------------------------------//

//main file to run the pattern by going through the different port numbers and changing the delay based on if the button is pressed.
#include <Arduino.h>
#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
#include "switch.h"
#define SHORT_DELAY 1000
#define LONG_DELAY 100

int main() {
//Initialization of the ports for LED and the Switch
initLED();
initswitch();

while (1) {
  //go through the different ports for the LED pattern
  for(int i = 4; i < 11; i++){
    //if the switch is pushed
    if(!(PINA & (1 << PINA0))){
      if(i == 8) //we want to skip 8 so it doesnt do the 8 and 7 ports twice
        i++;
      runLED(i);
      _delay_ms(1000);
    }
    //if the button isnt pushed
    else{
      if(i == 8)
        i++;
      runLED(i);
      _delay_ms(100);
    }
  }
}
}