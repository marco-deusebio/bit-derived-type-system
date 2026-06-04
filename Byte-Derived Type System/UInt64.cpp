//
//  UInt64.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/****************
 * UInt64  (8 Bytes)  *
 ****************/

#include "UInt64.h"
#include "Bool.h"

#include <ostream>
#include <stdexcept>

UInt64::UInt64() {
    for (int i = 0; i < 8; ++i) {
        this->bytes[i] = Byte(0);
    }
}

UInt64::UInt64(const Byte& b0, const Byte& b1, const Byte& b2, const Byte& b3,
               const Byte& b4, const Byte& b5, const Byte& b6, const Byte& b7) {
    this->bytes[0] = b0;
    this->bytes[1] = b1;
    this->bytes[2] = b2;
    this->bytes[3] = b3;
    this->bytes[4] = b4;
    this->bytes[5] = b5;
    this->bytes[6] = b6;
    this->bytes[7] = b7;
}

UInt64::UInt64(unsigned long long value) {
    this->bytes[0] = Byte(static_cast<std::uint8_t>(value & 0xFF));
    this->bytes[1] = Byte(static_cast<std::uint8_t>((value >> 8) & 0xFF));
    this->bytes[2] = Byte(static_cast<std::uint8_t>((value >> 16) & 0xFF));
    this->bytes[3] = Byte(static_cast<std::uint8_t>((value >> 24) & 0xFF));
    this->bytes[4] = Byte(static_cast<std::uint8_t>((value >> 32) & 0xFF));
    this->bytes[5] = Byte(static_cast<std::uint8_t>((value >> 40) & 0xFF));
    this->bytes[6] = Byte(static_cast<std::uint8_t>((value >> 48) & 0xFF));
    this->bytes[7] = Byte(static_cast<std::uint8_t>((value >> 56) & 0xFF));
}

Byte UInt64::getByte(int index) const {
    if (index < 0 || index > 7) {
        throw std::out_of_range("UInt64 byte index out of range.");
    }
    
    return this->bytes[index];
}

void UInt64::setByte(int index, const Byte& byte) {
    if (index < 0 || index > 7) {
        throw std::out_of_range("UInt64 byte index out of range.");
    }
    
    this->bytes[index] = byte;
}

unsigned long long UInt64::toUnsignedLongLong() const {
    return static_cast<unsigned long long>(this->bytes[0].raw()) |
    (static_cast<unsigned long long>(this->bytes[1].raw()) << 8) |
    (static_cast<unsigned long long>(this->bytes[2].raw()) << 16) |
    (static_cast<unsigned long long>(this->bytes[3].raw()) << 24) |
    (static_cast<unsigned long long>(this->bytes[4].raw()) << 32) |
    (static_cast<unsigned long long>(this->bytes[5].raw()) << 40) |
    (static_cast<unsigned long long>(this->bytes[6].raw()) << 48) |
    (static_cast<unsigned long long>(this->bytes[7].raw()) << 56);
}

UInt64& UInt64::operator++() {
    for (int i = 0; i < 8; ++i) {
        std::uint8_t before = this->bytes[i].raw();
        this->bytes[i].set(static_cast<std::uint8_t>(before + 1));
        
        if (this->bytes[i].raw() != 0) {
            break;
        }
    }
    
    return *this;
}

UInt64 UInt64::operator++(int) {
    UInt64 oldValue = *this;
    ++(*this);
    return oldValue;
}

UInt64& UInt64::operator--() {
    for (int i = 0; i < 8; ++i) {
        std::uint8_t before = this->bytes[i].raw();
        this->bytes[i].set(static_cast<std::uint8_t>(before - 1));
        
        if (before != 0) {
            break;
        }
    }
    
    return *this;
}

UInt64 UInt64::operator--(int) {
    UInt64 oldValue = *this;
    --(*this);
    return oldValue;
}

