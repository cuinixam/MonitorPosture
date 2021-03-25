#ifndef _config_h_
#define _config_h_

/* Use this only to force a certain mode.
Only needed for enabling the active code in the editor */
//#define APP_CONFIG APP_MONITOR_POSTURE

#define APP_MEASURE_DISTANCE   1
#define APP_MONITOR_POSTURE    2
#define APP_PROTOTYPING        3

#define RADIO_TRANSMITTER 1
#define RADIO_RECEIVER    2

#if (APP_CONFIG == APP_MEASURE_DISTANCE)

#define SERIAL_DEBUG 0
#define CFG_TOGGLE_DEBUG_LED_IN_TASK 0
#define CFG_USE_RADIO 1
#define CFG_USE_RADAR 1
#define CFG_RADIO_MODE RADIO_TRANSMITTER

#elif (APP_CONFIG == APP_MONITOR_POSTURE)

#define SERIAL_DEBUG 0
#define CFG_TOGGLE_DEBUG_LED_IN_TASK 0
#define CFG_USE_DISPLAY 0
#define CFG_USE_RADIO 1
#define CFG_USE_SPEAKER 1
#define CFG_RADIO_MODE RADIO_RECEIVER

#else


#endif

#endif