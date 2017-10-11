# Button Toggle
This code will change the color of the blinking LED on the press of a button. 

## Dependancies 
The simpleblink.c code depends on two separate files. The first file is the generic MSP430  header, and a config file which assigns the correct pins for each board. For more information about these files, visit their respective README files.


## Code Architecture 
This proram is simple, so the code is very straight forward. To begin, the dependencies are included in the file, using 
```c
#include <msp430.h>
#include <config.h>
```

### Functions 

#### LED Initialization

In order to make the code easier to digest, a void function was used to initialize the LEDs.
```c
void ledInitialize(void)
```
Inside of this function the LED pins are declared as an output, and their state is set to high. This function is then called inside of the main function and reduces the amount of possibly confusing code. The lines of code used to initialize the code are found below. 
```c 
L1_DIR |= LED1;
L2_DIR |= LED2;
L1_OUT |= LED1;
L2_OUT |= LED2; 
```

#### Main


In the main file there is no use of interrupts, so the Watch Dog timer needed to be disabled using the line 
```c
WDTCTL = WDTPW+WDTHOLD;
```
With the FR6989, FR2311, and FR5994 needing high impedance mode to be disabled, the line 
```c
HIGHZ;
```
is used to disable it. This is a macro defined in the config.h header file, and it will disable the high impedance mode for the specified board. For the other boards, it just opeartaes as a no-op. 

The main function contains an infinite while loop with a delay. Everytime the while loop runs, the status of the first LED is toggled using the code below.
```c
L1_OUT ^= LED1;
```
This XORs the bit that controls the LED state with itself, changing it everytime the code is activated. 

Similarly to the button blink code there is a for loop at the bottom,
```c
for(i=0; i<5000; i++) {
    if(i % 1000 == 0) {
        L2_OUT ^= (LED2);
    }
}
```
which adds a delay to the button blink. This `for` loop is also utilized to blink the second LED. As the value of i is increasing, the modulo operator compares it with a value of `1000`. This means that the second LED should toggle 5 times for every 1 time the first LED toggles.
