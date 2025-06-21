#include <sd.h>

SDCARD::SDCARD() {}

void SDCARD::init() {
    pinMode(pinSD, OUTPUT);
    digitalWrite(pinSD, HIGH);
    delay(500);
    if (!SD.begin(pinSD)) {
        Serial.println("[SD] Initialization failed.");
        while (1);
    }
    Serial.println("[SD] Ready.");
}

void SDCARD::up() {
    Serial.println("[SD] CS HIGH");
    digitalWrite(pinSD, HIGH);
    delay(10);
}

void SDCARD::down() {
    Serial.println("[SD] CS LOW");
    digitalWrite(pinSD, LOW);
    delay(10);
}

String SDCARD::getPayload(String payloadName) {
    sd.down();
    sd.init();
    String payload;
    File payloadFile = SD.open(payloadName);
    if (!payloadFile) {
        Serial.println("Failed to open source file!");
        return "!ERROR 333: Payload Retrieval!";
    }
    while (payloadFile.available()) {
        payload += (char)payloadFile.read();
    }
    payloadFile.close();
    delay(50);
    return payload;
}

SDCARD sd = SDCARD();