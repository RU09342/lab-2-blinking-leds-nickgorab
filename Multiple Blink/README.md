# Multiple Blink
This section includes code which uses both of the on-board LEDs, having them blink at different rates. The code for this section utilizes an If-Statement and the modulo operator in order to have two blinking LEDs.

## Code Architecture
In a similar fashion to the previous codes, the Watchdog Timer is disabled in the code, and the pins corresponding to the LEDs are set to be outputs with a high logic level. This section requires the use of multiple LEDs, so there needs to be code to initialize two of them. For almost every one of the boards, the pin number for the second LED differed, while the main LED at Pin 1.0 stayed the same. The table below shows the values of the secondary LEDs.


### Seconday LED Pins
- F5529 &nbsp;&nbsp;&nbsp;&nbsp; PIN 4.7
- FR2311&nbsp;&nbsp;&nbsp; PIN 2.0
- FR5994&nbsp;&nbsp;&nbsp; PIN 1.1
- FR6989&nbsp;&nbsp;&nbsp; PIN 9.7
- G2553	&nbsp;&nbsp;&nbsp;&nbsp; PIN 1.6


## Extra Work
This extra work sections goes into detail with controlling even more extra lights attached externally to the circuit. 

### Even More LEDs
Since up to this point you should have hopefully noticed that you are simply just controlling each pin on your processor. So... what is keeping you from putting an LED on each pin? Can you actually control the speed of each of these LEDs?

### Patterned Lights
If you can control a ton of LEDs, what is keeping you from having a little fun? Why not try and make something like a moving face or other moving object in lights. *CAUTION* I would only do this if you have finished the rest of the lab.

### UART Pattern Control
If you have been using UART, could you set which LEDs are on or off based off some UART command? Would you want to send an Array over UART such as [1 0 1 0] or would you want to send a byte that corresponds to the status? Can you not only say which LEDs are on, but also tell them to blink at a particular rate if they were on (so LED1 Blink every 100ms)?