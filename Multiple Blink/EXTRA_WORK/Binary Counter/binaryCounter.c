/*
 * patternedLights.c
 *
 *   Created on:  September 19, 2017
 *  Last Edited:  October 7, 2017
 *       Author:  Nick Gorab
 *        Board:  G2553
 */

 #include <msp430.h>    // Includes the header file for the board

void ledInitialize(void) {
    P1DIR |= BIT0;               // Sets pin 1.0 as an output
    P1DIR |= BIT1;               // Sets pin 1.1 as an output
    P1DIR |= BIT2;               // Sets pin 1.2 as an output
    P1DIR |= BIT3;               // Sets pin 1.3 as an output
    P1DIR |= BIT4;               // Sets pin 1.4 as an output
    P1DIR |= BIT5;               // Sets pin 1.5 as an output
    P1OUT |= BIT0;               // Sets pin 1.0 as an output
    P1OUT |= BIT1;               // Sets pin 1.1 as an output
    P1OUT |= BIT2;               // Sets pin 1.2 as an output
    P1OUT |= BIT3;               // Sets pin 1.3 as an output
    P1OUT |= BIT4;               // Sets pin 1.4 as an output
    P1OUT |= BIT5;               // Sets pin 1.5 as an output
}

int main(void){

    volatile int i;

    WDTCTL = WDTPW+WDTHOLD;     // Stops the watchdog timer

    ledInitialize();            // Calls function to initialize LEDS

    while(1) {                   // Creates a loop that toggles the LED

        P1OUT ^=(BIT0);          // Section of code that toggles the LED


        for(i=0; i<32000;i++) {
            if(i % 16000 == 0) {
                P1OUT ^=(BIT1);
            }
            if(i % 8000 == 0) {
               P1OUT ^= (BIT2);
            }
            if(i % 4000 == 0) {
               P1OUT ^= (BIT3);
            }
            if(i % 2000 == 0) {
               P1OUT ^= (BIT4);
            }
        }
        i++;
        }
    }

