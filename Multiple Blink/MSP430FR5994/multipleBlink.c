/*
 * multipleBlink.c
 *
 *   Created on:  September 15, 2017
 *  Last Edited:  September 18, 2017
 *       Author:  Nick Gorab
 *        Board:  FR5994
 */

#include <msp430.h>    // Includes the header file for the board

int main(void){

    volatile int i;

    PM5CTL0 &= ~LOCKLPM5;       // Disables high-impedance mode

    WDTCTL = WDTPW+WDTHOLD;     // Stops the watchdog timer

    P1DIR |= BIT0;               // Sets pin 1.0 as an output
    P1DIR |= BIT1;               // Sets pin 1.1 as an output

    P1OUT |= BIT0;               // Sets pin 1.0 as high
    P1OUT |= BIT1;               // Sets pin 1.1 as high

    while(1) {                  // Creates a loop that toggles the LED
        P1OUT ^=(BIT0);          // Section of code that toggles the LED via XOR


        for(i=0; i<5000; i++) {
            if(i % 1000 == 0) { // If statement which uses modulo for different blink rate
                P1OUT ^=(BIT1); // Toggles second LED via XOR
            }
        }
    }
}
