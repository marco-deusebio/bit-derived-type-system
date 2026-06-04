//
//  Int64.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/******************
 * Int64  (from UInt64)  *
 ******************/

#include "Int64.h"
#include "Bool.h"

#include <limits>
#include <ostream>

Int64::Int64(const UInt64& rawBits)
    : bits(rawBits) {}

Int64::Int64(long long value)
    : bits(Int64::fromSignedValue(value).bits) {}

Int64 Int64::fromSignedValue(long long value) {
    unsigned long long raw = static_cast<unsigned long long>(value);
    
    Byte b0(static_cast<std::uint8_t>(raw & 0xFF));
    Byte b1(static_cast<std::uint8_t>((raw >> 8) & 0xFF));
    Byte b2(static_cast<std::uint8_t>((raw >> 16) & 0xFF));
    Byte b3(static_cast<std::uint8_t>((raw >> 24) & 0xFF));
    Byte b4(static_cast<std::uint8_t>((raw >> 32) & 0xFF));
    Byte b5(static_cast<std::uint8_t>((raw >> 40) & 0xFF));
    Byte b6(static_cast<std::uint8_t>((raw >> 48) & 0xFF));
    Byte b7(static_cast<std::uint8_t>((raw >> 56) & 0xFF));
    
    return Int64(UInt64(b0, b1, b2, b3, b4, b5, b6, b7));
}

UInt64 Int64::raw() const {
    return this->bits;
}

long long Int64::toLongLong() const {
    unsigned long long rawValue = this->bits.toUnsignedLongLong();
    
    if (rawValue < 9223372036854775808ULL) {
        return static_cast<long long>(rawValue);
    }
    
    unsigned long long magnitude = (~rawValue) + 1ULL;
    
    if (magnitude == 9223372036854775808ULL) {
        return std::numeric_limits<long long>::min();
    }
    
    return -static_cast<long long>(magnitude);
}

Bool Int64::isNegative() const {
    if (this->bits.getByte(7).raw() >= 128) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Int64& Int64::operator++() {
    ++this->bits;
    return *this;
}

Int64 Int64::operator++(int) {
    Int64 oldValue = *this;
    ++(*this);
    return oldValue;
}

Int64& Int64::operator--() {
    --this->bits;
    return *this;
}

Int64 Int64::operator--(int) {
    Int64 oldValue = *this;
    --(*this);
    return oldValue;
}

Int64 Int64::operator+(const Int64& other) const {
    return Int64(this->bits + other.bits);
}

Int64 Int64::operator-(const Int64& other) const {
    return Int64(this->bits - other.bits);
}

Int64 Int64::operator*(const Int64& other) const {
    return Int64(this->bits * other.bits);
}

Int64 Int64::operator/(const Int64& other) const {
    long long divisor = other.toLongLong();
    
    if (divisor == 0) {
        throw std::invalid_argument("Cannot divide Int64 by zero.");
    }
    
    long long dividend = this->toLongLong();
    
    if (dividend == std::numeric_limits<long long>::min() && divisor == -1) {
        throw std::overflow_error("Int64 division overflow.");
    }
    
    return Int64::fromSignedValue(dividend / divisor);
}

Int64 Int64::operator%(const Int64& other) const {
    long long divisor = other.toLongLong();
    
    if (divisor == 0) {
        throw std::invalid_argument("Cannot modulo Int64 by zero.");
    }
    
    long long dividend = this->toLongLong();
    
    if (dividend == std::numeric_limits<long long>::min() && divisor == -1) {
        return Int64::fromSignedValue(0);
    }
    
    return Int64::fromSignedValue(dividend % divisor);
}

Int64& Int64::operator+=(const Int64& other) {
    *this = *this + other;
    return *this;
}

Int64& Int64::operator-=(const Int64& other) {
    *this = *this - other;
    return *this;
}

Int64& Int64::operator*=(const Int64& other) {
    *this = *this * other;
    return *this;
}

Int64& Int64::operator/=(const Int64& other) {
    *this = *this / other;
    return *this;
}

Int64& Int64::operator%=(const Int64& other) {
    *this = *this % other;
    return *this;
}

Bool Int64::operator==(const Int64& other) const {
    return this->bits == other.bits;
}

Bool Int64::operator!=(const Int64& other) const {
    return !(*this == other);
}

Bool Int64::operator<(const Int64& other) const {
    if (this->toLongLong() < other.toLongLong()) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Int64::operator>(const Int64& other) const {
    if (this->toLongLong() > other.toLongLong()) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Int64::operator<=(const Int64& other) const {
    return !(*this > other);
}

Bool Int64::operator>=(const Int64& other) const {
    return !(*this < other);
}

Int64 Int64::operator~() const {
    return Int64(~this->bits);
}

Int64 Int64::operator&(const Int64& other) const {
    return Int64(this->bits & other.bits);
}

Int64 Int64::operator|(const Int64& other) const {
    return Int64(this->bits | other.bits);
}

Int64 Int64::operator^(const Int64& other) const {
    return Int64(this->bits ^ other.bits);
}

Int64 Int64::operator<<(int amount) const {
    return Int64(this->bits << amount);
}

Int64 Int64::operator>>(int amount) const {
    if (amount < 0) {
        throw std::invalid_argument("Cannot right-shift Int64 by a negative amount.");
    }
    
    if (amount >= 64) {
        if (this->isNegative().toByte().raw() != 0) {
            return Int64::fromSignedValue(-1);
        }
        
        return Int64::fromSignedValue(0);
    }
    
    return Int64::fromSignedValue(this->toLongLong() >> amount);
}

Int64& Int64::operator&=(const Int64& other) {
    *this = *this & other;
    return *this;
}

Int64& Int64::operator|=(const Int64& other) {
    *this = *this | other;
    return *this;
}

Int64& Int64::operator^=(const Int64& other) {
    *this = *this ^ other;
    return *this;
}

Int64& Int64::operator<<=(int amount) {
    *this = *this << amount;
    return *this;
}

Int64& Int64::operator>>=(int amount) {
    *this = *this >> amount;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Int64& value) {
    os << value.toLongLong();
    return os;
}
