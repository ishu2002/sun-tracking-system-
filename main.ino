#include <Servo.h>

Servo tracker;
int ldrLeft = A0;
int ldrRight = A1;
int pos = 90;

void setup() {
  tracker.attach(9);
  tracker.write(pos);
}

void loop() {
  int leftValue = analogRead(ldrLeft);
  int rightValue = analogRead(ldrRight);
  int error = leftValue - rightValue;

  if (abs(error) > 50) {
    if (error > 0 && pos > 0) pos--;
    if (error < 0 && pos < 180) pos++;
    tracker.write(pos);
    delay(15);
  }
}
