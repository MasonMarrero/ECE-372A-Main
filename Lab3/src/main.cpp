// Author: MAson Marrero
// Net ID: masonmarrero
// Date: 10/5/23
// Assignment:     Lab 3
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
// Requirements:
//----------------------------------------------------------------------//





#include <Arduino.h>
#include <avr/io.h>
#include "led.h"
#include "switch.h"
#include "timer.h"
#include "lcd.h"
//global variables to keep track of the current flip speed, which will change when the button is pressed
volatile unsigned int flip_speed = 0;

//create states
typedef enum {wait_press, debounce_p, wait_release, debounce_r} button_state;
//declare the enum state variable
volatile button_state my_button_state = wait_press;

int main(){
  //initialization functions
  initTimer1();
  initLCD();
  initSwitchPB3();
  initLED();
  initTimer0();
  sei(); // Enable global interrupts.
  moveCursor(0, 0); // moves the cursor to 0,0 position
  writeString("Current mode: ");
  moveCursor(1, 0);  // moves the cursor to 1,0 position
  writeString("Fast");

  char i = 0;
  //while loop to keep the lights running
	while (1) {
    //if the flip speed is 1, make the delay 200
    if(flip_speed == 1){
    turnOnLEDWithChar(i);
    delayMs(200);
    moveCursor(1, 0);  // moves the cursor to 1,0 position
    writeString("Slow");
    i++;
    if(i == 16)
      i=0;
    }
    //If the flip speed is 0, make the delay 100
    else{
      turnOnLEDWithChar(i);
      delayMs(100);
      moveCursor(1, 0);  // moves the cursor to 1,0 position
      writeString("Fast");
      i++;
      if(i == 16)
        i=0;
    }
      //state machine for push buttton 
      switch (my_button_state)
      {
      case  wait_press:
        break;

      case  debounce_p:
        //eventually go to wait_release
        //need to delay by ~1ms
        delayMs(1);
        my_button_state = wait_release;
        break;

      case  wait_release:
        break;

      case  debounce_r:
        //eventually go to wait_release
        //need to delay by ~1ms
        delayMs(1);
        my_button_state = wait_press;
        break;
      default:
        break;
      }
  }
  return 0;
}

/* Implement an Pin Change Interrupt which handles the switch being
* pressed and released. When the switch is pressed and released, the LEDs
* change at twice the original rate. If the LEDs are already changing at twice
* the original rate, it goes back to the original rate.
*/
//Interrupt state machine
ISR(PCINT0_vect){
  //if pressed go to debounce state
  if(my_button_state == wait_press){
      my_button_state = debounce_p;
  }
  //if its pressed and released change the flip speed
  else if(my_button_state == wait_release){
    if (flip_speed == 0){
      flip_speed = 1;
    }
    else{
      flip_speed = 0;
    }
    my_button_state = debounce_r;
  }
}


