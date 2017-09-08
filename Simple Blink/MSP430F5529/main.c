#include <msp430f5529.h>	// Includes the header file for the board

int main(void){

	volatile int i;

	WDTCTL = WDTPW+WDTHOLD; 	// Stops the watchdog timer

	P1DIR = BIT6;				// Sets pin 6 as an output

	P1OUT = BIT6;				// Sets pin 6 as high

	while(1) {					// Creates a loop that toggles the LED
		P1OUT ^=(BIT6)			// Section of code that toggles the LED
		for(i=0; i<9999; i++)	//
	}
}
