//
//  Array.tpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/**********************
 * Array<T, Capacity> *
 **********************/

#include <ostream>
#include <stdexcept>

template <typename T, unsigned long long Capacity>
static UInt64 makeUInt64FromUnsignedLongLong(unsigned long long value) {
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

template <typename T, unsigned long long Capacity>
Array<T, Capacity>::Array() {}

template <typename T, unsigned long long Capacity>
T& Array<T, Capacity>::at(const UInt64& index) {
    unsigned long long rawIndex = index.toUnsignedLongLong();
    
    if (rawIndex >= Capacity) {
        throw std::out_of_range("Array index out of range.");
    }
    
    return this->values[rawIndex];
}

template <typename T, unsigned long long Capacity>
const T& Array<T, Capacity>::at(const UInt64& index) const {
    unsigned long long rawIndex = index.toUnsignedLongLong();
    
    if (rawIndex >= Capacity) {
        throw std::out_of_range("Array index out of range.");
    }
    
    return this->values[rawIndex];
}

template <typename T, unsigned long long Capacity>
T& Array<T, Capacity>::operator[](const UInt64& index) {
    return this->at(index);
}

template <typename T, unsigned long long Capacity>
const T& Array<T, Capacity>::operator[](const UInt64& index) const {
    return this->at(index);
}

template <typename T, unsigned long long Capacity>
UInt64 Array<T, Capacity>::size() const {
    return makeUInt64FromUnsignedLongLong<T, Capacity>(Capacity);
}

template <typename T, unsigned long long Capacity>
Bool Array<T, Capacity>::empty() const {
    if (Capacity == 0) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

template <typename T, unsigned long long Capacity>
void Array<T, Capacity>::fill(const T& value) {
    for (unsigned long long i = 0; i < Capacity; ++i) {
        this->values[i] = value;
    }
}

template <typename T, unsigned long long Capacity>
Bool Array<T, Capacity>::operator==(const Array<T, Capacity>& other) const {
    for (unsigned long long i = 0; i < Capacity; ++i) {
        if (static_cast<int>((this->values[i] != other.values[i]).toByte().raw()) != 0) {
            return Bool(Byte(0));
        }
    }
    
    return Bool(Byte(1));
}

template <typename T, unsigned long long Capacity>
Bool Array<T, Capacity>::operator!=(const Array<T, Capacity>& other) const {
    return !(*this == other);
}

template <typename T, unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os, const Array<T, Capacity>& array) {
    os << "[";
    
    for (unsigned long long i = 0; i < Capacity; ++i) {
        os << array[makeUInt64FromUnsignedLongLong<T, Capacity>(i)];
        
        if (i + 1 < Capacity) {
            os << ", ";
        }
    }
    
    os << "]";
    return os;
}
