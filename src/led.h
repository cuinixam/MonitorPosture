#ifndef _led_h_
#define _led_h_

#include "mcu.h"

class Led
{
public:
    unsigned int blink_counter;
    bool blink_status;
    unsigned long timestamp;
    uint8_t pin;

private:
    void loop(unsigned int);

public:
    Led();
    Led(uint8_t ioPin);
    ~Led();
    void loop_10ms();
    void loop_100ms();
    void on();
    void off();
};

#endif
