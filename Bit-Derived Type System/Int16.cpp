//
//  Int16.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/******************
 * Int16  (from UInt16)  *
 ******************/

#include "Int16.h"
#include "Bool.h"

#include <ostream>

Int16::Int16(const UInt16& rawBits)
    : bits(rawBits) {}

Int16::Int16(int value)
    : bits(Int16::fromSignedValue(value).bits) {}

Int16 Int16::fromSignedValue(int value) {
    unsigned int raw = static_cast<unsigned int>(value) & 0xFFFF;
    
    Byte lowByte(static_cast<std::uint8_t>(raw & 0xFF));
    Byte highByte(static_cast<std::uint8_t>((raw >> 8) & 0xFF));
    
    return Int16(UInt16(lowByte, highByte));
}

UInt16 Int16::raw() const {
    return this->bits;
}

int Int16::toInt() const {
    unsigned int rawValue = this->bits.toUnsignedInt();
    
    if (rawValue >= 32768) {
        return static_cast<int>(rawValue) - 65536;
    }
    
    return static_cast<int>(rawValue);
}

Bool Int16::isNegative() const {
    if (this->bits.getByte(1).raw() >= 128) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Int16& Int16::operator++() {
    ++this->bits;
    return *this;
}

Int16 Int16::operator++(int) {
    Int16 oldValue = *this;
    ++(*this);
    return oldValue;
}

Int16& Int16::operator--() {
    --this->bits;
    return *this;
}

Int16 Int16::operator--(int) {
    Int16 oldValue = *this;
    --(*this);
    return oldValue;
}

Int16 Int16::operator+(const Int16& other) const {
    return Int16(this->bits + other.bits);
}

Int16 Int16::operator-(const Int16& other) const {
    return Int16(this->bits - other.bits);
}

Bool Int16::operator==(const Int16& other) const {
    return this->bits == other.bits;
}

Bool Int16::operator!=(const Int16& other) const {
    return !(*this == other);
}

Bool Int16::operator<(const Int16& other) const {
    if (this->toInt() < other.toInt()) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Int16::operator>(const Int16& other) const {
    if (this->toInt() > other.toInt()) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Int16::operator<=(const Int16& other) const {
    return !(*this > other);
}

Bool Int16::operator>=(const Int16& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Int16& value) {
    os << value.toInt();
    return os;
}
