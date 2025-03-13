#include <Mouse.h>

const int downPin = 0;
const int upPin = 1;
int buttonState0 = 0;
int buttonState1 = 0;

void setup() {
  Serial.begin(115200);
  pinMode(downPin, INPUT_PULLDOWN);
  pinMode(upPin, INPUT_PULLDOWN);
  Mouse.begin();
  delay(5000);
}

void loop() {
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

