#include <Arduino.h>
#include <key.h>
#include <serials.h>
#include <sd.h>

void setup() {
  serials.upUsb();
  serials.up1();
  sd.init();
  key.up();
  delay(5000);
  String payload = sd.getPayload("payload");
  Serial.println(payload);
  // key.pullScript();

  // serials.pinSendHello();
}

void loop() {
  String pinResponse = serials.read1();
  serials.checkResponse(pinResponse);
  // if (pinResponse) {
  // } else {
  //   serials.print("No Response");
  // }

  delay(5000);
}