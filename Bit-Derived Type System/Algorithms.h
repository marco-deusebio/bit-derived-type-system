//
//  Algorithms.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/*****************
 * Algorithm  Helpers  *
 *****************/

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Array.h"
#include "Bool.h"
#include "Char.h"
#include "String.h"
#include "TypeHelpers.h"
#include "UInt64.h"
#include "Vector.h"

// =========================================================
// Generic swap
// =========================================================

template <typename T>
void swap(T& left, T& right) {
    T temp = left;
    left = right;
    right = temp;
}

// =========================================================
// Vector algorithms
// =========================================================

template <typename T, unsigned long long Capacity>
Bool find(const Vector<T, Capacity>& vector,
          const T& value,
          UInt64& outIndex) {
    for (unsigned long long i = 0; i < vector.size().toUnsignedLongLong(); ++i) {
        UInt64 index = makeIndex(i);
        
        if ((vector[index] == value).toByte().raw() != 0) {
            outIndex = index;
            return Bool(Byte(1));
        }
    }
    
    outIndex = makeIndex(Capacity);
    return Bool(Byte(0));
}

template <typename T, unsigned long long Capacity>
UInt64 count(const Vector<T, Capacity>& vector, const T& value) {
    unsigned long long count = 0;
    
    for (unsigned long long i = 0; i < vector.size().toUnsignedLongLong(); ++i) {
        UInt64 index = makeIndex(i);
        
        if ((vector[index] == value).toByte().raw() != 0) {
            ++count;
        }
    }
    
    return makeIndex(count);
}

template <typename T, unsigned long long Capacity>
void reverse(Vector<T, Capacity>& vector) {
    unsigned long long left = 0;
    unsigned long long right = vector.size().toUnsignedLongLong();
    
    if (right == 0) {
        return;
    }
    
    --right;
    
    while (left < right) {
        swap(vector[makeIndex(left)], vector[makeIndex(right)]);
        ++left;
        --right;
    }
}

template <typename T, unsigned long long Capacity>
void sortAscending(Vector<T, Capacity>& vector) {
    unsigned long long length = vector.size().toUnsignedLongLong();
    
    if (length < 2) {
        return;
    }
    
    for (unsigned long long pass = 0; pass < length - 1; ++pass) {
        for (unsigned long long i = 0; i + 1 < length - pass; ++i) {
            UInt64 currentIndex = makeIndex(i);
            UInt64 nextIndex = makeIndex(i + 1);
            
            if ((vector[currentIndex] > vector[nextIndex]).toByte().raw() != 0) {
                swap(vector[currentIndex], vector[nextIndex]);
            }
        }
    }
}

template <typename T, unsigned long long Capacity>
void sortDescending(Vector<T, Capacity>& vector) {
    unsigned long long length = vector.size().toUnsignedLongLong();
    
    if (length < 2) {
        return;
    }
    
    for (unsigned long long pass = 0; pass < length - 1; ++pass) {
        for (unsigned long long i = 0; i + 1 < length - pass; ++i) {
            UInt64 currentIndex = makeIndex(i);
            UInt64 nextIndex = makeIndex(i + 1);
            
            if ((vector[currentIndex] < vector[nextIndex]).toByte().raw() != 0) {
                swap(vector[currentIndex], vector[nextIndex]);
            }
        }
    }
}

// =========================================================
// Array algorithms
// =========================================================

template <typename T, unsigned long long Capacity>
Bool find(const Array<T, Capacity>& array,
          const T& value,
          UInt64& outIndex) {
    for (unsigned long long i = 0; i < Capacity; ++i) {
        UInt64 index = makeIndex(i);
        
        if ((array[index] == value).toByte().raw() != 0) {
            outIndex = index;
            return Bool(Byte(1));
        }
    }
    
    outIndex = makeIndex(Capacity);
    return Bool(Byte(0));
}

template <typename T, unsigned long long Capacity>
UInt64 count(const Array<T, Capacity>& array, const T& value) {
    unsigned long long count = 0;
    
    for (unsigned long long i = 0; i < Capacity; ++i) {
        UInt64 index = makeIndex(i);
        
        if ((array[index] == value).toByte().raw() != 0) {
            ++count;
        }
    }
    
    return makeIndex(count);
}

