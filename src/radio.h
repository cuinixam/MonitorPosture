#include "config.h"
#include "hw_config.h"
#include "RF24.h"

class Radio: public RF24
{
public:
    Radio();
    void setup();
    void sendData(const void* buf, uint8_t len);
    boolean txError();
    boolean rxReady();
};
