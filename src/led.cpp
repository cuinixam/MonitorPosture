#include "led.h"

Led::Led() {
   Led(LED_BUILTIN);
}

Led::Led(uint8_t ioPin)
{
    pin = ioPin;
    blink_counter = 0;
    blink_status = true;
    timestamp = 0;
    pinMode(pin, OUTPUT);
}

Led::~Led()
{
}

void Led::loop(unsigned int period) {
    blink_counter++;
   if (blink_counter > period)
   {
      timestamp = millis();
      blink_counter = 0;
      if (blink_status)
      {
         on();
         blink_status = false;
      }
      else
      {
         off();
         blink_status = true;
      }
   }
}

void Led::loop_10ms() {
   loop(100);
}

void Led::loop_100ms() {
   loop(10);
}

void Led::on() {
   digitalWrite(pin, HIGH);
}

void Led::off() {
   digitalWrite(pin, LOW);
}