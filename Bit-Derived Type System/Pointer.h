//
//  Pointer.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/**********************
 * Pointer<T, Capacity>  *
 **********************/

#ifndef POINTER_H
#define POINTER_H

#include <iosfwd>

#include "Bool.h"
#include "UInt64.h"

template <typename T, unsigned long long Capacity>
class Pointer {
private:
    UInt64 index;
    
public:
    Pointer();
    
    explicit Pointer(const UInt64& indexValue);
    
    static UInt64 makeIndex(unsigned long long value);
    static Pointer<T, Capacity> null();
    static Pointer<T, Capacity> fromIndex(const UInt64& indexValue);
    
    UInt64 getIndex() const;
    
    Bool isNull() const;
    Bool isNotNull() const;
    
    Bool operator==(const Pointer<T, Capacity>& other) const;
    Bool operator!=(const Pointer<T, Capacity>& other) const;
};

template <typename T, unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os, const Pointer<T, Capacity>& pointer);

#include "Pointer.tpp"

#endif  // POINTER_H
