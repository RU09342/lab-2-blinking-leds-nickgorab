# Button Speed Control
This code will change the rate of blinking of an LED after a button press. 

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

Two main variables are used in this code, `speed` is used as a variable to control the LED blinking and `select` is used in order to determine which case to use for the speed.

The main function contains an infinite while loop, which is consatntly polling for a button input. If statements, like the following
```c
if((B1_IN & BUTTON1) == 0x00)
```
are used to check for when the button is pressed. Inside of this loop, there is a code which will increment the value of the speed select variable by `1`. 

After the for loop, there is a case statement with states to control the rate of blinking. An example of this can be found below.

```c
case 1  :
      speed = 30000;
      break;
```
As these states are cycled through, the speed value will change. The only difference is that the final case statement resets the value of `select` to `0`.


In order to render the LED in the **OFF** state while `speed` is `0`, there is a surrounding if statement which will only run the following loop if `speed > 1`.
The blinking rate is controlled using a for loop but instead of a fixed value to compare i against, it is a variable which changes based on the switch statement. 
```c
for(i=0; i<speed; i++);
```
which adds a delay to the button blink. The speed of the blinking can be altered by changing the value i is being compared to. 

## Debouncing
With the button being utilized in this code, some steps needed to be taken in order to remove button bouncing. This can be seen inside of the first if statement, in the line 
```c 
__delay_cycles(5000);
```
This line will disable the processor for 5000 clock cycles, so any bouncing from the button will not be recognized by the processor. 