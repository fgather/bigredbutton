//
// Created by Florian on 07.05.2017.
//

#ifndef EMERGENCY_CONFIGSERVICE_H
#define EMERGENCY_CONFIGSERVICE_H

#include <Preferences.h>
#include <configuration/Config.h>
#include <Logger.h>

#ifndef PREFERENCE_NAME
#define PREFERENCE_NAME "brbutton"
#endif

class ConfigService {
public:
    ConfigService(Logger *logger);

    Config *getConfig() const;

    Config *getTempConfig() const;

    void loadDefaultValuesToTempConfig();
    void persistTempConfig();

private:
    Config *config;

    Logger *logger;
    Config *tempConfig;

    Config *loadConfig();

    void saveConfig(Config *config);

    Preferences preferences;
};


#endif //EMERGENCY_CONFIGSERVICE_H
