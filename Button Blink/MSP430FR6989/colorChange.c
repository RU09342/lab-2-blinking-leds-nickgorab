/*
 * colorChange.c
 *
 *   Created on:  September 15, 2017
 *  Last Edited:  September 18, 2017
 *       Author:  Nick Gorab
 *        Board:  FR6989
 */

 #include <msp430.h>

 void main(void)
 {

  WDTCTL = WDTPW|WDTHOLD;       // Disables the Watchdog Timer

  int LED = 1;                  // Creates an integer value to determine LED
  volatile int i;               // Volatile integer used for the timer

  P1DIR |= BIT0;                // Sets Pin 1.0 as an output (Red LED)
  P9DIR |= BIT7;                // Sets Pin 9.7 as an output (Green LED)

  P1REN = BIT1;                 // Enables the resistor on the button
  P1OUT = BIT1;                 // Sets the resistor as a pull-up resistor

  while(1){                           // Creates an infinite loop to run the program
    if((P1IN & BIT1) == 0x00){        // Runs statement if the button is pressed
      __delay_cycles(5000);           // Delays the program to prevent bouncing
      LED = !LED;                    // Toggles the value of the LED from 1 to 0

      while((P1IN & BIT1) == 0x00);   // Extra while loop helps prevent bouncing issues
    }

    switch (LED) {          // Creates a switch statement to chose the LED
      case 0 :
      P1OUT ^= (BIT0);      // Sets the LED on Pin 1.0 to blink via XOR
      P9OUT &= ~BIT7;       // Makes sure that the LED on Pin 9.7 is off by &ing it with itself
      break;

      case 1  :
      P9OUT ^= (BIT7);      // Sets the LED on Pin 9.7 to blink via XOR
      P1OUT &= ~BIT0;       // Makes sure that the LED on Pin 1.0 is off by &ing it with itself
      break;

    }



    for(i=0; i<10000; i++);   // Adds a delay for the flashing
  }
}