//
//  UInt32.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/****************
 * UInt32  (4 Bytes)  *
 ****************/

#include "UInt32.h"
#include "Bool.h"

#include <ostream>
#include <stdexcept>

UInt32::UInt32() {
    this->bytes[0] = Byte(0);
    this->bytes[1] = Byte(0);
    this->bytes[2] = Byte(0);
    this->bytes[3] = Byte(0);
}

UInt32::UInt32(const Byte& b0, const Byte& b1, const Byte& b2, const Byte& b3) {
    this->bytes[0] = b0;
    this->bytes[1] = b1;
    this->bytes[2] = b2;
    this->bytes[3] = b3;
}

UInt32::UInt32(unsigned long long value) {
    this->bytes[0] = Byte(static_cast<std::uint8_t>(value & 0xFF));
    this->bytes[1] = Byte(static_cast<std::uint8_t>((value >> 8) & 0xFF));
    this->bytes[2] = Byte(static_cast<std::uint8_t>((value >> 16) & 0xFF));
    this->bytes[3] = Byte(static_cast<std::uint8_t>((value >> 24) & 0xFF));
}

Byte UInt32::getByte(int index) const {
    if (index < 0 || index > 3) {
        throw std::out_of_range("UInt32 byte index out of range.");
    }
    
    return this->bytes[index];
}

void UInt32::setByte(int index, const Byte& byte) {
    if (index < 0 || index > 3) {
        throw std::out_of_range("UInt32 byte index out of range.");
    }
    
    this->bytes[index] = byte;
}

unsigned long long UInt32::toUnsignedLongLong() const {
    return static_cast<unsigned long long>(this->bytes[0].raw()) |
    (static_cast<unsigned long long>(this->bytes[1].raw()) << 8) |
    (static_cast<unsigned long long>(this->bytes[2].raw()) << 16) |
    (static_cast<unsigned long long>(this->bytes[3].raw()) << 24);
}

UInt32& UInt32::operator++() {
    for (int i = 0; i < 4; ++i) {
        std::uint8_t before = this->bytes[i].raw();
        this->bytes[i].set(static_cast<std::uint8_t>(before + 1));
        
        if (this->bytes[i].raw() != 0) {
            break;
        }
    }
    
    return *this;
}

UInt32 UInt32::operator++(int) {
    UInt32 oldValue = *this;
    ++(*this);
    return oldValue;
}

UInt32& UInt32::operator--() {
    for (int i = 0; i < 4; ++i) {
        std::uint8_t before = this->bytes[i].raw();
        this->bytes[i].set(static_cast<std::uint8_t>(before - 1));
        
        if (before != 0) {
            break;
        }
    }
    
    return *this;
}

UInt32 UInt32::operator--(int) {
    UInt32 oldValue = *this;
    --(*this);
    return oldValue;
}

UInt32 UInt32::operator+(const UInt32& other) const {
    UInt32 result;
    Byte carry(0);
    
    for (int i = 0; i < 4; ++i) {
        std::uint8_t a = this->bytes[i].raw();
        std::uint8_t b = other.bytes[i].raw();
        std::uint8_t c = carry.raw();
        
        std::uint8_t partial = static_cast<std::uint8_t>(a + b);
        std::uint8_t carry1 = partial < a ? 1 : 0;
        
        std::uint8_t finalValue = static_cast<std::uint8_t>(partial + c);
        std::uint8_t carry2 = finalValue < partial ? 1 : 0;
        
        result.bytes[i] = Byte(finalValue);
        
        if (carry1 != 0 || carry2 != 0) {
            carry = Byte(1);
        } else {
            carry = Byte(0);
        }
    }
    
    return result;
}

UInt32 UInt32::operator-(const UInt32& other) const {
    UInt32 result;
    Byte borrow(0);
    
    for (int i = 0; i < 4; ++i) {
        std::uint8_t a = this->bytes[i].raw();
        std::uint8_t b = other.bytes[i].raw();
        std::uint8_t br = borrow.raw();
        
        std::uint8_t subtrahend = static_cast<std::uint8_t>(b + br);
        
        std::uint8_t borrow1 = subtrahend < b ? 1 : 0;
        std::uint8_t borrow2 = a < subtrahend ? 1 : 0;
        
        result.bytes[i] = Byte(static_cast<std::uint8_t>(a - subtrahend));
        
        if (borrow1 != 0 || borrow2 != 0) {
            borrow = Byte(1);
        } else {
            borrow = Byte(0);
        }
    }
    
    return result;
}

