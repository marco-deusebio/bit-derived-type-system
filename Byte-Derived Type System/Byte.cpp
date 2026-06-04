//
//  Byte.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/***************
 * Byte (8-bit unit)  *
 ***************/

#include "Byte.h"

#include <ostream>

Byte::Byte(std::uint8_t v) : value(v) {}

std::uint8_t Byte::raw() const {
    return this->value;
}

void Byte::set(std::uint8_t v) {
    this->value = v;
}

Byte Byte::operator~() const {
    return Byte(static_cast<std::uint8_t>(~this->value));
}

Byte Byte::operator&(const Byte& other) const {
    return Byte(static_cast<std::uint8_t>(this->value & other.value));
}

Byte Byte::operator|(const Byte& other) const {
    return Byte(static_cast<std::uint8_t>(this->value | other.value));
}

Byte Byte::operator^(const Byte& other) const {
    return Byte(static_cast<std::uint8_t>(this->value ^ other.value));
}

Byte Byte::operator<<(int amount) const {
    return Byte(static_cast<std::uint8_t>(this->value << amount));
}

Byte Byte::operator>>(int amount) const {
    return Byte(static_cast<std::uint8_t>(this->value >> amount));
}

std::ostream& operator<<(std::ostream& os, const Byte& byte) {
    os << static_cast<int>(byte.raw());
    return os;
}
