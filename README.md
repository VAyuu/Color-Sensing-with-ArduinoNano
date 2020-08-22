# Color-Sensing-with-ArduinoNano

# Tools Needed

>>Arduino NANO - 1 

>>TCS3200 color sensor - 1

>>Common Cathode RGB Led - 1

>>Jumper Wires(Male to Female) - 7

>>Computer(to upload the code into Arduino NANO) - 1


# Wiring

## TCS3200---ArduinoNANO(PIN)

>>S0---05

>>S1---06

>>S2---07

>>S3---08

>>OUT---09

>>GND--04

>>VCC--27

## RGB Led---ArduinoNANO(Pin)

>> Common Cathode---GND(Pin 29)

>>Red Pin---Pin 19

>>Green Pin---Pin 20

>>Blue Pin---Pin 21

# Fixed_colors_specific_distance

>>This program caliberated a arduino nano for a fixed pre-decided colors and only works in a distance range decided by the user. The Program is not highly robust, thus it expects a near constant sorrounding's ligt conditions after the caliberation.

>>Caliberate the device whenever the sorroundings light conditions seems to be changed compared to that of previous caliberation.

>>For adding more colors to the detection device, add the color in the code as soecified by the example of "custom1_color" in the code.

# colordetection_generalcolor_experimental.ino
