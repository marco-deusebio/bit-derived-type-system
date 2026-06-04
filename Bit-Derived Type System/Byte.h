//
//  Byte.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/*************
 * Byte  (8 bits)  *
 *************/

#ifndef BYTE_H
#define BYTE_H

#include <cstdint>
#include <iosfwd>

#include "Bit.h"

class Byte {
private:
    Bit bits[8];
    
public:
    Byte(std::uint8_t v = 0);
    
    std::uint8_t raw() const;
    void set(std::uint8_t v);
    
    Bit getBit(int index) const;
    void setBit(int index, const Bit& bit);
    
    Byte operator~() const;
    
    Byte operator&(const Byte& other) const;
    Byte operator|(const Byte& other) const;
    Byte operator^(const Byte& other) const;
    
    Byte operator<<(int amount) const;
    Byte operator>>(int amount) const;
    
    Byte& operator&=(const Byte& other);
    Byte& operator|=(const Byte& other);
    Byte& operator^=(const Byte& other);
    Byte& operator<<=(int amount);
    Byte& operator>>=(int amount);
};

std::ostream& operator<<(std::ostream& os, const Byte& byte);

#endif  // BYTE_H
