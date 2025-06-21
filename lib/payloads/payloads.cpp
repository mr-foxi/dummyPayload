#include <payloads.h>

PAYLOADS::PAYLOADS() {}

payloadCode parsePayload(String targetPayload) {
    targetPayload.trim();
    // if (targetPayload == "payload") return PAYLOAD_TEST00;
    // if (targetPayload == "TESTING 00 ##!~") return PAYLOAD_TEST01;
    if (targetPayload == "TESTING 00 ##!~") return PAYLOAD_SDCARD00;
    if (targetPayload == "") return PAYLOAD_EMPTY;
    if (targetPayload == "???") return PAYLOAD_ERROR;
    return PAYLOAD_UNKNOWN;
    }
void PAYLOADS::usePayload(String targetPayload) {
    switch(parsePayload(targetPayload)) {
        // case PAYLOAD_TEST00:
        //     payloads.testPayload();
        //     Serial.println("PAYLOADTEST_00 COMPLETE");
        //     Serial1.println("#Roger Roger#");
        //     break;
        // case PAYLOAD_TEST01:
        //     payloads.testPayload();
        //     Serial.println("PAYLOADTEST_01 COMPLETE");
        //     Serial1.println("#Roger Roger#");
        //     break;
        case PAYLOAD_SDCARD00:
            Serial.println("PAYLOAD_SDCARD00 INITIATING");
            payloads.testPayload();
            Serial1.println("#Roger Roger#"); // REMOVED AS SENDS WHEN STARTING COMMAND, AND HARD TO MAKE 
            break;
        case PAYLOAD_EMPTY:
            Serial.println("Payload Request Empty...");
            break;
        case PAYLOAD_ERROR:
            Serial.println("Response Error");
            break;
        case PAYLOAD_UNKNOWN:
            Serial.print("Payload Request Unknown: ");
            Serial.println(targetPayload);
            break;
    }
}

void PAYLOADS::testPayload() {
    Serial.println("PAYLOAD_SDCARD00 COMPLETED");
}

PAYLOADS payloads = PAYLOADS();


