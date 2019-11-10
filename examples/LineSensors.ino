#include "SimpleTimer.h"
#include "DigitalIO.h"

// Ultrasonic usonic(13, 12);

//  void sensorRead() {
//    float distance = usonic.read();
//    Serial.println("Ultrasonic: " + String(distance, DEC) + "[cm]");
//  }

DigitalIO lineSensor1(A5, INPUT);
DigitalIO lineSensor2(A4, INPUT);
DigitalIO lineSensor3(A3, INPUT);

void ioTest() {
 uint8_t state1 = lineSensor1.read();
 uint8_t state2 = lineSensor2.read();
 uint8_t state3 = lineSensor3.read();
 Serial.println("Sensor Status: " + String(state1, DEC) + ", " + String(state2, DEC) + ", " + String(state3, DEC));
}

void setup() {
  // initializeMotors();
  Serial.begin(115200);
  Serial.println("---> Ultrasonic test");
  // timer.setInterval(500, &sensorRead);
  Timer.setInterval(500, &ioTest);
}

void loop() {
  Timer.run();
  // motorsTest();
}
