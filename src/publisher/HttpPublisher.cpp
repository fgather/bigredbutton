//
// Created by Florian on 12.05.2017.
//

#include "HttpPublisher.h"

HttpPublisher::HttpPublisher(Config *config, Logger *logger) : config(config),
                                                               logger(logger) {
    nonSecureClient.setTimeout(5);
    secureClient.setTimeout(5);
}

void HttpPublisher::publishEmergencySignal() {
    Client *client;

    if (config->getHttp_secure()->getValue()) {
        client = &secureClient;
    } else {
        client = &nonSecureClient;
    }

    if (!client->connect(config->getHttp_host()->getValue().c_str(), (uint16_t) config->getHttp_port()->getValue())) {
        logger->log("Could not connect to http host");
        return;
    }

    String contentLength = "";

    const String payload = config->getHttp_payload()->getValue();
    const bool hasPayload = payload.length() > 0;
    if (hasPayload) {
        contentLength = "Content-Length: " + String(payload.length()) + "\r\n";
    }

    String header =
            config->getHttp_method()->getValue() + String(" ") + config->getHttp_path()->getValue() + " HTTP/1.1\r\n" +
            "Host: " + config->getHttp_host()->getValue() + "\r\n" +
            contentLength +
            "Connection: close\r\n\r\n";

    client->print(header + payload);


    logger->log("Sent http request");
}
