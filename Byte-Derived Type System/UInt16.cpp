//
//  UInt16.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/*****************
 * UInt16    (2 Bytes)  *
 *****************/

#include "UInt16.h"
#include "Bool.h"

#include <ostream>
#include <stdexcept>

UInt16::UInt16() {
    this->bytes[0] = Byte(0);
    this->bytes[1] = Byte(0);
}

UInt16::UInt16(const Byte& lowByte, const Byte& highByte) {
    this->bytes[0] = lowByte;
    this->bytes[1] = highByte;
}

UInt16::UInt16(unsigned int value) {
    this->bytes[0] = Byte(static_cast<std::uint8_t>(value & 0xFF));
    this->bytes[1] = Byte(static_cast<std::uint8_t>((value >> 8) & 0xFF));
}

Byte UInt16::getByte(int index) const {
    if (index < 0 || index > 1) {
        throw std::out_of_range("UInt16 byte index out of range.");
    }
    
    return this->bytes[index];
}

void UInt16::setByte(int index, const Byte& byte) {
    if (index < 0 || index > 1) {
        throw std::out_of_range("UInt16 byte index out of range.");
    }
    
    this->bytes[index] = byte;
}

unsigned int UInt16::toUnsignedInt() const {
    return static_cast<unsigned int>(this->bytes[0].raw()) |
    (static_cast<unsigned int>(this->bytes[1].raw()) << 8);
}

UInt16& UInt16::operator++() {
    for (int i = 0; i < 2; ++i) {
        std::uint8_t before = this->bytes[i].raw();
        this->bytes[i].set(static_cast<std::uint8_t>(before + 1));
        
        if (this->bytes[i].raw() != 0) {
            break;
        }
    }
    
    return *this;
}

UInt16 UInt16::operator++(int) {
    UInt16 oldValue = *this;
    ++(*this);
    return oldValue;
}

UInt16& UInt16::operator--() {
    for (int i = 0; i < 2; ++i) {
        std::uint8_t before = this->bytes[i].raw();
        this->bytes[i].set(static_cast<std::uint8_t>(before - 1));
        
        if (before != 0) {
            break;
        }
    }
    
    return *this;
}

UInt16 UInt16::operator--(int) {
    UInt16 oldValue = *this;
    --(*this);
    return oldValue;
}

UInt16 UInt16::operator+(const UInt16& other) const {
    UInt16 result;
    Byte carry(0);
    
    for (int i = 0; i < 2; ++i) {
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

UInt16 UInt16::operator-(const UInt16& other) const {
    UInt16 result;
    Byte borrow(0);
    
    for (int i = 0; i < 2; ++i) {
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

Bool UInt16::operator==(const UInt16& other) const {
    for (int i = 0; i < 2; ++i) {
        if (this->bytes[i].raw() != other.bytes[i].raw()) {
            return Bool(Byte(0));
        }
    }
    
    return Bool(Byte(1));
}

Bool UInt16::operator!=(const UInt16& other) const {
    return !(*this == other);
}

Bool UInt16::operator<(const UInt16& other) const {
    for (int i = 1; i >= 0; --i) {
        if (this->bytes[i].raw() < other.bytes[i].raw()) {
            return Bool(Byte(1));
        }
        
        if (this->bytes[i].raw() > other.bytes[i].raw()) {
            return Bool(Byte(0));
        }
    }
    
    return Bool(Byte(0));
}

Bool UInt16::operator>(const UInt16& other) const {
    return other < *this;
}

Bool UInt16::operator<=(const UInt16& other) const {
    return !(*this > other);
}

Bool UInt16::operator>=(const UInt16& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const UInt16& value) {
    os << value.toUnsignedInt();
    return os;
}
