//
//  UInt16.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/*****************
 * UInt16    (2 Bytes)  *
 *****************/

#ifndef UINT16_H
#define UINT16_H

#include <iosfwd>

#include "Byte.h"

class Bool;

class UInt16 {
private:
    Byte bytes[2];
    
public:
    UInt16();
    UInt16(const Byte& lowByte, const Byte& highByte);
    UInt16(unsigned int value);
    
    Byte getByte(int index) const;
    void setByte(int index, const Byte& byte);
    
    unsigned int toUnsignedInt() const;
    
    UInt16& operator++();
    UInt16 operator++(int);
    
    UInt16& operator--();
    UInt16 operator--(int);
    
    UInt16 operator+(const UInt16& other) const;
    UInt16 operator-(const UInt16& other) const;
    
    Bool operator==(const UInt16& other) const;
    Bool operator!=(const UInt16& other) const;
    Bool operator<(const UInt16& other) const;
    Bool operator>(const UInt16& other) const;
    Bool operator<=(const UInt16& other) const;
    Bool operator>=(const UInt16& other) const;
};

std::ostream& operator<<(std::ostream& os, const UInt16& value);

#endif  // UINT16_H
