/*
 * patternedLights.c
 *
 *   Created on:  September 19, 2017
 *  Last Edited:  October 11, 2017
 *       Author:  Nick Gorab
 *        Board:  G2553
 */

 #include <msp430.h>    // Includes the header file for the board

void ledInitialize(void){

    P1DIR |= BIT0;               // Sets pin 1.0 as an output
    P1DIR |= BIT1;               // Sets pin 1.1 as an output
    P1DIR |= BIT2;               // Sets pin 1.2 as an output
    P1DIR |= BIT3;               // Sets pin 1.3 as an output
    P1DIR |= BIT4;               // Sets pin 1.4 as an output
    P1DIR |= BIT5;               // Sets pin 1.5 as an output
    P1DIR |= BIT6;               // Sets pin 1.6 as an output
    P1DIR |= BIT7;               // Sets pin 1.7 as an output
    P2DIR |= BIT0;               // Sets pin 2.0 as an output
    P2DIR |= BIT1;               // Sets pin 2.1 as an output
  
}

int main(void){

    volatile int i;
    int step;

    WDTCTL = WDTPW+WDTHOLD;     // Stops the watchdog timer

    ledInitialize();

    while(1) {                   // Creates a loop that toggles the LED
        step = step + 1;


        switch (step) {

            case 0  :            // Step 1 lights up only the first LED
            P1OUT |= BIT0;
            P1OUT &= ~BIT1;
            P1OUT &= ~BIT2;
            P1OUT &= ~BIT3;
            P1OUT &= ~BIT4;
            P1OUT &= ~BIT5;
            P1OUT &= ~BIT6;
            P1OUT &= ~BIT7;
            P2OUT &= ~BIT0;
            P2OUT &= ~BIT1;
            break;

            case 1  :            // Step 2 lights up only the second LED             
            P1OUT &= ~BIT0;
            P1OUT |= BIT1;
            P1OUT &= ~BIT2;
            P1OUT &= ~BIT3;
            P1OUT &= ~BIT4;
            P1OUT &= ~BIT5;
            P1OUT &= ~BIT6;
            P1OUT &= ~BIT7;
            P2OUT &= ~BIT0;
            P2OUT &= ~BIT1;
            break;

            case 2  :            // Step 3 lights up only the third LED
            P1OUT &= ~BIT0;
            P1OUT &= ~BIT1;
            P1OUT |= BIT2;
            P1OUT &= ~BIT3;
            P1OUT &= ~BIT4;
            P1OUT &= ~BIT5;
            P1OUT &= ~BIT6;
            P1OUT &= ~BIT7;
            P2OUT &= ~BIT0;
            P2OUT &= ~BIT1;
            break;

            case 3  :            // Step 4 lights up only the fouth LED
            P1OUT &= ~BIT0;
            P1OUT &= ~BIT1;
            P1OUT &= ~BIT2;
            P1OUT |= BIT3;
            P1OUT &= ~BIT4;
            P1OUT &= ~BIT5;
            P1OUT &= ~BIT6;
            P1OUT &= ~BIT7;
            P2OUT &= ~BIT0;
            P2OUT &= ~BIT1;
            break;

            case 4  :            // Step 5 lights up only the fifth LED
            step = 0
            P1OUT &= ~BIT0;
            P1OUT &= ~BIT1;
            P1OUT &= ~BIT2;
            P1OUT &= ~BIT3;
            P1OUT |= BIT4;
            P1OUT &= ~BIT5;
            P1OUT &= ~BIT6;
            P1OUT &= ~BIT7;
            P2OUT &= ~BIT0;
            P2OUT &= ~BIT1;
            break;



        for(i=0; i<1000; i++);    // For loop responsible for the lights
    }

