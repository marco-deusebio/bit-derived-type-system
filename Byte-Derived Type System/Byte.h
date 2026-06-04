//
//  Byte.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/***************
 * Byte (8-bit unit)  *
 ***************/

#ifndef BYTE_H
#define BYTE_H

#include <cstdint>
#include <iosfwd>

class Byte {
private:
    std::uint8_t value;
    
public:
    Byte(std::uint8_t v = 0);
    
    std::uint8_t raw() const;
    void set(std::uint8_t v);
    
    Byte operator~() const;
    
    Byte operator&(const Byte& other) const;
    Byte operator|(const Byte& other) const;
    Byte operator^(const Byte& other) const;
    
    Byte operator<<(int amount) const;
    Byte operator>>(int amount) const;
};

std::ostream& operator<<(std::ostream& os, const Byte& byte);

#endif  // BYTE_H
