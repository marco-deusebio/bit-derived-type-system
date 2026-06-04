//
//  StringParsing.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/*********************
 * String  Parsing  Helpers  *
 *********************/

#ifndef STRING_PARSING_H
#define STRING_PARSING_H

#include <cctype>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cerrno>

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

#include "Conversions.h"
#include "StringConversions.h"
#include "MyBuiltInTypes.h"

// =========================================================
// Internal helpers
// =========================================================

inline Bool parseLongLongStrict(const std::string& text, long long& out) {
    errno = 0;
    const char* start = text.c_str();
    char* endPtr = nullptr;
    long long value = std::strtoll(start, &endPtr, 10);
    if (errno != 0) { return Bool(Byte(0)); }
    if (endPtr == start) { return Bool(Byte(0)); }
    while (*endPtr != '\0' && std::isspace(static_cast<unsigned char>(*endPtr))) { ++endPtr; }
    if (*endPtr != '\0') { return Bool(Byte(0)); }
    out = value;
    return Bool(Byte(1));
}

inline Bool parseULongLongStrict(const std::string& text, unsigned long long& out) {
    errno = 0;
    const char* start = text.c_str();
    char* endPtr = nullptr;
    unsigned long long value = std::strtoull(start, &endPtr, 10);
    if (errno != 0) { return Bool(Byte(0)); }
    if (endPtr == start) { return Bool(Byte(0)); }
    while (*endPtr != '\0' && std::isspace(static_cast<unsigned char>(*endPtr))) { ++endPtr; }
    if (*endPtr != '\0') { return Bool(Byte(0)); }
    out = value;
    return Bool(Byte(1));
}

inline Bool parseDoubleStrict(const std::string& text, double& out) {
    errno = 0;
    const char* start = text.c_str();
    char* endPtr = nullptr;
    double value = std::strtod(start, &endPtr);
    if (errno != 0) { return Bool(Byte(0)); }
    if (endPtr == start) { return Bool(Byte(0)); }
    while (*endPtr != '\0' && std::isspace(static_cast<unsigned char>(*endPtr))) { ++endPtr; }
    if (*endPtr != '\0') { return Bool(Byte(0)); }
    out = value;
    return Bool(Byte(1));
}

inline Bool parseFloatStrict(const std::string& text, float& out) {
    errno = 0;
    const char* start = text.c_str();
    char* endPtr = nullptr;
    float value = std::strtof(start, &endPtr);
    if (errno != 0) { return Bool(Byte(0)); }
    if (endPtr == start) { return Bool(Byte(0)); }
    while (*endPtr != '\0' && std::isspace(static_cast<unsigned char>(*endPtr))) { ++endPtr; }
    if (*endPtr != '\0') { return Bool(Byte(0)); }
    out = value;
    return Bool(Byte(1));
}

inline std::string trimText(const std::string& text) {
    unsigned long long start = 0;
    unsigned long long end = text.size();
    
    while (start < end &&
           std::isspace(static_cast<unsigned char>(text[start]))) {
        ++start;
    }
    
    while (end > start &&
           std::isspace(static_cast<unsigned char>(text[end - 1]))) {
        --end;
    }
    
    return text.substr(start, end - start);
}

inline std::string lowerText(const std::string& text) {
    std::string result = text;
    
    for (unsigned long long i = 0; i < result.size(); ++i) {
        result[i] = static_cast<char>(
                                      std::tolower(static_cast<unsigned char>(result[i]))
                                      );
    }
    
    return result;
}

