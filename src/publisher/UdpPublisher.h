//
// Created by Florian on 08.05.2017.
//

#ifndef EMERGENCYSTOP_UDPPUBLISHER_H
#define EMERGENCYSTOP_UDPPUBLISHER_H


#include <WiFiUdp.h>
#include <Logger.h>
#include <configuration/Config.h>
#include "Publisher.h"

class UdpPublisher : public Publisher {
public:
    UdpPublisher(Config *config, Logger *logger);

    void publishEmergencySignal() override;

private:
    WiFiUDP udp;
    Config *config;
    Logger *logger;
};


#endif //EMERGENCYSTOP_UDPPUBLISHER_H
