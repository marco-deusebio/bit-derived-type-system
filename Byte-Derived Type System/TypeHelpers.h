//
//  TypeHelpers.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/********************
 * Type Helper Functions  *
 ********************/

#ifndef TYPE_HELPERS_H
#define TYPE_HELPERS_H

#include <cstdint>
#include <cstring>

#include "Byte.h"
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

inline Byte makeByte(unsigned long long value) {
    return Byte(static_cast<std::uint8_t>(value & 0xFF));
}

inline Bool makeBool(bool value) {
    if (value) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

inline Char makeChar(char value) {
    return Char(Byte(static_cast<std::uint8_t>(value)));
}

inline UInt8 makeUInt8(unsigned long long value) {
    return UInt8(Byte(static_cast<std::uint8_t>(value & 0xFF)));
}

inline Int8 makeInt8(long long value) {
    return Int8::fromSignedValue(static_cast<int>(value));
}

inline UInt16 makeUInt16(unsigned long long value) {
    return UInt16(
                  Byte(static_cast<std::uint8_t>(value & 0xFF)),
                  Byte(static_cast<std::uint8_t>((value >> 8) & 0xFF))
                  );
}

inline Int16 makeInt16(long long value) {
    return Int16::fromSignedValue(static_cast<int>(value));
}

inline UInt32 makeUInt32(unsigned long long value) {
    return UInt32(
                  Byte(static_cast<std::uint8_t>(value & 0xFF)),
                  Byte(static_cast<std::uint8_t>((value >> 8) & 0xFF)),
                  Byte(static_cast<std::uint8_t>((value >> 16) & 0xFF)),
                  Byte(static_cast<std::uint8_t>((value >> 24) & 0xFF))
                  );
}

inline Int32 makeInt32(long long value) {
    return Int32::fromSignedValue(value);
}

inline UInt64 makeUInt64(unsigned long long value) {
    return UInt64(
                  Byte(static_cast<std::uint8_t>(value & 0xFF)),
                  Byte(static_cast<std::uint8_t>((value >> 8) & 0xFF)),
                  Byte(static_cast<std::uint8_t>((value >> 16) & 0xFF)),
                  Byte(static_cast<std::uint8_t>((value >> 24) & 0xFF)),
                  Byte(static_cast<std::uint8_t>((value >> 32) & 0xFF)),
                  Byte(static_cast<std::uint8_t>((value >> 40) & 0xFF)),
                  Byte(static_cast<std::uint8_t>((value >> 48) & 0xFF)),
                  Byte(static_cast<std::uint8_t>((value >> 56) & 0xFF))
                  );
}

inline Int64 makeInt64(long long value) {
    return Int64::fromSignedValue(value);
}

inline Float32 makeFloat32(float value) {
    std::uint32_t raw = 0;
    
    std::memcpy(&raw, &value, sizeof(float));
    
    return Float32::fromBytes(
                              Byte(static_cast<std::uint8_t>(raw & 0xFF)),
                              Byte(static_cast<std::uint8_t>((raw >> 8) & 0xFF)),
                              Byte(static_cast<std::uint8_t>((raw >> 16) & 0xFF)),
                              Byte(static_cast<std::uint8_t>((raw >> 24) & 0xFF))
                              );
}

inline Float64 makeFloat64(double value) {
    std::uint64_t raw = 0;
    
    std::memcpy(&raw, &value, sizeof(double));
    
    return Float64::fromBytes(
                              Byte(static_cast<std::uint8_t>(raw & 0xFF)),
                              Byte(static_cast<std::uint8_t>((raw >> 8) & 0xFF)),
                              Byte(static_cast<std::uint8_t>((raw >> 16) & 0xFF)),
                              Byte(static_cast<std::uint8_t>((raw >> 24) & 0xFF)),
                              Byte(static_cast<std::uint8_t>((raw >> 32) & 0xFF)),
                              Byte(static_cast<std::uint8_t>((raw >> 40) & 0xFF)),
                              Byte(static_cast<std::uint8_t>((raw >> 48) & 0xFF)),
                              Byte(static_cast<std::uint8_t>((raw >> 56) & 0xFF))
                              );
}

// Friendly aliases for your common names
inline UInt32 makeUInt(unsigned long long value) {
    return makeUInt32(value);
}

inline Int32 makeInt(long long value) {
    return makeInt32(value);
}

inline UInt64 makeULong(unsigned long long value) {
    return makeUInt64(value);
}

inline Int64 makeLong(long long value) {
    return makeInt64(value);
}

inline Float32 makeFloat(float value) {
    return makeFloat32(value);
}

inline Float64 makeDouble(double value) {
    return makeFloat64(value);
}

// Helpful for Array, Vector, String, and CString indexing
inline UInt64 makeIndex(unsigned long long value) {
    return makeUInt64(value);
}

#endif  // TYPE_HELPERS_H