UInt64 UInt64::operator+(const UInt64& other) const {
    UInt64 result;
    Byte carry(0);
    
    for (int i = 0; i < 8; ++i) {
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

UInt64 UInt64::operator-(const UInt64& other) const {
    UInt64 result;
    Byte borrow(0);
    
    for (int i = 0; i < 8; ++i) {
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

UInt64 UInt64::operator*(const UInt64& other) const {
    unsigned long long result =
    this->toUnsignedLongLong() * other.toUnsignedLongLong();
    
    return UInt64(result);
}

UInt64 UInt64::operator/(const UInt64& other) const {
    if (other.toUnsignedLongLong() == 0) {
        throw std::invalid_argument("Cannot divide UInt64 by zero.");
    }
    
    unsigned long long result =
    this->toUnsignedLongLong() / other.toUnsignedLongLong();
    
    return UInt64(result);
}

UInt64 UInt64::operator%(const UInt64& other) const {
    if (other.toUnsignedLongLong() == 0) {
        throw std::invalid_argument("Cannot modulo UInt64 by zero.");
    }
    
    unsigned long long result =
    this->toUnsignedLongLong() % other.toUnsignedLongLong();
    
    return UInt64(result);
}

UInt64& UInt64::operator+=(const UInt64& other) {
    *this = *this + other;
    return *this;
}

UInt64& UInt64::operator-=(const UInt64& other) {
    *this = *this - other;
    return *this;
}

UInt64& UInt64::operator*=(const UInt64& other) {
    *this = *this * other;
    return *this;
}

UInt64& UInt64::operator/=(const UInt64& other) {
    *this = *this / other;
    return *this;
}

UInt64& UInt64::operator%=(const UInt64& other) {
    *this = *this % other;
    return *this;
}

Bool UInt64::operator==(const UInt64& other) const {
    for (int i = 0; i < 8; ++i) {
        if (this->bytes[i].raw() != other.bytes[i].raw()) {
            return Bool(Byte(0));
        }
    }
    
    return Bool(Byte(1));
}

Bool UInt64::operator!=(const UInt64& other) const {
    return !(*this == other);
}

Bool UInt64::operator<(const UInt64& other) const {
    for (int i = 7; i >= 0; --i) {
        if (this->bytes[i].raw() < other.bytes[i].raw()) {
            return Bool(Byte(1));
        }
        
        if (this->bytes[i].raw() > other.bytes[i].raw()) {
            return Bool(Byte(0));
        }
    }
    
    return Bool(Byte(0));
}

Bool UInt64::operator>(const UInt64& other) const {
    return other < *this;
}

Bool UInt64::operator<=(const UInt64& other) const {
    return !(*this > other);
}

Bool UInt64::operator>=(const UInt64& other) const {
    return !(*this < other);
}

UInt64 UInt64::operator~() const {
    UInt64 result;
    
    for (int i = 0; i < 8; ++i) {
        result.bytes[i] = ~this->bytes[i];
    }
    
    return result;
}

UInt64 UInt64::operator&(const UInt64& other) const {
    UInt64 result;
    
    for (int i = 0; i < 8; ++i) {
        result.bytes[i] = this->bytes[i] & other.bytes[i];
    }
    
    return result;
}

UInt64 UInt64::operator|(const UInt64& other) const {
    UInt64 result;
    
    for (int i = 0; i < 8; ++i) {
        result.bytes[i] = this->bytes[i] | other.bytes[i];
    }
    
    return result;
}

UInt64 UInt64::operator^(const UInt64& other) const {
    UInt64 result;
    
    for (int i = 0; i < 8; ++i) {
        result.bytes[i] = this->bytes[i] ^ other.bytes[i];
    }
    
    return result;
}

UInt64 UInt64::operator<<(int amount) const {
    if (amount < 0) {
        throw std::invalid_argument("Cannot left-shift UInt64 by a negative amount.");
    }
    
    if (amount >= 64) {
        return UInt64();
    }
    
    return UInt64(this->toUnsignedLongLong() << amount);
}

UInt64 UInt64::operator>>(int amount) const {
    if (amount < 0) {
        throw std::invalid_argument("Cannot right-shift UInt64 by a negative amount.");
    }
    
    if (amount >= 64) {
        return UInt64();
    }
    
    return UInt64(this->toUnsignedLongLong() >> amount);
}

UInt64& UInt64::operator&=(const UInt64& other) {
    *this = *this & other;
    return *this;
}

UInt64& UInt64::operator|=(const UInt64& other) {
    *this = *this | other;
    return *this;
}

UInt64& UInt64::operator^=(const UInt64& other) {
    *this = *this ^ other;
    return *this;
}

UInt64& UInt64::operator<<=(int amount) {
    *this = *this << amount;
    return *this;
}

UInt64& UInt64::operator>>=(int amount) {
    *this = *this >> amount;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const UInt64& value) {
    os << value.toUnsignedLongLong();
    return os;
}
