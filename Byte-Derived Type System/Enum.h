//
//  Enum.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/******************
 * Enum  (from Int32)   *
 ******************/

#ifndef ENUM_H
#define ENUM_H

#include <iosfwd>

#include "Bool.h"
#include "Int32.h"

class Enum {
private:
    Int32 value;
    Int32 min_val;
    Int32 max_val;
    
public:
    Enum();
    Enum(const Int32& initial, const Int32& min, const Int32& max);
    
    static Enum fromRange(long long initial, long long min, long long max);
    
    operator Int32() const;
    
    Int32 getValue() const;
    Int32 getMin() const;
    Int32 getMax() const;
    
    Bool isValid(const Int32& testValue) const;
    Bool setValue(const Int32& newValue);
    
    Bool sameRange(const Enum& other) const;
    
    Enum& operator++();
    Enum operator++(int);
    
    Enum& operator--();
    Enum operator--(int);
    
    Bool operator==(const Enum& other) const;
    Bool operator!=(const Enum& other) const;
    Bool operator<(const Enum& other) const;
    Bool operator>(const Enum& other) const;
    Bool operator<=(const Enum& other) const;
    Bool operator>=(const Enum& other) const;
};

std::ostream& operator<<(std::ostream& os, const Enum& value);

#endif  // ENUM_H
