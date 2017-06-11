//
// Created by Florian on 14.05.2017.
//

#include "BooleanProperty.h"

BooleanProperty::BooleanProperty(const String name, bool defaultValue) : name(name),
                                                                          defaultValue(defaultValue),
                                                                          value(defaultValue) {
}

bool BooleanProperty::getValue() const {
    return value;
}

String BooleanProperty::getName() const {
    return name;
}

bool BooleanProperty::setValue(const String value) {
    int i = atoi(value.c_str());
    if (i == 0) {
        this->value = false;
        return true;
    } else if (i == 1) {
        this->value = true;
        return true;
    }
    return false;
}

String BooleanProperty::getValueAsString() const {
    return String(value);
}
