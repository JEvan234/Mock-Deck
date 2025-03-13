/* Created by JEvan234
Part of the Mock-Deck Project on Github
https://github.com/JEvan234/Mock-Deck

This File serves as the INO file, or "firmware" that will be flashed to your pico.
In my case I am using a Pico 2.

3/12/2025 - As of right now all pins are according to my setup as I work things out
*/

// Header Files:
#include <Mouse.h>


// Pin name cooresponds with pico 2 datasheet (Refer to attached image)
// PINS 3/8 are Grounds
const int PIN1 = 0;
const int PIN2 = 1;
const int PIN4 = 2;
const int PIN5 = 3;
const int PIN6 = 4;
const int PIN7 = 5;
const int PIN9 = 6;
const int PIN10 = 7;
// States match the cooresponding pins
int State1 = 0;
int State2 = 0;


void setup() {
  // Establishes a serial connection using a "115200" Baud rate, which is default for the Pico 2
  Serial.begin(115200);
  // Establishes pins as inputs
  pinMode(PIN1, INPUT_PULLDOWN);
  pinMode(PIN2, INPUT_PULLDOWN);
  Mouse.begin();
  delay(5000);
}

void loop() {
  // Reads States abd performs actions accordingly
  State1 = digitalRead(PIN1);
  State2 = digitalRead(PIN2);
  if (State1 == HIGH) {
    Mouse.move(0, 0, -1);
  }
  if (State2 == HIGH) {
    Mouse.move(0, 0, 1);
  }
  else {
    Mouse.move(0,0,0);
  }
}

