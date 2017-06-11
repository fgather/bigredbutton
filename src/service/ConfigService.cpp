//
// Created by Florian on 07.05.2017.
//

#include "ConfigService.h"

ConfigService::ConfigService(Logger *logger) : logger(logger) {
    this->config = loadConfig();
    this->tempConfig = loadConfig();
}

void ConfigService::loadDefaultValuesToTempConfig() {
    tempConfig = new Config();
}

void ConfigService::persistTempConfig() {
    saveConfig(tempConfig);
}

Config *ConfigService::loadConfig() {
    preferences.begin(PREFERENCE_NAME, false);

    Config *config = new Config();

    for (int i = 0; i < config->getPropertyCount(); i++) {
        Property *prop = config->getPropertyArray()[i];

        String value = preferences.getString(prop->getName().c_str(), "");

        if (value != "") {
            bool success = prop->setValue(value);
            if (!success) {
                logger->log("Could not parse Property value " + value + " for property " + prop->getName());
            } else {
                logger->log(prop->getName() + ' ' + prop->getValueAsString());
            }
        }
    }

    preferences.end();

    return config;
}

void ConfigService::saveConfig(Config *config) {
    preferences.begin(PREFERENCE_NAME, false);
    preferences.clear();

    for (int i = 0; i < config->getPropertyCount(); i++) {
        Property *prop = config->getPropertyArray()[i];
        preferences.putString(prop->getName().c_str(), prop->getValueAsString());
    }

    preferences.end();
}

Config *ConfigService::getConfig() const {
    return config;
}

Config *ConfigService::getTempConfig() const {
    return tempConfig;
}
