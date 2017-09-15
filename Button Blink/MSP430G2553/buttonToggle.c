#include <msp430.h>

 void main(void)
 {

  WDTCTL = WDTPW|WDTHOLD;   // Disables Watchdog timer

  P1DIR = BIT0;             // Established the LED as an output
  P1REN = BIT3;             // Enables the resistor for the button
  P1OUT = BIT3;             // Creates a pull-up resistor
  
  while(1){                 // Creates an infinite loop

    if((P1IN & BIT3) == 0x00){          // If Pin_1 is an input and the button is pressed
    __delay_cycles(5000);               // Bouncing protection via software delay

      if((P1IN & BIT3) == 0x00){        // If Pin_1 is an input and the button is pressed
        P1OUT ^= BIT0;                  // ORs the register location with a 1, which will toggle the element

        while((P1IN & BIT3) == 0x00);   // While the pin and button are pressed keep the LED turned on, helps with bouncing
      }
    }
  }
}
