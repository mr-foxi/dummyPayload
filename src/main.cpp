#include <Arduino.h>
#include <key.h>
#include <serials.h>
#include <sd.h>
#include <payloads.h>

const int POLL_TIME = 200;

void setup() {
  serials.upUsb();
  serials.up1();
  sd.init();
  key.up();

  // delay(5000);

  // String testPayload = sd.getPayload("payload");
  // serials.checkResponse(testPayload); // Automatically send payload if found

  // payloads.usePayload(testPayload); // Manual payload request

  // Serial.print("Saved payload string: ");
  // Serial.println(payload);
  // key.pullScript();

  // serials.pinSendHello();
}

void loop() {
  String pinResponse = serials.read1();
  serials.checkResponse(pinResponse);

  delay(POLL_TIME);
}