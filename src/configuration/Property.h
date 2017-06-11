//
// Created by Florian on 14.05.2017.
//

#ifndef EMERGENCYSTOP_PROPERTY_H
#define EMERGENCYSTOP_PROPERTY_H


#include <WString.h>

class Property {

public:
    virtual bool setValue(const String value) = 0;

    virtual String getValueAsString() const = 0;

    virtual String getName() const = 0;
};


#endif //EMERGENCYSTOP_PROPERTY_H
