#include <wifi.h>
// #include <oled.h>
#include <WiFi.h>
#include <serials.h>
#include <payloadsList.h>
/* !#!# DANGER !#!# DANGER !#!# DANGER !#!# */
#include <pass.h>
/* !#!# DANGER !#!# DANGER !#!# DANGER !#!# */

WiFiServer server(ESP_PORT); // USING TCP ON PORT 7408
WIFI::WIFI() {}

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

void WIFI::apStart() {
    WiFi.softAPConfig(ESP_IP, ESP_IP, ESP_SUBNET);
    // Start Wi-Fi in AP mode
    WiFi.softAP(ESP_SSID, ESP_PASS);
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

WIFI wifi = WIFI();