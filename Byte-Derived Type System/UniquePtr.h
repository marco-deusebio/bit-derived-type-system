//
//  UniquePtr.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/************************
 * UniquePtr<T, Capacity>  *
 ************************/

#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <iosfwd>

#include "Bool.h"
#include "Memory.h"
#include "Pointer.h"

template <typename T, unsigned long long Capacity>
class UniquePtr {
private:
    Pointer<T, Capacity> pointer;
    
public:
    UniquePtr();
    
    explicit UniquePtr(const Pointer<T, Capacity>& pointerValue);
    
    UniquePtr(const UniquePtr<T, Capacity>& other) = delete;
    UniquePtr<T, Capacity>& operator=(const UniquePtr<T, Capacity>& other) = delete;
    
    UniquePtr(UniquePtr<T, Capacity>&& other) noexcept;
    UniquePtr<T, Capacity>& operator=(UniquePtr<T, Capacity>&& other) noexcept;
    
    static UniquePtr<T, Capacity> make(Memory<T, Capacity>& memory,
                                       const T& value);
    
    Pointer<T, Capacity> getPointer() const;
    
    Bool isNull() const;
    Bool isNotNull() const;
    
    T& get(Memory<T, Capacity>& memory);
    const T& get(const Memory<T, Capacity>& memory) const;
    
    Bool set(Memory<T, Capacity>& memory, const T& value);
    
    Bool reset(Memory<T, Capacity>& memory);
    Bool reset(Memory<T, Capacity>& memory, const T& value);
    
    Pointer<T, Capacity> release();
    
    Bool operator==(const UniquePtr<T, Capacity>& other) const;
    Bool operator!=(const UniquePtr<T, Capacity>& other) const;
};

template <typename T, unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os,
                         const UniquePtr<T, Capacity>& uniquePtr);

#include "UniquePtr.tpp"

#endif  // UNIQUE_PTR_H
