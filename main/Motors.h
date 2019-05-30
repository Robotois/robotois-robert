#include <Arduino.h>
const uint8_t CW_DIR = 1;
const uint8_t CCW_DIR = 2;

uint8_t pwmPins[2] = {};
uint8_t cwPins[2] = {};
uint8_t ccwPins[2] = {};

int PWM_MIN = -255, PWM_MAX = 255;

int pwmBound(int value) {
  if(value < PWM_MIN) {
    return PWM_MIN;
  }
  if(value > PWM_MAX) {
    return PWM_MAX;
  }
  return value;
}

void motorsInit(
  uint8_t ccwPin,
  uint8_t cwPin,
  uint8_t pwmPin,
  uint8_t motorIdx
) {
  pwmPins[motorIdx] = pwmPin;
  cwPins[motorIdx] = cwPin;
  ccwPins[motorIdx] = ccwPin;

  pinMode(cwPin, OUTPUT);
  pinMode(ccwPin, OUTPUT);
  digitalWrite(cwPin, LOW);
  digitalWrite(ccwPin, LOW);

  pinMode(pwmPin, OUTPUT);
  analogWrite(pwmPin, 0);
}

void setDirection(uint8_t motorIdx, uint8_t dir) {
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

void motorPWM(int pwm, uint8_t motorIdx) {
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
 * User intended functions
*/
void initializeMotors() {
  // Left motor
  motorsInit(7, 8, 6, 1);
  // Right motor
  motorsInit(4, 3, 5, 0);
}

/**
 * Speed is intended to move the wheels forward and backwards 
*/
void drive(int speedLeft, int speedRight) {
  motorPWM(speedLeft * -1, 0);
  motorPWM(speedRight, 1);
}

void moveForward(int speed) {
  drive(speed, speed);
}

void moveBackward(int speed) {
  drive(-speed, -speed);
}

void motorLeft(int speed) {
  motorPWM(speed, 0);
}

void motorRight(int speed) {
  motorPWM(speed, 1);
}

void turnLeft() {
  drive(0, 64);
}

void turnRight() {
  drive(64, 0);
}

void stop() {
  motorPWM(0, 0);
  motorPWM(0, 1);
}

int pwm = 0;
int increase = 5;

void motorsTest() {
  Serial.println("Move Forward => drive(64, 64)");
  drive(64, 64);
  delay(2000);
  stop();
  delay(1000);
  Serial.println("Move Backward => drive(-64, -64)");
  drive(-64, -64);
  delay(2000);
  stop();
  delay(1000);
  Serial.println("Move Forward => moveForward(64)");
  moveForward(64);
  delay(2000);
  stop();
  delay(1000);
  Serial.println("Move Backward => moveBackward(64)");
  moveBackward(64);
  delay(2000);
  stop();
  delay(1000);
  Serial.println("Motor Left ClockWise => motorLeft(64)");
  motorLeft(64);
  delay(2000);
  stop();
  delay(1000);
  Serial.println("Motor Left CounterClockWise => motorLeft(-64)");
  motorLeft(-64);
  delay(2000);
  stop();
  delay(1000);
  Serial.println("Motor Right ClockWise => motorRight(64)");
  motorRight(64);
  delay(2000);
  stop();
  delay(1000);
  Serial.println("Motor Right CounterClockWise => motorRight(-64)");
  motorRight(-64);
  delay(2000);
  stop();
  delay(1000);
  Serial.println("Turn Left => turnLeft()");
  turnLeft();
  delay(2000);
  stop();
  delay(1000);
  Serial.println("Turn Right => turnRight()");
  turnRight();
  delay(2000);
  stop();
  delay(1000);
}