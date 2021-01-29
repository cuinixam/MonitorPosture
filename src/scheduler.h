#include "types.h"
/* How many different functions will be scheduled */
#define executionListLength 10
#define schedulerNoCallable NULL

#define CFG_USED_TIMER 1

class Scheduler{
   private:
      typedef void (*callable)();
      Scheduler::callable executionList[executionListLength];
      unsigned char counter_1ms = 0;

   public:
      Scheduler();
      bool Attach(Scheduler::callable);
      void Start(void);
      void Task_10ms(void);
      void Task_1ms(void);   

   private:
      void ClearScheduleQueue(void);
      void ConfigureTimer(void);
      void ConfigureTimer1(void);
      void ConfigureTimer2(void);
      void StartTimer(void);
};

extern Scheduler scheduler;
