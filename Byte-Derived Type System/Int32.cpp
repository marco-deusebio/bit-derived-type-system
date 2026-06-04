//
//  Int32.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/******************
 * Int32  (from UInt32)  *
 ******************/

#include "Int32.h"
#include "Bool.h"

#include <ostream>

Int32::Int32(const UInt32& rawBits)
    : bits(rawBits) {}

Int32::Int32(long long value)
    : bits(Int32::fromSignedValue(value).bits) {}

Int32 Int32::fromSignedValue(long long value) {
    unsigned long long raw = static_cast<unsigned long long>(value) & 0xFFFFFFFFULL;
    
    Byte b0(static_cast<std::uint8_t>(raw & 0xFF));
    Byte b1(static_cast<std::uint8_t>((raw >> 8) & 0xFF));
    Byte b2(static_cast<std::uint8_t>((raw >> 16) & 0xFF));
    Byte b3(static_cast<std::uint8_t>((raw >> 24) & 0xFF));
    
    return Int32(UInt32(b0, b1, b2, b3));
}

UInt32 Int32::raw() const {
    return this->bits;
}

long long Int32::toLongLong() const {
    unsigned long long rawValue = this->bits.toUnsignedLongLong();
    
    if (rawValue >= 2147483648ULL) {
        return static_cast<long long>(rawValue) - 4294967296LL;
    }
    
    return static_cast<long long>(rawValue);
}

Bool Int32::isNegative() const {
    if (this->bits.getByte(3).raw() >= 128) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Int32& Int32::operator++() {
    ++this->bits;
    return *this;
}

Int32 Int32::operator++(int) {
    Int32 oldValue = *this;
    ++(*this);
    return oldValue;
}

Int32& Int32::operator--() {
    --this->bits;
    return *this;
}

Int32 Int32::operator--(int) {
    Int32 oldValue = *this;
    --(*this);
    return oldValue;
}

Int32 Int32::operator+(const Int32& other) const {
    return Int32(this->bits + other.bits);
}

Int32 Int32::operator-(const Int32& other) const {
    return Int32(this->bits - other.bits);
}

Int32 Int32::operator*(const Int32& other) const {
    long long result = this->toLongLong() * other.toLongLong();
    return Int32::fromSignedValue(result);
}

Int32 Int32::operator/(const Int32& other) const {
    if (other.toLongLong() == 0) {
        throw std::invalid_argument("Cannot divide Int32 by zero.");
    }
    
    long long result = this->toLongLong() / other.toLongLong();
    return Int32::fromSignedValue(result);
}

Int32 Int32::operator%(const Int32& other) const {
    if (other.toLongLong() == 0) {
        throw std::invalid_argument("Cannot modulo Int32 by zero.");
    }
    
    long long result = this->toLongLong() % other.toLongLong();
    return Int32::fromSignedValue(result);
}

Int32& Int32::operator+=(const Int32& other) {
    *this = *this + other;
    return *this;
}

Int32& Int32::operator-=(const Int32& other) {
    *this = *this - other;
    return *this;
}

Int32& Int32::operator*=(const Int32& other) {
    *this = *this * other;
    return *this;
}

Int32& Int32::operator/=(const Int32& other) {
    *this = *this / other;
    return *this;
}

Int32& Int32::operator%=(const Int32& other) {
    *this = *this % other;
    return *this;
}

Bool Int32::operator==(const Int32& other) const {
    return this->bits == other.bits;
}

Bool Int32::operator!=(const Int32& other) const {
    return !(*this == other);
}

Bool Int32::operator<(const Int32& other) const {
    if (this->toLongLong() < other.toLongLong()) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Int32::operator>(const Int32& other) const {
    if (this->toLongLong() > other.toLongLong()) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Int32::operator<=(const Int32& other) const {
    return !(*this > other);
}

Bool Int32::operator>=(const Int32& other) const {
    return !(*this < other);
}

Int32 Int32::operator~() const {
    return Int32(~this->bits);
}

Int32 Int32::operator&(const Int32& other) const {
    return Int32(this->bits & other.bits);
}

Int32 Int32::operator|(const Int32& other) const {
    return Int32(this->bits | other.bits);
}

Int32 Int32::operator^(const Int32& other) const {
    return Int32(this->bits ^ other.bits);
}

Int32 Int32::operator<<(int amount) const {
    return Int32(this->bits << amount);
}

Int32 Int32::operator>>(int amount) const {
    if (amount < 0) {
        throw std::invalid_argument("Cannot right-shift Int32 by a negative amount.");
    }
    
    if (amount >= 32) {
        if (this->isNegative().toByte().raw() != 0) {
            return Int32::fromSignedValue(-1);
        }
        
        return Int32::fromSignedValue(0);
    }
    
    return Int32::fromSignedValue(this->toLongLong() >> amount);
}

Int32& Int32::operator&=(const Int32& other) {
    *this = *this & other;
    return *this;
}

Int32& Int32::operator|=(const Int32& other) {
    *this = *this | other;
    return *this;
}

Int32& Int32::operator^=(const Int32& other) {
    *this = *this ^ other;
    return *this;
}

Int32& Int32::operator<<=(int amount) {
    *this = *this << amount;
    return *this;
}

Int32& Int32::operator>>=(int amount) {
    *this = *this >> amount;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Int32& value) {
    os << value.toLongLong();
    return os;
}
