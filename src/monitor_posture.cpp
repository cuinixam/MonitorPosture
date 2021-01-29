#include "monitor_posture.h"
#include "mcu.h"

/* Debounce time for switching states [10ms] */
#define DETECTION_THRESHOLD 100
#define DETECTION_INCREMENT 1
#define DETECTION_DECREMENT 2

/* Distances greater than this thereshold means not present [mm]*/
#define NOT_PRESENT_MIN_THRESHOLD   500
/* Distances lower that this threshold means present [mm] */
#define PRESENT_MAX_THRESHOLD   250


MonitorPosture::MonitorPosture()
{
    state = UNKNOWN;
    counter = 0;
    distance = 0;
    timestamp = 0;
#if CFG_USE_DISPLAY
    display = Display();
#endif
    radar = Radar();
    speaker = Speaker();
    led = Led();
}

void MonitorPosture::loop_10ms() {
    led.loop_10ms();
    MonitorPosture::State newState = determineState(distance);
    if (state == newState) {
        decrementCounter();
    } else {
        incrementCounter();
    }

    if (counter >= DETECTION_THRESHOLD) {
        counter = 0;
        state = newState;
    }
}

void MonitorPosture::loop() {
    distance = radar.getDistance();
#if CFG_USE_DISPLAY
    display.show(distance);
#endif
    if (state == BAD_POSTURE) {
        speaker.sound_on();
        led.on();
    } else {
        speaker.sound_off();
    }
}                       

void MonitorPosture::incrementCounter() {
    if (counter + DETECTION_INCREMENT > DETECTION_THRESHOLD) {
        counter = DETECTION_THRESHOLD;
    } else {
        counter += DETECTION_INCREMENT;
    }
}

void MonitorPosture::decrementCounter() {
    if (counter - DETECTION_DECREMENT < 0) {
        counter = 0;
    } else {
        counter -= DETECTION_DECREMENT;
    }
}

MonitorPosture::State MonitorPosture::determineState(int distance) {
    MonitorPosture::State state;
    if (distance < PRESENT_MAX_THRESHOLD) {
        state = PRESENT;
    } else if (distance > NOT_PRESENT_MIN_THRESHOLD) {
        state = NOT_PRESENT;
    } else {
        state = BAD_POSTURE;
    }
    return state;
}