//
//  Int32.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/******************
 * Int32  (from UInt32)  *
 ******************/

#ifndef INT32_H
#define INT32_H

#include <iosfwd>

#include "UInt32.h"

class Bool;

class Int32 {
private:
    UInt32 bits;
    
public:
    Int32(const UInt32& rawBits = UInt32());
    Int32(long long value);
    
    static Int32 fromSignedValue(long long value);
    
    UInt32 raw() const;
    long long toLongLong() const;
    
    Bool isNegative() const;
    
    Int32& operator++();
    Int32 operator++(int);
    
    Int32& operator--();
    Int32 operator--(int);
    
    Int32 operator+(const Int32& other) const;
    Int32 operator-(const Int32& other) const;
    Int32 operator*(const Int32& other) const;
    Int32 operator/(const Int32& other) const;
    Int32 operator%(const Int32& other) const;
    
    Int32& operator+=(const Int32& other);
    Int32& operator-=(const Int32& other);
    Int32& operator*=(const Int32& other);
    Int32& operator/=(const Int32& other);
    Int32& operator%=(const Int32& other);
    
    Bool operator==(const Int32& other) const;
    Bool operator!=(const Int32& other) const;
    Bool operator<(const Int32& other) const;
    Bool operator>(const Int32& other) const;
    Bool operator<=(const Int32& other) const;
    Bool operator>=(const Int32& other) const;
    
    Int32 operator~() const;
    
    Int32 operator&(const Int32& other) const;
    Int32 operator|(const Int32& other) const;
    Int32 operator^(const Int32& other) const;
    
    Int32 operator<<(int amount) const;
    Int32 operator>>(int amount) const;
    
    Int32& operator&=(const Int32& other);
    Int32& operator|=(const Int32& other);
    Int32& operator^=(const Int32& other);
    Int32& operator<<=(int amount);
    Int32& operator>>=(int amount);
};

std::ostream& operator<<(std::ostream& os, const Int32& value);

#endif  // INT32_H
