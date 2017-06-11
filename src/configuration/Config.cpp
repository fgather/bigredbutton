//
// Created by Florian on 14.05.2017.
//

#include "Config.h"

StringProperty *Config::getWifi_ssid() const {
    return wifi_ssid;
}

StringProperty *Config::getWifi_password() const {
    return wifi_password;
}

BooleanProperty *Config::getUdp_enabled() const {
    return udp_enabled;
}

StringProperty *Config::getUdp_host() const {
    return udp_host;
}

IntegerProperty *Config::getUdp_port() const {
    return udp_port;
}

BooleanProperty *Config::getHttp_enabled() const {
    return http_enabled;
}

StringProperty *Config::getHttp_host() const {
    return http_host;
}

StringProperty *Config::getHttp_path() const {
    return http_path;
}

IntegerProperty *Config::getHttp_port() const {
    return http_port;
}

StringProperty *Config::getHttp_method() const {
    return http_method;
}

StringProperty *Config::getHttp_payload() const {
    return http_payload;
}

BooleanProperty *Config::getHttp_secure() const {
    return http_secure;
}

BooleanProperty *Config::getMqtt_enabled() const {
    return mqtt_enabled;
}

StringProperty *Config::getMqtt_host() const {
    return mqtt_host;
}

StringProperty *Config::getMqtt_topic() const {
    return mqtt_topic;
}

StringProperty *Config::getMqtt_message() const {
    return mqtt_message;
}

StringProperty *Config::getMqtt_clientid() const {
    return mqtt_clientid;
}

IntegerProperty *Config::getSerial_baudrate() const {
    return serial_baudrate;
}

Property *const *Config::getPropertyArray() const {
    return properties;
}

Property *const *Config::getProperties() const {
    return properties;
}

uint16_t Config::getPropertyCount() const {
    return sizeof(properties) / sizeof(Property *);
}

Property *Config::getPropertyByName(String propertyName) {
    for (int i = 0; i < getPropertyCount(); i++) {
        Property *prop = getPropertyArray()[i];
        if (prop->getName().equals(propertyName)) {
            return prop;
        }
    }
    return NULL;
}

