//
//  Vector.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/**********************
 * Vector<T, Capacity>   *
 **********************/

#ifndef VECTOR_H
#define VECTOR_H

#include <iosfwd>

#include "Array.h"
#include "Bool.h"
#include "UInt64.h"

template <typename T, unsigned long long Capacity>
class Vector {
private:
    Array<T, Capacity> values;
    UInt64 length;
    
public:
    Vector();
    
    static UInt64 makeIndex(unsigned long long value);
    
    UInt64 size() const;
    UInt64 capacity() const;
    
    Bool empty() const;
    Bool full() const;
    
    void clear();
    
    Bool pushBack(const T& value);
    Bool popBack();
    
    Bool insertAt(const UInt64& index, const T& value);
    Bool removeAt(const UInt64& index);
    
    Bool set(const UInt64& index, const T& value);
    
    T& at(const UInt64& index);
    const T& at(const UInt64& index) const;
    
    T& operator[](const UInt64& index);
    const T& operator[](const UInt64& index) const;
    
    T& front();
    const T& front() const;
    
    T& back();
    const T& back() const;
    
    Bool contains(const T& value) const;
    Bool indexOf(const T& value, UInt64& outIndex) const;
    
    Bool operator==(const Vector<T, Capacity>& other) const;
    Bool operator!=(const Vector<T, Capacity>& other) const;
};

template <typename T, unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os, const Vector<T, Capacity>& vector);

#include "Vector.tpp"

#endif  // VECTOR_H
