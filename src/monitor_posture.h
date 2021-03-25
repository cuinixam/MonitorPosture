#ifndef _monitor_posture_h_
#define _monitor_posture_h_

#include "config.h"

/* Debounce time for switching states [100ms] */
#define DETECTION_THRESHOLD 10
#define DETECTION_INCREMENT 1
#define DETECTION_DECREMENT 2

/* Distances greater than this thereshold means not present [mm]*/
#define NOT_PRESENT_MIN_THRESHOLD 500
/* Distances lower that this threshold means present [mm] */
#define PRESENT_MAX_THRESHOLD 250

class MonitorPosture
{
public:
    enum State
    {
        UNKNOWN,
        PRESENT,
        NOT_PRESENT,
        BAD_POSTURE
    };
public:
    MonitorPosture();
    void loop_100ms();
    void loop();
    void setup();

public:
    State state;
    int counter;
    unsigned long timestamp;
    int distance;

    State determineState(int distance);
    void incrementCounter();
    void decrementCounter();
};

#endif
