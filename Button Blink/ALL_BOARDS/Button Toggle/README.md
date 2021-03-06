# Button Toggle
This code will toggle the state of an LED with the press of a button. 

## Code Architecture 
### Dependencies 
The `buttonToggle.c` code depends on two separate files. The first file is the generic MSP430  header (`msp430.h`), and a config file (`config.h`) which assigns the correct pins for each board. For more information about these, visit their respective `README.h` files.

```c
#include <msp430.h>
#include <config.h>
```
This is the section of the code which is used to include the header files.

### Functions 

#### Button Initialization

In order to make the code easier to digest, a void function was used to initialize the button.
```c
void button1Initialize(void)
```
Inside of this function the button pin is declared an input, and the resistor is enabled and assigned to the pull up position. This function is then called inside of the main function and reduces the amount of possibly confusing code. The lines of code used to initialize the code are found below. 
```c 
B1_DIR |= ~BUTTON1;
B1_REN |=  BUTTON1;
B1_OUT |=  BUTTON1;
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

The main function contains an infinite while loop, which is consatntly polling for a button input. If statements, like the following
```c
if((B1_IN & BUTTON1) == 0x00)
```
are used to check for when the button is pressed. As soon as this loop is activated, the LED is toggled using the code 
```c
L1_OUT ^= LED1;
```
This XORs the bit that controls the LED state with itself, changing it everytime the code is activated. With the MSP430 boards being RISC, they all attempt to complete 1 instruction per clock cycle, so the operation which is chosen for the toggling does not make a huge difference.

Similarly to the button blink code there is a for loop at the bottom,
```c
for(i=0; i<10000; i++);
```
which adds a delay to the button blink. The speed of the blinking can be altered by changing the value i is being compared to. 

## Debouncing
With the button being utilized in this code, some steps needed to be taken in order to remove button bouncing. This can be seen inside of the first if statement, in the line 
```c 
__delay_cycles(5000);
```
This line will disable the processor for 5000 clock cycles, so any bouncing from the button will not be recognized by the processor. 