#include "monitor_posture.h"
#include "config.h"
#include "mcu.h"
#if CFG_USE_RADAR
#include "radar.h"
#endif
#if CFG_USE_RADIO
#include "radio.h"
#endif
#include "led.h"

class MonitorPostureSender: public MonitorPosture {

public:
#if CFG_USE_RADAR
    Radar radar;
#endif
#if CFG_USE_RADIO
    Radio radio;
#endif
    Led errorLed;
    Led statusLed;
    radar_package_t radarPackage;

public:
    MonitorPostureSender();
    void loop_100ms();
    void loop();
    void setup();
};
