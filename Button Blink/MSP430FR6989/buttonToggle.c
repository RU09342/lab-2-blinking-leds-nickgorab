/*
 * buttonToggle.c
 *
 *   Created on:  September 15, 2017
 *  Last Edited:  September 18, 2017
 *       Author:  Nick Gorab
 *        Board:  FR6989
 */

 #include <msp430.h>

 void main(void)
 {

  WDTCTL = WDTPW|WDTHOLD;   // Disables Watchdog timer

  P1DIR = BIT0;             // Established the LED as an output
  P1REN = BIT1;             // Enables the resistor for the button
  P1OUT = BIT1;             // Creates a pull-up resistor
  
  while(1){                 // Creates an infinite loop 

    if((P1IN & BIT1) == 0x00){          // If Pin_1 is an input and the button is pressed, both equal to zero
    __delay_cycles(5000);               // Bouncing protection via software delay

      if((P1IN & BIT1) == 0x00){        // If Pin_1 is an input and the button is pressed, both equal to zero
        P1OUT ^= BIT0;                  // ORs the register location with a 1, which will toggle the LED via XOR

        while((P1IN & BIT1) == 0x00);   // While the pin and button are pressed keep the LED turned on, helps with bouncing
      }
    }
  }
}
