//
//  UInt8.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/*****************
 * UInt8   (from Byte)  *
 *****************/

#include "UInt8.h"
#include "Bool.h"

#include <ostream>
#include <stdexcept>

UInt8::UInt8(const Byte& byte)
    : value(byte) {}

UInt8::UInt8(unsigned int value)
    : value(Byte(static_cast<std::uint8_t>(value & 0xFF))) {}

UInt8::operator Byte() const {
    return this->value;
}

Byte UInt8::toByte() const {
    return this->value;
}

int UInt8::toInt() const {
    return static_cast<int>(this->value.raw());
}

void UInt8::set(const Byte& byte) {
    this->value = byte;
}

UInt8& UInt8::operator++() {
    this->value.set(static_cast<std::uint8_t>(this->value.raw() + 1));
    return *this;
}

UInt8 UInt8::operator++(int) {
    UInt8 oldValue = *this;
    ++(*this);
    return oldValue;
}

UInt8& UInt8::operator--() {
    this->value.set(static_cast<std::uint8_t>(this->value.raw() - 1));
    return *this;
}

UInt8 UInt8::operator--(int) {
    UInt8 oldValue = *this;
    --(*this);
    return oldValue;
}

UInt8 UInt8::operator+(const UInt8& other) const {
    return UInt8(Byte(static_cast<std::uint8_t>(
                                                this->value.raw() + other.value.raw()
                                                )));
}

UInt8 UInt8::operator-(const UInt8& other) const {
    return UInt8(Byte(static_cast<std::uint8_t>(
                                                this->value.raw() - other.value.raw()
                                                )));
}

UInt8 UInt8::operator*(const UInt8& other) const {
    return UInt8(Byte(static_cast<std::uint8_t>(
                                                this->value.raw() * other.value.raw()
                                                )));
}

UInt8 UInt8::operator/(const UInt8& other) const {
    if (other.value.raw() == 0) {
        throw std::invalid_argument("Cannot divide UInt8 by zero.");
    }
    
    return UInt8(Byte(static_cast<std::uint8_t>(
                                                this->value.raw() / other.value.raw()
                                                )));
}

UInt8 UInt8::operator%(const UInt8& other) const {
    if (other.value.raw() == 0) {
        throw std::invalid_argument("Cannot modulo UInt8 by zero.");
    }
    
    return UInt8(Byte(static_cast<std::uint8_t>(
                                                this->value.raw() % other.value.raw()
                                                )));
}

UInt8& UInt8::operator+=(const UInt8& other) {
    *this = *this + other;
    return *this;
}

UInt8& UInt8::operator-=(const UInt8& other) {
    *this = *this - other;
    return *this;
}

UInt8& UInt8::operator*=(const UInt8& other) {
    *this = *this * other;
    return *this;
}

UInt8& UInt8::operator/=(const UInt8& other) {
    *this = *this / other;
    return *this;
}

UInt8& UInt8::operator%=(const UInt8& other) {
    *this = *this % other;
    return *this;
}

Bool UInt8::operator==(const UInt8& other) const {
    return Bool(Byte(this->value.raw() == other.value.raw()));
}

Bool UInt8::operator!=(const UInt8& other) const {
    return Bool(Byte(this->value.raw() != other.value.raw()));
}

Bool UInt8::operator<(const UInt8& other) const {
    return Bool(Byte(this->value.raw() < other.value.raw()));
}

Bool UInt8::operator>(const UInt8& other) const {
    return Bool(Byte(this->value.raw() > other.value.raw()));
}

Bool UInt8::operator<=(const UInt8& other) const {
    return Bool(Byte(this->value.raw() <= other.value.raw()));
}

Bool UInt8::operator>=(const UInt8& other) const {
    return Bool(Byte(this->value.raw() >= other.value.raw()));
}

std::ostream& operator<<(std::ostream& os, const UInt8& value) {
    os << value.toInt();
    return os;
}
