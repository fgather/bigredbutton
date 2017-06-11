//
// Created by Florian on 25.05.2017.
//

#ifndef EMERGENCY_HTTPCONFIGSERVICE_H
#define EMERGENCY_HTTPCONFIGSERVICE_H


#include <WiFiServer.h>
#include "ConfigService.h"

class HttpConfigService {
public:
    HttpConfigService(ConfigService *configService, Logger *logger);

    void doWork();

private:
    WiFiServer *server;

    ConfigService *configService;
    Logger *logger;

    bool started = false;

    void handleConfigPost(WiFiClient &client) const;

    void sendConfigPage(WiFiClient &client) const;

    String readUntil(WiFiClient &client, String until, char ignore) const;

    String urldecode(String src) const;
};


#endif //EMERGENCY_HTTPCONFIGSERVICE_H
