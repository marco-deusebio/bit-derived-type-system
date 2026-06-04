//
//  Memory.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/************************
 *  Memory<T, Capacity>   *
 ************************/

#ifndef MEMORY_H
#define MEMORY_H

#include <iosfwd>

#include "Array.h"
#include "Bool.h"
#include "Pointer.h"
#include "UInt64.h"

template <typename T, unsigned long long Capacity>
class Memory {
private:
    Array<T, Capacity> values;
    Array<Bool, Capacity> used;
    
public:
    Memory();
    
    static UInt64 makeIndex(unsigned long long value);
    
    UInt64 capacity() const;
    UInt64 usedCount() const;
    
    Bool full() const;
    Bool empty() const;
    
    Pointer<T, Capacity> allocate(const T& value);
    Bool deallocate(const Pointer<T, Capacity>& pointer);
    
    Bool contains(const Pointer<T, Capacity>& pointer) const;
    
    T& get(const Pointer<T, Capacity>& pointer);
    const T& get(const Pointer<T, Capacity>& pointer) const;
    
    Bool set(const Pointer<T, Capacity>& pointer, const T& value);
};

template <typename T, unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os, const Memory<T, Capacity>& memory);

#include "Memory.tpp"

#endif  // MEMORY_H
