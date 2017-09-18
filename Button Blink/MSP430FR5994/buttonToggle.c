/*
 * buttonToggle.c
 *
 *   Created on:  September 15, 2017
 *  Last Edited:  September 18, 2017
 *       Author:  Nick Gorab
 *        Board:  FR5994
 */

 #include <msp430.h>

 void main(void)
 {

  WDTCTL = WDTPW|WDTHOLD;   // Disables Watchdog timer
  PM5CTL0 &= ~LOCKLPM5;     // Disables high-impedance mode

  P1DIR = BIT0;             // Established the LED as an output
  P5REN = BIT6;             // Enables the resistor for the button
  P5OUT = BIT6;             // Creates a pull-up resistor
  
  while(1){                 // Creates an infinite loop

    if((P5IN & BIT6) == 0x00){          // If Pin_1 is an input and the button is pressed, both equal to zero
    __delay_cycles(5000);               // Bouncing protection via software delay

      if((P5IN & BIT6) == 0x00){        // If Pin_1 is an input and the button is pressed, both equal to zero
        P1OUT ^= BIT0;                  // ORs the register location with a 1, which will toggle the LED via XOR

        while((P5IN & BIT6) == 0x00);   // While the pin and button are pressed keep the LED turned on/off, helps with bouncing
      }
    }
  }
}
