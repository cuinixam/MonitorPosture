#include "monitor_posture_receiver.h"

MonitorPostureReceiver::MonitorPostureReceiver():MonitorPosture()
{
    statusLed = Led(PIN_STATUS_LED);
}

void MonitorPostureReceiver::loop_100ms()
{
    MonitorPosture::loop_100ms();
#if CFG_USE_DISPLAY
    display.show(100);
#endif
#if CFG_USE_RADIO
    // TODO: the error flag is set even if the communication is working.
    //if (!radio.rxReady())
    //    errorLed.on();
    //else
    //    errorLed.off();
#endif
}

void MonitorPostureReceiver::loop()
{
#if CFG_USE_RADIO
    if (radio.available())
    {
        radio.read(&radarPackage, sizeof(radarPackage));
        distance = radarPackage.distance;
    }
#endif
    if (state == BAD_POSTURE) 
    {
#if CFG_USE_SPEAKER
        speaker.sound_on();
#endif
        statusLed.on();
    }
    else
    {
#if CFG_USE_SPEAKER
        speaker.sound_off();
#endif
        statusLed.off();
    }
}

void MonitorPostureReceiver::setup()
{
#if CFG_USE_RADIO
    radio.setup();
#endif
}