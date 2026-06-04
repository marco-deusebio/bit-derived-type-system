//
//  Bit.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/******
 * Bit   *
 ******/

#include "Bit.h"
#include "Bool.h"

#include <ostream>

Bit::Bit(std::uint8_t v)
    : value(v == 0 ? 0 : 1) {}

Bit::Bit(bool v)
    : value(v ? 1 : 0) {}

Bit::Bit(int v)
    : value(v == 0 ? 0 : 1) {}

Bit::Bit(const Bool& v)
    : value(static_cast<std::uint8_t>(v.toByte().raw() != 0)) {}
    
std::uint8_t Bit::raw() const {
    return this->value;
}

void Bit::set(std::uint8_t v) {
    this->value = v == 0 ? 0 : 1;
}

void Bit::set(bool v) {
    this->value = v ? 1 : 0;
}

Bit Bit::operator!() const {
    return Bit(this->value == 0);
}

Bit Bit::operator~() const {
    return !(*this);
}

Bit Bit::operator&(const Bit& other) const {
    return Bit(this->value != 0 && other.value != 0);
}

Bit Bit::operator|(const Bit& other) const {
    return Bit(this->value != 0 || other.value != 0);
}

Bit Bit::operator^(const Bit& other) const {
    return Bit(this->value != other.value);
}

Bit& Bit::operator&=(const Bit& other) {
    *this = *this & other;
    return *this;
}

Bit& Bit::operator|=(const Bit& other) {
    *this = *this | other;
    return *this;
}

Bit& Bit::operator^=(const Bit& other) {
    *this = *this ^ other;
    return *this;
}

bool Bit::operator==(const Bit& other) const {
    return this->value == other.value;
}

bool Bit::operator!=(const Bit& other) const {
    return this->value != other.value;
}

std::ostream& operator<<(std::ostream& os, const Bit& bit) {
    os << static_cast<int>(bit.raw());
    return os;
}

