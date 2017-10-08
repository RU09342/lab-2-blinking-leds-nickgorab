/*
 * buttonToggle.c
 *
 *   Created on:  September 9, 2017
 *  Last Edited:  October 7, 2017
 *       Author:  Nick Gorab
 *        Board:  ALL
 */


#include <msp430.h>    // Includes the general msp430 header file
#include <config.h>    // Includes the config file for Pin assignments

void button1Initialize(void) {    // Void function that intiializes the button
  B1_DIR |= ~BUTTON1;              // Establishes the button as an input
  B1_REN |=  BUTTON1;              // Enables the resistor for the button
  B1_OUT |=  BUTTON1;              // Creates a pull-up resistor
}

void main(void) {

  button1Initialize();

  WDTCTL = WDTPW|WDTHOLD;   // Disables Watchdog timer
  HIGHZ;                    // Disables high-impedance mode for proper boards

  L1_DIR = LED1;            // Initializes the LED1 as an output


  while(1){                 // Creates an infinite loop

    if((B1_IN & BUTTON1) == 0x00){          // Seeing if button is pressed and set as an input
    __delay_cycles(5000);                   // Bouncing protection via software delay

      if((B1_IN & BUTTON1) == 0x00){        // Seeing if button is pressed and set as an input
        L1_OUT ^= LED1;                     // Toggles LED with XOR

        while((B1_IN & BUTTON1) == 0x00);   // While the pin and button are pressed keep the LED turned on/off, helps with bouncing
      }
    }
  }
}
