//
// Created by Florian on 13.05.2017.
//

#ifndef EMERGENCYSTOP_SERIALPUBLISHER_H
#define EMERGENCYSTOP_SERIALPUBLISHER_H


#include <Logger.h>
#include <configuration/Config.h>
#include "Publisher.h"

class SerialPublisher : public Publisher {
public:
    SerialPublisher(Config *config, Logger *logger);

    void publishEmergencySignal() override;

private:
    Config *config;
    Logger *logger;
};


#endif //EMERGENCYSTOP_SERIALPUBLISHER_H
