//
//  Conversions.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/*******************
 * Conversion  Helpers   *
 *******************/

#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <cstdint>

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

#include "MyBuiltInTypes.h"

// =========================================================
// Bool conversions
// =========================================================

inline Bool toBool(const Bool& value) {
    return value;
}

inline Bool toBool(bool value) {
    return Bool(value);
}

inline Bool toBool(const Byte& value) {
    return Bool(value);
}

inline Bool toBool(const Char& value) {
    return Bool(value.toByte());
}

inline Bool toBool(const UInt8& value) {
    return Bool(Byte(value.toInt() != 0));
}

inline Bool toBool(const Int8& value) {
    return Bool(Byte(value.toInt() != 0));
}

inline Bool toBool(const UInt16& value) {
    return Bool(Byte(value.toUnsignedInt() != 0));
}

inline Bool toBool(const Int16& value) {
    return Bool(Byte(value.toInt() != 0));
}

inline Bool toBool(const UInt32& value) {
    return Bool(Byte(value.toUnsignedLongLong() != 0));
}

inline Bool toBool(const Int32& value) {
    return Bool(Byte(value.toLongLong() != 0));
}

inline Bool toBool(const UInt64& value) {
    return Bool(Byte(value.toUnsignedLongLong() != 0));
}

inline Bool toBool(const Int64& value) {
    return Bool(Byte(value.toLongLong() != 0));
}

inline Bool toBool(const Float32& value) {
    return value != Float32(0.0f);
}

inline Bool toBool(const Float64& value) {
    return value != Float64(0.0);
}

// =========================================================
// Byte / Char conversions
// =========================================================

inline Byte toByte(const Byte& value) {
    return value;
}

inline Byte toByte(const Bool& value) {
    return value.toByte();
}

inline Byte toByte(const Char& value) {
    return value.toByte();
}

inline Byte toByte(const UInt8& value) {
    return value.toByte();
}

inline Byte toByte(const Int8& value) {
    return value.raw().toByte();
}

inline Byte toByte(const UInt16& value) {
    return value.getByte(0);
}

inline Byte toByte(const Int16& value) {
    return value.raw().getByte(0);
}

inline Byte toByte(const UInt32& value) {
    return value.getByte(0);
}

inline Byte toByte(const Int32& value) {
    return value.raw().getByte(0);
}

inline Byte toByte(const UInt64& value) {
    return value.getByte(0);
}

inline Byte toByte(const Int64& value) {
    return value.raw().getByte(0);
}

inline Byte toByte(const Float32& value) {
    return value.raw().getByte(0);
}

inline Byte toByte(const Float64& value) {
    return value.raw().getByte(0);
}

inline Byte toByte(unsigned long long value) {
    return Byte(static_cast<std::uint8_t>(value & 0xFF));
}

inline Char toChar(const Char& value) {
    return value;
}

inline Char toChar(const Byte& value) {
    return Char(value);
}

inline Char toChar(const UInt8& value) {
    return Char(value.toByte());
}

inline Char toChar(const Int8& value) {
    return Char(value.raw().toByte());
}

inline Char toChar(const UInt16& value) {
    return Char(value.getByte(0));
}

inline Char toChar(const Int16& value) {
    return Char(value.raw().getByte(0));
}

inline Char toChar(const UInt32& value) {
    return Char(value.getByte(0));
}

inline Char toChar(const Int32& value) {
    return Char(value.raw().getByte(0));
}

inline Char toChar(const UInt64& value) {
    return Char(value.getByte(0));
}

inline Char toChar(const Int64& value) {
    return Char(value.raw().getByte(0));
}

inline Char toChar(char value) {
    return Char(value);
}

inline Char toChar(int value) {
    return Char(Byte(static_cast<std::uint8_t>(value & 0xFF)));
}

// =========================================================
// 8-bit conversions
// =========================================================

inline UInt8 toUInt8(const UInt8& value) {
    return value;
}

inline UInt8 toUInt8(const Byte& value) {
    return UInt8(value);
}

inline UInt8 toUInt8(const Int8& value) {
    return UInt8(value.raw().toByte());
}

inline UInt8 toUInt8(const UInt16& value) {
    return UInt8(value.getByte(0));
}

inline UInt8 toUInt8(const Int16& value) {
    return UInt8(value.raw().getByte(0));
}

inline UInt8 toUInt8(const UInt32& value) {
    return UInt8(value.getByte(0));
}

inline UInt8 toUInt8(const Int32& value) {
    return UInt8(value.raw().getByte(0));
}

inline UInt8 toUInt8(const UInt64& value) {
    return UInt8(value.getByte(0));
}

inline UInt8 toUInt8(const Int64& value) {
    return UInt8(value.raw().getByte(0));
}

inline UInt8 toUInt8(unsigned long long value) {
    return UInt8(static_cast<unsigned int>(value & 0xFF));
}