template <typename T, unsigned long long Capacity>
void reverse(Array<T, Capacity>& array) {
    if (Capacity == 0) {
        return;
    }
    
    unsigned long long left = 0;
    unsigned long long right = Capacity - 1;
    
    while (left < right) {
        Swap(array[makeIndex(left)], array[makeIndex(right)]);
        ++left;
        --right;
    }
}

template <typename T, unsigned long long Capacity>
void sortAscending(Array<T, Capacity>& array) {
    if (Capacity < 2) {
        return;
    }
    
    for (unsigned long long pass = 0; pass < Capacity - 1; ++pass) {
        for (unsigned long long i = 0; i + 1 < Capacity - pass; ++i) {
            UInt64 currentIndex = makeIndex(i);
            UInt64 nextIndex = makeIndex(i + 1);
            
            if ((array[currentIndex] > array[nextIndex]).toByte().raw() != 0) {
                Swap(array[currentIndex], array[nextIndex]);
            }
        }
    }
}

template <typename T, unsigned long long Capacity>
void sortDescending(Array<T, Capacity>& array) {
    if (Capacity < 2) {
        return;
    }
    
    for (unsigned long long pass = 0; pass < Capacity - 1; ++pass) {
        for (unsigned long long i = 0; i + 1 < Capacity - pass; ++i) {
            UInt64 currentIndex = makeIndex(i);
            UInt64 nextIndex = makeIndex(i + 1);
            
            if ((array[currentIndex] < array[nextIndex]).toByte().raw() != 0) {
                Swap(array[currentIndex], array[nextIndex]);
            }
        }
    }
}

// =========================================================
// String algorithms
// =========================================================

template <unsigned long long Capacity>
void reverse(String<Capacity>& string) {
    unsigned long long left = 0;
    unsigned long long right = string.size().toUnsignedLongLong();
    
    if (right == 0) {
        return;
    }
    
    --right;
    
    while (left < right) {
        Swap(string[makeIndex(left)], string[makeIndex(right)]);
        ++left;
        --right;
    }
}

template <unsigned long long Capacity>
UInt64 count(const String<Capacity>& string, const Char& value) {
    unsigned long long count = 0;
    
    for (unsigned long long i = 0; i < string.size().toUnsignedLongLong(); ++i) {
        UInt64 index = makeIndex(i);
        
        if ((string[index] == value).toByte().raw() != 0) {
            ++count;
        }
    }
    
    return makeIndex(count);
}

template <unsigned long long Capacity>
Bool find(const String<Capacity>& string,
          const Char& value,
          UInt64& outIndex) {
    for (unsigned long long i = 0; i < string.size().toUnsignedLongLong(); ++i) {
        UInt64 index = makeIndex(i);
        
        if ((string[index] == value).toByte().raw() != 0) {
            outIndex = index;
            return Bool(Byte(1));
        }
    }
    
    outIndex = makeIndex(Capacity);
    return Bool(Byte(0));
}

template <unsigned long long Capacity>
void toUpper(String<Capacity>& string) {
    for (unsigned long long i = 0; i < string.size().toUnsignedLongLong(); ++i) {
        UInt64 index = makeIndex(i);
        unsigned int ascii = string[index].toAscii();
        
        if (ascii >= 97 && ascii <= 122) {
            string[index] = Char(Byte(static_cast<std::uint8_t>(ascii - 32)));
        }
    }
}

template <unsigned long long Capacity>
void toLower(String<Capacity>& string) {
    for (unsigned long long i = 0; i < string.size().toUnsignedLongLong(); ++i) {
        UInt64 index = makeIndex(i);
        unsigned int ascii = string[index].toAscii();
        
        if (ascii >= 65 && ascii <= 90) {
            string[index] = Char(Byte(static_cast<std::uint8_t>(ascii + 32)));
        }
    }
}

#endif  // ALGORITHMS_H
