/*
 * multipleBlink.c
 *
 *   Created on:  September 14, 2017
 *  Last Edited:  September 18, 2017
 *       Author:  Nick Gorab
 *        Board:  G2553
 */

#include <msp430.h>    // Includes the header file for the board

int main(void){

    volatile int i;

    WDTCTL = WDTPW+WDTHOLD;     // Stops the watchdog timer

    P1DIR |= BIT0;               // Sets pin 1.0 as an output
    P1DIR |= BIT6;               // Sets pin 1.6 as an output

    P1OUT |= BIT0;               // Sets pin 1.0 as high
    P1OUT |= BIT6;               // Sets pin 1.6 as high

    while(1) {                  // Creates a loop that toggles the LED
        P1OUT ^=(BIT6);         // Section of code that toggles the LED via XOR


        for(i=0; i<5000; i++) {
            if(i % 1000 == 0) { // If statement which uses modulo for different blink rate
                P1OUT ^=(BIT0); // Toggles second LED via XOR
            }
        }
    }
}

