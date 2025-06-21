#ifndef PAYLOADS_H
#define PAYLOADS_H

#include <Arduino.h>

const String payload00 = "TEST PAYLOAD 00";

enum payloadCode {
//   PAYLOAD_TEST00,
//   PAYLOAD_TEST01,
  PAYLOAD_SDCARD00,
  PAYLOAD_EMPTY,
  PAYLOAD_UNKNOWN,
  PAYLOAD_ERROR
};


class PAYLOADS
{
public:
    PAYLOADS();
    void usePayload(String);
    void testPayload();
};

extern PAYLOADS payloads;

#endif