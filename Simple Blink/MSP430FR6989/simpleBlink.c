/*
 * simpleBlink.c
 *
 *   Created on:  September 15, 2017
 * 	Last Edited:  September 18, 2017
 *       Author:  Nick Gorab
 *        Board:  FR6989
 */

#include <msp430.h>    // Includes the header file for the board

int main(void){

    volatile int i;

    WDTCTL = WDTPW+WDTHOLD;     // Stops the watchdog timer

    P1DIR = BIT0;               // Sets pin 1.0 as an output, this is the red LED

    P1OUT = BIT0;               // Sets pin 1.0 as high, turning the LED on

    while(1) {                  // Creates a loop that toggles the LEDs
        P1OUT ^= (BIT0);        // XORs the output with itself, which will toggle the LED
             
        for(i=0; i<20000; i++);   // Adds a delay for the blinking
    }
}