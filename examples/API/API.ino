#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager

#include <EEPROM.h>

const char* id = qboxName.c_str();


void setup() {
    WiFiManager wifiManager; // Initialise WiFiManager
    wifiManager.setAPISaveCallback(apiCallback); // Set the callback to set the API

    wifiManager.autoConnect(id); // Start the portal/connect to wifi
}

void loop() {
    // put your main code here, to run repeatedly:
}

void apiCallback(WiFiManager *wifiManager) { // create the callback called when API is saved
  String uri = wifiManager->api_static_name; // pass the saved api URI
  storeApi(uri); // save it using the function below using EEPROM
}

void storeApi(String id) { // store the passed id of type string using EEPROM
  int i;
  int size = id.length();
  char idArr[size+1];
  strcpy(idArr, id.c_str());
  EEPROM.begin(512);
  for (i=0; i < size; i++) {
    EEPROM.write(API_ADDR+i, idArr[i]);
  }
  EEPROM.write(API_ADDR+size, '\0');
  EEPROM.commit();
  EEPROM.end();
}
