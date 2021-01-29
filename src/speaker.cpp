#include "speaker.h"
#include "mcu.h"

Speaker::Speaker() {
    init();
}

void Speaker::init(void) {
   pinMode(PIN_SPEAKER_OUT, OUTPUT);
}

void Speaker::sound_on() {
    tone(PIN_SPEAKER_OUT, 988);
}

void Speaker::sound_off() {
    noTone(PIN_SPEAKER_OUT);
}