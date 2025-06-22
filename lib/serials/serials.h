#ifndef SERIALS_H
#define SERIALS_H

#include <Arduino.h>
#include <HardwareSerial.h> // For Arduino framework

const int RX_PIN = 26; // For WiPy3 Tthis is GPIO 26, which is P21 in silk screen
const int TX_PIN = 22; // For WiPy3 Tthis is GPIO 22, which is P11 in silk screen
const int SERIALS_BAUD = 115200;

enum ResponseCode {
  RESPONSE_UNKNOWN,
  RESPONSE_HELLO,
  RESPONSE_EMPTY,
  RESPONSE_ROGER,
  RESPONSE_ERROR404,
//   RESPONSE_ERROR222, GOOD DEBUG LINE
  RESPONSE_ERROR
};

class SERIALS
{
public:
    SERIALS();
    void usbInit();
    void pinInit();
    void pinSendHello();
    String pinRead();
    void print(String);
    void checkResponse(String);
    void sdPayload();
    void pullScript();
    void pullScriptExit();
};

extern SERIALS serials;

#endif