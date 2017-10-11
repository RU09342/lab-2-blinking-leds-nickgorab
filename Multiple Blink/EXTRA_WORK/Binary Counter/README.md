# Binary Counter
Utilizes 5 LEDs connected off-board to create a binary counter. 

## Dependancies 
The `binaryCounter.c` code depends on the generic MSP430  header (`msp430.h`). 

## Code Architecture 

### Functions 

#### LED Initialization

In order to make the code easier to digest, a void function was used to initialize the LEDs.
```c
void ledInitialize(void)
```
Inside of this function the LED pins are declared as an output, and their state is set to high. This function is then called inside of the main function and reduces the amount of possibly confusing code. The lines of code used to initialize the code are found below. 
```c 
P1DIR |= BIT0;
P1DIR |= BIT1;
P1DIR |= BIT2;
P1DIR |= BIT3;
P1DIR |= BIT4;
P1DIR |= BIT5;
P1OUT |= BIT0;
P1OUT |= BIT1;
P1OUT |= BIT2;
P1OUT |= BIT3;
P1OUT |= BIT4;
P1OUT |= BIT5;
```

#### Main
```c
void main(void)
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

The main function contains an infinite while loop with a delay. Everytime the while loop runs, the status of the first LED is toggled using the code below.
```c
L1_OUT ^= LED1;
```
This XORs the bit that controls the LED state with itself, changing it everytime the code is activated. 

Similarly to `multipleBlink.c`, there is a for loop ,
```c
for(i=0; i<32000;i++) {
    if(i % 16000 == 0) {
        P1OUT ^=(BIT1);
    }
    if(i % 8000 == 0) {
       P1OUT ^= (BIT2);
    }
    if(i % 4000 == 0) {
       P1OUT ^= (BIT3);
    }
    if(i % 2000 == 0) {
       P1OUT ^= (BIT4);
    }
    i++;
}
```
which adds a delay to the button blink. This `for` loop is also utilized to blink the other LEDs. As the value of `i` is increasing, the modulo operator compares it with a values that progressively double in size. This means that the second LED should toggle 1 time for every 2 time the first LED toggles.
