#include <TM1637Display.h>

class Display: public TM1637Display {
public:
   Display();
   void show(unsigned int number);
};