/*
  THIS CODE IS A MODIFICATION OF THE ORIGINAL ARDUINO PROJECTS BOOK: CRYSTAL BALL,
  HOWEVER I HAVE ADAPTED IT, AND IT IS IN THE PUBLIC DOMAIN,
  I DO NOT OWN THIS CODE NOR DO I CLAIM TO
  HOWEVER,
  I WILL SAY THAT THE MODIFICATION WAS BY ME AND I AM NOT SIMPLY REUPLOADING SOMEBODY ELSE'S CODE
  
  Anyways though, here are some credits
  
  AUTHOR: Aryan Sinha
  IDE: Arduino 1.8.15
  ARDUINO BOARD: Arduino Uno
  FAVORITE PUNCTUATION MARK: commas
*/
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// set up a constant for the tilt switch pin
const int lightPin = 6;

// variable to hold the value of the switch pin
int lightState = 0;

// variable to hold previous value of the switch pin
int prevLightState = 0;

// a variable to choose which reply from the crystal ball
int reply;

void setup() {
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);

  // set up the switch pin as an input
  pinMode(lightPin, INPUT);

  // Print a message to the LCD.
  lcd.print("Ask the");
  // set the cursor to column 0, line 1
  // line 1 is the second row, since counting begins with 0
  lcd.setCursor(0, 1);
  // print to the second line
  lcd.print("Crystal Ball!");
}

void loop() {
  // check the status of the switch
  lightState = digitalRead(lightPin);

  // compare the switchState to its previous state
  if (lightState != prevLightState) {
    // if the state has changed from HIGH to LOW you know that the ball has been
    // tilted from one direction to the other
    if (lightState == HIGH) {
      // randomly chose a reply
      reply = random(8);
      // clean up the screen before printing a new reply
      lcd.clear();
      // set the cursor to column 0, line 0
      lcd.setCursor(0, 0);
      // print some text
      lcd.print("the ball says:");
      // move the cursor to the second line
      lcd.setCursor(0, 1);

      // choose a saying to print based on the value in reply
      switch (reply) {
        case 0:
          lcd.print("Yes");
          break;

        case 1:
          lcd.print("Most likely");
          break;

        case 2:
          lcd.print("Certainly");
          break;

        case 3:
          lcd.print("Outlook good");
          break;

        case 4:
          lcd.print("Unsure");
          break;

        case 5:
          lcd.print("Ask again");
          break;

        case 6:
          lcd.print("Doubtful");
          break;

        case 7:
          lcd.print("No");
          break;
      }
    }
  }
  // save the current switch state as the last state
  prevLightState = lightState;
}
