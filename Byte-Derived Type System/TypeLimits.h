//
//  TypeLimits.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/**********************
 * My  Built-In  Type  Limits   *
 **********************/

#ifndef TYPE_LIMITS_H
#define TYPE_LIMITS_H

#include <limits>

#include "TypeHelpers.h"
#include "MyBuiltInTypes.h"

template <typename T>
class TypeLimits;

// Bool
template <>
class TypeLimits<Bool> {
public:
    static Bool min() {
        return makeBool(false);
    }
    
    static Bool max() {
        return makeBool(true);
    }
    
    static Bool zero() {
        return makeBool(false);
    }
    
    static Bool one() {
        return makeBool(true);
    }
};

// Byte
template <>
class TypeLimits<Byte> {
public:
    static Byte min() {
        return makeByte(0);
    }
    
    static Byte max() {
        return makeByte(255);
    }
    
    static Byte zero() {
        return makeByte(0);
    }
    
    static Byte one() {
        return makeByte(1);
    }
};

// Char
template <>
class TypeLimits<Char> {
public:
    static Char min() {
        return makeChar(static_cast<char>(0));
    }
    
    static Char max() {
        return Char(Byte(255));
    }
    
    static Char zero() {
        return makeChar(static_cast<char>(0));
    }
    
    static Char one() {
        return Char(Byte(1));
    }
};

// UInt8
template <>
class TypeLimits<UInt8> {
public:
    static UInt8 min() {
        return makeUInt8(0);
    }
    
    static UInt8 max() {
        return makeUInt8(255);
    }
    
    static UInt8 zero() {
        return makeUInt8(0);
    }
    
    static UInt8 one() {
        return makeUInt8(1);
    }
};

// Int8
template <>
class TypeLimits<Int8> {
public:
    static Int8 min() {
        return makeInt8(-128);
    }
    
    static Int8 max() {
        return makeInt8(127);
    }
    
    static Int8 zero() {
        return makeInt8(0);
    }
    
    static Int8 one() {
        return makeInt8(1);
    }
};

// UInt16
template <>
class TypeLimits<UInt16> {
public:
    static UInt16 min() {
        return makeUInt16(0);
    }
    
    static UInt16 max() {
        return makeUInt16(65535);
    }
    
    static UInt16 zero() {
        return makeUInt16(0);
    }
    
    static UInt16 one() {
        return makeUInt16(1);
    }
};

// Int16
template <>
class TypeLimits<Int16> {
public:
    static Int16 min() {
        return makeInt16(-32768);
    }
    
    static Int16 max() {
        return makeInt16(32767);
    }
    
    static Int16 zero() {
        return makeInt16(0);
    }
    
    static Int16 one() {
        return makeInt16(1);
    }
};

// UInt32
template <>
class TypeLimits<UInt32> {
public:
    static UInt32 min() {
        return makeUInt32(0);
    }
    
    static UInt32 max() {
        return makeUInt32(4294967295ULL);
    }
    
    static UInt32 zero() {
        return makeUInt32(0);
    }
    
    static UInt32 one() {
        return makeUInt32(1);
    }
};

// Int32
template <>
class TypeLimits<Int32> {
public:
    static Int32 min() {
        return makeInt32(-2147483647LL - 1);
    }
    
    static Int32 max() {
        return makeInt32(2147483647LL);
    }
    
    static Int32 zero() {
        return makeInt32(0);
    }
    
    static Int32 one() {
        return makeInt32(1);
    }
};

// UInt64
template <>
class TypeLimits<UInt64> {
public:
    static UInt64 min() {
        return makeUInt64(0);
    }
    
    static UInt64 max() {
        return makeUInt64(18446744073709551615ULL);
    }
    
    static UInt64 zero() {
        return makeUInt64(0);
    }
    
    static UInt64 one() {
        return makeUInt64(1);
    }
};

// Int64
template <>
class TypeLimits<Int64> {
public:
    static Int64 min() {
        return makeInt64(std::numeric_limits<long long>::min());
    }
    
    static Int64 max() {
        return makeInt64(std::numeric_limits<long long>::max());
    }
    
    static Int64 zero() {
        return makeInt64(0);
    }
    
    static Int64 one() {
        return makeInt64(1);
    }
};

// Float32
template <>
class TypeLimits<Float32> {
public:
    static Float32 lowest() {
        return makeFloat32(std::numeric_limits<float>::lowest());
    }
    
    static Float32 max() {
        return makeFloat32(std::numeric_limits<float>::max());
    }
    
    static Float32 minPositive() {
        return makeFloat32(std::numeric_limits<float>::min());
    }
    
    static Float32 epsilon() {
        return makeFloat32(std::numeric_limits<float>::epsilon());
    }
    
    static Float32 zero() {
        return makeFloat32(0.0f);
    }
    
    static Float32 one() {
        return makeFloat32(1.0f);
    }
};

// Float64
template <>
class TypeLimits<Float64> {
public:
    static Float64 lowest() {
        return makeFloat64(std::numeric_limits<double>::lowest());
    }
    
    static Float64 max() {
        return makeFloat64(std::numeric_limits<double>::max());
    }
    
    static Float64 minPositive() {
        return makeFloat64(std::numeric_limits<double>::min());
    }
    
    static Float64 epsilon() {
        return makeFloat64(std::numeric_limits<double>::epsilon());
    }
    
    static Float64 zero() {
        return makeFloat64(0.0);
    }
    
    static Float64 one() {
        return makeFloat64(1.0);
    }
};

#endif  // TYPE_LIMITS_H
