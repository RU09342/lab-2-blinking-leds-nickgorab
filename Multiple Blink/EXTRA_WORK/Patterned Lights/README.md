# Patterned Lights
This code will light up external LEDs in a pattern. 

## Dependancies 
The `binaryCounter.c` code depends on the generic MSP430  header (`msp430.h`). 

## External Circuitry
For this project, the same board used for the Binary Counter and Off-Board Blink was used. For more information on this see the `README.md` file for `offBoardBlink.c`.

## Code Architecture 

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

The main function contains an infinite while loop with a delay. Inside of the while loop, there is a switch statement which controls which one of the LEDs is lit. This is done using the following block of code.
```c
 case 1  :      
 P1OUT &= ~BIT0;
 P1OUT |= BIT1;
 P1OUT &= ~BIT2;
 P1OUT &= ~BIT3;
 P1OUT &= ~BIT4;
 P1OUT &= ~BIT5;
 P1OUT &= ~BIT6;
 P1OUT &= ~BIT7;
 P2OUT &= ~BIT0;
 P2OUT &= ~BIT1;
 break;
```
This code will turn off all of the LEDS except for the second light. After repeating this with a case for each LED, a wave pattern is created in the LEDs.