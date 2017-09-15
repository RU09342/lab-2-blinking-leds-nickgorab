#include <msp430.h>

 void main(void)
 {

  WDTCTL = WDTPW|WDTHOLD;       // Disables the Watchdog Timer

  int select = 0;
  int speed = 0;                // Creates an integer value to determine LED
  volatile int i;               // Volatile integer used for the timer

  P1DIR |= BIT0;                // Sets Pin 1.0 as an output (Red LED)

  P1REN = BIT1;                 // Enables the resistor on the button
  P1OUT = BIT1;                 // Sets the resistor as a pull-up resistor

  while(1){                           // Creates an infinite loop to run the program
    if((P1IN & BIT1) == 0x00){        // Runs statement if the button is pressed
      __delay_cycles(5000);           // Delays the program to prevent bouncing
      select = select + 1;            // Toggles the value of the LED from 1 to 0

      while((P1IN & BIT1) == 0x00);   // Extra while loop helps prevent bouncing issues
    }

    switch (select) {                 // Creates a switch statement to chose the LED

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


    if (speed > 0) {          // If statement which only runs the blinking if the speed is greater than zero

    P1OUT ^= BIT0;            // ORs the LED bit with itself, toggling the LED
    for(i=0; i<speed; i++);   // Adds a delay for the blinking
  }
  }
}
