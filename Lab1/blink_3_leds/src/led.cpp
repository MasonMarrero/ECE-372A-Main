#include <Arduino.h>
#include <avr/io.h>
#include "led.h"

// showing use of serial print to the serial monitor for debugging only
// set baud rate for the serial port print function




void initLEDs() {
DDRB  |= (1 << DDB5)| (1 << DDB4) | (1 << DDH6) | (1 << DDH5) | (1 << DDH4) | (1 << DDH3) | (1 << DDE3) | (1 << DDG5);
}

///////////////////////////////////////////////////////////////////
// function void Turnon_LEDs passes a count variable that corresponds to the LED
// and turns on the specific LED
// starting count at the header pin # 11
void Turnon_LEDs(unsigned int LEDnum) {
    switch (LEDnum)
    {
    case 4:  // header pin 11
        PORTG |= ( 1 << PORTG5);
        break;
    case 5:  // header pin 11
        PORTE |= ( 1 << PORTE3);
        break;
    case 6:  // header pin 11
        PORTH |= ( 1 << PORTH3);
        break;
    case 7:  // header pin 11
        PORTH |= ( 1 << PORTH4);
        break;
    case 8:  // header pin 11
        PORTH |= ( 1 << PORTH5);
        break;
    case 9:  // header pin 11
        PORTH |= ( 1 << PORTH6);
        break;

    case 10:  // header pin 12
        PORTB |= (1 << PORTB4);
        break;

    case 11:  // header piin 13
        PORTB |= (1 << PORTB5);
        break;
    
    default:
        break;
    }

}
// function void Turnoff_LEDs passes a count variable that corresponds to the LED
// and turns off the specific LED
// starting count at the header pin # 11
void Turnoff_LEDs(unsigned int LEDnum) {
    switch (LEDnum)
    {
    case 4:  // header pin 11
        PORTG &= ~( 1 << PORTG5);
        break;
    case 5:  // header pin 11
        PORTE &= ~( 1 << PORTE3);
        break;
    case 6:  // header pin 11
        PORTH &= ~( 1 << PORTH3);
        break;
    case 7:  // header pin 11
        PORTH &= ~( 1 << PORTH4);
        break;
    case 8:  //header pin 11//
        PORTH &= ~(1 << PORTH5);
        break;
    case 9:  //header pin 11//
        PORTH &= ~(1 << PORTH6);
        break;
    case 10:  // led in header pin 12
        PORTB &= ~(1 << PORTB4);
        break;

    case 11:  // led in header pin 13
        PORTB &= ~(1 << PORTB5);
        break;

    default:
        break;
    }
}

//
void runLED(unsigned int LEDnum){
    int matchLED = (-2 * LEDnum) + 15 + LEDnum;
    //ON        OFF
    //11 & 4    10&5
    //10 & 5    11 & 5
    //9 & 6     10 & 5
    //8 & 7     9 & 6
    //9 & 6     8 & 7
    //10 & 5    9 & 6
    //11 & 4    10 & 5
    Turnon_LEDs(LEDnum);
    Turnon_LEDs(matchLED);
    if (LEDnum != 4){
        Turnoff_LEDs(LEDnum - 1);
        Turnoff_LEDs(matchLED + 1);
    }
    else{
        Turnoff_LEDs(10);
        Turnoff_LEDs(5);
    }
}
