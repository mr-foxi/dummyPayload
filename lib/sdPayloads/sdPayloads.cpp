#include <sdPayloads.h>
#include <payloadsList.h>
#include <key.h>
#include <sd.h>

SD_PAYLOADS::SD_PAYLOADS() {}

payloadCode parsePayload(String targetPayload) {
    targetPayload.trim();
    if (targetPayload == payloadsList.CONST_SD_PAYLOAD) return SD_PAYLOAD_PAYLOAD;
    if (targetPayload == payloadsList.CONST_SD_PAYLOAD) return SD_PAYLOAD_PULLSCRIPT;
    if (targetPayload == payloadsList.CONST_SD_PAYLOAD) return SD_PAYLOAD_PULLSCRIPTEXIT;
    if (targetPayload == "TESTING 00 ##!~") return PAYLOAD_SDCARDTEST;
    if (targetPayload == "") return PAYLOAD_EMPTY;
    if (targetPayload == "???") return PAYLOAD_ERROR;
    return PAYLOAD_UNKNOWN;
    }
void SD_PAYLOADS::usePayload(String targetPayload) {
    switch(parsePayload(targetPayload)) {
// Pre-Determined Payloads
        case SD_PAYLOAD_PAYLOAD: // Should not need with serials.checkResonse for now: This is for if the Payload String is calling for "SD Card File Payload" 
            Serial.println("SD Card Payload Iniating...");
            key.runPayload(sd.getPayload(payloadsList.CONST_SD_FILE));
            Serial1.println("#Roger Roger#"); 
            break;
        case SD_PAYLOAD_PULLSCRIPT: // Should not need with serials.checkResonse for now
            Serial.println("SD Card Payload Iniating...");
            key.pullScript();
            Serial1.println("#Roger Roger#"); 
            break;
        case SD_PAYLOAD_PULLSCRIPTEXIT: // Should not need with serials.checkResonse for now
            Serial.println("SD Card Payload Iniating...");
            key.pullScriptExit();
            Serial1.println("#Roger Roger#");  
            break;
// Test Payload
        case PAYLOAD_SDCARDTEST:
            Serial.println("PAYLOAD_SDCARD00 INITIATING");
            sdPayloads.testPayload();
            Serial1.println("#Roger Roger#"); 
            break;
// Error handling  
        case PAYLOAD_EMPTY:
            Serial.println("Payload Request Empty...");
            break;
        case PAYLOAD_ERROR:
            Serial.println("Response Error");
            break;
// If it is not pre-determined, attempt to run it as admin Powershell            
        case PAYLOAD_UNKNOWN: 
            Serial.println("Payload Request Not Predetermined");
            Serial.println(targetPayload); // Good Debug Line
            Serial.println("Running as Keyboard Payload");
            key.runPayload(targetPayload);
    }
}

void SD_PAYLOADS::testPayload() {
    Serial.println("PAYLOAD_SDCARD00 COMPLETED");
}

SD_PAYLOADS sdPayloads = SD_PAYLOADS();


