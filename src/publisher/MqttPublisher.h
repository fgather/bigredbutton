//
// Created by Florian on 19.05.2017.
//

#ifndef EMERGENCYSTOP_MQTTPUBLISHER_H
#define EMERGENCYSTOP_MQTTPUBLISHER_H


#include <MQTTClient.h>
#include <configuration/Config.h>
#include <Logger.h>
#include <WiFiClient.h>
#include "Publisher.h"

class MqttPublisher : public Publisher {
public:
    MqttPublisher(Config *pConfig, Logger *pLogger);

    void publishEmergencySignal() override;

    void doWork() override;

private:
    Config *config;
    Logger *logger;
    MQTTClient mqttClient;
    WiFiClient wiFiClient;

    void tryConnect();

    char *getNewHostNameCharBuffer(const Config *config) const;
};


#endif //EMERGENCYSTOP_MQTTPUBLISHER_H
