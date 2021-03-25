#include "radio.h"

byte RADIO_ADDRESS[6] = "00001";

Radio::Radio()
:RF24(PIN_RADIO_CE, PIN_RADIO_CSN, RF24_SPI_SPEED) {

}

void Radio::sendData(const void* buf, uint8_t len) {
    write(buf, len);
}

boolean Radio::txError() {
    bool tx_ok, tx_fail, rx_ready;
    whatHappened(tx_ok, tx_fail, rx_ready);
    return (!tx_ok);
}

boolean Radio::rxReady() {
    bool tx_ok, tx_fail, rx_ready;
    whatHappened(tx_ok, tx_fail, rx_ready);
    return rx_ready;
}

void Radio::setup() {
    begin();
#if (CFG_RADIO_MODE == RADIO_TRANSMITTER)
    openWritingPipe(RADIO_ADDRESS);
    setPALevel(RF24_PA_LOW);
    stopListening();
#endif
#if (CFG_RADIO_MODE == RADIO_RECEIVER)
    openReadingPipe(0, RADIO_ADDRESS);
    setPALevel(RF24_PA_LOW);
    startListening();
#endif

}