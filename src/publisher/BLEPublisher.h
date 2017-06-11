//
// Created by Florian on 21.05.2017.
//

#ifndef EMERGENCY_BLEPUBLISHER_H
#define EMERGENCY_BLEPUBLISHER_H


#include "Publisher.h"

class BLEPublisher : public Publisher {

public:

    BLEPublisher();

    void publishEmergencySignal() override;

    void doWork() override;
};


#endif //EMERGENCY_BLEPUBLISHER_H
