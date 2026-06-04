//
//  NullPtr.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/***************
 * NullPtr  (nullptr)  *
 ***************/

#ifndef NULL_PTR_H
#define NULL_PTR_H

#include <iosfwd>

#include "Bool.h"
#include "Pointer.h"

class NullPtr {
private:
    Bool marker;
    
public:
    NullPtr();
    
    Bool isNull() const;
    
    Bool operator==(const NullPtr& other) const;
    Bool operator!=(const NullPtr& other) const;
};

template <typename T, unsigned long long Capacity>
Bool operator==(const Pointer<T, Capacity>& pointer, const NullPtr& nullPtr);

template <typename T, unsigned long long Capacity>
Bool operator==(const NullPtr& nullPtr, const Pointer<T, Capacity>& pointer);

template <typename T, unsigned long long Capacity>
Bool operator!=(const Pointer<T, Capacity>& pointer, const NullPtr& nullPtr);

template <typename T, unsigned long long Capacity>
Bool operator!=(const NullPtr& nullPtr, const Pointer<T, Capacity>& pointer);

std::ostream& operator<<(std::ostream& os, const NullPtr& value);

#include "NullPtr.tpp"

#endif  // NULL_PTR_H
