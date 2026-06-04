//
//  String.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/******************
 * String<Capacity>  *
 ******************/

#ifndef STRING_H
#define STRING_H

#include <iosfwd>

#include "Bool.h"
#include "Byte.h"
#include "Char.h"
#include "CString.h"
#include "UInt64.h"
#include "Vector.h"

template <unsigned long long Capacity>
class String {
private:
    Vector<Char, Capacity> characters;
    
public:
    String();
    String(const char* text);
    
    static UInt64 makeIndex(unsigned long long value);
    
    UInt64 size() const;
    UInt64 capacity() const;
    
    Bool empty() const;
    Bool full() const;
    
    void clear();
    
    Bool pushBack(const Char& value);
    Bool pushBack(const Byte& byte);
    
    Bool popBack();
    
    Bool append(const char* text);
    Bool append(const String<Capacity>& other);
    Bool append(const CString<Capacity>& other);
    
    Char& at(const UInt64& index);
    const Char& at(const UInt64& index) const;
    
    Char& operator[](const UInt64& index);
    const Char& operator[](const UInt64& index) const;
    
    Bool operator==(const String<Capacity>& other) const;
    Bool operator!=(const String<Capacity>& other) const;
    Bool operator<(const String<Capacity>& other) const;
    Bool operator>(const String<Capacity>& other) const;
    Bool operator<=(const String<Capacity>& other) const;
    Bool operator>=(const String<Capacity>& other) const;
    
    String<Capacity>& operator+=(const String<Capacity>& other);
    String<Capacity>& operator+=(const CString<Capacity>& other);
    String<Capacity>& operator+=(const char* text);
    
    String<Capacity> operator+(const String<Capacity>& other) const;
    String<Capacity> operator+(const CString<Capacity>& other) const;
    String<Capacity> operator+(const char* text) const;
    
    Bool startsWith(const String<Capacity>& prefix) const;
    Bool endsWith(const String<Capacity>& suffix) const;
    Bool contains(const String<Capacity>& text) const;
    
    Bool indexOf(const Char& value, UInt64& outIndex) const;
    Bool indexOf(const String<Capacity>& text, UInt64& outIndex) const;};

template <unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os, const String<Capacity>& string);

#include "String.tpp"

#endif  // STRING_H
