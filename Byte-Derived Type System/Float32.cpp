//
//  Float32.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/********************
 * Float32   (from UInt32)  *
 ********************/

#include "Float32.h"

#include <cmath>
#include <cstdint>
#include <cstring>
#include <ostream>
#include <stdexcept>

Float32::Float32()
    : bits(UInt32()) {}

Float32::Float32(float value)
    : bits(UInt32()) {
    std::uint32_t raw = 0;
    
    std::memcpy(&raw, &value, sizeof(float));
    
    this->bits = UInt32(
                        Byte(static_cast<std::uint8_t>(raw & 0xFF)),
                        Byte(static_cast<std::uint8_t>((raw >> 8) & 0xFF)),
                        Byte(static_cast<std::uint8_t>((raw >> 16) & 0xFF)),
                        Byte(static_cast<std::uint8_t>((raw >> 24) & 0xFF))
                        );
}

Float32::Float32(const UInt32& rawBits)
    : bits(rawBits) {}

Float32 Float32::fromBytes(const Byte& b0,
                           const Byte& b1,
                           const Byte& b2,
                           const Byte& b3) {
    return Float32(UInt32(b0, b1, b2, b3));
}

Float32::operator float() const {
    return this->toFloat();
}

UInt32 Float32::raw() const {
    return this->bits;
}

float Float32::toFloat() const {
    std::uint32_t raw =
    static_cast<std::uint32_t>(this->bits.getByte(0).raw()) |
    (static_cast<std::uint32_t>(this->bits.getByte(1).raw()) << 8) |
    (static_cast<std::uint32_t>(this->bits.getByte(2).raw()) << 16) |
    (static_cast<std::uint32_t>(this->bits.getByte(3).raw()) << 24);
    
    float result = 0.0f;
    
    std::memcpy(&result, &raw, sizeof(float));
    
    return result;
}

Bool Float32::signBit() const {
    Byte highestByte = this->bits.getByte(3);
    
    if ((highestByte.raw() & 0x80) != 0) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

UInt8 Float32::exponentBits() const {
    Byte byte2 = this->bits.getByte(2);
    Byte byte3 = this->bits.getByte(3);
    
    unsigned int exponent =
    ((byte3.raw() & 0x7F) << 1) |
    ((byte2.raw() & 0x80) >> 7);
    
    return UInt8(Byte(static_cast<std::uint8_t>(exponent)));
}

UInt32 Float32::fractionBits() const {
    Byte b0 = this->bits.getByte(0);
    Byte b1 = this->bits.getByte(1);
    Byte b2 = Byte(static_cast<std::uint8_t>(this->bits.getByte(2).raw() & 0x7F));
    Byte b3 = Byte(0);
    
    return UInt32(b0, b1, b2, b3);
}

Bool Float32::isZero() const {
    if (this->exponentBits().toInt() == 0 &&
        this->fractionBits().toUnsignedLongLong() == 0) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Float32::isInfinity() const {
    if (this->exponentBits().toInt() == 255 &&
        this->fractionBits().toUnsignedLongLong() == 0) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Float32::isNaN() const {
    if (this->exponentBits().toInt() == 255 &&
        this->fractionBits().toUnsignedLongLong() != 0) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Float32::isClose(const Float32& other, float tolerance) const {
    if (tolerance < 0.0f) {
        tolerance = -tolerance;
    }
    
    return Bool(Byte(std::fabs(this->toFloat() - other.toFloat()) <= tolerance));
}

Float32& Float32::operator++() {
    *this = Float32(this->toFloat() + 1.0f);
    return *this;
}

Float32 Float32::operator++(int) {
    Float32 oldValue = *this;
    ++(*this);
    return oldValue;
}

Float32& Float32::operator--() {
    *this = Float32(this->toFloat() - 1.0f);
    return *this;
}

Float32 Float32::operator--(int) {
    Float32 oldValue = *this;
    --(*this);
    return oldValue;
}

Float32 Float32::operator+(const Float32& other) const {
    return Float32(this->toFloat() + other.toFloat());
}

Float32 Float32::operator-(const Float32& other) const {
    return Float32(this->toFloat() - other.toFloat());
}

Float32 Float32::operator*(const Float32& other) const {
    return Float32(this->toFloat() * other.toFloat());
}

Float32 Float32::operator/(const Float32& other) const {
    if (other.toFloat() == 0.0f) {
        throw std::invalid_argument("Cannot divide Float32 by zero.");
    }
    
    return Float32(this->toFloat() / other.toFloat());
}

Float32& Float32::operator+=(const Float32& other) {
    *this = *this + other;
    return *this;
}

Float32& Float32::operator-=(const Float32& other) {
    *this = *this - other;
    return *this;
}

Float32& Float32::operator*=(const Float32& other) {
    *this = *this * other;
    return *this;
}

Float32& Float32::operator/=(const Float32& other) {
    *this = *this / other;
    return *this;
}

Bool Float32::operator==(const Float32& other) const {
    if (this->isNaN().toByte().raw() != 0 ||
        other.isNaN().toByte().raw() != 0) {
        return Bool(Byte(0));
    }
    
    return this->isClose(other);
}

Bool Float32::operator!=(const Float32& other) const {
    return !(*this == other);
}

Bool Float32::operator<(const Float32& other) const {
    if ((*this == other).toByte().raw() != 0) {
        return Bool(Byte(0));
    }
    
    return Bool(Byte(this->toFloat() < other.toFloat()));
}

Bool Float32::operator>(const Float32& other) const {
    if ((*this == other).toByte().raw() != 0) {
        return Bool(Byte(0));
    }
    
    return Bool(Byte(this->toFloat() > other.toFloat()));
}

Bool Float32::operator<=(const Float32& other) const {
    return !(*this > other);
}

Bool Float32::operator>=(const Float32& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Float32& value) {
    os << value.toFloat();
    return os;
}
