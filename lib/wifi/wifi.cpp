#include <wifi.h>
// #include <oled.h>
#include <WiFi.h>
#include <serials.h>
/* !#!# DANGER !#!# DANGER !#!# DANGER !#!# */
#include <pass.h>
/* !#!# DANGER !#!# DANGER !#!# DANGER !#!# */


WIFI::WIFI() {}
// wifiHTTP::wifiHTTP() {}

void WIFI::up() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting");
    // oled.printString("Connecting");
while(WiFi.status() != WL_CONNECTED) { 
        int i = 0;    
        delay(1000);
        Serial.print(".");
        // oled.printString(".");
        i++;
        if (i > 60) {break;}
    }
    if (WL_CONNECTED) {
        // oled.clear();
        Serial.print("Connected to WiFi network with IP Address: ");
        // oled.printlnString("Connected to WiFi!");
        // oled.printlnString("IP address: ");
        String ipAddr = WiFi.localIP().toString();
        Serial.println(WiFi.localIP());
        // oled.printlnString(ipAddr);
    } else {
        Serial.println("WiFi Connection Failed");
        // oled.printlnString("WiFi Connection Failed");
    }
}
void WIFI::RSSI() {
    int signal = WiFi.RSSI();
    Serial.print("RSSI: ");
    Serial.println(signal);
    // oled.printString("RSSI: ");
    // oled.printlnInt(signal);
}
void WIFI::httpRequest() {
    HTTPClient http;
    http.begin(HOST_NAME + PATH_NAME); //HTTP
    int httpCode = http.GET();
    // httpCode will be negative on error
    if (httpCode > 0) {
    // file found at server
    if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
        // oled.printString(payload);
    } else {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);
        // oled.printString("[HTTP] GET... code: ");
        // oled.printlnInt(httpCode);
    }
    } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        // oled.printString("[HTTP] GET... failed, error: ");
        // oled.printlnInt(httpCode);
    }
    http.end();
}
WiFiServer server(7408); // USING TCP ON PORT 7408
void WIFI::apStart() {
    // Serial.begin(115200);

    // Start Wi-Fi in AP mode
    WiFi.softAP("esp-ap", "TestPass42");
    Serial.println("Access Point Started");
    Serial.println(WiFi.softAPIP()); // Should print 192.168.4.1

    // Start TCP server
    server.begin();
    Serial.println("Server started");
}
String WIFI::apRecieve() {
    WiFiClient client = server.available();  // Wait for a client
    String msg;
    if (client) {
        Serial.println("Client connected");
        while (client.connected()) {
        if (client.available()) {
            msg = client.readStringUntil('\n');
            Serial.print("Received: ");
            Serial.println(msg);
        }
        }
        client.stop();
        Serial.println("Client disconnected");
    }
    return msg;
}
wifiPayload checkPayload(String response) {
  response.trim();
  if (response == "") return PAYLOAD_EMPTY;
  if (response == "Error") return PAYLOAD_ERROR;
  if (response == "!ERROR: 404!") return PAYLOAD_ERROR404;
//   if (response == "!ERROR: 222!") return RESPONSE_ERROR222; GOOD DEBUG LINE
  if (response == "#Roger Roger#") return PAYLOAD_ROGER;
  if (response == "$Test Payload$") return PAYLOAD_TEST;
  if (response == "$PAYLOAD - SDCARD$") return PAYLOAD_SDCARD;
  if (response == "$PAYLOAD - PULLSCRIPT$") return PAYLOAD_PULLSCRIPT;
  if (response == "$PAYLOAD - PULLSCRIPTEXIT$") return PAYLOAD_PULLSCRIPTEXIT;
  return PAYLOAD_UNKNOWN;
}

void WIFI::handlePayload(String response) {
    switch(checkPayload(response)) {
        case PAYLOAD_EMPTY:
            // Serial.println("No Response Yet..."); GOOD DEBUG LINE
            break;
        case PAYLOAD_ERROR:
            Serial.println("Response Error");
            break;
        case PAYLOAD_ERROR404:
            Serial.println("!Error: 404! - Error Not Found");
            break;
        // case RESPONSE_ERROR222:
        //     Serial.println("!Error: 222! - Serial Pin Not Available"); GOOD DEBUG LINE
        //     break;
        case PAYLOAD_ROGER:
            Serial.println("Roger Roger!");
            // oled.clear();
            // oled.printlnString("Roger Roger!");
            delay(3000);
            // oled.clear();
            // oled.printlnString("!!  FoxDev BADUSB  !!");
            break;
        case PAYLOAD_TEST:
            // oled.printString("Test Payload");
            Serial.print("Test Payload Activated");
            serials.sdPayload();
            break;
        case PAYLOAD_SDCARD:
            // oled.printString("Test Payload");
            Serial.print("SD Payload Activated");
            serials.sdPayload();
            break;
        case PAYLOAD_PULLSCRIPT:
            // oled.printString("Test Payload");
            Serial.print("Pull Script Payload Activated");
            serials.pullScript();
            break;
        case PAYLOAD_PULLSCRIPTEXIT:
            // oled.printString("Test Payload");
            Serial.print("Pull Script Exit Payload Activated");
            serials.pullScriptExit();
            break;
        case PAYLOAD_UNKNOWN:
            Serial.print("Unknown Response: ");
            Serial.println(response);
            break;

    }
}
WIFI wifi = WIFI();
// wifiHTTP http = wifiHTTP();
