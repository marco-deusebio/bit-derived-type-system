//
//  SharedMemory.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/****************************
 * SharedMemory<T, Capacity>  *
 ****************************/

#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <iosfwd>

#include "Array.h"
#include "Bool.h"
#include "Pointer.h"
#include "UInt64.h"

template <typename T, unsigned long long Capacity>
class SharedMemory {
private:
    Array<T, Capacity> values;
    Array<Bool, Capacity> used;
    Array<UInt64, Capacity> refCounts;
    
public:
    SharedMemory();
    
    static UInt64 makeIndex(unsigned long long value);
    
    UInt64 capacity() const;
    UInt64 usedCount() const;
    
    Bool full() const;
    Bool empty() const;
    
    Pointer<T, Capacity> allocate(const T& value);
    
    Bool acquire(const Pointer<T, Capacity>& pointer);
    Bool release(const Pointer<T, Capacity>& pointer);
    
    UInt64 useCount(const Pointer<T, Capacity>& pointer) const;
    
    Bool contains(const Pointer<T, Capacity>& pointer) const;
    
    T& get(const Pointer<T, Capacity>& pointer);
    const T& get(const Pointer<T, Capacity>& pointer) const;
    
    Bool set(const Pointer<T, Capacity>& pointer, const T& value);
};

template <typename T, unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os,
                         const SharedMemory<T, Capacity>& memory);

#include "SharedMemory.tpp"

#endif  // SHARED_MEMORY_H
