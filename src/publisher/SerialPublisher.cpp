//
// Created by Florian on 13.05.2017.
//

#include <HardwareSerial.h>
#include "SerialPublisher.h"

SerialPublisher::SerialPublisher(Config *config, Logger *logger) : config(config),
                                                                   logger(logger) {}

void SerialPublisher::publishEmergencySignal() {
    Serial.println("BigRedButton");
};
