//
// Created by Florian on 14.05.2017.
//

#ifndef EMERGENCYSTOP_PUBLISHSERVICE_H
#define EMERGENCYSTOP_PUBLISHSERVICE_H


#include <publisher/Publisher.h>
#include <cstdint>
#include <configuration/Config.h>
#include "../logger.h"

class PublishService {
public:
    PublishService(Config *config, Logger *logger);

    void publishEmergencySignal();

    void doWork();

private:
    Config *config;
    Logger *logger;

    Publisher *publisher[4];
    uint8_t publisherCount;
};


#endif //EMERGENCYSTOP_PUBLISHSERVICE_H
