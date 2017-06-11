//
// Created by Florian on 19.05.2017.
//

#include <WiFi.h>
#include "MqttPublisher.h"

MqttPublisher::MqttPublisher(Config *config, Logger *logger) : config(config),
                                                               logger(logger) {
    char *hostNameBuffer = getNewHostNameCharBuffer(config);

    mqttClient.begin(hostNameBuffer, 1883, wiFiClient);
}

void MqttPublisher::publishEmergencySignal() {
    if (mqttClient.connected()) {
        mqttClient.publish(config->getMqtt_topic()->getValue(), config->getMqtt_message()->getValue());
    }
}

void MqttPublisher::doWork() {
    mqttClient.loop();

    if (!mqttClient.connected()) {
        tryConnect();
    }
}

void MqttPublisher::tryConnect() {
    if (WiFi.status() != WL_CONNECTED) {
        return;
    }

    logger->log("connecting to Mqtt Server: " + config->getMqtt_host()->getValue());
    if (!mqttClient.connect(config->getMqtt_clientid()->getValue().c_str())) {
        logger->log("connecting to Mqtt Server failed");
        return;
    }
}

//this is a Hack since the DNS lookup somehow destroys the Arduino String Buffers
char *MqttPublisher::getNewHostNameCharBuffer(const Config *config) const {
    String hostNameString = config->getMqtt_host()->getValue();
    const unsigned int bufferSize = hostNameString.length() + 1;
    char *hostNameBuffer = (char *) malloc(sizeof(char) * bufferSize);

    hostNameString.toCharArray(hostNameBuffer, bufferSize, 0);
    return hostNameBuffer;
}

void messageReceived(String topic, String payload, char *bytes, unsigned int length) {
}