inline Int8 toInt8(const Int8& value) {
    return value;
}

inline Int8 toInt8(const UInt8& value) {
    return Int8(value);
}

inline Int8 toInt8(const UInt16& value) {
    return Int8(UInt8(value.getByte(0)));
}

inline Int8 toInt8(const Int16& value) {
    return Int8(UInt8(value.raw().getByte(0)));
}

inline Int8 toInt8(const UInt32& value) {
    return Int8(UInt8(value.getByte(0)));
}

inline Int8 toInt8(const Int32& value) {
    return Int8(UInt8(value.raw().getByte(0)));
}

inline Int8 toInt8(const UInt64& value) {
    return Int8(UInt8(value.getByte(0)));
}

inline Int8 toInt8(const Int64& value) {
    return Int8(UInt8(value.raw().getByte(0)));
}

inline Int8 toInt8(long long value) {
    return Int8::fromSignedValue(static_cast<int>(value));
}

// =========================================================
// 16-bit conversions
// =========================================================

inline UInt16 toUInt16(const UInt16& value) {
    return value;
}

inline UInt16 toUInt16(const UInt8& value) {
    return UInt16(value.toByte(), Byte(0));
}

inline UInt16 toUInt16(const Int8& value) {
    return UInt16(value.raw().toByte(), Byte(0));
}

inline UInt16 toUInt16(const UInt32& value) {
    return UInt16(value.getByte(0), value.getByte(1));
}

inline UInt16 toUInt16(const Int32& value) {
    return UInt16(value.raw().getByte(0), value.raw().getByte(1));
}

inline UInt16 toUInt16(const UInt64& value) {
    return UInt16(value.getByte(0), value.getByte(1));
}

inline UInt16 toUInt16(const Int64& value) {
    return UInt16(value.raw().getByte(0), value.raw().getByte(1));
}

inline UInt16 toUInt16(unsigned long long value) {
    return UInt16(static_cast<unsigned int>(value));
}

inline Int16 toInt16(const Int16& value) {
    return value;
}

inline Int16 toInt16(const UInt16& value) {
    return Int16(value);
}

inline Int16 toInt16(const Int8& value) {
    return Int16::fromSignedValue(value.toInt());
}

inline Int16 toInt16(const UInt8& value) {
    return Int16::fromSignedValue(value.toInt());
}

inline Int16 toInt16(const Int32& value) {
    return Int16::fromSignedValue(static_cast<int>(value.toLongLong()));
}

inline Int16 toInt16(const UInt32& value) {
    return Int16(UInt16(value.getByte(0), value.getByte(1)));
}

inline Int16 toInt16(const Int64& value) {
    return Int16::fromSignedValue(static_cast<int>(value.toLongLong()));
}

inline Int16 toInt16(const UInt64& value) {
    return Int16(UInt16(value.getByte(0), value.getByte(1)));
}

inline Int16 toInt16(long long value) {
    return Int16::fromSignedValue(static_cast<int>(value));
}

// =========================================================
// 32-bit conversions
// =========================================================

inline UInt toUInt(const UInt& value) {
    return value;
}

inline UInt toUInt(const Int& value) {
    return value.raw();
}

inline UInt toUInt(const UInt8& value) {
    return UInt(value.toInt());
}

inline UInt toUInt(const Int8& value) {
    return UInt(static_cast<unsigned long long>(
                                                static_cast<std::uint8_t>(value.toInt())
                                                ));
}

inline UInt toUInt(const UInt16& value) {
    return UInt(value.toUnsignedInt());
}

inline UInt toUInt(const Int16& value) {
    return UInt(static_cast<unsigned long long>(
                                                static_cast<unsigned int>(value.toInt())
                                                ));
}

inline UInt toUInt(const ULongInt& value) {
    return UInt(
                value.getByte(0),
                value.getByte(1),
                value.getByte(2),
                value.getByte(3)
                );
}

inline UInt toUInt(const LongInt& value) {
    UInt64 raw = value.raw();
    
    return UInt(
                raw.getByte(0),
                raw.getByte(1),
                raw.getByte(2),
                raw.getByte(3)
                );
}

inline UInt toUInt(const Float& value) {
    return UInt(static_cast<unsigned long long>(value.toFloat()));
}

inline UInt toUInt(const Double& value) {
    return UInt(static_cast<unsigned long long>(value.toDouble()));
}

inline UInt toUInt(unsigned long long value) {
    return UInt(value);
}

inline Int toInt(const Int& value) {
    return value;
}

inline Int toInt(const UInt& value) {
    return Int(value);
}

inline Int toInt(const UInt8& value) {
    return Int(value.toInt());
}

inline Int toInt(const Int8& value) {
    return Int(value.toInt());
}

inline Int toInt(const UInt16& value) {
    return Int(value.toUnsignedInt());
}

