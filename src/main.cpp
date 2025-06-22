#include <Arduino.h>
#include <key.h>
#include <serials.h>
#include <sd.h>
#include <sdPayloads.h>

const int POLL_TIME = 100;

void setup() {
  serials.upUsb();
  serials.up1();
  sd.init();
  key.up();
}

void loop() {
  String pinResponse = serials.read1();
  serials.checkResponse(pinResponse);

  delay(POLL_TIME);
}