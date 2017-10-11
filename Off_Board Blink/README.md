# Off Board Blink
The offboard blink section required removing the G2553 chip form it's board and putting it on a breadboard. This required extra circuitry to power the LEDs, and resarch into the specifications and limits of the chip.

## Code
The code for this section was rather straight forward. It is similar in structure to the code found in the multiple blink section, with the only difference being the pin addresses. With the chip no longer connected to the board, there are no designated pins for the LEDs, so any GPIO pin can be used. For this specific code I used pins 1.4, 1.5, and 2.0.

## Hardware
According to the datasheet for the G2553 chip, the maximum current output at each pin was 6 mA, with a voltage of 3V. A single LED needs somewhere in the area of 20 mA to operate, so they can not be powered soley by the chip; external circuitry is required. 

In order for the chip to operate outside of the board, power needed to be supplied to certain pins on the chip. Going off of the datasheet, Vcc needs to be applied to Pins 1 and 16 on the chip. Pin 1 is for the main chip power, while pin 16 is for the reset function. In order for the reset to function, a 10k Ohm resisor needs to placed in series with Vcc.

The external circuitry was done in the form of a Common Emitter BJT circuit. A model/simulation can be found in the next subsection. This circuit is able to draw from the 3.3V rail which is found on the LaunchPad Board for the necessary current. According to the simulation, the circuit requires roughly 200 uA from the chip, which is well below the threshold of 6 mA. 

Below is a circuit diagram demonstrating the external circuitry required to power the LEDs. 
![Circuit Schematic](https://github.com/RU09342/lab-2-blinking-leds-nickgorab/blob/master/Off_Board%20Blink/MSP430G2553/OffBoard%20LED.JPG)

### EveryCircuit simulation
A cicuit simulation for one of the LED-transistor circuits can be found
<a href="http://everycircuit.com/circuit/5126254895562752">here.</a><br>

### Circuit demonstration
![Circuit GIF](https://github.com/RU09342/lab-2-blinking-leds-nickgorab/blob/master/Off_Board%20Blink/MSP430G2553/20171007_184942.gif)

## Extra Work
This section contains all of the extra work performed in this section.

### Off-Board Programming 
In order for the board to be programmed off of the LaunchPad board, two wires neeed to be routed from the board to the breadboard. According to the datasheet, the ability for the chip to be programmed relies on two pins, TEST and RST. In order to connect these to the breadboard, the jumpers at J3 need to be removed. The wires from there are attached to the corresponding pins on the breadboard. The TEST wire goes to Pin 17 on the chip while RST goes to Pin 16.

After these two connections are made, the board was able to be programmed while still on the breadboard. 

The picture below shows the correct connections being made to the board.
![Picture of board](https://github.com/RU09342/lab-2-blinking-leds-nickgorab/blob/master/Off_Board%20Blink/MSP430G2553/P9170630.jpg)
