//
// Created by Florian on 14.05.2017.
//

#include "StringProperty.h"

StringProperty::StringProperty(const String name, const String defaultValue) : name(name),
                                                                               defaultValue(defaultValue),
                                                                               value(defaultValue) {
}

String StringProperty::getValue() const {
    return value;
}

bool StringProperty::setValue(const String value) {
    StringProperty::value = value;
    return true;
}

String StringProperty::getValueAsString() const {
    return value;
}

String StringProperty::getName() const {
    return name;
}
