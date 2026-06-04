//
//  Memory.tpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/***********************
 * Memory<T, Capacity> *
 ***********************/

#include <ostream>
#include <stdexcept>

template <typename T, unsigned long long Capacity>
Memory<T, Capacity>::Memory()
    : values(), used() {
    for (unsigned long long i = 0; i < Capacity; ++i) {
        this->used[makeIndex(i)] = Bool(Byte(0));
    }
}

template <typename T, unsigned long long Capacity>
UInt64 Memory<T, Capacity>::makeIndex(unsigned long long value) {
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
UInt64 Memory<T, Capacity>::capacity() const {
    return makeIndex(Capacity);
}

template <typename T, unsigned long long Capacity>
UInt64 Memory<T, Capacity>::usedCount() const {
    unsigned long long count = 0;

    for (unsigned long long i = 0; i < Capacity; ++i) {
        if (this->used[makeIndex(i)].toByte().raw() != 0) {
            ++count;
        }
    }

    return makeIndex(count);
}

template <typename T, unsigned long long Capacity>
Bool Memory<T, Capacity>::full() const {
    if (this->usedCount().toUnsignedLongLong() >= Capacity) {
        return Bool(Byte(1));
    }

    return Bool(Byte(0));
}

template <typename T, unsigned long long Capacity>
Bool Memory<T, Capacity>::empty() const {
    if (this->usedCount().toUnsignedLongLong() == 0) {
        return Bool(Byte(1));
    }

    return Bool(Byte(0));
}

template <typename T, unsigned long long Capacity>
Pointer<T, Capacity> Memory<T, Capacity>::allocate(const T& value) {
    for (unsigned long long i = 0; i < Capacity; ++i) {
        UInt64 index = makeIndex(i);

        if (this->used[index].toByte().raw() == 0) {
            this->values[index] = value;
            this->used[index] = Bool(Byte(1));

            return Pointer<T, Capacity>::fromIndex(index);
        }
    }

    return Pointer<T, Capacity>::null();
}

template <typename T, unsigned long long Capacity>
Bool Memory<T, Capacity>::deallocate(const Pointer<T, Capacity>& pointer) {
    if (this->contains(pointer).toByte().raw() == 0) {
        return Bool(Byte(0));
    }

    this->used[pointer.getIndex()] = Bool(Byte(0));

    return Bool(Byte(1));
}

template <typename T, unsigned long long Capacity>
Bool Memory<T, Capacity>::contains(const Pointer<T, Capacity>& pointer) const {
    if (pointer.isNull().toByte().raw() != 0) {
        return Bool(Byte(0));
    }

    UInt64 index = pointer.getIndex();

    if (index.toUnsignedLongLong() >= Capacity) {
        return Bool(Byte(0));
    }

    if (this->used[index].toByte().raw() == 0) {
        return Bool(Byte(0));
    }

    return Bool(Byte(1));
}

template <typename T, unsigned long long Capacity>
T& Memory<T, Capacity>::get(const Pointer<T, Capacity>& pointer) {
    if (this->contains(pointer).toByte().raw() == 0) {
        throw std::out_of_range("Invalid memory access through Pointer.");
    }

    return this->values[pointer.getIndex()];
}

template <typename T, unsigned long long Capacity>
const T& Memory<T, Capacity>::get(const Pointer<T, Capacity>& pointer) const {
    if (this->contains(pointer).toByte().raw() == 0) {
        throw std::out_of_range("Invalid memory access through Pointer.");
    }

    return this->values[pointer.getIndex()];
}

template <typename T, unsigned long long Capacity>
Bool Memory<T, Capacity>::set(const Pointer<T, Capacity>& pointer, const T& value) {
    if (this->contains(pointer).toByte().raw() == 0) {
        return Bool(Byte(0));
    }

    this->values[pointer.getIndex()] = value;

    return Bool(Byte(1));
}

template <typename T, unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os, const Memory<T, Capacity>& memory) {
    os << "Memory{";

    os << "used=" << memory.usedCount()
       << ", capacity=" << memory.capacity()
       << "}";

    return os;
}
