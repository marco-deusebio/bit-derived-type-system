//
//  StringConversions.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/************************
 * String  Conversion  Helpers   *
 ************************/

#ifndef STRING_CONVERSIONS_H
#define STRING_CONVERSIONS_H

#include <sstream>
#include <string>

#include "Bool.h"
#include "Byte.h"
#include "Char.h"

#include "UInt8.h"
#include "Int8.h"

#include "UInt16.h"
#include "Int16.h"

#include "UInt32.h"
#include "Int32.h"

#include "UInt64.h"
#include "Int64.h"

#include "Float32.h"
#include "Float64.h"

#include "CString.h"
#include "String.h"

#include "MyBuiltInTypes.h"

// =========================================================
// Internal helper
// =========================================================

template <unsigned long long Capacity>
String<Capacity> stringFromStdString(const std::string& text) {
    String<Capacity> result;
    
    for (unsigned long long i = 0; i < text.size(); ++i) {
        if (result.pushBack(Char(text[i])).toByte().raw() == 0) {
            break;
        }
    }
    
    return result;
}

// =========================================================
// Custom String -> std::string
// =========================================================

template <unsigned long long Capacity>
std::string toStdString(const String<Capacity>& value) {
    std::string result;
    
    for (unsigned long long i = 0; i < value.size().toUnsignedLongLong(); ++i) {
        result += static_cast<char>(value[String<Capacity>::makeIndex(i)].toByte().raw());
    }
    
    return result;
}

template <unsigned long long Capacity>
std::string toStdString(const CString<Capacity>& value) {
    std::string result;
    
    for (unsigned long long i = 0; i < value.size().toUnsignedLongLong(); ++i) {
        result += static_cast<char>(value[CString<Capacity>::makeIndex(i)].toByte().raw());
    }
    
    return result;
}

// =========================================================
// Text-like values -> String<Capacity>
// =========================================================

template <unsigned long long Capacity>
String<Capacity> toString(const char* text) {
    if (text == nullptr) {
        return String<Capacity>();
    }
    
    return String<Capacity>(text);
}

template <unsigned long long Capacity>
String<Capacity> toString(const std::string& text) {
    return stringFromStdString<Capacity>(text);
}

template <unsigned long long Capacity>
String<Capacity> toString(const String<Capacity>& value) {
    return value;
}

template <unsigned long long OutCapacity, unsigned long long InCapacity>
String<OutCapacity> toString(const String<InCapacity>& value) {
    String<OutCapacity> result;
    
    for (unsigned long long i = 0; i < value.size().toUnsignedLongLong(); ++i) {
        if (result.pushBack(value[String<InCapacity>::makeIndex(i)]).toByte().raw() == 0) {
            break;
        }
    }
    
    return result;
}

template <unsigned long long OutCapacity, unsigned long long InCapacity>
String<OutCapacity> toString(const CString<InCapacity>& value) {
    String<OutCapacity> result;
    
    for (unsigned long long i = 0; i < value.size().toUnsignedLongLong(); ++i) {
        if (result.pushBack(value[CString<InCapacity>::makeIndex(i)]).toByte().raw() == 0) {
            break;
        }
    }
    
    return result;
}

// =========================================================
// Bool / Byte / Char -> String<Capacity>
// =========================================================

template <unsigned long long Capacity>
String<Capacity> toString(const Bool& value) {
    if (value.toByte().raw() != 0) {
        return String<Capacity>("true");
    }
    
    return String<Capacity>("false");
}

template <unsigned long long Capacity>
String<Capacity> toString(bool value) {
    if (value) {
        return String<Capacity>("true");
    }
    
    return String<Capacity>("false");
}

template <unsigned long long Capacity>
String<Capacity> toString(const Byte& value) {
    return stringFromStdString<Capacity>(
                                         std::to_string(static_cast<unsigned int>(value.raw()))
                                         );
}

template <unsigned long long Capacity>
String<Capacity> toString(const Char& value) {
    String<Capacity> result;
    result.pushBack(value);
    return result;
}

template <unsigned long long Capacity>
String<Capacity> toString(char value) {
    String<Capacity> result;
    result.pushBack(Char(value));
    return result;
}

// =========================================================
// 8-bit integers -> String<Capacity>
// =========================================================

template <unsigned long long Capacity>
String<Capacity> toString(const UInt8& value) {
    return stringFromStdString<Capacity>(
                                         std::to_string(value.toInt())
                                         );
}

template <unsigned long long Capacity>
String<Capacity> toString(const Int8& value) {
    return stringFromStdString<Capacity>(
                                         std::to_string(value.toInt())
                                         );
}

// =========================================================
// 16-bit integers -> String<Capacity>
// =========================================================

template <unsigned long long Capacity>
String<Capacity> toString(const UInt16& value) {
    return stringFromStdString<Capacity>(
                                         std::to_string(value.toUnsignedInt())
                                         );
}

template <unsigned long long Capacity>
String<Capacity> toString(const Int16& value) {
    return stringFromStdString<Capacity>(
                                         std::to_string(value.toInt())
                                         );
}

// =========================================================
// 32-bit integers -> String<Capacity>
// =========================================================

template <unsigned long long Capacity>
String<Capacity> toString(const UInt32& value) {
    return stringFromStdString<Capacity>(
                                         std::to_string(value.toUnsignedLongLong())
                                         );
}

template <unsigned long long Capacity>
String<Capacity> toString(const Int32& value) {
    return stringFromStdString<Capacity>(
                                         std::to_string(value.toLongLong())
                                         );
}

// =========================================================
// 64-bit integers -> String<Capacity>
// =========================================================

template <unsigned long long Capacity>
String<Capacity> toString(const UInt64& value) {
    return stringFromStdString<Capacity>(
                                         std::to_string(value.toUnsignedLongLong())
                                         );
}

template <unsigned long long Capacity>
String<Capacity> toString(const Int64& value) {
    return stringFromStdString<Capacity>(
                                         std::to_string(value.toLongLong())
                                         );
}

// =========================================================
// Floating-point values -> String<Capacity>
// =========================================================

template <unsigned long long Capacity>
String<Capacity> toString(const Float32& value) {
    std::ostringstream out;
    out << value.toFloat();
    
    return stringFromStdString<Capacity>(out.str());
}

template <unsigned long long Capacity>
String<Capacity> toString(const Float64& value) {
    std::ostringstream out;
    out << value.toDouble();
    
    return stringFromStdString<Capacity>(out.str());
}

template <unsigned long long Capacity>
String<Capacity> toString(float value) {
    std::ostringstream out;
    out << value;
    
    return stringFromStdString<Capacity>(out.str());
}

template <unsigned long long Capacity>
String<Capacity> toString(double value) {
    std::ostringstream out;
    out << value;
    
    return stringFromStdString<Capacity>(out.str());
}

#endif  // STRING_CONVERSIONS_H
