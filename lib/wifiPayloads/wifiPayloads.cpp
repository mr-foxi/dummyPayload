#include <wifiPayloads.h>
// #include <oled.h>
#include <WiFi.h>
#include <serials.h>
#include <payloadsList.h>
/* !#!# DANGER !#!# DANGER !#!# DANGER !#!# */
#include <pass.h>
/* !#!# DANGER !#!# DANGER !#!# DANGER !#!# */

WIFIPAYLOADS::WIFIPAYLOADS() {}

payloadEnum checkPayload(String response) {
  response.trim();
  if (response == "") return PAYLOAD_EMPTY;
  if (response == "Error") return PAYLOAD_ERROR;
  if (response == "!ERROR: 404!") return PAYLOAD_ERROR404;
//   if (response == "!ERROR: 222!") return RESPONSE_ERROR222; GOOD DEBUG LINE
  if (response == "#Roger Roger#") return PAYLOAD_ROGER;
  if (response == "$Test Payload$") return PAYLOAD_TEST;
  if (response == payloadsList.CONST_SDCARD) return PAYLOAD_SDCARD;
  if (response == payloadsList.CONST_PULLSCRIPT) return PAYLOAD_PULLSCRIPT;
  if (response == payloadsList.CONST_PULLSCRIPTEXIT) return PAYLOAD_PULLSCRIPTEXIT;
  return PAYLOAD_UNKNOWN;
}

void WIFIPAYLOADS::handlePayload(String response) {
    switch(checkPayload(response)) {
        case PAYLOAD_EMPTY:
            // Serial.println("No Response Yet..."); GOOD DEBUG LINE
            break;
        case PAYLOAD_ERROR:
            Serial.println("Response Error");
            break;
        case PAYLOAD_ERROR404:
            Serial.println("!Error: 404! - Error Not Found");
            break;
        // case RESPONSE_ERROR222:
        //     Serial.println("!Error: 222! - Serial Pin Not Available"); GOOD DEBUG LINE
        //     break;
        case PAYLOAD_ROGER:
            Serial.println("Roger Roger!");
            // oled.clear();
            // oled.printlnString("Roger Roger!");
            delay(3000);
            // oled.clear();
            // oled.printlnString("!!  FoxDev BADUSB  !!");
            break;
        case PAYLOAD_TEST:
            // oled.printString("Test Payload");
            Serial.print("Test Payload Activated");
            serials.sdPayload();
            break;
        case PAYLOAD_SDCARD:
            // oled.printString("Test Payload");
            Serial.print("SD Payload Activated");
            serials.sdPayload();
            break;
        case PAYLOAD_PULLSCRIPT:
            // oled.printString("Test Payload");
            Serial.print("Pull Script Payload Activated");
            serials.pullScript();
            break;
        case PAYLOAD_PULLSCRIPTEXIT:
            // oled.printString("Test Payload");
            Serial.print("Pull Script Exit Payload Activated");
            serials.pullScriptExit();
            break;
        case PAYLOAD_UNKNOWN:
            Serial.print("Unknown Response: ");
            Serial.println(response);
            break;

    }
}
WIFIPAYLOADS wifiPayloads = WIFIPAYLOADS();
