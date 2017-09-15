#include <msp430.h>

 void main(void)
 {

  WDTCTL = WDTPW|WDTHOLD;       // Disables the Watchdog Timer
  PM5CTL0 &= ~LOCKLPM5;         // Disables high-impedance mode

  P1DIR = BIT0;                 // Sets Pin 1.0 as an output
  P5REN = BIT6;                 // Enables the resistor on the button
  P5OUT = BIT6;                 // Sets the resistor as a pull-up resistor

  while(1){                           // Creates an infinite loop to run the program
    if((P5IN & BIT6) == 0x00){        // Runs statement if the button is pressed
      __delay_cycles(5000);           // Delays the program to prevent bouncing
      P1OUT ^= BIT0;                  // Toggles the LED

      while((P5IN & BIT6) == 0x00);   // Extra while loop helps prevent bouncing issues

    }
  }
}
