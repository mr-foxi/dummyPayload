#include <serial.h>

SERIALCOM::SERIALCOM() {}

void SERIALCOM::up() {
    Serial.begin(115200); // USB Serial for Arduino Due
    Serial1.begin(115200); // Pin 18 (TX1) & Pin 19 (RX1) for Arduino Due
    delay(50);
};

SERIALCOM serialCom = SERIALCOM();