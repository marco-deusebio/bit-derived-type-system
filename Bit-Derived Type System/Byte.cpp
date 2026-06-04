//
//  Byte.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/*************
 * Byte  (8 bits)  *
 *************/

#include "Byte.h"

#include <ostream>
#include <stdexcept>

Byte::Byte(std::uint8_t v) {
    this->set(v);
}

std::uint8_t Byte::raw() const {
    std::uint8_t result = 0;
    
    for (int i = 0; i < 8; ++i) {
        if (this->bits[i].raw() != 0) {
            result = static_cast<std::uint8_t>(result | (1u << i));
        }
    }
    
    return result;
}

void Byte::set(std::uint8_t v) {
    for (int i = 0; i < 8; ++i) {
        std::uint8_t bitValue = static_cast<std::uint8_t>((v >> i) & 1u);
        this->bits[i] = Bit(static_cast<std::uint8_t>(bitValue));
    }
}

Bit Byte::getBit(int index) const {
    if (index < 0 || index >= 8) {
        throw std::out_of_range("Byte bit index out of range.");
    }
    
    return this->bits[index];
}

void Byte::setBit(int index, const Bit& bit) {
    if (index < 0 || index >= 8) {
        throw std::out_of_range("Byte bit index out of range.");
    }
    
    this->bits[index] = bit;
}

Byte Byte::operator~() const {
    Byte result;
    
    for (int i = 0; i < 8; ++i) {
        result.bits[i] = ~this->bits[i];
    }
    
    return result;
}

Byte Byte::operator&(const Byte& other) const {
    Byte result;
    
    for (int i = 0; i < 8; ++i) {
        result.bits[i] = this->bits[i] & other.bits[i];
    }
    
    return result;
}

Byte Byte::operator|(const Byte& other) const {
    Byte result;
    
    for (int i = 0; i < 8; ++i) {
        result.bits[i] = this->bits[i] | other.bits[i];
    }
    
    return result;
}

Byte Byte::operator^(const Byte& other) const {
    Byte result;
    
    for (int i = 0; i < 8; ++i) {
        result.bits[i] = this->bits[i] ^ other.bits[i];
    }
    
    return result;
}

Byte Byte::operator<<(int amount) const {
    if (amount < 0) {
        throw std::invalid_argument("Cannot left-shift Byte by a negative amount.");
    }
    
    Byte result;
    
    if (amount >= 8) {
        return result;
    }
    
    for (int i = 7; i >= amount; --i) {
        result.bits[i] = this->bits[i - amount];
    }
    
    for (int i = 0; i < amount; ++i) {
        result.bits[i] = Bit(static_cast<std::uint8_t>(0));
    }
    
    return result;
}

Byte Byte::operator>>(int amount) const {
    if (amount < 0) {
        throw std::invalid_argument("Cannot right-shift Byte by a negative amount.");
    }
    
    Byte result;
    
    if (amount >= 8) {
        return result;
    }
    
    for (int i = 0; i + amount < 8; ++i) {
        result.bits[i] = this->bits[i + amount];
    }
    
    for (int i = 8 - amount; i < 8; ++i) {
        result.bits[i] = Bit(static_cast<std::uint8_t>(0));
    }
    
    return result;
}

Byte& Byte::operator&=(const Byte& other) {
    *this = *this & other;
    return *this;
}

Byte& Byte::operator|=(const Byte& other) {
    *this = *this | other;
    return *this;
}

Byte& Byte::operator^=(const Byte& other) {
    *this = *this ^ other;
    return *this;
}

Byte& Byte::operator<<=(int amount) {
    *this = *this << amount;
    return *this;
}

Byte& Byte::operator>>=(int amount) {
    *this = *this >> amount;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Byte& byte) {
    os << static_cast<int>(byte.raw());
    return os;
}
