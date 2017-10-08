/*
 * buttonSpeedControl.c
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

  WDTCTL = WDTPW|WDTHOLD;       // Disables the Watchdog Timer
  HIGHZ;                        // Disables high impedance mode

  int select = 0;               // Creates an integer value to determine LED
  int speed = 0;                // Creates an integer value to determine speed
  volatile int i;               // Volatile integer used for the timer

  button1Initialize();          // Void function that initializes the button

  L1_DIR |= LED1;                  // Established LED 1 as an output

  while(1){                              // Creates an infinite loop to run the program
    if((B1_IN & BUTTON1) == 0x00){       // Runs statement if the button is pressed
      __delay_cycles(5000);              // Delays the program to prevent bouncing
      select = select + 1;               // Toggles the value of the LED from 1 to 0

      while((B1_IN & BUTTON1) == 0x00);  // Extra while loop helps prevent bouncing issues
    }

    switch (select) { // Creates a switch statement to chose the LED

      case 0 :
      speed = 0;      // This is the off state, the blinking loop will not run
      break;

      case 1  :
      speed = 30000;  // This is considered the 'slow' speed
      break;

      case 2  :
      speed = 10000;  // This is considered the 'medium' speed
      break;

      case 3  :
      speed = 3000;   // This is considered the 'fast' speed
      break;

      case 4  :
      select = 0;     // Once the speed cycles through, it gets sent back to case 0
      break;
    }


    if (speed > 1) {            // If statement which only runs the blinking if the speed is greater than zero

      L1_OUT ^= LED1;           // XORs the LED bit with itself, toggling the LED

      for(i=0; i<speed; i++);   // Adds a delay for the blinking
    }
  }
}
