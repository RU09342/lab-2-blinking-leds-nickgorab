# Simple Blink
The code contained in these folders blinks the red LEDs of the provided boards with a 50% duty cycle. 

## Dependancies 
The simpleblink.c code depends on two separate files. The first file is the generic MSP430  header, and a config file which assigns the correct pins for each board. For more information about these files, visit their respective README files.

## Code Architecture 
This proram is simple, so the code is very straight forward. To begin, the dependencies are included in the file, using 
```c
#include <msp430.h>
#include <config.h>
```
In the main file there is no use of interrupts, so the Watch Dog timer needed to be disabled using the line 
```c
WDTCTL = WDTPW+WDTHOLD;
```
With the FR6989, FR2311, and FR5994 needing high impedance mode to be disabled, the line 
```c
HIGHZ;
```
is used to disable it. This is a macro defined in the config.h header file, and it will disable the high impedance mode for the specified board. For the other boards, it just opeartaes as a no-op. 

The main part of this code is the while loop which toggles the state of the LED. 
```c
while(1) {
	L1_OUT ^= (LED1);
	for(i=0; i<20000; i++);
}
```
The while loop is infinite, so the function inside of it is always running. The for loop acts as a delay which controls the rate the LED blinks. 