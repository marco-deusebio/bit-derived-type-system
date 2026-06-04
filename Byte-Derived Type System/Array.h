//
//  Array.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/*********************
 * Array<T, Capacity>   *
 *********************/

#ifndef ARRAY_H
#define ARRAY_H

#include <iosfwd>

#include "Bool.h"
#include "UInt64.h"

template <typename T, unsigned long long Capacity>
class Array {
private:
    T values[Capacity];
    
public:
    Array();
    
    T& at(const UInt64& index);
    const T& at(const UInt64& index) const;
    
    T& operator[](const UInt64& index);
    const T& operator[](const UInt64& index) const;
    
    UInt64 size() const;
    Bool empty() const;
    
    void fill(const T& value);
    
    Bool operator==(const Array<T, Capacity>& other) const;
    Bool operator!=(const Array<T, Capacity>& other) const;
};

template <typename T, unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os, const Array<T, Capacity>& array);

#include "Array.tpp"

#endif  // ARRAY_H
