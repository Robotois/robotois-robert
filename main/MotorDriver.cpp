#include "MotorDriver.h"

MotorDriver::MotorDriver() {

}

MotorDriver::~MotorDriver() {

}

void MotorDriver::beginMotor(
  uint8_t ccwPin,
  uint8_t cwPin,
  uint8_t pwmPin,
  uint8_t motorIdx
) {
  uint8_t index = motorIdx - 1;
  if (index >= 0 && index <= 1) {
    pwmPins[index] = pwmPin;
    cwPins[index] = cwPin;
    ccwPins[index] = ccwPin;

    pinMode(cwPin, OUTPUT);
    pinMode(ccwPin, OUTPUT);
    digitalWrite(cwPin, LOW);
    digitalWrite(ccwPin, LOW);

    pinMode(pwmPin, OUTPUT);
    analogWrite(pwmPin, 0);
  }
}

void MotorDriver::begin() {
  // Left motor
  beginMotor(7, 8, 6, 2);
  // Right motor
  beginMotor(4, 3, 5, 1);
}

void MotorDriver::setDirection(uint8_t motorIdx, uint8_t dir) {
  switch (dir) {
    case 1: // Clockwise
      digitalWrite(cwPins[motorIdx], HIGH);
      digitalWrite(ccwPins[motorIdx], LOW);
      break;
    case 2: // CounterClockwise
      digitalWrite(cwPins[motorIdx], LOW);
      digitalWrite(ccwPins[motorIdx], HIGH);
      break;
    default:
    // case 0: // Stop on any other value
      digitalWrite(cwPins[motorIdx], LOW);
      digitalWrite(ccwPins[motorIdx], LOW);
  }
}

void MotorDriver::motorPWM(int pwm, uint8_t motorIdx) {
  int newPwm = pwmBound(pwm);
  if(newPwm == 0) {
    setDirection(motorIdx, 0);
    analogWrite(pwmPins[motorIdx], 0);
    return;
  }
  if(newPwm > 0) {
    setDirection(motorIdx, CW_DIR);
    analogWrite(pwmPins[motorIdx], newPwm);
  } else {
    setDirection(motorIdx, CCW_DIR);
    analogWrite(pwmPins[motorIdx], -newPwm);
  }
}

/**
 * Speed is intended to move the wheels forward and backwards 
*/
void MotorDriver::drive(int speedLeft, int speedRight) {
  motorPWM(speedLeft * -1, 0);
  motorPWM(speedRight, 1);
}

void MotorDriver::moveForward(int speed) {
  drive(speed, speed);
}

void MotorDriver::moveBackward(int speed) {
  drive(-speed, -speed);
}

void MotorDriver::motorLeft(int speed) {
  motorPWM(speed, 0);
}

void MotorDriver::motorRight(int speed) {
  motorPWM(speed, 1);
}

void MotorDriver::turnLeft() {
  drive(0, 64);
}

void MotorDriver::turnRight() {
  drive(64, 0);
}

void MotorDriver::stop() {
  motorPWM(0, 0);
  motorPWM(0, 1);
}

int MotorDriver::pwmBound(int value) {
  if(value < PWM_MIN) {
    return PWM_MIN;
  }
  if(value > PWM_MAX) {
    return PWM_MAX;
  }
  return value;
}

MotorDriver Motors;
