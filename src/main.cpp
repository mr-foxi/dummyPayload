#include <Arduino.h>
#include <wifi.h>
#include <wifiPayloads.h>
#include <WiFi.h>
#include <serials.h>

const int POLL_TIME = 200;

void setup() {
  serials.pinInit();
  serials.usbInit();
  delay(3000);
  wifi.apStart();
}

void loop() {
  String pinResponse = serials.pinRead();
  serials.checkResponse(pinResponse);

  String recievedMessage = wifi.apRecieve();
  if (recievedMessage) {wifiPayloads.handlePayload(recievedMessage);}

  delay(POLL_TIME);
}
