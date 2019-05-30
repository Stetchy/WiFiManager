#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager

#define LED_RED 5
#define LED_GREEN 14
  
#define LED_ON HIGH
#define LED_OFF LOW

const char* id = qboxName.c_str();


void setup() {
    WiFiManager wifiManager; // Initialise WiFiManager
    wifiManager.setLoopCallback(configModeCallback); // set the callback to be looped if the portal is started
    wifiManager.autoConnect(id); // attempt to connect/start portal
    wifiManager.setLoopCallback(NULL); // set the the callback to null if connected to wifi
    digitalWrite(LED_GREEN, LED_OFF);
    digitalWrite(LED_RED, LED_OFF);
}

void loop() {
    // put your main code here, to run repeatedly:
}

void configModeCallback(WiFiManager *wifiManager) { // sample callback to flash LEDs
  bool redOn = digitalRead(LED_RED);
  if (millis() - last > 500) {
    last = millis();
    redOn = !redOn;
    digitalWrite(LED_GREEN, !redOn);
    digitalWrite(LED_RED, redOn);
  }
}
