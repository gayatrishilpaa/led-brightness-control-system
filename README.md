# led-brightness-control-system

This Arduino project allows a user to control an LED through the Serial Monitor using a menu-driven interface. The LED can be turned on or off, set to predefined brightness levels, display its current brightness percentage, or be controlled dynamically using a potentiometer.

## Components
- Arduino Uno
- Breadboard
- LED
- 1kΩ Resistor
- Potentiometer
- Jumper Wires
- Serial Menu Interface

--> The user can interact with the Arduino through the Serial Monitor using the following commands:

## Command	Functions
1. on	: Turns the LED fully on
2. off	: Turns the LED off
3. max :	Sets LED brightness to maximum
4. min :	Sets LED brightness to a low brightness level - 10
5. percent	: Displays the current LED brightness as a percentage
   - Percentage Calculation:
   -- The program keeps track of the current brightness value and converts it into a percentage using: 
     Brightness Percentage = (Current Brightness / 255) × 100
   -- This allows the user to monitor the LED intensity relative to its maximum possible brightness.
6. brightness	: Enables real-time brightness control using a potentiometer
   - Brightness Control : When the brightness command is selected
   -- The potentiometer value is continuously read from the analog input pin.
   -- The reading range of 0–1023 is scaled to the PWM range of 0–255.
   -- The scaled value is used to adjust LED brightness in real time.

## Concepts Demonstrated
- Variables and data types
- Serial communication
- User input handling
- Conditional statements (if / else if)
- Analog input (analogRead)
- PWM output (analogWrite)
- Linear scaling between ranges
- Menu-driven programming
- Real-time hardware control

## Circuit Connections

### LED

| Component       | Arduino Pin            |
| --------------- | ---------------------- |
| LED Anode (+)   | D6 (through resistor)  |                 
| LED Cathode (-) | GND                    |

### Potentiometer

| Potentiometer Pin | Arduino Pin |
| ----------------- | ----------- |
| VCC               | 5V          |
| GND               | GND         |
| Signal            | A5          |


## How to Use
- Upload the sketch to the Arduino.
- Open the Serial Monitor.
- Set the baud rate to 9600.
- Enter one of the available commands from the menu.
- Observe the LED response.

## To control brightness using the potentiometer:
- Enter brightness.
- Rotate the potentiometer knob to change LED intensity.
- Type any character in the Serial Monitor to exit brightness mode.

## Learning Outcomes
This project demonstrates how software and hardware interact through Arduino. It combines serial communication, PWM-based LED control, analog sensor readings, and user-driven menu navigation into a single application. It also introduces the concept of mapping values between different ranges, a technique commonly used in embedded systems and robotics.
