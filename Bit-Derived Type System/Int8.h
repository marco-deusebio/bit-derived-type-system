//
//  Int8.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/****************
 * Int8  (from UInt8)  *
 ****************/

#ifndef INT8_H
#define INT8_H

#include <iosfwd>

#include "UInt8.h"

class Bool;

class Int8 {
private:
    UInt8 bits;
    
public:
    Int8(const UInt8& rawBits = UInt8(Byte(0)));
    Int8(int value);
    
    static Int8 fromSignedValue(int value);
    
    operator UInt8() const;
    
    UInt8 raw() const;
    int toInt() const;
    
    Bool isNegative() const;
    
    Int8& operator++();
    Int8 operator++(int);
    
    Int8& operator--();
    Int8 operator--(int);
    
    Int8 operator+(const Int8& other) const;
    Int8 operator-(const Int8& other) const;
    Int8 operator*(const Int8& other) const;
    Int8 operator/(const Int8& other) const;
    Int8 operator%(const Int8& other) const;
    
    Bool operator==(const Int8& other) const;
    Bool operator!=(const Int8& other) const;
    Bool operator<(const Int8& other) const;
    Bool operator>(const Int8& other) const;
    Bool operator<=(const Int8& other) const;
    Bool operator>=(const Int8& other) const;
};

std::ostream& operator<<(std::ostream& os, const Int8& value);

#endif  // INT8_H
