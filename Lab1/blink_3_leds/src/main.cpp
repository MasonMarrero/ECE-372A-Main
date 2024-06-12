
#include <Arduino.h>
#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
#include "switch.h"
#define SHORT_DELAY 100
#define LONG_DELAY 1000

int main() {
initLEDs ();
initswitch();

while (1) {
  for(int i = 4; i < 11; i++){
    if(!(PINA & (1 << PINA0))){
      if(i == 8)
        i++;
      runLED(i);
      _delay_ms(100);
    }
    else{
            if(i == 8)
        i++;
      runLED(i);
      _delay_ms(1000);
    }
  }
}
}
