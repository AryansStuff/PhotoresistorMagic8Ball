# PhotoresistorMagic8Ball
A Magic8Ball operated with a Photoresitor

Setting up:

Download arduino IDE here
https://www.arduino.cc/en/software

paste this code into the IDE,

use FIG-2 on page 116 of https://bastiaanvanhengel.files.wordpress.com/2016/06/arduino_projects_book.pdf

In replace of of the tilt switch put down a photoresistor,

```
***
INFO
_______
Photoresistors detect levels of light, A common use for them is as a daylight sensor
_____________________________________
HOW TO WRITE CODE FOR THEM
______________________________
Photoresistors have 2 levels, HIGH and LOW

the most basic code you can write for a photoresistor is:

void setup() 
{
  Serial.begin(9600);
}


void loop() 
{
  int value = analogRead(A0); //Only use AnalogRead if the pin that connects to the photoresistor is on the Analog pin section (A0, A1, A2, etc)
  Serial.println("Light value : ");
  Serial.println(value);
}
____________________________________
Now back to the project!
______________________________________
***
```
I'll assume your using the normal arduino breadboard from the arduino starter pack,
move the wire(digital pin 6) from its original position where it connected to the tilt switch to 4E on your breadboard
Connect the photoresistor's pins to D1, and D4, and connect the wire getting positive charge to A1


Also a side note, you might notce that the LCD just won't show the characters, you can fix this by simply moving the potentiometer's front 2 pins to A9 and A11 so that the middle pin gives output

Also here's a video of it working!
https://youtu.be/eX1QMOH9sbk
