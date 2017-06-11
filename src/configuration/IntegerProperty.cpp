//
// Created by Florian on 14.05.2017.
//

#include "IntegerProperty.h"

IntegerProperty::IntegerProperty(const String name, uint32_t defaultValue) : name(name),
                                                                              defaultValue(defaultValue),
                                                                              value(defaultValue) {

}

uint32_t IntegerProperty::getValue() const {
    return value;
}

String IntegerProperty::getName() const {
    return name;
}

bool IntegerProperty::setValue(const String value) {
    this->value = (uint32_t) atoi(value.c_str());
    return true;
}

String IntegerProperty::getValueAsString() const {
    return String(value);
}
