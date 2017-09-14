#include <msp430.h>

 #define LED BIT0
 #define BUTTON BIT1

 void main(void)
 {

  WDTCTL = WDTPW|WDTHOLD;             // Disables Watchdog timer

  P1DIR = LED;                        // Established the LED as an output

  P1REN = BUTTON;                     // Enables the resistor for the button

  P1OUT = BUTTON;                     // Establishes the LED as a high output
  
  while(1){                           // Creates an infinite loop 

    if((P1IN & BUTTON) == 0x00){      // If Pin_1 is an input and the button is pressed
    __delay_cycles(5000);             // Bouncing protection via software delay
      if((P1IN & BUTTON) == 0x00){    // If Pin_1 is an input and the button is pressed
      P1OUT ^= LED;                   // ORs the register location with a 1, which will toggle the element
      while((P1IN & BUTTON) == 0x00); // While the pin and button are pressed keep the LED turned on, helps with bouncing
      }
    }
  }
}
