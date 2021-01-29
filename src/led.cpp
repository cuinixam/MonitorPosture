#include "led.h"
#include "mcu.h"

Led::Led(/* args */)
{
    blink_counter = 0;
    blink_status = true;
    timestamp = 0;
}

Led::~Led()
{
}

void Led::loop_10ms() {
    blink_counter++;
   if (blink_counter > 100)
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

void Led::on() {
   digitalWrite(LED_BUILTIN, HIGH);
}

void Led::off() {
   digitalWrite(LED_BUILTIN, LOW);
}