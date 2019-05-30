#include "Ultrasonic.h"

// Anything over 400 cm (23200 us pulse) is "out of range"
const unsigned int Ultrasonic::MAX_DIST = 23200;

Ultrasonic::Ultrasonic(int trigger, int echo) {
  TRIGGER_PIN = trigger;
  ECHO_PIN = echo;
  RPS = 5;
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);  
}

void Ultrasonic::begin() {
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);  
}

Ultrasonic::Ultrasonic(int trigger, int echo, int rps) {
  TRIGGER_PIN = trigger;
  ECHO_PIN = echo;
  RPS = rps;
}

Ultrasonic::~Ultrasonic() {

}

void Ultrasonic::trigger() {
  startRead = true;
}

float Ultrasonic::read() {
  unsigned long t1;
  unsigned long t2;
  unsigned long pulse_width;

  // Hold the trigger pin high for at least 10 us
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Wait for pulse on echo pin
  while ( digitalRead(ECHO_PIN) == 0 );

  // Measure how long the echo pin was held high (pulse width)
  // Note: the micros() counter will overflow after ~70 min
  t1 = micros();
  while ( digitalRead(ECHO_PIN) == 1);
  t2 = micros();
  pulse_width = t2 - t1;

  // Calculate distance in centimeters and inches. The constants
  // are found in the datasheet, and calculated from the assumed speed 
  //of sound in air at sea level (~340 m/s).
  // inches = pulse_width / 148.0;

  // // Print out results
  if ( pulse_width > MAX_DIST ) {
    prevValue = value;
    value = 400;
  } else {
    prevValue = value;
    value = pulse_width / 58.0f;
  }
  
  onRead = true;
  startRead = false;
  return value;
}

void Ultrasonic::loop(void (*func)(float value, float prevValue)) {
  if (startRead) {
    read();
  }
  if (onRead) {
    func(value, prevValue);
    onRead = false;
  }
}