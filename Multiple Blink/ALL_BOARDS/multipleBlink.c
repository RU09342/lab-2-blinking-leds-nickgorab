/*
 * multipleBlink.c
 *
 *   Created on:  September 9, 2017
 *  Last Edited:  October 7, 2017
 *       Author:  Nick Gorab
 *        Board:  ALL
 */

#include <msp430.h>    // Includes the general msp430 header file
#include <config.h>    // Includes the config file for Pin assignments

void ledInitialize(void){
    L1_DIR |= LED1;               // Sets pin 1.0 as an output
    L2_DIR |= LED2;               // Sets pin 4.7 as an output
    L1_OUT |= LED1;               // Sets pin 1.0 as high
    L2_OUT |= LED2;               // Sets pin 4.7 as high
}

int main(void) {

    volatile int i;               // Creates an int to control second led speed

    ledInitialize();              // Void function that intializes the LEDs

    WDTCTL = WDTPW+WDTHOLD;       // Stops the watchdog timer
    HIGHZ;                        // Disables high-impedance mode for required boards

    while(1) {                    // Creates a loop that toggles the LED
        L1_OUT ^= (LED1);         // Section of code that toggles the LED via XOR

        for(i=0; i<5000; i++) {
            if(i % 1000 == 0) {   // If statement which uses modulo for different blink rate
                L2_OUT ^= (LED2); // Toggles second LED via XOR
            }
        }
    }
}

