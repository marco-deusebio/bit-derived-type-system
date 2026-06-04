//
//  TypeIO.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/********************
 * Type  Input  Operators  *
 ********************/

#ifndef TYPE_IO_H
#define TYPE_IO_H

#include <istream>
#include <limits>
#include <string>

#include "TypeHelpers.h"

#include "Bool.h"
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

// Bool input:
// Accepts: true, false, 1, 0, yes, no, y, n
inline std::istream& operator>>(std::istream& is, Bool& value) {
    std::string text;
    is >> text;
    
    if (!is) {
        return is;
    }
    
    if (text == "true" || text == "True" || text == "TRUE" ||
        text == "1" ||
        text == "yes" || text == "Yes" || text == "YES" ||
        text == "y" || text == "Y") {
        value = Bool(Byte(1));
    } else if (text == "false" || text == "False" || text == "FALSE" ||
               text == "0" ||
               text == "no" || text == "No" || text == "NO" ||
               text == "n" || text == "N") {
        value = Bool(Byte(0));
    } else {
        is.setstate(std::ios::failbit);
    }
    
    return is;
}

// Char input
inline std::istream& operator>>(std::istream& is, Char& value) {
    char input;
    is >> input;
    
    if (is) {
        value = makeChar(input);
    }
    
    return is;
}

// UInt8 input
inline std::istream& operator>>(std::istream& is, UInt8& value) {
    unsigned int input;
    is >> input;
    
    if (is) {
        value = makeUInt8(input);
    }
    
    return is;
}

// Int8 input
inline std::istream& operator>>(std::istream& is, Int8& value) {
    int input;
    is >> input;
    
    if (is) {
        value = makeInt8(input);
    }
    
    return is;
}

// UInt16 input
inline std::istream& operator>>(std::istream& is, UInt16& value) {
    unsigned int input;
    is >> input;
    
    if (is) {
        value = makeUInt16(input);
    }
    
    return is;
}

// Int16 input
inline std::istream& operator>>(std::istream& is, Int16& value) {
    int input;
    is >> input;
    
    if (is) {
        value = makeInt16(input);
    }
    
    return is;
}

// UInt32 input
inline std::istream& operator>>(std::istream& is, UInt32& value) {
    unsigned long long input;
    is >> input;
    
    if (is) {
        value = makeUInt32(input);
    }
    
    return is;
}

// Int32 input
inline std::istream& operator>>(std::istream& is, Int32& value) {
    long long input;
    is >> input;
    
    if (is) {
        value = makeInt32(input);
    }
    
    return is;
}

// UInt64 input
inline std::istream& operator>>(std::istream& is, UInt64& value) {
    unsigned long long input;
    is >> input;
    
    if (is) {
        value = makeUInt64(input);
    }
    
    return is;
}

// Int64 input
inline std::istream& operator>>(std::istream& is, Int64& value) {
    long long input;
    is >> input;
    
    if (is) {
        value = makeInt64(input);
    }
    
    return is;
}

// Float32 input
inline std::istream& operator>>(std::istream& is, Float32& value) {
    float input;
    is >> input;
    
    if (is) {
        value = makeFloat32(input);
    }
    
    return is;
}

// Float64 input
inline std::istream& operator>>(std::istream& is, Float64& value) {
    double input;
    is >> input;
    
    if (is) {
        value = makeFloat64(input);
    }
    
    return is;
}

// CString input
// Reads one word, similar to normal std::cin >> std::string.
template <unsigned long long Capacity>
std::istream& operator>>(std::istream& is, CString<Capacity>& value) {
    std::string input;
    is >> input;
    
    if (!is) {
        return is;
    }
    
    value.clear();
    
    for (unsigned long long i = 0; i < input.size(); ++i) {
        if (value.pushBack(makeChar(input[i])).toByte().raw() == 0) {
            break;
        }
    }
    
    return is;
}

// String input
// Reads one word, similar to normal std::cin >> std::string.
template <unsigned long long Capacity>
std::istream& operator>>(std::istream& is, String<Capacity>& value) {
    std::string input;
    is >> input;
    
    if (!is) {
        return is;
    }
    
    value.clear();
    
    for (unsigned long long i = 0; i < input.size(); ++i) {
        if (value.pushBack(makeChar(input[i])).toByte().raw() == 0) {
            break;
        }
    }
    
    return is;
}

// Helper for reading a full line into String<Capacity>.
template <unsigned long long Capacity>
std::istream& getline(std::istream& is, String<Capacity>& value) {
    std::string input;
    std::getline(is, input);
    
    if (!is) {
        return is;
    }
    
    value.clear();
    
    for (unsigned long long i = 0; i < input.size(); ++i) {
        if (value.pushBack(makeChar(input[i])).toByte().raw() == 0) {
            break;
        }
    }
    
    return is;
}

// Helper for reading a full line into CString<Capacity>.
template <unsigned long long Capacity>
std::istream& getline(std::istream& is, CString<Capacity>& value) {
    std::string input;
    std::getline(is, input);
    
    if (!is) {
        return is;
    }
    
    value.clear();
    
    for (unsigned long long i = 0; i < input.size(); ++i) {
        if (value.pushBack(makeChar(input[i])).toByte().raw() == 0) {
            break;
        }
    }
    
    return is;
}

#endif  // TYPE_IO_H
