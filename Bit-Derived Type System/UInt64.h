//
//  UInt64.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/****************
 * UInt64  (8 Bytes)  *
 ****************/

#ifndef UINT64_H
#define UINT64_H

#include <iosfwd>

#include "Byte.h"

class Bool;

class UInt64 {
private:
    Byte bytes[8];
    
public:
    UInt64();
    UInt64(const Byte& b0, const Byte& b1, const Byte& b2, const Byte& b3,
           const Byte& b4, const Byte& b5, const Byte& b6, const Byte& b7);
    UInt64(unsigned long long value);
    
    Byte getByte(int index) const;
    void setByte(int index, const Byte& byte);
    
    unsigned long long toUnsignedLongLong() const;
    
    UInt64& operator++();
    UInt64 operator++(int);
    
    UInt64& operator--();
    UInt64 operator--(int);
    
    UInt64 operator+(const UInt64& other) const;
    UInt64 operator-(const UInt64& other) const;
    UInt64 operator*(const UInt64& other) const;
    UInt64 operator/(const UInt64& other) const;
    UInt64 operator%(const UInt64& other) const;
    
    UInt64& operator+=(const UInt64& other);
    UInt64& operator-=(const UInt64& other);
    UInt64& operator*=(const UInt64& other);
    UInt64& operator/=(const UInt64& other);
    UInt64& operator%=(const UInt64& other);
    
    Bool operator==(const UInt64& other) const;
    Bool operator!=(const UInt64& other) const;
    Bool operator<(const UInt64& other) const;
    Bool operator>(const UInt64& other) const;
    Bool operator<=(const UInt64& other) const;
    Bool operator>=(const UInt64& other) const;
    
    UInt64 operator~() const;
    
    UInt64 operator&(const UInt64& other) const;
    UInt64 operator|(const UInt64& other) const;
    UInt64 operator^(const UInt64& other) const;
    
    UInt64 operator<<(int amount) const;
    UInt64 operator>>(int amount) const;
    
    UInt64& operator&=(const UInt64& other);
    UInt64& operator|=(const UInt64& other);
    UInt64& operator^=(const UInt64& other);
    UInt64& operator<<=(int amount);
    UInt64& operator>>=(int amount);
};

std::ostream& operator<<(std::ostream& os, const UInt64& value);

#endif  // UINT64_H
