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

# Fixed_colors_variable_distance

>>colordetection_specific_fixed_colors.ino program caliberated a arduino nano for a fixed pre-decided colors and only works in a distance range decided by the user. The Program is not highly robust, thus it expects a near constant sorrounding's ligt conditions after the caliberation.

>>Caliberate the device whenever the sorroundings light conditions seems to be changed compared to that of previous caliberation.

>>For adding more colors to the detection device, add the color in the code as soecified by the example of "custom1_color" in the code.

# Variable_Colors_Experimental

>>colordetection_generalcolor_experimental.ino caliberates the Arduino NANO and maps the maximum and minimum values of red, green and blue photodiode filter data to received in the caliberation step, to 0 and 255 respectively.(Note that photodiode data gives less value when high value of the respective color is present n input rays.)

>>In the loop section the program determines the red,green, and blue value of the object present and maps it accordingingly between 0 and 255.

>>These values are then used to light up the RGB Led and try to replicate the input color.

>>In the caliberation step 'high-color' represents the state(distance) at which the input rays represent the color 'color' with complete certainity with little effect from sorrounding light conditions.(Usually such a state is to keep the sensor very near to the 'color' surface). Similarly 'low-color' represents the state(distance) in which the color 'color' can be said to not to be 0 value. (Usually thi state is to keep the TCS3200 sensor a little far away from the 'color' surface)

>>Try different way to caliberate for 'high-color' and 'low-color' situations (for example try removing the object completely to caliberate 'low-color' conditions) and explore the options which give better result.
