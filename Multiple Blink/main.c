#include <msp430f5529.h>    // Includes the header file for the board

int main(void){

    volatile int i;

    WDTCTL = WDTPW+WDTHOLD;     // Stops the watchdog timer

    P1DIR = BIT0;               // Sets pin 1.0 as an output
    P4DIR = BIT7;               // Sets pin 4.7 as an output

    P1OUT = BIT0;               // Sets pin 1.0 as high
    P4OUT = BIT7;               // Sets pin 4.7 as high

    while(1) {                  // Creates a loop that toggles the LED
        P1OUT ^=(BIT0);          // Section of code that toggles the LED


        for(i=0; i<5000; i++) {
            if(i % 500 == 0) {
                P4OUT ^=(BIT7);
            }
        }
    }
}

