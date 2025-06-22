#ifndef SD_PAYLOADS_H
#define SD_PAYLOADS_H

#include <Arduino.h>

const String payload00 = "TEST PAYLOAD 00";

enum payloadCode {
  SD_PAYLOAD_PAYLOAD,
  SD_PAYLOAD_PULLSCRIPT,
  SD_PAYLOAD_PULLSCRIPTEXIT,
  PAYLOAD_SDCARDTEST,
  PAYLOAD_EMPTY,
  PAYLOAD_UNKNOWN,
  PAYLOAD_ERROR
};

class SD_PAYLOADS
{
public:
    SD_PAYLOADS();
    void usePayload(String);
    void testPayload();
};

extern SD_PAYLOADS sdPayloads;

#endif