//
// Created by Florian on 14.05.2017.
//

#ifndef EMERGENCYSTOP_STRINGPROPERTY_H
#define EMERGENCYSTOP_STRINGPROPERTY_H


#include <WString.h>
#include "Property.h"

class StringProperty : public Property {

public:
    StringProperty(const String name, const String defaultValue);

    String getValue() const;

    bool setValue(const String value) override;

    String getName() const override;

    String getValueAsString() const override;

private:
    String name;
    String defaultValue;
    String value;
};


#endif //EMERGENCYSTOP_STRINGPROPERTY_H
