#include "monitor_posture_sender.h"


MonitorPostureSender::MonitorPostureSender() {
    radarPackage = {0, 0};
    errorLed = Led(PIN_ERROR_LED);
    statusLed = Led(PIN_STATUS_LED);
}

void MonitorPostureSender::loop_100ms() {
#if CFG_USE_RADAR
    distance = radar.getDistance();
    radarPackage.distance = distance;
#endif
    radarPackage.counter++;
#if CFG_USE_RADIO
    radio.sendData(&radarPackage, sizeof(radarPackage));
    // TODO: the error flag is set even if the communication is working.
    //if (radio.txError())
    //    errorLed.on();
    //else
    //    errorLed.off();
#endif
    MonitorPosture::loop_100ms();
}

void MonitorPostureSender::loop() {
    if (state == BAD_POSTURE) 
        statusLed.on();
    else
        statusLed.off();
}

void MonitorPostureSender::setup() {
#if CFG_USE_RADIO
    radio.setup();
#endif
}                                                      
