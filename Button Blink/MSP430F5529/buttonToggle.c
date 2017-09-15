#include <msp430.h>

 void main(void)
 {

  WDTCTL = WDTPW|WDTHOLD;       // Disables the Watchdog Timer

  P1DIR = BIT0;                 // Sets Pin 1.0 as an output
  P2REN = BIT1;                 // Enables the resistor on the button
  P2OUT = BIT1;                 // Sets the resistor as a pull-up resistor

  while(1){                           // Creates an infinite loop to run the program
    if((P2IN & BIT1) == 0x00){        // Runs statement if the button is pressed
      __delay_cycles(10000);           // Delays the program to prevent bouncing
      P1OUT ^= BIT0;                  // Toggles the LED

      while((P2IN & BIT1) == 0x00);   // Extra while loop helps prevent bouncing issues

    }
  }
}
