#include <msp430f5529.h>    // Includes the header file for the board

int main(void){

    volatile int i;

    WDTCTL = WDTPW+WDTHOLD;     // Stops the watchdog timer

    P1DIR = BIT0;               // Sets pin 1.0 as an output
    P1DIE = BIT1;

    P1OUT = BIT0;               // Sets pin 1.0 as high

    while(1) {                  // Creates a loop that toggles the LED
       if(P1IN )

            }
        }
    }
}

