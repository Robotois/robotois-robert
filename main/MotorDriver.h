#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include <Arduino.h>

class MotorDriver {
  private:

    uint8_t pwmPins[2] = {0};
    uint8_t cwPins[2] = {0};
    uint8_t ccwPins[2] = {0};
    const uint8_t CW_DIR = 1;
    const uint8_t CCW_DIR = 2;
    const int PWM_MIN = -255;
    const int PWM_MAX = 255;
  public:
    MotorDriver(/* args */);
    ~MotorDriver();
    void beginMotor(
      uint8_t ccwPin,
      uint8_t cwPin,
      uint8_t pwmPin,
      uint8_t motorIdx      
    );
    void begin();
    void motorPWM(int pwm, uint8_t motorIdx);
    void setDirection(uint8_t motorIdx, uint8_t dir);
    void drive(int speedLeft, int speedRight);
    void moveForward(int speed);
    void moveBackward(int speed);
    void motorLeft(int speed);
    void motorRight(int speed);
    void turnLeft();
    void turnRight();
    void stop();
    int pwmBound(int value);
};

extern MotorDriver Motors;
#endif