//
// Created by Florian on 14.05.2017.
//

#ifndef EMERGENCYSTOP_CONFIG_H
#define EMERGENCYSTOP_CONFIG_H

#include "StringProperty.h"
#include "IntegerProperty.h"
#include "BooleanProperty.h"

class Config {
public:
    StringProperty *getWifi_ssid() const;

    StringProperty *getWifi_password() const;

    BooleanProperty *getUdp_enabled() const;

    StringProperty *getUdp_host() const;

    IntegerProperty *getUdp_port() const;

    BooleanProperty *getHttp_enabled() const;

    StringProperty *getHttp_host() const;

    StringProperty *getHttp_path() const;

    IntegerProperty *getHttp_port() const;

    StringProperty *getHttp_method() const;

    StringProperty *getHttp_content_type() const;

    StringProperty *getHttp_payload() const;

    BooleanProperty *getHttp_secure() const;

    BooleanProperty *getMqtt_enabled() const;

    StringProperty *getMqtt_host() const;

    StringProperty *getMqtt_topic() const;

    StringProperty *getMqtt_message() const;

    StringProperty *getMqtt_clientid() const;

    IntegerProperty *getSerial_baudrate() const;

    Property *const *getPropertyArray() const;

    uint16_t getPropertyCount() const;

    Property *getPropertyByName(String propertyName);

    Property *const *getProperties() const;

private:
    StringProperty *wifi_ssid = new StringProperty("wifi_ssid", "testAP");
    StringProperty *wifi_password = new StringProperty("wifi_password", "testPassword");

    BooleanProperty *udp_enabled = new BooleanProperty("udp_enabled", false);
    StringProperty *udp_host = new StringProperty("udp_host", "192.168.0.1");
    IntegerProperty *udp_port = new IntegerProperty("udp_port", 6666);

    BooleanProperty *http_enabled = new BooleanProperty("http_enabled", false);
    StringProperty *http_host = new StringProperty("http_host", "192.168.0.1");
    StringProperty *http_path = new StringProperty("http_path", "/test");
    IntegerProperty *http_port = new IntegerProperty("http_port", 80);
    StringProperty *http_method = new StringProperty("http_method", "GET");
    StringProperty *http_content_type = new StringProperty("http_cont_type", "");
    StringProperty *http_payload = new StringProperty("http_payload", "");
    BooleanProperty *http_secure = new BooleanProperty("http_secure", false);

    BooleanProperty *mqtt_enabled = new BooleanProperty("mqtt_enabled", false);
    StringProperty *mqtt_host = new StringProperty("mqtt_host", "192.168.0.1");
    StringProperty *mqtt_topic = new StringProperty("mqtt_topic", "/home/test/");
    StringProperty *mqtt_message = new StringProperty("mqtt_message", "BigRedButton");
    StringProperty *mqtt_clientid = new StringProperty("mqtt_clientid", "BigRedButton");

    IntegerProperty *serial_baudrate = new IntegerProperty("serial_baudrate", 115200);

    Property *properties[19] = {wifi_ssid, wifi_password, udp_enabled, udp_host, udp_port, http_enabled, http_host,
                                http_path, http_port, http_method, http_content_type, http_payload, http_secure,
                                mqtt_enabled, mqtt_host, mqtt_topic, mqtt_message, mqtt_clientid, serial_baudrate};


};


#endif //EMERGENCYSTOP_CONFIG_H
