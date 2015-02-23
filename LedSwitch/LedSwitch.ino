/*

LED Switch

Pretty simple here.

Multicolor LED in pins 9, 10, 11 (red is 9, green is 10, blue is 11)



 */

const int redPin =  9;
const int greenPin = 10;
const int bluePin = 11;

int onOffStatus = 0;
int switchCurrentlyPressed = 0;
const int ledBrightness = 5;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);


  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  
}

// the loop function runs over and over again forever
void loop() {
  
  // Need to track if the switch is currently pressed or not, otherwise it may switch back and forth
  if (digitalRead(2) == HIGH && !switchCurrentlyPressed) {
    switchCurrentlyPressed = 1;
    toggleOnOff();
  } else if (digitalRead(2) == LOW) {
    switchCurrentlyPressed = 0;
  }

  if (onOffStatus == 0) {
    analogWrite(redPin, ledBrightness);
    analogWrite(greenPin, LOW);
  } else {
    analogWrite(redPin, LOW);
    analogWrite(greenPin, ledBrightness);
  }

}

void toggleOnOff() {
  if (onOffStatus == 0) {
    onOffStatus = 1;
  } else {
    onOffStatus = 0;
  }
}


