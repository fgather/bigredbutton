//
// Created by Florian on 25.05.2017.
//

#include <WiFi.h>
#include "HttpConfigService.h"

HttpConfigService::HttpConfigService(ConfigService *configService, Logger *logger) : configService(configService),
                                                                                     logger(logger) {
    server = new WiFiServer();
}

void HttpConfigService::doWork() {
    if (WiFi.getMode() == WIFI_STA && WiFi.status() != WL_CONNECTED) {
        started = false;
        return;
    }

    if (!started) {
        logger->log("Initialize HTTP Server");
        server->begin();
        started = true;
    }


    WiFiClient client = server->available();
    if (client) {
        String currentLine = "";
        while (client.connected()) {
            if (client.available()) {
                char c = client.read();
                if (c == '\n') {
                    if (currentLine.length() == 0) {
                        sendConfigPage(client);
                        break;
                    } else {
                        currentLine = "";
                    }
                } else if (c != '\r') {
                    currentLine += c;
                }

                if (currentLine.endsWith("POST /save")) {
                    handleConfigPost(client);
                    return;
                }

            }
            yield();
        }
        client.stop();
    }
}

void HttpConfigService::sendConfigPage(WiFiClient &client) const {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();


    client.print("<!DOCTYPE html><html><body><form action=\"/save\" method=\"post\">");

    Config *config = configService->getTempConfig();
    for (int i = 0; i < config->getPropertyCount(); i++) {
        client.print(config->getProperties()[i]->getName() + " <input type=\"text\" name=\"" +
                     config->getProperties()[i]->getName() +
                     "\" value=\"" + config->getProperties()[i]->getValueAsString() + "\"><br>");
    }

    client.print("<input type=\"submit\" value=\"Save and Restart\"></form></body></html>");


    client.println();
}

void HttpConfigService::handleConfigPost(WiFiClient &client) const {
    logger->log("Config was posted");

    logger->log(readUntil(client, "\n\n", '\r'));

    logger->log("Header received");

    Config *config = configService->getTempConfig();

    while (true) {
        String string = readUntil(client, "&", '\r');

        if (string.endsWith("&")) {
            string = string.substring(0, string.length() - 1);
        }

        if (string.length() == 0) {
            break;
        }

        const unsigned int indexOf = (const unsigned int) string.indexOf('=');
        String parameter = string.substring(0, indexOf);
        String value = urldecode(string.substring(indexOf + 1));

        logger->log(parameter);
        logger->log(value);

        Property *pProperty = config->getPropertyByName(parameter);

        if (pProperty != NULL) {
            pProperty->setValue(value);
        }
    }
    logger->log("All data received");

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.println("<html><body>Config saved</body></html>");
    client.println();

    client.stop();

    logger->log("Save and restart");
    configService->persistTempConfig();

    delay(1000);

    esp_restart();
}

String HttpConfigService::readUntil(WiFiClient &client, String until, char ignore) const {
    String current = "";
    while (client.available()) {
        char c = client.read();

        if (c != ignore) {
            current += c;
        }

        if (current.endsWith(until)) {
            return current;
        }
    }

    return current;
}

String HttpConfigService::urldecode(String src) const {
    String result = "";
    char a, b;
    for (int i = 0; i < src.length(); i++) {
        if ((src[i] == '%') &&
            ((a = src[i + 1]) && (b = src[i + 2])) &&
            (isxdigit(a) && isxdigit(b))) {
            if (a >= 'a')
                a -= 'a' - 'A';
            if (a >= 'A')
                a -= ('A' - 10);
            else
                a -= '0';
            if (b >= 'a')
                b -= 'a' - 'A';
            if (b >= 'A')
                b -= ('A' - 10);
            else
                b -= '0';
            result += (char) (16 * a + b);
            i += 2;
        } else {
            result += src[i];
        }
    }
    return result;
}
