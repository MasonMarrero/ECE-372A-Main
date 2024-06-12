// Author: Mason Marrero  
// Net ID: masonmarrero     
// Date: 9/14/23      
// Assignment: Lab 1
//----------------------------------------------------------------------//
//File is to initialize the LEDs, turn them on and off and run the blinking pattern
#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

// initLED which returns void and takes no parameters. Will initialize the ports we will use
void initLED(){
  DDRB  |= (1 << DDB5)| (1 << DDB4);
  DDRH  |=  (1 << DDH6) | (1 << DDH5) | (1 << DDH4) | (1 << DDH3);
  DDRE  |=  (1 << DDE3);
  DDRG  |=  (1 << DDG5);

}

// turnOnLED which returns void and takes in an unsigned int parameter called led
void Turnon_LEDs(unsigned int led){
  switch (led)
    {
    case 4:  // header pin 4
        PORTG |= ( 1 << PORTG5);
        break;
    case 5:  // header pin 5
        PORTE |= ( 1 << PORTE3);
        break;
    case 6:  // header pin 6
        PORTH |= ( 1 << PORTH3);
        break;
    case 7:  // header pin 7
        PORTH |= ( 1 << PORTH4);
        break;
    case 8:  // header pin 8
        PORTH |= ( 1 << PORTH5);
        break;
    case 9:  // header pin 9
        PORTH |= ( 1 << PORTH6);
        break;

    case 10:  // header pin 10
        PORTB |= (1 << PORTB4);
        break;

    case 11:  // header piin 11
        PORTB |= (1 << PORTB5);
        break;
    
    default:
        break;
    }

}
// function void Turnoff_LEDs passes a count variable that corresponds to the LED and will then turn off that LED
void Turnoff_LEDs(unsigned int led) {
    switch (led)
    {
    case 4:  // header pin 4
        PORTG &= ~( 1 << PORTG5);
        break;
    case 5:  // header pin 5
        PORTE &= ~( 1 << PORTE3);
        break;
    case 6:  // header pin 6
        PORTH &= ~( 1 << PORTH3);
        break;
    case 7:  // header pin 7
        PORTH &= ~( 1 << PORTH4);
        break;
    case 8:  //header pin 8
        PORTH &= ~(1 << PORTH5);
        break;
    case 9:  //header pin 9
        PORTH &= ~(1 << PORTH6);
        break;
    case 10:  // led in header pin 10
        PORTB &= ~(1 << PORTB4);
        break;

    case 11:  // led in header pin 11
        PORTB &= ~(1 << PORTB5);
        break;

    default:
        break;
    }
}

// runLED will take an int that corresponds to an LED and then run the code to make sure that it, and its matching LED
//will turn on, and turn off the previous lights.
void runLED(unsigned int led){
    int matchLED = (-2 * led) + 15 + led; //used to calculate the next LED
    //pattern:
    //ON        OFF
    //11 & 4    10&5
    //10 & 5    11 & 5
    //9 & 6     10 & 5
    //8 & 7     9 & 6
    //9 & 6     8 & 7
    //10 & 5    9 & 6
    //11 & 4    10 & 5

    //turn on the LED and its match
    Turnon_LEDs(led);
    Turnon_LEDs(matchLED);
    //turn off the LED from before
    if (led != 4){
        Turnoff_LEDs(led - 1);
        Turnoff_LEDs(matchLED + 1);
    }
    else{
        Turnoff_LEDs(10);
        Turnoff_LEDs(5);
    }
}
