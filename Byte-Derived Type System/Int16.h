//
//  Int16.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/******************
 * Int16  (from UInt16)  *
 ******************/

#ifndef INT16_H
#define INT16_H

#include <iosfwd>

#include "UInt16.h"

class Bool;

class Int16 {
private:
    UInt16 bits;
    
public:
    Int16(const UInt16& rawBits = UInt16());
    Int16(int value);
    
    static Int16 fromSignedValue(int value);
    
    UInt16 raw() const;
    int toInt() const;
    
    Bool isNegative() const;
    
    Int16& operator++();
    Int16 operator++(int);
    
    Int16& operator--();
    Int16 operator--(int);
    
    Int16 operator+(const Int16& other) const;
    Int16 operator-(const Int16& other) const;
    
    Bool operator==(const Int16& other) const;
    Bool operator!=(const Int16& other) const;
    Bool operator<(const Int16& other) const;
    Bool operator>(const Int16& other) const;
    Bool operator<=(const Int16& other) const;
    Bool operator>=(const Int16& other) const;
};

std::ostream& operator<<(std::ostream& os, const Int16& value);

#endif  // INT16_H
