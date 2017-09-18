#include <msp430.h>    // Includes the header file for the board

int main(void){

    volatile int i;

    WDTCTL = WDTPW+WDTHOLD;     // Stops the watchdog timer

    P1DIR |= BIT4;               // Sets pin 1.4 as an output
    P1DIR |= BIT5;               // Sets pin 1.5 as an output
    P2DIR |= BIT0;

    P1OUT |= BIT4;               // Sets pin 1.4 as high
    P1OUT |= BIT5;               // Sets pin 1.5 as high
    P2OUT |= BIT0;

    while(1) {                  // Creates a loop that toggles the LED

        P1OUT ^=(BIT4);         // Section of code that toggles the red LED


        for(i=0; i<5000;i++) {      
            if(i % 1000 == 0) {     // Blinks the yellow LED
                P1OUT ^=(BIT5);
            }
            if(i % 500 == 0) {      // Blinks the red LED
               P2OUT ^= (BIT0);

            }
            }
        }
    }


