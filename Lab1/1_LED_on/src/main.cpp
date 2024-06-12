// Dale Hetherington
// Date:
// Assignment:  Classroom example program
//
// Description: main program to turn on LEDs
//----------------------------------------------------------------------


#include <avr/io.h>   // this includes all of the SFR macros
#include "led.h"  //  other header files you define

int main ()    {
    initLEDs();  // Initialize the LED which turns it on

    while(1)    {

    }
        return(0);
}

