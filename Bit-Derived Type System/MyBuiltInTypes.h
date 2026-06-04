//
//  MyBuiltInTypes.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/*********************
 * My Built-in Type Names  *
 *********************/

#ifndef MY_BUILT_IN_TYPES_H
#define MY_BUILT_IN_TYPES_H

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

#include "NullPtr.h"
#include "Void.h"

// 8-bit integer types
using UChar = UInt8;
using SChar = Int8;

// 16-bit integer types
using UShortInt = UInt16;
using ShortInt = Int16;

// 32-bit integer types
using UInt = UInt32;
using Int = Int32;

// 64-bit integer types
using ULongInt = UInt64;
using LongInt = Int64;

using ULongLongInt = UInt64;
using LongLongInt = Int64;

// Floating-point representation types
using Float = Float32;
using Double = Float64;

#endif  // MY_BUILT_IN_TYPES_H
