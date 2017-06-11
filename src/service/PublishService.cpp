//
// Created by Florian on 14.05.2017.
//

#include <publisher/UdpPublisher.h>
#include <publisher/HttpPublisher.h>
#include <publisher/MqttPublisher.h>
#include <publisher/SerialPublisher.h>
#include "PublishService.h"

PublishService::PublishService(Config *config, Logger *logger) : config(config), logger(logger) {
    publisherCount = 0;
    if (config->getUdp_enabled()->getValue()) {
        publisher[publisherCount++] = new UdpPublisher(config, logger);
    }
    if (config->getHttp_enabled()->getValue()) {
        publisher[publisherCount++] = new HttpPublisher(config, logger);
    }
    if (config->getMqtt_enabled()->getValue()) {
        publisher[publisherCount++] = new MqttPublisher(config, logger);
    }

    publisher[publisherCount++] = new SerialPublisher(config, logger);
}

void PublishService::publishEmergencySignal() {
    logger->log("Publishing Press event");
    for (int i = 0; i < publisherCount; i++) {
        publisher[i]->publishEmergencySignal();
    }
}

void PublishService::doWork() {
    for (int i = 0; i < publisherCount; i++) {
        publisher[i]->doWork();
    }
}
