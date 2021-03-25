#include "radar.h"
#include "mcu.h"

/**
 * Cut-off frequency: 100 Hz
 * Sampling frequency: 1000 Hz
 */
//0.38 // a
#define FILT_PARAM_A    1
//0.61 // 1-a
#define FILT_PARAM_B    0

// 2 meters - 2000mm
#define RADAR_MAX_VALID_VALUE 2000

Radar::Radar() {
   setup();
}

int Radar::getDistance(void) {
   int distance_mm = 0;
   long time_us=0;
   
   digitalWrite(PIN_RADAR_TRIGGER, LOW);
   delayMicroseconds(3);
   digitalWrite(PIN_RADAR_TRIGGER, HIGH);
   delayMicroseconds(10);
   digitalWrite(PIN_RADAR_TRIGGER, LOW);
   time_us = pulseIn(PIN_RADAR_ECHO, HIGH);
   time_us = filterLowPass(time_us, time_filt_prev);
   time_filt_prev = time_us;
   /* The time is for both ways, to the object and back */
   distance_mm = constrain((int)(((float)time_us)*0.34/2), 0, RADAR_MAX_VALID_VALUE);
   return(distance_mm);
}

long Radar::filterLowPass(long value, long prev_value) {
   return (long)(FILT_PARAM_A*(float)value + FILT_PARAM_B*(float)prev_value);
}

void Radar::setup(void) {
   pinMode(PIN_RADAR_TRIGGER, OUTPUT);
   pinMode(PIN_RADAR_ECHO, INPUT);
   time_filt_prev = 0;
}