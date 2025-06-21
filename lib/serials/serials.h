#ifndef SERIALS_H
#define SERIALS_H

#include <Arduino.h>

const int SERIALS_BAUD = 115200;

enum ResponseCode {
  RESPONSE_EMPTY,
  RESPONSE_UNKNOWN,
  RESPONSE_HELLO,
  RESPONSE_SDPAYLOAD,
  RESPONSE_PULLSCRIPT,
  RESPONSE_ERROR404,
//   RESPONSE_ERROR222, GOOD DEBUG LINE
  RESPONSE_ERROR333,
  RESPONSE_ERROR
};

class SERIALS
{
public:
    SERIALS();
    void upUsb();
    void up1();
    void up2();
    void up3();
    void pinSendHello();
    String read1();
    void print(String);
    void checkResponse(String);
};

extern SERIALS serials;

#endif