//
//  Reference.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/************************
 * Reference<T, Capacity>  *
 ************************/

#ifndef REFERENCE_H
#define REFERENCE_H

#include <iosfwd>

#include "Bool.h"
#include "Memory.h"
#include "Pointer.h"

template <typename T, unsigned long long Capacity>
class Reference {
private:
    Pointer<T, Capacity> pointer;
    
public:
    Reference() = delete;
    
    explicit Reference(const Pointer<T, Capacity>& pointerValue);
    
    static Reference<T, Capacity> bind(const Pointer<T, Capacity>& pointerValue);
    
    Pointer<T, Capacity> getPointer() const;
    
    T& get(Memory<T, Capacity>& memory);
    const T& get(const Memory<T, Capacity>& memory) const;
    
    Bool set(Memory<T, Capacity>& memory, const T& value);
    
    Bool operator==(const Reference<T, Capacity>& other) const;
    Bool operator!=(const Reference<T, Capacity>& other) const;
};

template <typename T, unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os,
                         const Reference<T, Capacity>& reference);

#include "Reference.tpp"

#endif  // REFERENCE_H
