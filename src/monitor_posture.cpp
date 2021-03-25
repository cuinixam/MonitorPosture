#include "monitor_posture.h"

MonitorPosture::MonitorPosture()
{
    state = UNKNOWN;
    counter = 0;
    distance = 0;
    timestamp = 0;
}

void MonitorPosture::loop_100ms()
{
    MonitorPosture::State newState = determineState(distance);
    if (state == newState)
        decrementCounter();
    else
        incrementCounter();

    if (counter >= DETECTION_THRESHOLD)
    {
        counter = 0;
        state = newState;
    }
}

void MonitorPosture::loop()
{

}

void MonitorPosture::incrementCounter()
{
    if (counter + DETECTION_INCREMENT > DETECTION_THRESHOLD)
        counter = DETECTION_THRESHOLD;
    else
        counter += DETECTION_INCREMENT;
}

void MonitorPosture::decrementCounter()
{
    if (counter - DETECTION_DECREMENT < 0)
        counter = 0;
    else
        counter -= DETECTION_DECREMENT;
}

MonitorPosture::State MonitorPosture::determineState(int distance)
{
    MonitorPosture::State state;
    if (distance < PRESENT_MAX_THRESHOLD)
        state = PRESENT;
    else if (distance > NOT_PRESENT_MIN_THRESHOLD)
        state = NOT_PRESENT;
    else
        state = BAD_POSTURE;
    return state;
}

void MonitorPosture::setup()
{
}