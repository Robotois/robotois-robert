#include "Ultrasonic.h"
#include "SimpleTimer.h"
#include "Motors.h"

SimpleTimer timer;

Ultrasonic usonic(13, 12);


void navigate() {
  float distance = usonic.read();
  long randNumber = random(0, 2);

  if(distance < 20.00) {
    if(randNumber > 0) {
      turnRight();
    } else {
      turnLeft();
    }
  } else {
    moveForward(64);
  }
}

void setup() {
  initializeMotors();
  timer.setInterval(500, &navigate);
}

void loop() {
  timer.run();
}
