# Flash Thunder Box

An easy way to determine the distance of a storm is the "flash-to-bang" method. It calculates the distance of a storm using the seconds passing between flash and thunder.

The Flash Thunder Box calculates that distance for you. It consists of a button which can be pressed twice (first time when the flash is spotted, second time when the thunder is being heard) and displays the approximate distance to the storm.

# Building and Testing

To run the test program (testing the LED and the 7-segment display), press the button connected to `D9` during uploading/starting.

## Components

### 4-Digit 7-Segment Display

Part number: kyx-5461as

Pin layout: bottom left to right: 1-6, top right to left: 7-12

    KYX-5461AS Description Arduino 
    1 Segment E 7 
    2 Segment D 8 
    3 Decimal point 9 
    4 Segment C 10 
    5 Segment G 11 
    6 Digit 4 12 
    7 Segment B 13 
    8 Digit 3 2 
    9 Digit 2 3 
    10 Segment F 4 
    11 Segment A 5 
    12 Digit 1 6

For more information and Arduino Uno pin layout: http://www.ithepro.com/2015/11/kyx-5461as-4-digit-7-segment-led.html

### Button with LED

https://www.adafruit.com/products/1443

### Power Switch

https://www.sparkfun.com/products/11138
https://www.adafruit.com/products/805
