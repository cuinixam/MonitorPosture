#include "display.h"
#include "radar.h"
#include "speaker.h"
#include "led.h"

#define CFG_USE_DISPLAY 0

class MonitorPosture
{
    enum State
    {
        UNKNOWN,
        PRESENT,
        NOT_PRESENT,
        BAD_POSTURE
    };

public:
    State state;
    int counter;
    MonitorPosture();
    void loop_10ms();
    void loop();

private:
    unsigned long timestamp;
    int distance;
#if CFG_USE_DISPLAY
    Display display;
#endif
    Radar radar;
    Speaker speaker;
    Led led;

    State determineState(int distance);
    void incrementCounter();
    void decrementCounter();
};
