#include "Arduino.h"

#include <service/PublishService.h>
#include <service/HttpConfigService.h>
#include "service/WifiService.h"
#include "service/SerialService.h"

Logger *logger = new Logger();

SerialService *serialService;
PublishService *publishService;
HttpConfigService *httpConfigService;
WifiService *wifiService;

#include <Bounce2.h>

const uint8_t buttonPin = 17;
Bounce debouncer = Bounce();

bool configMode = false;

void buttonInterruptHandler() {
    debouncer.update();
}

void setupConfigMode() {
    Serial.begin(115200);
    ConfigService *configService = new ConfigService(logger);

    httpConfigService = new HttpConfigService(configService, logger);

    serialService = new SerialService(configService);
    serialService->setup();

    wifiService = new WifiService(configService->getConfig(), logger);
    wifiService->setupAPMode();
}

void setupNormalMode() {
    Serial.begin(115200);
    ConfigService *configService = new ConfigService(logger);

    serialService = new SerialService(configService);
    serialService->setup();

    wifiService = new WifiService(configService->getConfig(), logger);
    wifiService->setup();

    publishService = new PublishService(configService->getConfig(), logger);

    pinMode(buttonPin, INPUT_PULLUP);
    debouncer.attach(buttonPin);
    debouncer.interval(5);
    attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterruptHandler, CHANGE);
}

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);
    delay(10);
    if (!digitalRead(buttonPin)) {
        configMode = true;
    }

    if (configMode) {
        setupConfigMode();
    } else {
        setupNormalMode();
    }
}

void loopConfigMode() {
    serialService->doWork();
    httpConfigService->doWork();
    delay(100);
}


void loopNormalMode() {
    serialService->doWork();
    publishService->doWork();

    debouncer.update();
    if (debouncer.fallingEdge()) {
        publishService->publishEmergencySignal();
    }

    delay(100);
}

void loop() {
    if (configMode) {
        loopConfigMode();
    } else {
        loopNormalMode();
    }
}
