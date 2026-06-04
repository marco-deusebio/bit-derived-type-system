//
//  Float32.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/********************
 * Float32   (from UInt32)  *
 ********************/

#ifndef FLOAT32_H
#define FLOAT32_H

#include <iosfwd>

#include "Bool.h"
#include "UInt8.h"
#include "UInt32.h"

class Float32 {
private:
    UInt32 bits;
    
public:
    Float32();
    Float32(float value);
    
    explicit Float32(const UInt32& rawBits);
    
    static Float32 fromBytes(const Byte& b0,
                             const Byte& b1,
                             const Byte& b2,
                             const Byte& b3);
    
    operator float() const;
    
    UInt32 raw() const;
    float toFloat() const;
    
    Bool signBit() const;
    UInt8 exponentBits() const;
    UInt32 fractionBits() const;
    
    Bool isZero() const;
    Bool isInfinity() const;
    Bool isNaN() const;
    
    Bool isClose(const Float32& other, float tolerance = 0.000001f) const;
    
    Float32& operator++();
    Float32 operator++(int);
    
    Float32& operator--();
    Float32 operator--(int);
    
    Float32 operator+(const Float32& other) const;
    Float32 operator-(const Float32& other) const;
    Float32 operator*(const Float32& other) const;
    Float32 operator/(const Float32& other) const;
    
    Float32& operator+=(const Float32& other);
    Float32& operator-=(const Float32& other);
    Float32& operator*=(const Float32& other);
    Float32& operator/=(const Float32& other);
    
    Bool operator==(const Float32& other) const;
    Bool operator!=(const Float32& other) const;
    Bool operator<(const Float32& other) const;
    Bool operator>(const Float32& other) const;
    Bool operator<=(const Float32& other) const;
    Bool operator>=(const Float32& other) const;
};

std::ostream& operator<<(std::ostream& os, const Float32& value);

#endif  // FLOAT32_H
