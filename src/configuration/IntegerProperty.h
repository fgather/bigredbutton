//
// Created by Florian on 14.05.2017.
//

#ifndef EMERGENCYSTOP_INTEGERPROPERTY_H
#define EMERGENCYSTOP_INTEGERPROPERTY_H


#include <cstdint>
#include <WString.h>
#include "Property.h"

class IntegerProperty : public Property {
public:
    IntegerProperty(const String name, uint32_t defaultValue);

    uint32_t getValue() const;

    String getName() const override;

    bool setValue(const String value) override;

    String getValueAsString() const override;

private:
    const String name;
    const uint32_t defaultValue;
    uint32_t value;
};


#endif //EMERGENCYSTOP_INTEGERPROPERTY_H
