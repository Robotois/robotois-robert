#ifndef Ultrasonic_h
#define Ultrasonic_h

#include <Arduino.h>

class Ultrasonic {
  private:
    int TRIGGER_PIN;
    int ECHO_PIN;
    int RPS;
    static const unsigned int MAX_DIST;
    float prevValue = 0, value = 0;
    volatile bool startRead = false;
    bool onRead = false;
  public:
    Ultrasonic(int trigger, int echo);
    Ultrasonic(int trigger, int echo, int rps);
    void begin();
    void trigger();
    float read();
    void loop(void (*func)(float value, float prevValue));
    ~Ultrasonic();
};

#endif
