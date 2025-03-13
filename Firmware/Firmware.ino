/* Created by JEvan234
Part of the Mock-Deck Project on Github
https://github.com/JEvan234/Mock-Deck

This File serves as the INO file, or "firmware" that will be flashed to your pico.
In my case I am using a Pico 2.

3/12/2025 - As of right now all pins are according to my setup as I work things out
*/

// Header Files:
#include <Mouse.h>


// States and declared pins. Pins are constant and are declared as such
// Pins 1 and 2 on Pico
const int downPin = 0;
const int upPin = 1;
// Buttonstates help read High and Low, and can change
int buttonState0 = 0;
int buttonState1 = 0;


void setup() {
  // Establishes a serial connection using a "115200" Baud rate, which is default for the Pico 2
  Serial.begin(115200);
  // Establishes pins as inputs
  pinMode(downPin, INPUT_PULLDOWN);
  pinMode(upPin, INPUT_PULLDOWN);
  Mouse.begin();
  delay(5000);
}

void loop() {
  // Reads States abd performs actions accordingly
  buttonState0 = digitalRead(downPin);
  buttonState1 = digitalRead(upPin);
  if (buttonState0 == HIGH) {
    Mouse.move(0, 0, -1);
  }
  if (buttonState1 == HIGH) {
    Mouse.move(0, 0, 1);
  }
  else {
    Mouse.move(0,0,0);
  }
}

