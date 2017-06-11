//
// Created by Florian on 14.05.2017.
//

#ifndef EMERGENCYSTOP_BOOLEANPROPERTY_H
#define EMERGENCYSTOP_BOOLEANPROPERTY_H


#include <WString.h>
#include "Property.h"

class BooleanProperty : public Property {
public:
    BooleanProperty(const String name, bool defaultValue);

    bool getValue() const;

    String getName() const override;

    bool setValue(const String value) override;

    String getValueAsString() const override;

private:
    const String name;
    const bool defaultValue;
    bool value;
};


#endif //EMERGENCYSTOP_BOOLEANPROPERTY_H
