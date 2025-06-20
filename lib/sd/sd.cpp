#include <sd.h>

SDCARD::SDCARD() {}

void SDCARD::init() {
    pinMode(pinSD, OUTPUT);
    digitalWrite(pinSD, HIGH);
    delay(500);
    if (!SD.begin(pinSD)) {
        Serial.println("[SD] Initialization failed.");
        Serial1.println("[SD] Initialization failed.");
        while (1);
    }
    Serial.println("[SD] Ready.");
    Serial1.println("[SD] Ready.");
}

void SDCARD::up() {
    Serial.println("[SD] CS HIGH");
    Serial1.println("[SD] CS HIGH");
    digitalWrite(pinSD, HIGH);
    delay(10);
}

void SDCARD::down() {
    Serial.println("[SD] CS LOW");
    Serial1.println("[SD] CS LOW");
    digitalWrite(pinSD, LOW);
    delay(10);
}

SDCARD sd = SDCARD();