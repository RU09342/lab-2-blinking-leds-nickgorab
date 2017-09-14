#include <msp430.h>    // Includes the header file for the board



int main(void){

    volatile int i;
    int x;
    int speed = 0;

    WDTCTL = WDTPW+WDTHOLD;     // Stops the watchdog timer

    P1DIR = BIT0;               // Sets pin 1.0 as an output, this is the red LED

    P1REN |= BIT1;               // Enables the resistor for the button
    P1OUT |= BIT1;               // Enables the pull up resistor

    P1OUT = ~BIT0;               // Sets pin 1.0 as high, turning the LED on

    while(1) {                  // Creates an infinite loop

        P1OUT ^= (BIT0);        // Responsible for the blinking of the LED


        if((P1IN & BIT1) == 0x00) {
            __delay_cycles(5000);
            speed++;

        }

        if(speed == 3) {
            speed = 0;
        }

        switch(speed) {
        case 0  :           // Slowest speed
            x = 50000;
            break;
        case 1  :           // Medium speed
            x = 10000;
            break;
        case 2  :           // Fastest speed
            x = 2000;
            break;
        default :           // Default case returns to slow speed.
            x = 1;
            break;
        }

        for(i=0; i<x; i++); // For loop that creates delay.

    }
}

