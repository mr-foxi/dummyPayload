#include <serials.h>
#include <key.h>
#include <sd.h>

SERIALS::SERIALS() {}

void SERIALS::upUsb() {
    Serial.begin(SERIALS_BAUD); // USB Serial for Arduino Due
}
void SERIALS::up1() {
    Serial1.begin(SERIALS_BAUD); // Pin 18 (TX1) & Pin 19 (RX1) for Arduino Due
}
void SERIALS::up2() {
    Serial2.begin(SERIALS_BAUD); // Pin 16 (TX2) & Pin 17 (RX2) for Arduino Due
}
void SERIALS::up3() {
    Serial3.begin(SERIALS_BAUD); // Pin 14 (TX3) & Pin 15 (RX3) for Arduino Due
}

void SERIALS::print(String msg) {
    Serial.println(msg);
    Serial1.println(msg);
    Serial2.println(msg);
    Serial3.println(msg);
}

void SERIALS::pinSendHello() {
    Serial1.println("Hello WING!");
}
String SERIALS::read1() {
    if (Serial1.available()) {
        String msg = Serial1.readStringUntil('\n');
        msg.trim();
        return msg;
    } else {
        return "!ERROR: 222!";
    }
}

ResponseCode parseResponse(String response) {
  response.trim();
  if (response == "") return RESPONSE_EMPTY;
  if (response == "Hello DUE!") return RESPONSE_HELLO;
  if (response == "payload") return RESPONSE_SDPAYLOAD;
  if (response == "pullScript") return RESPONSE_PULLSCRIPT;
  if (response == "!ERROR!") return RESPONSE_ERROR;
  if (response == "!ERROR: 404!") return RESPONSE_ERROR404;
  if (response == "!ERROR: 222!") return RESPONSE_ERROR222;
  return RESPONSE_UNKNOWN;
}

void SERIALS::checkResponse(String response) {
    switch(parseResponse(response)) {
        case RESPONSE_EMPTY:
            Serial.println("No Response Yet...");
            break;
        case RESPONSE_ERROR:
            Serial.println("Response Error");
            break;
        case RESPONSE_ERROR404:
            Serial.println("!Error 404! - Error Not Found");
            break;
        case RESPONSE_ERROR222:
            Serial.println("!Error: 222! - Serial Pin Not Available");
            break;
        case RESPONSE_HELLO:
            Serial.println("Recieved Hello!");
            serials.pinSendHello();
            break;
        case RESPONSE_PULLSCRIPT:
            key.pullScript();
            break;
        case RESPONSE_SDPAYLOAD:
            sd.getPayload(response);
            break;
        case RESPONSE_UNKNOWN:
            Serial.print("Unknown Response: ");
            Serial.println(response);
            break;

    }
}

SERIALS serials = SERIALS();