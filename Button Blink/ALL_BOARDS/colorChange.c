/*
 * colorChange.c
 *
 *   Created on:  September 14, 2017
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

  WDTCTL = WDTPW|WDTHOLD;  // Disables the Watchdog Timer
  HIGHZ;                   // Disables high-impedance mode 

  int LED = 1;             // Creates an integer value to determine LED
  volatile int i;          // Volatile integer used for the timer

  L1_DIR |= LED1;           // Sets the red LED as an output
  L2_DIR |= LED2;           // Sets the green LED as an output


  while(1){                           // Creates an infinite loop to run the program
    if((B1_IN & BUTTON1) == 0x00){        // Runs statement if the button is pressed
      __delay_cycles(5000);           // Delays the program to prevent bouncing
      LED = !LED;                     // Toggles the value of the LED from 1 to 0

      while((B1_IN & BUTTON1) == 0x00);   // Extra while loop helps prevent bouncing issues
    }

    switch (LED) {          // Creates a switch statement to chose the LED
      case 0 :
      L1_OUT ^= (LED1);      // Toggles red LED via XOR
      L2_OUT &= ~LED2;       // Makes sure that the green LED is off by &ing it with itself
      break;

      case 1  :
      L2_OUT ^= (LED2);      // Toggles red LED via XOR
      L1_OUT &= ~LED1;       // Makes sure that the red LED is off by &ing it with itself
      break;

    }



    for(i=0; i<10000; i++);   // Adds a delay for the flashing
  }
}
