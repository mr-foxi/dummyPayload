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
    String payload;
    File payloadFile = SD.open(payloadName);
    if (!payloadFile) {
        Serial.println("Failed to open source file!");
        return "";
    }
    while (payloadFile.available()) {
        payload += (char)payloadFile.read();
    }
    payloadFile.close();
    return payload;
}

void SDCARD::copy() {
    // Open the original file
    File sourceFile = SD.open("source.bin");
    if (!sourceFile) {
        Serial.println("Failed to open source file!");
        return;
    }

    // Create a new file on the same SD for the copy
    File destFile = SD.open("copy.bin", FILE_WRITE);
    if (!destFile) {
        Serial.println("Failed to create destination file!");
        sourceFile.close();
        return;
    }

    // Copy the file content
    // Use a buffer (array) to read and write chunks of data
    const int BUFFER_SIZE = 512; // A common and efficient buffer size for SD card operations
    uint8_t buffer[BUFFER_SIZE];
    int bytesRead;

    while ((bytesRead = sourceFile.read(buffer, sizeof(buffer))) > 0) {
        destFile.write(buffer, bytesRead);
    }

    // Close both files
    sourceFile.close();
    destFile.close();

    Serial.println("File copied successfully!");
}

SDCARD sd = SDCARD();