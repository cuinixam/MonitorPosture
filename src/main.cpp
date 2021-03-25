#include "config.h"
#include "mcu.h"
#include "scheduler.h"

#if (APP_CONFIG == APP_MEASURE_DISTANCE)

#include "monitor_posture_sender.h"
#include "led.h"

MonitorPostureSender monitorPostureSender;
Led led;

void Task(void)
{
#if SERIAL_DEBUG
   //Serial.println("Task!");
#endif
   monitorPostureSender.loop_100ms();
#if CFG_TOGGLE_DEBUG_LED_IN_TASK
   led.loop_100ms();
#endif
}

void setup()
{
#if SERIAL_DEBUG
   Serial.begin(9600);
#endif
   monitorPostureSender.setup();
   scheduler.Attach(Task, Scheduler::TASK_100MS);
   scheduler.Start();
#if SERIAL_DEBUG
   Serial.println("Setup done");
#endif
}

void loop() {
   monitorPostureSender.loop();
#if SERIAL_DEBUG
   Serial.print("Radar distance: ");
   Serial.println(monitorPostureSender.distance);
   //Serial.print("Package size: ");
   //Serial.println(sizeof(measureDistance.radarPackage));
   Serial.print("Package counter: ");
   Serial.println(monitorPostureSender.radarPackage.counter);
   delay(1000);
#endif
}

#elif (APP_CONFIG == APP_MONITOR_POSTURE)
#include "monitor_posture_receiver.h"
#include "led.h"

MonitorPostureReceiver monitorPostureReceiver;
#if CFG_TOGGLE_DEBUG_LED_IN_TASK
Led led(PIN_DEBUG_LED);
#endif

void Task(void)
{
#if SERIAL_DEBUG
   //Serial.println("Task!");
#endif
   monitorPostureReceiver.loop_100ms();
#if CFG_TOGGLE_DEBUG_LED_IN_TASK
   led.loop_100ms();
#endif
}

void setup()
{
#if SERIAL_DEBUG
   Serial.begin(9600);
#endif
   monitorPostureReceiver.setup();
   scheduler.Attach(Task, Scheduler::TASK_100MS);
   scheduler.Start();
#if SERIAL_DEBUG
   Serial.println("Setup done");
#endif
}

void loop() {
   monitorPostureReceiver.loop();
#if SERIAL_DEBUG
   Serial.print("Radar distance: ");
   Serial.println(monitorPostureReceiver.radarPackage.distance);
   delay(100);
#endif
}

#elif (APP_CONFIG == APP_PROTOTYPING)
#include "display.h"
#include "radar.h"
#include "speaker.h"
#include "led.h"

Display display;
Radar radar;
Speaker speaker;
Led led(PIN_DEBUG_LED);
int dist_mm;

void Task(void)
{
   led.loop_100ms();
}

void setup()
{
   Serial.begin(9600);
   scheduler.Attach(Task, Scheduler::TASK_100MS);
   scheduler.Start();
}

void loop()
{
#if 0
   //Serial.println("Counter 10ms: " + scheduler.counter_10ms);
   delay(500);
#endif
#if 0
   speaker.sound_off();
   delay(500);
   //speaker.sound_on();
   delay(500);
#endif
#if 0
   dist_mm = radar.getDistance();
   display.show(dist_mm);
   if (dist_mm <500) {
      speaker.sound_on();
   } else {
      speaker.sound_off();
   }
   //Serial.print("Distance ");
   //Serial.print(dist_mm);
   //Serial.println("[mm]");
#endif
}

#endif
