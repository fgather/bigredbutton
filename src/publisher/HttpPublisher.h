//
// Created by Florian on 12.05.2017.
//

#ifndef EMERGENCYSTOP_HTTPPUBLISHER_H
#define EMERGENCYSTOP_HTTPPUBLISHER_H


//hack for min/max bug in WifiClient.h/Arduino.h
#define _GLIBCXX_VECTOR

#include <WiFiClient.h>
#include <WiFiClientSecure.h>

#include <Logger.h>
#include <configuration/Config.h>

#include "Publisher.h"

class HttpPublisher : public Publisher {
public:
    HttpPublisher(Config *config, Logger *logger);

    void publishEmergencySignal() override;

private:
    WiFiClient nonSecureClient;
    WiFiClientSecure secureClient;
    Config *config;
    Logger *logger;
};


#endif //EMERGENCYSTOP_HTTPPUBLISHER_H
