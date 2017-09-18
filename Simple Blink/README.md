# Simple Blink
The code contained in these folders blinks the LEDs of the corresponding boards with a 50% duty cycle.

## Code Architecture
This code runs with no interrupts, so the first step was do disable the watchdog timer.

Then the pins needed to be set as an output in their high state.  For each board that we are working with in this lab, there is a LED on PIN 1.0, so this was the pin used for all boards.

In order to establish the blinking of the lights, there is a for loop included in the code which will delay the program for a specified amount of time.

Once the for loop executes, the output of the PIN is XOR'd with the state of the PIN (High or Low), which will toggle the state of the output everytime it runs through. With the lights being toggled at a constant rate, that means the duty cycle for the LED must be 50%, as required by the lab. 

The only change in this code throughout the boards can be found in the main.c file for the FR5994. This board requires an extra line of code which will turn off 'High Impedance Mode' on the board, allowing the LEDs to be activated. 


## README
Remember to replace this README with your README once you are ready to submit. I would recommend either making a copy of this file or taking a screen shot. There might be a copy of all of these README's in a folder on the top level depending on the exercise.

## Extra Work
Since this is so basic, there are a few things which might be interesting to implement.

### UART Control: Single Character
For starters, it would be interesting to tie in some of the UART code that was used before into this project. You might want to have the speed of the blinking controlled by a character sent over UART. For example, 's' could be a slow setting, 'm' could be medium speed, 'f' could be fast, and 'o' could be off.

### UART Control: Rate Number
Instead of depending on a character, what if we wanted to send a blinking period in milliseconds? So instead of 's', you could send something like '100' which corresponds to a 100 millisecond delay between the time the LED turns on again. Before you decide to tackle this, I would take a look at using a logic analyzer to see exactly what your computer is sending to your microprocessor. Also remember that the code previously provided will only service the UART Buffer one character at a time.