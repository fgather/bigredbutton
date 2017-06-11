//
// Created by Florian on 08.05.2017.
//

#include "UdpPublisher.h"

UdpPublisher::UdpPublisher(Config *config, Logger *logger) : config(config),
                                                             logger(logger) {}

void UdpPublisher::publishEmergencySignal() {
    udp.beginPacket(config->getUdp_host()->getValue().c_str(), (uint16_t) config->getUdp_port()->getValue());
    udp.printf("BigRedButton");
    udp.endPacket();

    logger->log("Sent udp packet");
}
