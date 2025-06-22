#include <Arduino.h>
#include <wifi.h>
#include <WiFi.h>
#include <serials.h>

const int POLL_TIME = 200;

void setup() {
  serials.pinInit();
  serials.usbInit();
  wifi.apStart();

  // delay(3000);
  // serials.sdPayload();
}

void loop() {
  String pinResponse = serials.pinRead();
  serials.checkResponse(pinResponse);
  String wifiPayload = wifi.apRecieve();
  if (wifiPayload) {wifi.handlePayload(wifiPayload);}

  delay(POLL_TIME);
}
