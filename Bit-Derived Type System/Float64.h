//
//  Float64.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/********************
 * Float64   (from UInt64)  *
 ********************/

#ifndef FLOAT64_H
#define FLOAT64_H

#include <iosfwd>

#include "Bool.h"
#include "UInt16.h"
#include "UInt64.h"

class Float64 {
private:
    UInt64 bits;
    
public:
    Float64();
    Float64(double value);
    
    explicit Float64(const UInt64& rawBits);
    
    static Float64 fromBytes(const Byte& b0,
                             const Byte& b1,
                             const Byte& b2,
                             const Byte& b3,
                             const Byte& b4,
                             const Byte& b5,
                             const Byte& b6,
                             const Byte& b7);
    
    operator double() const;
    
    UInt64 raw() const;
    double toDouble() const;
    
    Bool signBit() const;
    UInt16 exponentBits() const;
    UInt64 fractionBits() const;
    
    Bool isZero() const;
    Bool isInfinity() const;
    Bool isNaN() const;
    
    Bool sameBits(const Float64& other) const;
    Bool isClose(const Float64& other, double tolerance = 0.000000001) const;
    
    Float64& operator++();
    Float64 operator++(int);
    
    Float64& operator--();
    Float64 operator--(int);
    
    Float64 operator+(const Float64& other) const;
    Float64 operator-(const Float64& other) const;
    Float64 operator*(const Float64& other) const;
    Float64 operator/(const Float64& other) const;
    
    Float64& operator+=(const Float64& other);
    Float64& operator-=(const Float64& other);
    Float64& operator*=(const Float64& other);
    Float64& operator/=(const Float64& other);
    
    Bool operator==(const Float64& other) const;
    Bool operator!=(const Float64& other) const;
    Bool operator<(const Float64& other) const;
    Bool operator>(const Float64& other) const;
    Bool operator<=(const Float64& other) const;
    Bool operator>=(const Float64& other) const;
};

std::ostream& operator<<(std::ostream& os, const Float64& value);

#endif  // FLOAT64_H
