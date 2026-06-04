//
//  SharedPtr.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/************************
 * SharedPtr<T, Capacity>  *
 ************************/

#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <iosfwd>

#include "Bool.h"
#include "Pointer.h"
#include "SharedMemory.h"

template <typename T, unsigned long long Capacity>
class SharedPtr {
private:
    Pointer<T, Capacity> pointer;
    
public:
    SharedPtr();
    
    explicit SharedPtr(const Pointer<T, Capacity>& pointerValue);
    
    SharedPtr(const SharedPtr<T, Capacity>& other) = delete;
    SharedPtr<T, Capacity>& operator=(const SharedPtr<T, Capacity>& other) = delete;
    
    SharedPtr(SharedPtr<T, Capacity>&& other) noexcept;
    SharedPtr<T, Capacity>& operator=(SharedPtr<T, Capacity>&& other) noexcept;
    
    static SharedPtr<T, Capacity> make(SharedMemory<T, Capacity>& memory,
                                       const T& value);
    
    SharedPtr<T, Capacity> share(SharedMemory<T, Capacity>& memory) const;
    
    Pointer<T, Capacity> getPointer() const;
    
    UInt64 useCount(const SharedMemory<T, Capacity>& memory) const;
    
    Bool unique(const SharedMemory<T, Capacity>& memory) const;
    
    Bool isNull() const;
    Bool isNotNull() const;
    
    T& get(SharedMemory<T, Capacity>& memory);
    const T& get(const SharedMemory<T, Capacity>& memory) const;
    
    Bool set(SharedMemory<T, Capacity>& memory, const T& value);
    
    Bool reset(SharedMemory<T, Capacity>& memory);
    
    Bool operator==(const SharedPtr<T, Capacity>& other) const;
    Bool operator!=(const SharedPtr<T, Capacity>& other) const;
};

template <typename T, unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os,
                         const SharedPtr<T, Capacity>& sharedPtr);

#include "SharedPtr.tpp"

#endif  // SHARED_PTR_H
