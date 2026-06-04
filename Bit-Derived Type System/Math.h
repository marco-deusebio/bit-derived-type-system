//
//  Math.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/**************
 * Math  Helpers  *
 **************/

#ifndef MATH_H
#define MATH_H

#include "MyBuiltInTypes.h"

inline Int absol(const Int& value) {
    if ((value < Int(0)).toByte().raw() != 0) {
        return Int(0) - value;
    }
    
    return value;
}

inline LongInt absol(const LongInt& value) {
    if ((value < LongInt(0)).toByte().raw() != 0) {
        return LongInt(0) - value;
    }
    
    return value;
}

inline Float absol(const Float& value) {
    if ((value < Float(0.0f)).toByte().raw() != 0) {
        return Float(0.0f) - value;
    }
    
    return value;
}

inline Double absol(const Double& value) {
    if ((value < Double(0.0)).toByte().raw() != 0) {
        return Double(0.0) - value;
    }
    
    return value;
}

template <typename T>
T min(const T& left, const T& right) {
    if ((left < right).toByte().raw() != 0) {
        return left;
    }
    
    return right;
}

template <typename T>
T max(const T& left, const T& right) {
    if ((left > right).toByte().raw() != 0) {
        return left;
    }
    
    return right;
}

template <typename T>
T clamp(const T& value, const T& low, const T& high) {
    if ((value < low).toByte().raw() != 0) {
        return low;
    }
    
    if ((value > high).toByte().raw() != 0) {
        return high;
    }
    
    return value;
}

#endif  // MATH_H
