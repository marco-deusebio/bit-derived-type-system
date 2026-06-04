//
//  TypeSystem.h
//  Byte-Derived Type System
//
//  Created by Marco D’Eusebio on 6/3/26.
//

#ifndef TYPE_SYSTEM_H
#define TYPE_SYSTEM_H

// Foundation
#include "Byte.h"
#include "Bool.h"
#include "Char.h"

// Integer types
#include "UInt8.h"
#include "Int8.h"

#include "UInt16.h"
#include "Int16.h"

#include "UInt32.h"
#include "Int32.h"

#include "UInt64.h"
#include "Int64.h"

// Floating-point representation types
#include "Float32.h"
#include "Float64.h"

// Containers / text
#include "Array.h"
#include "Array2D.h"
#include "Vector.h"
#include "CString.h"
#include "String.h"

// Simulated language-feature types
#include "Pointer.h"
#include "Memory.h"
#include "UniquePtr.h"
#include "SharedMemory.h"
#include "SharedPtr.h"
#include "Reference.h"
#include "NullPtr.h"
#include "Void.h"
#include "Enum.h"

// Friendly aliases
#include "MyBuiltInTypes.h"

// Helper functions
#include "TypeHelpers.h"

// Conversion helpers
#include "Conversions.h"

// String conversion helpers
#include "StringConversions.h"

// String parsing helpers
#include "StringParsing.h"

// Type limits
#include "TypeLimits.h"

// Math helpers
#include "Math.h"

// Algorithm helpers
#include "Algorithms.h"

// Input/output convenience
#include "TypeIO.h"

#endif  // TYPE_SYSTEM_H
