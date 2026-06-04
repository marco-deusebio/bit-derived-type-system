//
//  UInt32.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/****************
 * UInt32  (4 Bytes)  *
 ****************/

#ifndef UINT32_H
#define UINT32_H

#include <iosfwd>

#include "Byte.h"

class Bool;

class UInt32 {
private:
    Byte bytes[4];
    
public:
    UInt32();
    UInt32(const Byte& b0, const Byte& b1, const Byte& b2, const Byte& b3);
    UInt32(unsigned long long value);
    
    Byte getByte(int index) const;
    void setByte(int index, const Byte& byte);
    
    unsigned long long toUnsignedLongLong() const;
    
    UInt32& operator++();
    UInt32 operator++(int);
    
    UInt32& operator--();
    UInt32 operator--(int);
    
    UInt32 operator+(const UInt32& other) const;
    UInt32 operator-(const UInt32& other) const;
    UInt32 operator*(const UInt32& other) const;
    UInt32 operator/(const UInt32& other) const;
    UInt32 operator%(const UInt32& other) const;
    
    UInt32& operator+=(const UInt32& other);
    UInt32& operator-=(const UInt32& other);
    UInt32& operator*=(const UInt32& other);
    UInt32& operator/=(const UInt32& other);
    UInt32& operator%=(const UInt32& other);
    
    Bool operator==(const UInt32& other) const;
    Bool operator!=(const UInt32& other) const;
    Bool operator<(const UInt32& other) const;
    Bool operator>(const UInt32& other) const;
    Bool operator<=(const UInt32& other) const;
    Bool operator>=(const UInt32& other) const;
    
    UInt32 operator~() const;
    
    UInt32 operator&(const UInt32& other) const;
    UInt32 operator|(const UInt32& other) const;
    UInt32 operator^(const UInt32& other) const;
    
    UInt32 operator<<(int amount) const;
    UInt32 operator>>(int amount) const;
    
    UInt32& operator&=(const UInt32& other);
    UInt32& operator|=(const UInt32& other);
    UInt32& operator^=(const UInt32& other);
    UInt32& operator<<=(int amount);
    UInt32& operator>>=(int amount);
};

std::ostream& operator<<(std::ostream& os, const UInt32& value);

#endif  // UINT32_H
