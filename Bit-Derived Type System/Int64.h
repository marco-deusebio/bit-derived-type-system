//
//  Int64.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/******************
 * Int64  (from UInt64)  *
 ******************/

#ifndef INT64_H
#define INT64_H

#include <iosfwd>

#include "UInt64.h"

class Bool;

class Int64 {
private:
    UInt64 bits;
    
public:
    Int64(const UInt64& rawBits = UInt64());
    Int64(long long value);
    
    static Int64 fromSignedValue(long long value);
    
    UInt64 raw() const;
    long long toLongLong() const;
    
    Bool isNegative() const;
    
    Int64& operator++();
    Int64 operator++(int);
    
    Int64& operator--();
    Int64 operator--(int);
    
    Int64 operator+(const Int64& other) const;
    Int64 operator-(const Int64& other) const;
    Int64 operator*(const Int64& other) const;
    Int64 operator/(const Int64& other) const;
    Int64 operator%(const Int64& other) const;
    
    Int64& operator+=(const Int64& other);
    Int64& operator-=(const Int64& other);
    Int64& operator*=(const Int64& other);
    Int64& operator/=(const Int64& other);
    Int64& operator%=(const Int64& other);
    
    Bool operator==(const Int64& other) const;
    Bool operator!=(const Int64& other) const;
    Bool operator<(const Int64& other) const;
    Bool operator>(const Int64& other) const;
    Bool operator<=(const Int64& other) const;
    Bool operator>=(const Int64& other) const;
    
    Int64 operator~() const;
    
    Int64 operator&(const Int64& other) const;
    Int64 operator|(const Int64& other) const;
    Int64 operator^(const Int64& other) const;
    
    Int64 operator<<(int amount) const;
    Int64 operator>>(int amount) const;
    
    Int64& operator&=(const Int64& other);
    Int64& operator|=(const Int64& other);
    Int64& operator^=(const Int64& other);
    Int64& operator<<=(int amount);
    Int64& operator>>=(int amount);
};

std::ostream& operator<<(std::ostream& os, const Int64& value);

#endif  // INT64_H
