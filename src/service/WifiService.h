//
// Created by Florian on 07.05.2017.
//

#ifndef EMERGENCY_WIFISERVICE_H
#define EMERGENCY_WIFISERVICE_H


#include "service/ConfigService.h"
#include <WiFi.h>
#include <Logger.h>

class WifiService {
public:
    WifiService(Config *config, Logger *logger);

    void setup();

    void setupAPMode();
private:
    Config *config;
    Logger *logger;

    void connectToWiFi(const char *ssid, const char *pwd);
};


#endif //EMERGENCY_WIFISERVICE_H
