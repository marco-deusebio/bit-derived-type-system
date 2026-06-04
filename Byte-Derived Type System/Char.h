//
//  Char.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/****************
 * Char  (from Byte)  *
 ****************/

#ifndef CHAR_H
#define CHAR_H

#include <iosfwd>

#include "Byte.h"

class Bool;

class Char {
private:
    Byte value;
    
public:
    Char(const Byte& byte = Byte(0));
    Char(char c);
    
    operator Byte() const;
    
    Byte toByte() const;
    int toAscii() const;
    
    void set(const Byte& byte);
    void set(char c);

    Bool isAlpha() const;
    Bool isDigit() const;
    
    Char& operator++();
    Char operator++(int);
    
    Char& operator--();
    Char operator--(int);
    
    Bool operator==(const Char& other) const;
    Bool operator!=(const Char& other) const;
    Bool operator<(const Char& other) const;
    Bool operator>(const Char& other) const;
    Bool operator<=(const Char& other) const;
    Bool operator>=(const Char& other) const;
};

std::ostream& operator<<(std::ostream& os, const Char& value);

#endif  // CHAR_H
