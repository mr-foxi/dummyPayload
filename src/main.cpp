#include <Arduino.h>
#include <key.h>
#include <serial.h>

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  key.up();
  delay(5000);
  key.pullScript();
}

void loop() {
}