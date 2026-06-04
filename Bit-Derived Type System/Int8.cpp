//
//  Int8.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/****************
 * Int8  (from UInt8)  *
 ****************/

#include "Int8.h"
#include "Bool.h"

#include <ostream>
#include <stdexcept>

Int8::Int8(const UInt8& rawBits)
    : bits(rawBits) {}

Int8::Int8(int value)
    : bits(UInt8(Byte(static_cast<std::uint8_t>(value)))) {}

Int8 Int8::fromSignedValue(int value) {
    return Int8(UInt8(Byte(static_cast<std::uint8_t>(value))));
}

Int8::operator UInt8() const {
    return this->bits;
}

UInt8 Int8::raw() const {
    return this->bits;
}

int Int8::toInt() const {
    int rawValue = this->bits.toInt();
    
    if (rawValue >= 128) {
        return rawValue - 256;
    }
    
    return rawValue;
}

Bool Int8::isNegative() const {
    return Bool(Byte(this->bits.toInt() >= 128));
}

Int8& Int8::operator++() {
    this->bits++;
    return *this;
}

Int8 Int8::operator++(int) {
    Int8 oldValue = *this;
    ++(*this);
    return oldValue;
}

Int8& Int8::operator--() {
    this->bits--;
    return *this;
}

Int8 Int8::operator--(int) {
    Int8 oldValue = *this;
    --(*this);
    return oldValue;
}

Int8 Int8::operator+(const Int8& other) const {
    return Int8(this->bits + other.bits);
}

Int8 Int8::operator-(const Int8& other) const {
    return Int8(this->bits - other.bits);
}

Int8 Int8::operator*(const Int8& other) const {
    return Int8::fromSignedValue(this->toInt() * other.toInt());
}

Int8 Int8::operator/(const Int8& other) const {
    if (other.toInt() == 0) {
        throw std::invalid_argument("Cannot divide Int8 by zero.");
    }
    
    return Int8::fromSignedValue(this->toInt() / other.toInt());
}

Int8 Int8::operator%(const Int8& other) const {
    if (other.toInt() == 0) {
        throw std::invalid_argument("Cannot modulo Int8 by zero.");
    }
    
    return Int8::fromSignedValue(this->toInt() % other.toInt());
}

Bool Int8::operator==(const Int8& other) const {
    return Bool(Byte(this->bits.toInt() == other.bits.toInt()));
}

Bool Int8::operator!=(const Int8& other) const {
    return Bool(Byte(this->bits.toInt() != other.bits.toInt()));
}

Bool Int8::operator<(const Int8& other) const {
    return Bool(Byte(this->toInt() < other.toInt()));
}

Bool Int8::operator>(const Int8& other) const {
    return Bool(Byte(this->toInt() > other.toInt()));
}

Bool Int8::operator<=(const Int8& other) const {
    return Bool(Byte(this->toInt() <= other.toInt()));
}

Bool Int8::operator>=(const Int8& other) const {
    return Bool(Byte(this->toInt() >= other.toInt()));
}

std::ostream& operator<<(std::ostream& os, const Int8& value) {
    os << value.toInt();
    return os;
}
