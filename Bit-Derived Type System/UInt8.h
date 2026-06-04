//
//  UInt8.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/*****************
 * UInt8   (from Byte)  *
 *****************/

#ifndef UINT8_H
#define UINT8_H

#include <iosfwd>

#include "Byte.h"

class Bool;

class UInt8 {
private:
    Byte value;
    
public:
    UInt8(const Byte& byte = Byte(0));
    UInt8(unsigned int value);
    
    operator Byte() const;
    
    Byte toByte() const;
    int toInt() const;
    
    void set(const Byte& byte);
    
    UInt8& operator++();
    UInt8 operator++(int);
    
    UInt8& operator--();
    UInt8 operator--(int);
    
    UInt8 operator+(const UInt8& other) const;
    UInt8 operator-(const UInt8& other) const;
    UInt8 operator*(const UInt8& other) const;
    UInt8 operator/(const UInt8& other) const;
    UInt8 operator%(const UInt8& other) const;
    
    UInt8& operator+=(const UInt8& other);
    UInt8& operator-=(const UInt8& other);
    UInt8& operator*=(const UInt8& other);
    UInt8& operator/=(const UInt8& other);
    UInt8& operator%=(const UInt8& other);
    
    Bool operator==(const UInt8& other) const;
    Bool operator!=(const UInt8& other) const;
    Bool operator<(const UInt8& other) const;
    Bool operator>(const UInt8& other) const;
    Bool operator<=(const UInt8& other) const;
    Bool operator>=(const UInt8& other) const;
};

std::ostream& operator<<(std::ostream& os, const UInt8& value);

#endif  // UINT8_H
