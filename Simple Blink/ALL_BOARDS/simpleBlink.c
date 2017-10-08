/*
 * simpleBlink.c
 *
 *   Created on:  September 8, 2017
 *  Last Edited:  October 7, 2017
 *       Author:  Nick Gorab
 *        Board:  ALL
 */


#include <msp430.h>    // Includes the general msp430 header file
#include <config.h>	   // Includes the config file for Pin assignments

void main(void) {

    volatile int i;

    WDTCTL = WDTPW+WDTHOLD;       // Stops the watchdog timer
    HIGHZ;						  // Disables high-impedance mode for proper boards

    L1_DIR = LED1;                // Sets pin 1.0 as an output, this is the red LED
    L1_OUT = LED1;                // Sets pin 1.0 as high, turning the LED on

    while(1) {                    // Creates a loop that toggles the LEDs
        L1_OUT ^= (LED1);         // XORs the output with itself, which will toggle the LED

        for(i=0; i<20000; i++);   // Adds a delay for the blinking
    }
}
