#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

enum wifiPayload {
  PAYLOAD_UNKNOWN,
  PAYLOAD_EMPTY,
  PAYLOAD_ROGER,
  PAYLOAD_ERROR404,
  PAYLOAD_TEST,
  PAYLOAD_SDCARD,
  PAYLOAD_PULLSCRIPT,
  PAYLOAD_PULLSCRIPTEXIT,
//   RESPONSE_ERROR222, GOOD DEBUG LINE
  PAYLOAD_ERROR
};

class WIFI
{
public:
    WIFI();
    void up();
    void RSSI();
    void httpRequest();
    void apStart();
    String apRecieve();
    void handlePayload(String);

    String HOST_NAME   = "http://httpforever.com";
    String PATH_NAME   = "";
    // String PATH_NAME   = "/products/arduino.php";
    String queryString = "temperature=26&humidity=70"; // OPTIONAL
};

// class wifiHTTP
// {
// public:
//     wifiHTTP();
// };
extern WIFI wifi;
// extern wifiHTTP http;

#endif