//
// Created by Florian on 07.05.2017.
//

#include <HardwareSerial.h>
#include "SerialService.h"

SerialService::SerialService(ConfigService *configService) : configService(configService) {
}

void SerialService::setup() {
    Serial.begin(configService->getConfig()->getSerial_baudrate()->getValue());
}

void SerialService::doWork() {
    while (Serial.available()) {
        char inChar = Serial.read();

        if (inChar == terminationChar) {
            if (!executeCommand(serialBuffer)) {
                Serial.println("Command not found");
            }

            clearBuffer();
        } else if (inChar != '\r') {
            if (serialBufferPosition < SERIAL_BUFFERSIZE) {
                serialBuffer[serialBufferPosition++] = inChar;  // Put character into buffer
                serialBuffer[serialBufferPosition] = '\0'; // Null terminate
            }
        }

    }
}

bool SerialService::executeCommand(char *buffer) {
    char *firstToken = strtok(buffer, " ");
    String command = String(firstToken);

    if (command.equals("set")) {
        char *secondToken = strtok(NULL, " ");

        if (secondToken == NULL) {
            Serial.println("too few parameters for set operation");
            return true;
        }

        char *thirdToken = strtok(NULL, " ");

        if (thirdToken == NULL) {
            Serial.println("too few parameters for set operation");
            return true;
        }

        String propertyName = String(secondToken);
        String value = String(thirdToken);

        Property *property = configService->getTempConfig()->getPropertyByName(propertyName);
        if (property == NULL) {
            Serial.println("Property not found: " + propertyName);
        } else {
            property->setValue(value);
            Serial.println("set ok");
        }

        return true;
    }

    if (command.equals("loaddefaults")) {
        configService->loadDefaultValuesToTempConfig();
        Serial.println("loaded default setting");
        return true;
    }

    if (command.equals("save")) {
        configService->persistTempConfig();
        Serial.println("save ok");
        return true;
    }

    if (command.equals("reboot")) {
        Serial.println("reboot in 1 sec");
        delay(1000);
        ESP.restart();
    }

    return false;
}

void SerialService::clearBuffer() {
    serialBuffer[0] = '\0';
    serialBufferPosition = 0;
}
