//
// Created by Florian on 12.05.2017.
//

#include <HardwareSerial.h>
#include "Logger.h"

void Logger::log(String message) {
    Serial.println(message);
    Serial.flush();
}
