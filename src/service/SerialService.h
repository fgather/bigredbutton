//
// Created by Florian on 07.05.2017.
//

#ifndef EMERGENCYSTOP_SERIALSERVICE_H
#define EMERGENCYSTOP_SERIALSERVICE_H


#include <Arduino.h>
#include "service/ConfigService.h"

#ifndef SERIAL_BUFFERSIZE
#define SERIAL_BUFFERSIZE 100
#endif

class SerialService {
public:
    SerialService(ConfigService *configService);

    void setup();

    void doWork();

private:
    ConfigService *configService;

    char terminationChar = '\n';

    char serialBuffer[SERIAL_BUFFERSIZE + 1];
    byte serialBufferPosition = 0;

    void clearBuffer();

    bool executeCommand(char *buffer);
};


#endif //EMERGENCYSTOP_SERIALSERVICE_H