UInt32 UInt32::operator*(const UInt32& other) const {
    unsigned long long result =
    this->toUnsignedLongLong() * other.toUnsignedLongLong();
    
    return UInt32(result);
}

UInt32 UInt32::operator/(const UInt32& other) const {
    if (other.toUnsignedLongLong() == 0) {
        throw std::invalid_argument("Cannot divide UInt32 by zero.");
    }
    
    unsigned long long result =
    this->toUnsignedLongLong() / other.toUnsignedLongLong();
    
    return UInt32(result);
}

UInt32 UInt32::operator%(const UInt32& other) const {
    if (other.toUnsignedLongLong() == 0) {
        throw std::invalid_argument("Cannot modulo UInt32 by zero.");
    }
    
    unsigned long long result =
    this->toUnsignedLongLong() % other.toUnsignedLongLong();
    
    return UInt32(result);
}

UInt32& UInt32::operator+=(const UInt32& other) {
    *this = *this + other;
    return *this;
}

UInt32& UInt32::operator-=(const UInt32& other) {
    *this = *this - other;
    return *this;
}

UInt32& UInt32::operator*=(const UInt32& other) {
    *this = *this * other;
    return *this;
}

UInt32& UInt32::operator/=(const UInt32& other) {
    *this = *this / other;
    return *this;
}

UInt32& UInt32::operator%=(const UInt32& other) {
    *this = *this % other;
    return *this;
}

Bool UInt32::operator==(const UInt32& other) const {
    for (int i = 0; i < 4; ++i) {
        if (this->bytes[i].raw() != other.bytes[i].raw()) {
            return Bool(Byte(0));
        }
    }
    
    return Bool(Byte(1));
}

Bool UInt32::operator!=(const UInt32& other) const {
    return !(*this == other);
}

Bool UInt32::operator<(const UInt32& other) const {
    for (int i = 3; i >= 0; --i) {
        if (this->bytes[i].raw() < other.bytes[i].raw()) {
            return Bool(Byte(1));
        }
        
        if (this->bytes[i].raw() > other.bytes[i].raw()) {
            return Bool(Byte(0));
        }
    }
    
    return Bool(Byte(0));
}

Bool UInt32::operator>(const UInt32& other) const {
    return other < *this;
}

Bool UInt32::operator<=(const UInt32& other) const {
    return !(*this > other);
}

Bool UInt32::operator>=(const UInt32& other) const {
    return !(*this < other);
}

UInt32 UInt32::operator~() const {
    UInt32 result;
    
    for (int i = 0; i < 4; ++i) {
        result.bytes[i] = ~this->bytes[i];
    }
    
    return result;
}

UInt32 UInt32::operator&(const UInt32& other) const {
    UInt32 result;
    
    for (int i = 0; i < 4; ++i) {
        result.bytes[i] = this->bytes[i] & other.bytes[i];
    }
    
    return result;
}

UInt32 UInt32::operator|(const UInt32& other) const {
    UInt32 result;
    
    for (int i = 0; i < 4; ++i) {
        result.bytes[i] = this->bytes[i] | other.bytes[i];
    }
    
    return result;
}

UInt32 UInt32::operator^(const UInt32& other) const {
    UInt32 result;
    
    for (int i = 0; i < 4; ++i) {
        result.bytes[i] = this->bytes[i] ^ other.bytes[i];
    }
    
    return result;
}

UInt32 UInt32::operator<<(int amount) const {
    if (amount < 0) {
        throw std::invalid_argument("Cannot left-shift UInt32 by a negative amount.");
    }
    
    if (amount >= 32) {
        return UInt32();
    }
    
    return UInt32(this->toUnsignedLongLong() << amount);
}

UInt32 UInt32::operator>>(int amount) const {
    if (amount < 0) {
        throw std::invalid_argument("Cannot right-shift UInt32 by a negative amount.");
    }
    
    if (amount >= 32) {
        return UInt32();
    }
    
    return UInt32(this->toUnsignedLongLong() >> amount);
}

UInt32& UInt32::operator&=(const UInt32& other) {
    *this = *this & other;
    return *this;
}

UInt32& UInt32::operator|=(const UInt32& other) {
    *this = *this | other;
    return *this;
}

UInt32& UInt32::operator^=(const UInt32& other) {
    *this = *this ^ other;
    return *this;
}

UInt32& UInt32::operator<<=(int amount) {
    *this = *this << amount;
    return *this;
}

UInt32& UInt32::operator>>=(int amount) {
    *this = *this >> amount;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const UInt32& value) {
    os << value.toUnsignedLongLong();
    return os;
}
