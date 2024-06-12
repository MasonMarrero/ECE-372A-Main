// Author: Mason Marrero  
// Net ID: masonmarrero     
// Date: 9/14/23      
// Assignment: Lab 1
//----------------------------------------------------------------------//

//Headerfile for leds
#ifndef LED_H
#define LED_H

// initLED which returns void and takes no parameters
void initLED();

// turnOnLED which returns void and takes in an unsigned int parameter called led
void TurnOn_LEDs(unsigned int led);

// turnOffLED which returns void and takes in an unsigned int parameter called led
void TurnOff_LEDs(unsigned int led);

// runLED which returns void and takes in an unsigned int parameter called led
void runLED(unsigned int led);

#endif
