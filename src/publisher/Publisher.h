//
// Created by Florian on 07.05.2017.
//

#ifndef PUBLISHER_H
#define PUBLISHER_H


class Publisher {
public:
    virtual void publishEmergencySignal()= 0;

    virtual void doWork() {
    }
};


#endif //PUBLISHER_H
