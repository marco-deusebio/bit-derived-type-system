//
//  Bool.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/****************
 * Bool  (from Byte)  *
 ****************/

#include "Bool.h"

#include <ostream>

Byte Bool::normalize(const Byte& byte) {
    if (byte.raw() == 0) {
        return Byte(0);
    }
    
    return Byte(1);
}

Bool::Bool(const Byte& byte)
    : value(normalize(byte)) {}

Bool::Bool(bool v)
    : value(v ? Byte(1) : Byte(0)) {}

Bool::operator Byte() const {
    return this->value;
}

Bool::operator bool() const {
    return this->value.raw() != 0;
}

Byte Bool::toByte() const {
    return this->value;
}

int Bool::toInt() const {
    return static_cast<int>(this->value.raw());
}

void Bool::set(const Byte& byte) {
    this->value = normalize(byte);
}

void Bool::set(bool v) {
    this->value = v ? Byte(1) : Byte(0);
}

Bool Bool::operator!() const {
    if (this->value.raw() == 0) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Bool::operator&&(const Bool& other) const {
    if (this->value.raw() == 1 && other.value.raw() == 1) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Bool::operator||(const Bool& other) const {
    if (this->value.raw() == 1 || other.value.raw() == 1) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Bool::operator==(const Bool& other) const {
    if (this->value.raw() == other.value.raw()) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Bool::operator!=(const Bool& other) const {
    if (this->value.raw() != other.value.raw()) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

std::ostream& operator<<(std::ostream& os, const Bool& value) {
    if (value.toByte().raw() == 0) {
        os << "false";
    } else {
        os << "true";
    }
    
    return os;
}
