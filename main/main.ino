// #include "Ultrasonic.h"
#include "SimpleTimer.h"
#include "MotorDriver.h"
// #include "DigitalIO.h"

// Ultrasonic usonic(13, 12);

//  void sensorRead() {
//    float distance = usonic.read();
//    Serial.println("Ultrasonic: " + String(distance, DEC) + "[cm]");
//  }

// DigitalIO lineSensor1(A5, INPUT);
// DigitalIO lineSensor2(A4, INPUT);
// DigitalIO lineSensor3(A3, INPUT);

// void ioTest() {
//  uint8_t state1 = lineSensor1.read();
//  uint8_t state2 = lineSensor2.read();
//  uint8_t state3 = lineSensor3.read();
//  Serial.println("Sensor Status: " + String(state1, DEC) + ", " + String(state2, DEC) + ", " + String(state3, DEC));
// }

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
