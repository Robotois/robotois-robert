#include "DigitalIO.h"

DigitalIO::DigitalIO(uint8_t pin, uint8_t dir) {
  ioPin = pin;
  direction = dir;
  inverted = 0;
  pinMode(pin, dir);
}

DigitalIO::DigitalIO(uint8_t pin, uint8_t dir, uint8_t inv) {
  ioPin = pin;
  direction = dir;
  inverted = inv;
  pinMode(pin, dir);
}

DigitalIO::~DigitalIO() {
}

uint8_t DigitalIO::read() {
  if (direction == INPUT) {
    uint8_t state = digitalRead(ioPin);
    if (inverted == 1) {
      return !state;
    }
    return state;
  }
  return LOW;
}

void DigitalIO::write(uint8_t state) {
  if (direction == OUTPUT) {
    digitalWrite(ioPin, state);
  }
}