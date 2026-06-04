//
//  Float64.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/********************
 * Float64   (from UInt64)  *
 ********************/

#include "Float64.h"

#include <cmath>
#include <cstdint>
#include <cstring>
#include <ostream>
#include <stdexcept>

Float64::Float64()
    : bits(UInt64()) {}

Float64::Float64(double value)
    : bits(UInt64()) {
    std::uint64_t raw = 0;
    
    std::memcpy(&raw, &value, sizeof(double));
    
    this->bits = UInt64(
                        Byte(static_cast<std::uint8_t>(raw & 0xFF)),
                        Byte(static_cast<std::uint8_t>((raw >> 8) & 0xFF)),
                        Byte(static_cast<std::uint8_t>((raw >> 16) & 0xFF)),
                        Byte(static_cast<std::uint8_t>((raw >> 24) & 0xFF)),
                        Byte(static_cast<std::uint8_t>((raw >> 32) & 0xFF)),
                        Byte(static_cast<std::uint8_t>((raw >> 40) & 0xFF)),
                        Byte(static_cast<std::uint8_t>((raw >> 48) & 0xFF)),
                        Byte(static_cast<std::uint8_t>((raw >> 56) & 0xFF))
                        );
}

Float64::Float64(const UInt64& rawBits)
    : bits(rawBits) {}

Float64 Float64::fromBytes(const Byte& b0,
                           const Byte& b1,
                           const Byte& b2,
                           const Byte& b3,
                           const Byte& b4,
                           const Byte& b5,
                           const Byte& b6,
                           const Byte& b7) {
    return Float64(UInt64(b0, b1, b2, b3, b4, b5, b6, b7));
}

Float64::operator double() const {
    return this->toDouble();
}

UInt64 Float64::raw() const {
    return this->bits;
}

double Float64::toDouble() const {
    std::uint64_t raw =
    static_cast<std::uint64_t>(this->bits.getByte(0).raw()) |
    (static_cast<std::uint64_t>(this->bits.getByte(1).raw()) << 8) |
    (static_cast<std::uint64_t>(this->bits.getByte(2).raw()) << 16) |
    (static_cast<std::uint64_t>(this->bits.getByte(3).raw()) << 24) |
    (static_cast<std::uint64_t>(this->bits.getByte(4).raw()) << 32) |
    (static_cast<std::uint64_t>(this->bits.getByte(5).raw()) << 40) |
    (static_cast<std::uint64_t>(this->bits.getByte(6).raw()) << 48) |
    (static_cast<std::uint64_t>(this->bits.getByte(7).raw()) << 56);
    
    double result = 0.0;
    
    std::memcpy(&result, &raw, sizeof(double));
    
    return result;
}

Bool Float64::signBit() const {
    Byte highestByte = this->bits.getByte(7);
    
    if ((highestByte.raw() & 0x80) != 0) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

UInt16 Float64::exponentBits() const {
    Byte byte6 = this->bits.getByte(6);
    Byte byte7 = this->bits.getByte(7);
    
    unsigned int exponent =
    ((byte7.raw() & 0x7F) << 4) |
    ((byte6.raw() & 0xF0) >> 4);
    
    Byte lowByte = Byte(static_cast<std::uint8_t>(exponent & 0xFF));
    Byte highByte = Byte(static_cast<std::uint8_t>((exponent >> 8) & 0xFF));
    
    return UInt16(lowByte, highByte);
}

UInt64 Float64::fractionBits() const {
    Byte b0 = this->bits.getByte(0);
    Byte b1 = this->bits.getByte(1);
    Byte b2 = this->bits.getByte(2);
    Byte b3 = this->bits.getByte(3);
    Byte b4 = this->bits.getByte(4);
    Byte b5 = this->bits.getByte(5);
    Byte b6 = Byte(static_cast<std::uint8_t>(this->bits.getByte(6).raw() & 0x0F));
    Byte b7 = Byte(0);
    
    return UInt64(b0, b1, b2, b3, b4, b5, b6, b7);
}

Bool Float64::isZero() const {
    if (this->exponentBits().toUnsignedInt() == 0 &&
        this->fractionBits().toUnsignedLongLong() == 0) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Float64::isInfinity() const {
    if (this->exponentBits().toUnsignedInt() == 2047 &&
        this->fractionBits().toUnsignedLongLong() == 0) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Float64::isNaN() const {
    if (this->exponentBits().toUnsignedInt() == 2047 &&
        this->fractionBits().toUnsignedLongLong() != 0) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Float64::sameBits(const Float64& other) const {
    return this->bits == other.bits;
}

Bool Float64::isClose(const Float64& other, double tolerance) const {
    if (tolerance < 0.0) {
        tolerance = -tolerance;
    }
    
    return Bool(Byte(std::fabs(this->toDouble() - other.toDouble()) <= tolerance));
}

Float64& Float64::operator++() {
    *this = Float64(this->toDouble() + 1.0);
    return *this;
}

Float64 Float64::operator++(int) {
    Float64 oldValue = *this;
    ++(*this);
    return oldValue;
}

Float64& Float64::operator--() {
    *this = Float64(this->toDouble() - 1.0);
    return *this;
}

Float64 Float64::operator--(int) {
    Float64 oldValue = *this;
    --(*this);
    return oldValue;
}

Float64 Float64::operator+(const Float64& other) const {
    return Float64(this->toDouble() + other.toDouble());
}

Float64 Float64::operator-(const Float64& other) const {
    return Float64(this->toDouble() - other.toDouble());
}

Float64 Float64::operator*(const Float64& other) const {
    return Float64(this->toDouble() * other.toDouble());
}

Float64 Float64::operator/(const Float64& other) const {
    if (other.toDouble() == 0.0) {
        throw std::invalid_argument("Cannot divide Float64 by zero.");
    }
    
    return Float64(this->toDouble() / other.toDouble());
}

Float64& Float64::operator+=(const Float64& other) {
    *this = *this + other;
    return *this;
}

Float64& Float64::operator-=(const Float64& other) {
    *this = *this - other;
    return *this;
}

Float64& Float64::operator*=(const Float64& other) {
    *this = *this * other;
    return *this;
}

Float64& Float64::operator/=(const Float64& other) {
    *this = *this / other;
    return *this;
}

Bool Float64::operator==(const Float64& other) const {
    if (this->isNaN().toByte().raw() != 0 ||
        other.isNaN().toByte().raw() != 0) {
        return Bool(Byte(0));
    }
    
    return this->isClose(other);
}

Bool Float64::operator!=(const Float64& other) const {
    return !(*this == other);
}

Bool Float64::operator<(const Float64& other) const {
    if ((*this == other).toByte().raw() != 0) {
        return Bool(Byte(0));
    }
    
    return Bool(Byte(this->toDouble() < other.toDouble()));
}

Bool Float64::operator>(const Float64& other) const {
    if ((*this == other).toByte().raw() != 0) {
        return Bool(Byte(0));
    }
    
    return Bool(Byte(this->toDouble() > other.toDouble()));
}

Bool Float64::operator<=(const Float64& other) const {
    return !(*this > other);
}

Bool Float64::operator>=(const Float64& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Float64& value) {
    os << value.toDouble();
    return os;
}
