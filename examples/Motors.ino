#include "Ultrasonic.h"
#include "SimpleTimer.h"
#include "MotorDriver.h"
#include "DigitalIO.h"

int speed = 0, steps = 20;

void motorTest() {
  speed += steps;
  Motors.drive(speed, speed);
  if (speed >= 100) {
    steps = -20;
  }
  if (speed <= -100) {
    steps = 20;
  }
}

void setup() {
  Motors.begin();
  Serial.begin(115200);
  Serial.println("---> Ultrasonic test");
  Timer.setInterval(1000, &motorTest);
}

void loop() {
  Timer.run();
}