inline Bool hasNegativeSign(const std::string& text) {
    std::string trimmed = trimText(text);
    
    if (trimmed.size() > 0 && trimmed[0] == '-') {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

// =========================================================
// Bool parsing
// =========================================================

inline Bool tryToBool(const std::string& text, Bool& outValue) {
    std::string value = lowerText(trimText(text));
    
    if (value == "true" || value == "1" ||
        value == "yes" || value == "y") {
        outValue = Bool(true);
        return Bool(Byte(1));
    }
    
    if (value == "false" || value == "0" ||
        value == "no" || value == "n") {
        outValue = Bool(false);
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

inline Bool toBool(const std::string& text) {
    Bool result;
    
    if (tryToBool(text, result).toByte().raw() == 0) {
        throw std::invalid_argument("Cannot convert string to Bool.");
    }
    
    return result;
}

inline Bool toBool(const char* text) {
    if (text == nullptr) {
        throw std::invalid_argument("Cannot convert null text to Bool.");
    }
    
    return toBool(std::string(text));
}

template <unsigned long long Capacity>
Bool tryToBool(const String<Capacity>& text, Bool& outValue) {
    return tryToBool(toStdString(text), outValue);
}

template <unsigned long long Capacity>
Bool tryToBool(const CString<Capacity>& text, Bool& outValue) {
    return tryToBool(toStdString(text), outValue);
}

template <unsigned long long Capacity>
Bool toBool(const String<Capacity>& text) {
    return toBool(toStdString(text));
}

template <unsigned long long Capacity>
Bool toBool(const CString<Capacity>& text) {
    return toBool(toStdString(text));
}

// =========================================================
// Char parsing
// =========================================================

inline Bool tryToChar(const std::string& text, Char& outValue) {
    std::string trimmed = trimText(text);
    
    if (trimmed.size() == 0) {
        return Bool(Byte(0));
    }
    
    outValue = Char(trimmed[0]);
    return Bool(Byte(1));
}

inline Char toChar(const std::string& text) {
    Char result;
    
    if (tryToChar(text, result).toByte().raw() == 0) {
        throw std::invalid_argument("Cannot convert string to Char.");
    }
    
    return result;
}

inline Char toChar(const char* text) {
    if (text == nullptr) {
        throw std::invalid_argument("Cannot convert null text to Char.");
    }
    
    return toChar(std::string(text));
}

template <unsigned long long Capacity>
Bool tryToChar(const String<Capacity>& text, Char& outValue) {
    return tryToChar(toStdString(text), outValue);
}

template <unsigned long long Capacity>
Bool tryToChar(const CString<Capacity>& text, Char& outValue) {
    return tryToChar(toStdString(text), outValue);
}

template <unsigned long long Capacity>
Char toChar(const String<Capacity>& text) {
    return toChar(toStdString(text));
}

template <unsigned long long Capacity>
Char toChar(const CString<Capacity>& text) {
    return toChar(toStdString(text));
}

// =========================================================
// Signed integer parsing
// =========================================================

inline Bool tryToLongInt(const std::string& text, LongInt& outValue) {
    try {
        std::string trimmed = trimText(text);
        long long value = 0;
        if (parseLongLongStrict(trimmed, value).toByte().raw() == 0) {
            return Bool(Byte(0));
        }
        outValue = LongInt(value);
        return Bool(Byte(1));
    } catch (...) {
        return Bool(Byte(0));
    }
}

inline LongInt toLongInt(const std::string& text) {
    LongInt result;
    
    if (tryToLongInt(text, result).toByte().raw() == 0) {
        throw std::invalid_argument("Cannot convert string to LongInt.");
    }
    
    return result;
}

inline LongInt toLongInt(const char* text) {
    if (text == nullptr) {
        throw std::invalid_argument("Cannot convert null text to LongInt.");
    }
    
    return toLongInt(std::string(text));
}

template <unsigned long long Capacity>
Bool tryToLongInt(const String<Capacity>& text, LongInt& outValue) {
    return tryToLongInt(toStdString(text), outValue);
}

template <unsigned long long Capacity>
Bool tryToLongInt(const CString<Capacity>& text, LongInt& outValue) {
    return tryToLongInt(toStdString(text), outValue);
}

template <unsigned long long Capacity>
LongInt toLongInt(const String<Capacity>& text) {
    return toLongInt(toStdString(text));
}

template <unsigned long long Capacity>
LongInt toLongInt(const CString<Capacity>& text) {
    return toLongInt(toStdString(text));
}

inline Bool tryToInt(const std::string& text, Int& outValue) {
    LongInt temp;
    
    if (tryToLongInt(text, temp).toByte().raw() == 0) {
        return Bool(Byte(0));
    }
    
    outValue = toInt(temp);
    return Bool(Byte(1));
}

inline Int toInt(const std::string& text) {
    Int result;
    
    if (tryToInt(text, result).toByte().raw() == 0) {
        throw std::invalid_argument("Cannot convert string to Int.");
    }
    
    return result;
}

inline Int toInt(const char* text) {
    if (text == nullptr) {
        throw std::invalid_argument("Cannot convert null text to Int.");
    }
    
    return toInt(std::string(text));
}

template <unsigned long long Capacity>
Bool tryToInt(const String<Capacity>& text, Int& outValue) {
    return tryToInt(toStdString(text), outValue);
}

template <unsigned long long Capacity>
Bool tryToInt(const CString<Capacity>& text, Int& outValue) {
    return tryToInt(toStdString(text), outValue);
}

template <unsigned long long Capacity>
Int toInt(const String<Capacity>& text) {
    return toInt(toStdString(text));
}

template <unsigned long long Capacity>
Int toInt(const CString<Capacity>& text) {
    return toInt(toStdString(text));
}

// =========================================================
// Unsigned integer parsing
// =========================================================

inline Bool tryToULongInt(const std::string& text, ULongInt& outValue) {
    try {
        std::string trimmed = trimText(text);
        
        if (hasNegativeSign(trimmed).toByte().raw() != 0) {
            return Bool(Byte(0));
        }
        
        unsigned long long value = 0;
        if (parseULongLongStrict(trimmed, value).toByte().raw() == 0) {
            return Bool(Byte(0));
        }
        
        outValue = ULongInt(value);
        return Bool(Byte(1));
    } catch (...) {
        return Bool(Byte(0));
    }
}

inline ULongInt toULongInt(const std::string& text) {
    ULongInt result;
    
    if (tryToULongInt(text, result).toByte().raw() == 0) {
        throw std::invalid_argument("Cannot convert string to ULongInt.");
    }
    
    return result;
}

inline ULongInt toULongInt(const char* text) {
    if (text == nullptr) {
        throw std::invalid_argument("Cannot convert null text to ULongInt.");
    }
    
    return toULongInt(std::string(text));
}

template <unsigned long long Capacity>
Bool tryToULongInt(const String<Capacity>& text, ULongInt& outValue) {
    return tryToULongInt(toStdString(text), outValue);
}

template <unsigned long long Capacity>
Bool tryToULongInt(const CString<Capacity>& text, ULongInt& outValue) {
    return tryToULongInt(toStdString(text), outValue);
}

template <unsigned long long Capacity>
ULongInt toULongInt(const String<Capacity>& text) {
    return toULongInt(toStdString(text));
}

template <unsigned long long Capacity>
ULongInt toULongInt(const CString<Capacity>& text) {
    return toULongInt(toStdString(text));
}

inline Bool tryToUInt(const std::string& text, UInt& outValue) {
    ULongInt temp;
    
    if (tryToULongInt(text, temp).toByte().raw() == 0) {
        return Bool(Byte(0));
    }
    
    outValue = toUInt(temp);
    return Bool(Byte(1));
}

inline UInt toUInt(const std::string& text) {
    UInt result;
    
    if (tryToUInt(text, result).toByte().raw() == 0) {
        throw std::invalid_argument("Cannot convert string to UInt.");
    }
    
    return result;
}

inline UInt toUInt(const char* text) {
    if (text == nullptr) {
        throw std::invalid_argument("Cannot convert null text to UInt.");
    }
    
    return toUInt(std::string(text));
}

template <unsigned long long Capacity>
Bool tryToUInt(const String<Capacity>& text, UInt& outValue) {
    return tryToUInt(toStdString(text), outValue);
}

template <unsigned long long Capacity>
Bool tryToUInt(const CString<Capacity>& text, UInt& outValue) {
    return tryToUInt(toStdString(text), outValue);
}

template <unsigned long long Capacity>
UInt toUInt(const String<Capacity>& text) {
    return toUInt(toStdString(text));
}

template <unsigned long long Capacity>
UInt toUInt(const CString<Capacity>& text) {
    return toUInt(toStdString(text));
}

// =========================================================
// Floating-point parsing
// =========================================================

inline Bool tryToDouble(const std::string& text, Double& outValue) {
    try {
        std::string trimmed = trimText(text);
        double value = 0.0;
        if (parseDoubleStrict(trimmed, value).toByte().raw() == 0) {
            return Bool(Byte(0));
        }
        outValue = Double(value);
        return Bool(Byte(1));
    } catch (...) {
        return Bool(Byte(0));
    }
}

inline Double toDouble(const std::string& text) {
    Double result;
    
    if (tryToDouble(text, result).toByte().raw() == 0) {
        throw std::invalid_argument("Cannot convert string to Double.");
    }
    
    return result;
}

inline Double toDouble(const char* text) {
    if (text == nullptr) {
        throw std::invalid_argument("Cannot convert null text to Double.");
    }
    
    return toDouble(std::string(text));
}

template <unsigned long long Capacity>
Bool tryToDouble(const String<Capacity>& text, Double& outValue) {
    return tryToDouble(toStdString(text), outValue);
}

template <unsigned long long Capacity>
Bool tryToDouble(const CString<Capacity>& text, Double& outValue) {
    return tryToDouble(toStdString(text), outValue);
}

template <unsigned long long Capacity>
Double toDouble(const String<Capacity>& text) {
    return toDouble(toStdString(text));
}

template <unsigned long long Capacity>
Double toDouble(const CString<Capacity>& text) {
    return toDouble(toStdString(text));
}

inline Bool tryToFloat(const std::string& text, Float& outValue) {
    try {
        std::string trimmed = trimText(text);
        float value = 0.0f;
        if (parseFloatStrict(trimmed, value).toByte().raw() == 0) {
            return Bool(Byte(0));
        }
        outValue = Float(value);
        return Bool(Byte(1));
    } catch (...) {
        return Bool(Byte(0));
    }
}

inline Float toFloat(const std::string& text) {
    Float result;
    
    if (tryToFloat(text, result).toByte().raw() == 0) {
        throw std::invalid_argument("Cannot convert string to Float.");
    }
    
    return result;
}

inline Float toFloat(const char* text) {
    if (text == nullptr) {
        throw std::invalid_argument("Cannot convert null text to Float.");
    }
    
    return toFloat(std::string(text));
}

template <unsigned long long Capacity>
Bool tryToFloat(const String<Capacity>& text, Float& outValue) {
    return tryToFloat(toStdString(text), outValue);
}

template <unsigned long long Capacity>
Bool tryToFloat(const CString<Capacity>& text, Float& outValue) {
    return tryToFloat(toStdString(text), outValue);
}

template <unsigned long long Capacity>
Float toFloat(const String<Capacity>& text) {
    return toFloat(toStdString(text));
}

template <unsigned long long Capacity>
Float toFloat(const CString<Capacity>& text) {
    return toFloat(toStdString(text));
}

#endif  // STRING_PARSING_H
