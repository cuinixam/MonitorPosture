#include "display.h"
#include "mcu.h"

Display::Display() : TM1637Display(PIN_DISPLAY_CLK, PIN_DISPLAY_DIO) {
   setBrightness(0x0a);
   /* Configure available segments */
   unsigned char segments_cfg[] = { 0xff, 0xff, 0xff, 0xff };
   setSegments(segments_cfg);
}

void Display::show(unsigned int number) {
   showNumberDec(number, false, 4, 4); 
}