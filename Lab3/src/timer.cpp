// Author: 
// Net ID: 
// Date: 
// Assignment: Lab 3
//----------------------------------------------------------------------//

#include "timer.h"
//You many use any timer you wish for the microsecond delay and the millisecond delay


/* Initialize timer 1, you should not turn the timer on here. Use CTC mode  .*/
void initTimer1(){
	TCCR1A &= ~( (1 << WGM10) | ( 1 << WGM11));
    TCCR1B |= ( 1 << WGM12);
    TCCR1B &= ~ ( 1 << WGM13);

   TIMSK1 |= (1 << OCIE1A);
    OCR1A = 2;
}

/* This delays the program an amount of microseconds specified by unsigned int delay.
*/
void delayUs(unsigned int delay){
    int unsigned count = 0;
    //Turn on the clock by setting prescalar bits to 64
    TCCR1B |= (1 << CS10) | (1 << CS11); 
    TCCR1B &= ~(1 << CS12); 

    //THis can be put in the initialization function initTimer0()
    
    while(count < delay){
        //put the output compare match flag down OCF0A , by writing a logic 1 to it
        TIFR1 |= (1 << OCF1A);
        TCNT1 = 0; //Clear the count register

        //poll the OCF0A flag until it is set or is logic 1
        while (!(TIFR1 & (1 << OCF1A))); //do nothing while the flag is down. This wait is called polling
        //after the flag has been raised, 1 milisecond has elapsed
        count++;
    }
    //After exitting the larger while loop, the time elapsed has been 1ms * delay
    //turn the clock off to conserve power.
    TCCR0B &= ~((1 << CS10) | (1 << CS11)); 
    TCCR0B &= ~(1 << CS12);
}

/* Initialize timer 0, you should not turn the timer on here.
* You will need to use CTC mode */
void initTimer0(){
//initialize Timer0 for CTC mode of operation and interrupts
//WGM00 = 0, WGM01 = 1, WGM02 = 0 for CTC mode
    TCCR0A &= ~(1 << WGM00);
    TCCR0A |= (1 << WGM01);
    TCCR0B &= ~(1 << WGM02);

    //Enable the TIMER0 interrupt for output compare OCR0A 
    TIMSK0 |= (1 << OCIE0A);
}

/* This delays the program an amount specified by unsigned int delay.
* Use timer 0. Keep in mind that you need to choose your prescalar wisely
* such that your timer is precise to 1 millisecond and can be used for
* 100-200 milliseconds
*/
void delayMs(unsigned int delay){
    int unsigned count = 0;
    //Turn on the clock by setting prescalar bits to 64
    TCCR0B |= (1 << CS00) | (1 << CS01); 
    TCCR0B &= ~(1 << CS02); 

    //Use #counts = (td*fCPU)/ps = 1ms * 16MHz / 64 = 250 -1 = 249
    //THis can be put in the initialization function initTimer0()
    OCR0A = 249;
    while(count < delay){
        //put the output compare match flag down OCF0A , by writing a logic 1 to it
        TIFR0 |= (1 << OCF0A);
        TCNT0 = 0; //Clear the count register

        //poll the OCF0A flag until it is set or is logic 1
        while (!(TIFR0 & (1 << OCF0A))); //do nothing while the flag is down. This wait is called polling
        //after the flag has been raised, 1 milisecond has elapsed
        count++;
    }
    //After exitting the larger while loop, the time elapsed has been 1ms * delay
    //turn the clock off to conserve power.
    TCCR0B &= ~((1 << CS00) | (1 << CS01)); 
    TCCR0B &= ~(1 << CS02); 
}
