#include <msp430.h>    // Includes the header file for the board

int main(void){

    volatile int i;

    WDTCTL = WDTPW+WDTHOLD;     // Stops the watchdog timer

    P1DIR = BIT0;               // Sets pin 1.0 as an output
    P2DIR = BIT0;               // Sets pin 2.0 as an output

    P1OUT = BIT0;               // Sets pin 1.0 as high
    P2OUT = BIT0;               // Sets pin 2.0 as high

    while(1) {                  // Creates a loop that toggles the LED
        P1OUT ^=(BIT0);          // Section of code that toggles the LED


        for(i=0; i<50000; i++) {
            if(i % 500 == 0) {
                P2OUT ^=(BIT0);
            }
        }
    }
}

