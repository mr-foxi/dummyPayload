#include <Arduino.h>
#include <key.h>
#include <serial.h>
#include <sd.h>

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  sd.init();
  key.up();
  delay(5000);
  // key.pullScript();
  String payload = sd.getPayload("payload");
  Serial.println(payload);
  Serial1.println(payload);
}

void loop() {
}