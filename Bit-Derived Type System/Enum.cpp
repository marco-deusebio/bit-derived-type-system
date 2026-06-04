//
//  Enum.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/******************
 * Enum  (from Int32)   *
 ******************/

#include "Enum.h"

#include <ostream>

Enum::Enum()
: value(Int32::fromSignedValue(0)),
min_val(Int32::fromSignedValue(0)),
max_val(Int32::fromSignedValue(0)) {}

Enum::Enum(const Int32& initial, const Int32& min, const Int32& max)
: value(initial), min_val(min), max_val(max) {
    if ((this->min_val > this->max_val).toByte().raw() != 0) {
        Int32 temp = this->min_val;
        this->min_val = this->max_val;
        this->max_val = temp;
    }
    
    if ((this->value < this->min_val).toByte().raw() != 0) {
        this->value = this->min_val;
    }
    
    if ((this->value > this->max_val).toByte().raw() != 0) {
        this->value = this->max_val;
    }
}

Enum Enum::fromRange(long long initial, long long min, long long max) {
    return Enum(
                Int32::fromSignedValue(initial),
                Int32::fromSignedValue(min),
                Int32::fromSignedValue(max)
                );
}

Enum::operator Int32() const {
    return this->value;
}

Int32 Enum::getValue() const {
    return this->value;
}

Int32 Enum::getMin() const {
    return this->min_val;
}

Int32 Enum::getMax() const {
    return this->max_val;
}

Bool Enum::isValid(const Int32& testValue) const {
    if ((testValue < this->min_val).toByte().raw() != 0) {
        return Bool(Byte(0));
    }
    
    if ((testValue > this->max_val).toByte().raw() != 0) {
        return Bool(Byte(0));
    }
    
    return Bool(Byte(1));
}

Bool Enum::setValue(const Int32& newValue) {
    if (this->isValid(newValue).toByte().raw() == 0) {
        return Bool(Byte(0));
    }
    
    this->value = newValue;
    return Bool(Byte(1));
}

Bool Enum::sameRange(const Enum& other) const {
    return (this->min_val == other.min_val) &&
    (this->max_val == other.max_val);
}

Enum& Enum::operator++() {
    if ((this->value < this->max_val).toByte().raw() != 0) {
        ++this->value;
    }
    
    return *this;
}

Enum Enum::operator++(int) {
    Enum oldValue = *this;
    ++(*this);
    return oldValue;
}

Enum& Enum::operator--() {
    if ((this->value > this->min_val).toByte().raw() != 0) {
        --this->value;
    }
    
    return *this;
}

Enum Enum::operator--(int) {
    Enum oldValue = *this;
    --(*this);
    return oldValue;
}

Bool Enum::operator==(const Enum& other) const {
    return this->value == other.value;
}

Bool Enum::operator!=(const Enum& other) const {
    return !(*this == other);
}

Bool Enum::operator<(const Enum& other) const {
    return this->value < other.value;
}

Bool Enum::operator>(const Enum& other) const {
    return this->value > other.value;
}

Bool Enum::operator<=(const Enum& other) const {
    return this->value <= other.value;
}

Bool Enum::operator>=(const Enum& other) const {
    return this->value >= other.value;
}

std::ostream& operator<<(std::ostream& os, const Enum& value) {
    os << "Enum{"
    << "value=" << value.getValue()
    << ", min=" << value.getMin()
    << ", max=" << value.getMax()
    << "}";
    
    return os;
}
