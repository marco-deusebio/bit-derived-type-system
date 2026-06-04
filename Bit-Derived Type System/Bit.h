//
//  Bit.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/******
 * Bit   *
 ******/

#ifndef BIT_H
#define BIT_H

#include <cstdint>
#include <iosfwd>

class Bool;

class Bit {
private:
    std::uint8_t value;
    
public:
    Bit(std::uint8_t v = 0);
    Bit(bool v);
    Bit(int v);
    Bit(const Bool& v);
    
    std::uint8_t raw() const;
    
    void set(std::uint8_t v);
    void set(bool v);
    
    Bit operator!() const;
    Bit operator~() const;
    
    Bit operator&(const Bit& other) const;
    Bit operator|(const Bit& other) const;
    Bit operator^(const Bit& other) const;
    
    Bit& operator&=(const Bit& other);
    Bit& operator|=(const Bit& other);
    Bit& operator^=(const Bit& other);
    
    bool operator==(const Bit& other) const;
    bool operator!=(const Bit& other) const;
};

std::ostream& operator<<(std::ostream& os, const Bit& bit);

#endif  // BIT_H

