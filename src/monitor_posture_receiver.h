#include "monitor_posture.h"
#include "config.h"
#include "mcu.h"
#if (CFG_USE_DISPLAY)
#include "display.h"
#endif
#include "speaker.h"
#if CFG_USE_RADIO
#include "radio.h"
#endif
#include "led.h"


class MonitorPostureReceiver: public MonitorPosture
{
public:
    MonitorPostureReceiver();
    void loop_100ms();
    void loop();
    void setup();

public:
    Led statusLed;
    radar_package_t radarPackage;
#if CFG_USE_DISPLAY
    Display display;
#endif
#if CFG_USE_RADIO
    Radio radio;
#endif
    Speaker speaker;

};
