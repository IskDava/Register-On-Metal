# Register-On-Metal

## Description
Code for Arduino to bassicly work like a register. It stores it value in binary (HIGH and LOW power in D3-D10). You can write a char (1 byte) on it and then read it as decimal (type "read" in Serial for reading and any char for writting). It will display its current value with LEDs (8 lights - 8 bits).

## Requirements

Required:
- Tested on Arduino Nano (or any other board)
- Data cabel

Optional:
- Breadboard
- 8+ wires (I suggest around 12)
- 8 resistors (for lights) and 1 f
- 8 LEDs (displaying )

## Schema

1. Plug Arduino Nano and 8 LEDs on separate rows on the bread board
2. LED has two pins. The long one is `+` (VCC), shorter one is `-` (GND). So connect `+` to each data pin (D3 - D11) with a **RESISTOR** (NOT a wire, because if you give LED to much volts either it will burn or the pin will (needs ~3V while data pins produce 5V)). After that, connect `-` with GND (on your board) using a wire (resistor is not necessary)
3. Copy & Paste my code to your Arduino IDE, connect Arduino board to the computer and run the code!
4. Now if you input `read` into the `Serial` it will return you the value stored in register. To write something into you just have to write `char` that you want to store (for example, `A` (ASCII 65)), corresponding to its binary value lights will turn on.