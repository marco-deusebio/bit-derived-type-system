//
//  Pointer.tpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/************************
 * Pointer<T, Capacity> *
 ************************/

#include <ostream>

template <typename T, unsigned long long Capacity>
Pointer<T, Capacity>::Pointer()
    : index(makeIndex(Capacity)) {}

template <typename T, unsigned long long Capacity>
Pointer<T, Capacity>::Pointer(const UInt64& indexValue)
    : index(indexValue) {}

template <typename T, unsigned long long Capacity>
UInt64 Pointer<T, Capacity>::makeIndex(unsigned long long value) {
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
Pointer<T, Capacity> Pointer<T, Capacity>::null() {
    return Pointer<T, Capacity>(makeIndex(Capacity));
}

template <typename T, unsigned long long Capacity>
Pointer<T, Capacity> Pointer<T, Capacity>::fromIndex(const UInt64& indexValue) {
    if (indexValue.toUnsignedLongLong() >= Capacity) {
        return Pointer<T, Capacity>::null();
    }

    return Pointer<T, Capacity>(indexValue);
}

template <typename T, unsigned long long Capacity>
UInt64 Pointer<T, Capacity>::getIndex() const {
    return this->index;
}

template <typename T, unsigned long long Capacity>
Bool Pointer<T, Capacity>::isNull() const {
    if (this->index.toUnsignedLongLong() >= Capacity) {
        return Bool(Byte(1));
    }

    return Bool(Byte(0));
}

template <typename T, unsigned long long Capacity>
Bool Pointer<T, Capacity>::isNotNull() const {
    return !this->isNull();
}

template <typename T, unsigned long long Capacity>
Bool Pointer<T, Capacity>::operator==(const Pointer<T, Capacity>& other) const {
    return this->index == other.index;
}

template <typename T, unsigned long long Capacity>
Bool Pointer<T, Capacity>::operator!=(const Pointer<T, Capacity>& other) const {
    return !(*this == other);
}

template <typename T, unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os, const Pointer<T, Capacity>& pointer) {
    if (pointer.isNull().toByte().raw() != 0) {
        os << "Pointer(null)";
    } else {
        os << "Pointer(index=" << pointer.getIndex() << ")";
    }

    return os;
}