inline Int toInt(const Int16& value) {
    return Int(value.toInt());
}

inline Int toInt(const ULongInt& value) {
    return Int(toUInt(value));
}

inline Int toInt(const LongInt& value) {
    return Int(toUInt(value));
}

inline Int toInt(const Float& value) {
    return Int(static_cast<long long>(value.toFloat()));
}

inline Int toInt(const Double& value) {
    return Int(static_cast<long long>(value.toDouble()));
}

inline Int toInt(long long value) {
    return Int(value);
}

// =========================================================
// 64-bit conversions
// =========================================================

inline ULongInt toULongInt(const ULongInt& value) {
    return value;
}

inline ULongInt toULongInt(const LongInt& value) {
    return value.raw();
}

inline ULongInt toULongInt(const UInt& value) {
    return ULongInt(value.toUnsignedLongLong());
}

inline ULongInt toULongInt(const Int& value) {
    return ULongInt(static_cast<unsigned long long>(value.toLongLong()));
}

inline ULongInt toULongInt(const UInt16& value) {
    return ULongInt(value.toUnsignedInt());
}

inline ULongInt toULongInt(const Int16& value) {
    return ULongInt(static_cast<unsigned long long>(value.toInt()));
}

inline ULongInt toULongInt(const UInt8& value) {
    return ULongInt(value.toInt());
}

inline ULongInt toULongInt(const Int8& value) {
    return ULongInt(static_cast<unsigned long long>(value.toInt()));
}

inline ULongInt toULongInt(const Float& value) {
    return ULongInt(static_cast<unsigned long long>(value.toFloat()));
}

inline ULongInt toULongInt(const Double& value) {
    return ULongInt(static_cast<unsigned long long>(value.toDouble()));
}

inline ULongInt toULongInt(unsigned long long value) {
    return ULongInt(value);
}

inline LongInt toLongInt(const LongInt& value) {
    return value;
}

inline LongInt toLongInt(const ULongInt& value) {
    return LongInt(value);
}

inline LongInt toLongInt(const Int& value) {
    return LongInt(value.toLongLong());
}

inline LongInt toLongInt(const UInt& value) {
    return LongInt(static_cast<long long>(value.toUnsignedLongLong()));
}

inline LongInt toLongInt(const Int16& value) {
    return LongInt(value.toInt());
}

inline LongInt toLongInt(const UInt16& value) {
    return LongInt(value.toUnsignedInt());
}

inline LongInt toLongInt(const Int8& value) {
    return LongInt(value.toInt());
}

inline LongInt toLongInt(const UInt8& value) {
    return LongInt(value.toInt());
}

inline LongInt toLongInt(const Float& value) {
    return LongInt(static_cast<long long>(value.toFloat()));
}

inline LongInt toLongInt(const Double& value) {
    return LongInt(static_cast<long long>(value.toDouble()));
}

inline LongInt toLongInt(long long value) {
    return LongInt(value);
}

// LongLongInt / ULongLongInt are aliases to Int64 / UInt64.
// These functions are separate names for readability.

inline ULongLongInt toULongLongInt(const ULongInt& value) {
    return value;
}

inline ULongLongInt toULongLongInt(unsigned long long value) {
    return ULongLongInt(value);
}

inline LongLongInt toLongLongInt(const LongInt& value) {
    return value;
}

inline LongLongInt toLongLongInt(long long value) {
    return LongLongInt(value);
}

// =========================================================
// Floating-point conversions
// =========================================================

inline Float toFloat(const Float& value) {
    return value;
}

inline Float toFloat(const Double& value) {
    return Float(static_cast<float>(value.toDouble()));
}

inline Float toFloat(const Int& value) {
    return Float(static_cast<float>(value.toLongLong()));
}

inline Float toFloat(const UInt& value) {
    return Float(static_cast<float>(value.toUnsignedLongLong()));
}

inline Float toFloat(const LongInt& value) {
    return Float(static_cast<float>(value.toLongLong()));
}

inline Float toFloat(const ULongInt& value) {
    return Float(static_cast<float>(value.toUnsignedLongLong()));
}

inline Float toFloat(float value) {
    return Float(value);
}

inline Double toDouble(const Double& value) {
    return value;
}

inline Double toDouble(const Float& value) {
    return Double(static_cast<double>(value.toFloat()));
}

inline Double toDouble(const Int& value) {
    return Double(static_cast<double>(value.toLongLong()));
}

inline Double toDouble(const UInt& value) {
    return Double(static_cast<double>(value.toUnsignedLongLong()));
}

inline Double toDouble(const LongInt& value) {
    return Double(static_cast<double>(value.toLongLong()));
}

inline Double toDouble(const ULongInt& value) {
    return Double(static_cast<double>(value.toUnsignedLongLong()));
}

inline Double toDouble(double value) {
    return Double(value);
}

#endif  // CONVERSIONS_H
