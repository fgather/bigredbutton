//
// Created by Florian on 07.05.2017.
//

#include <WiFi.h>
#include "WifiService.h"

WifiService::WifiService(Config *config, Logger *logger) : config(config), logger(logger) {
}

void WifiService::setup() {
    logger->log("Initializing Wifi, SSID: " + config->getWifi_ssid()->getValue());
    connectToWiFi(config->getWifi_ssid()->getValue().c_str(), config->getWifi_password()->getValue().c_str());
}


void WifiService::setupAPMode() {
    WiFi.mode(WIFI_MODE_AP);
    WiFi.softAP("BigRedButton", "BigRedButton");
    WiFi.softAPConfig(IPAddress(192,168,1,1),IPAddress(192,168,1,1),IPAddress(255,255,255,0));
}

void test(system_event_id_t event) {
    Serial.print("Wifi Event: ");
    Serial.println(event, DEC);

    if (event == SYSTEM_EVENT_STA_GOT_IP) {
        Serial.print("Obtained ip: ");
        Serial.println(WiFi.localIP());
    }
}

void WifiService::connectToWiFi(const char *ssid, const char *pwd) {
    WiFi.mode(WIFI_MODE_STA);
    WiFi.disconnect(true);
    WiFi.begin(ssid, pwd);
    WiFi.onEvent(test);
    WiFi.setAutoConnect(true);
}
