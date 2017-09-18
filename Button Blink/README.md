# Button Blink
This section of the lab contains code which will toggle the state of a LED with the push of one of the on-chip buttons. 

## Code Architecture
As seen in the simple blink code, the correct pin needed to be established for the LED light. PIN 1.0 was used for each of the codes.

Additionally, the Watchdog timer was also disabled because the code contains no interrupts. 

Due to the addition of the button, a pull-up resistor needed to be enabled in order for proper operation. This was done by setting the button pin as an input and then altering the output value, as this changed the state of the resistor between pull-up and pull-down. When the button is pressed, it's value will read a zero.

An infinite while loop was used to poll for an input from the button. Then, If statements were implemented in order to change the state of the LED. In order to avoid any kind of bouncing, a software delay is implemented. This will halt the program until after any bouncing affects take place. 

The button was toggled in the same fashion as the simple blink command. 

### List of button pinouts
- F5529   PIN 1.1
- FR2311  PIN 1.1
- FR5994  PIN 5.6
- FR6989  PIN 1.1
- G2553	  PIN 1.3

## Extra Work
This section contains some of the extra project performed with the boards. 

### Button Based Speed Control
The purpose of this program is to control the speed of the blinking with the press of a button. There are four States: Slow, Medium, Fast, and Off. 

This was done by implementing a counter which affected a switch statement. Every time the button is pressed the counter increases, corresponding to a switch condition with a certain speed. Once the counter reaches 4 it will reset back to the original state of Off. 

### Color Change
This program will change the blinking LED from red to green. This was done in a fashion similar to the Button Based Speed Control program. There is a switch statement and a variable which corresponds to different switch states. 

In order to make sure that the lights aren't left on when the color swithces, inside of the switch statement there is a line of code to turn the light off. 