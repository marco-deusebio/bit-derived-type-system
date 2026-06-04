//
//  CString.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/*******************
 * CString<Capacity>  *
 *******************/

#ifndef CSTRING_H
#define CSTRING_H

#include <iosfwd>

#include "Array.h"
#include "Bool.h"
#include "Char.h"
#include "UInt64.h"

template <unsigned long long Capacity>
class CString {
private:
    Array<Char, Capacity> characters;
    UInt64 length;
    
    void writeNullTerminator();
    
public:
    CString();
    CString(const char* text);
    
    static UInt64 makeIndex(unsigned long long value);
    
    UInt64 size() const;
    UInt64 capacity() const;
    
    Bool empty() const;
    Bool full() const;
    Bool isTerminated() const;
    
    void clear();
    
    Bool pushBack(const Char& value);
    Bool pushBack(const Byte& byte);
    
    Char& at(const UInt64& index);
    const Char& at(const UInt64& index) const;
    
    Char& operator[](const UInt64& index);
    const Char& operator[](const UInt64& index) const;
    
    Bool operator==(const CString<Capacity>& other) const;
    Bool operator!=(const CString<Capacity>& other) const;
    Bool operator<(const CString<Capacity>& other) const;
    Bool operator>(const CString<Capacity>& other) const;
    Bool operator<=(const CString<Capacity>& other) const;
    Bool operator>=(const CString<Capacity>& other) const;
};

template <unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os, const CString<Capacity>& string);

#include "CString.tpp"

#endif  // CSTRING_H
