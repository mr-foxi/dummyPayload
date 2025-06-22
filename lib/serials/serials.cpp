#include <serials.h>
#include <key.h>
#include <sd.h>
#include <sdPayloads.h>
#include <payloadsList.h>

SERIALS::SERIALS() {}

void SERIALS::upUsb() {Serial.begin(SERIALS_BAUD);} // USB Serial for Arduino Due
void SERIALS::up1() {Serial1.begin(SERIALS_BAUD);} // Pin 18 (TX1) & Pin 19 (RX1) for Arduino Due
// void SERIALS::up2() {Serial2.begin(SERIALS_BAUD);} // Pin 16 (TX2) & Pin 17 (RX2) for Arduino Due
// void SERIALS::up3() {Serial3.begin(SERIALS_BAUD);} // Pin 14 (TX3) & Pin 15 (RX3) for Arduino Due

// void SERIALS::print(String msg) {
//     Serial.println(msg);
//     Serial1.println(msg);
//     Serial2.println(msg);
//     Serial3.println(msg);
// }

// This is a debug function
void SERIALS::pinSendHello() {
    Serial1.println("Hello WING!");
}
String SERIALS::read1() {
    if (Serial1.available()) {
        String msg = Serial1.readStringUntil('\n');
        msg.trim();
        return msg;
    } else {
        return "";
    //     return "!ERROR: 222!"; GOOD DEBUG LINE
    }
}
// Identify Recieved Serial Information
ResponseCode parseResponse(String response) {
  response.trim();
// Error handling
  if (response == "") return RESPONSE_EMPTY;
  if (response == "!ERROR!") return RESPONSE_ERROR;
  if (response == "!ERROR: 404!") return RESPONSE_ERROR404;
// GOOD DEBUG LINE
//   if (response == "!ERROR: 222!") return RESPONSE_ERROR222; 
// Testing
  if (response == "Hello DUE!") return RESPONSE_HELLO;
// Pre-Determined Script Payloads
  if (response == payloadsList.CONST_SDCARD) return RESPONSE_SDCARD;
  if (response == payloadsList.CONST_PULLSCRIPT) return RESPONSE_PULLSCRIPT;
  if (response == payloadsList.CONST_PULLSCRIPTEXIT) return RESPONSE_PULLSCRIPTEXIT;
  return RESPONSE_UNKNOWN;
}
// Check the recieved information on the Serial Pins
void SERIALS::checkResponse(String response) {
    switch(parseResponse(response)) {
// Error handling 
        case RESPONSE_EMPTY:
            // Serial.println("No Response Yet..."); GOOD DEBUG LINE
            break;
        case RESPONSE_ERROR:
            Serial.println("Response Error");
            break;
        case RESPONSE_ERROR404:
            Serial.println("!Error 404! - Error Not Found");
            break;
// GOOD DEBUG LINE
        // case RESPONSE_ERROR222:
        //     Serial.println("!Error: 222! - Serial Pin Not Available"); 
        //     break;
// Testing
        case RESPONSE_HELLO:
            // Serial.println("Recieved Hello!");
            Serial.print(".");
            serials.pinSendHello();
            break;
// Pre-Determined Script Payloads
    // When revieving payloadsList.CONST_SDCARD (@SD_PAYLOAD - PAYLOAD@)
    // It will get the payload String from the SD card file payloadsList.CONST_SD_FILE (payload)
    // Then run it 
        case RESPONSE_SDCARD: 
            Serial.println();
            Serial.print("Roger Roger: ");
            Serial.println(response);
            sdPayloads.usePayload(sd.getPayload(payloadsList.CONST_SD_FILE));
            Serial1.println("#Roger Roger#");
            break;
        case RESPONSE_PULLSCRIPT:
            Serial.println();
            Serial.print("Roger Roger: ");
            Serial.println(response);
            key.pullScript();
            Serial1.println("#Roger Roger#");
            break;
        case RESPONSE_PULLSCRIPTEXIT:
            Serial.println();
            Serial.print("Roger Roger: ");
            Serial.println(response);
            key.pullScriptExit();
            Serial1.println("#Roger Roger#");
            break;
// Unknown Response
        case RESPONSE_UNKNOWN:
            Serial.print("Unknown Response: ");
            Serial.println(response);
            break;
// 
//         case RESPONSE_SDPAYLOAD:
//             Serial.println();
//             Serial.print("Roger Roger: ");
//             Serial.println(response);
//             String sdPayload = sd.getPayload(response);
//             Serial1.println("#Roger Roger#");
//             payloads.usePayload(sdPayload);
    }
}

SERIALS serials = SERIALS();