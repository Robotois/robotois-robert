#ifndef DigitalIO_h
#define DigitalIO_h
#include "Arduino.h"

class DigitalIO
{
  private:
    /* data */
    uint8_t ioPin;
    uint8_t direction;
    uint8_t inverted;
  public:
    DigitalIO(uint8_t pin, uint8_t dir);
    DigitalIO(uint8_t pin, uint8_t dir, uint8_t inv);
    ~DigitalIO();

    uint8_t read();
    void write(uint8_t state);
};

#endif