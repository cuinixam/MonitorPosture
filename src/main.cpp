#include "mcu.h"
#include "scheduler.h"
#include "monitor_posture.h"

#define DEBUG_MODE 0

#if !DEBUG_MODE

MonitorPosture monitorPosture = MonitorPosture();

void Task10ms(void)
{
   monitorPosture.loop_10ms();
}

void setup()
{
   scheduler.Attach(Task10ms);
   scheduler.Start();
}

void loop() {
   monitorPosture.loop();
}

#else

Display display;
Radar radar;
Speaker speaker;
Led led;
int dist_mm;

void Task10ms(void)
{
   led.loop_10ms();
}

void setup()
{
   Serial.begin(9600);
   scheduler.Attach(Task10ms);
   scheduler.Start();
}

void loop()
{
#if 0
   speaker.sound_off();
   delay(500);
   //speaker.sound_on();
   delay(500);
#endif
#if 1
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

#endif // #if DEBUG_MODE