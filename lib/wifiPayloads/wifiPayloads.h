#ifndef WIFIPAYLOADS_H
#define WIFIPAYLOADS_H

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

enum payloadEnum {
  PAYLOAD_UNKNOWN,
  PAYLOAD_EMPTY,
  PAYLOAD_ROGER,
  PAYLOAD_ERROR404,
  PAYLOAD_TEST,
  PAYLOAD_SDCARD,
  PAYLOAD_PULLSCRIPT,
  PAYLOAD_PULLSCRIPTEXIT,
//   RESPONSE_ERROR222, GOOD DEBUG LINE
  PAYLOAD_ERROR
};

class WIFIPAYLOADS
{
public:
    WIFIPAYLOADS();
    void handlePayload(String);
};

extern WIFIPAYLOADS wifiPayloads;

#endif