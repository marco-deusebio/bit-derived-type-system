//
//  Vector.tpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/***********************
 * Vector<T, Capacity> *
 ***********************/

#include <ostream>
#include <stdexcept>

template <typename T, unsigned long long Capacity>
Vector<T, Capacity>::Vector()
    : values(), length(UInt64()) {}

template <typename T, unsigned long long Capacity>
UInt64 Vector<T, Capacity>::makeIndex(unsigned long long value) {
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
UInt64 Vector<T, Capacity>::size() const {
    return this->length;
}

template <typename T, unsigned long long Capacity>
UInt64 Vector<T, Capacity>::capacity() const {
    return makeIndex(Capacity);
}

template <typename T, unsigned long long Capacity>
Bool Vector<T, Capacity>::empty() const {
    return Bool(Byte(this->length.toUnsignedLongLong() == 0));
}

template <typename T, unsigned long long Capacity>
Bool Vector<T, Capacity>::full() const {
    return Bool(Byte(this->length.toUnsignedLongLong() >= Capacity));
}

template <typename T, unsigned long long Capacity>
void Vector<T, Capacity>::clear() {
    this->length = UInt64();
}

template <typename T, unsigned long long Capacity>
Bool Vector<T, Capacity>::pushBack(const T& value) {
    if (this->full().toByte().raw() != 0) {
        return Bool(Byte(0));
    }

    this->values[this->length] = value;
    ++this->length;

    return Bool(Byte(1));
}

template <typename T, unsigned long long Capacity>
Bool Vector<T, Capacity>::popBack() {
    if (this->empty().toByte().raw() != 0) {
        return Bool(Byte(0));
    }

    --this->length;
    return Bool(Byte(1));
}

template <typename T, unsigned long long Capacity>
Bool Vector<T, Capacity>::insertAt(const UInt64& index, const T& value) {
    unsigned long long rawIndex = index.toUnsignedLongLong();
    unsigned long long rawLength = this->length.toUnsignedLongLong();

    if (this->full().toByte().raw() != 0) {
        return Bool(Byte(0));
    }

    if (rawIndex > rawLength) {
        return Bool(Byte(0));
    }

    for (unsigned long long i = rawLength; i > rawIndex; --i) {
        this->values[makeIndex(i)] = this->values[makeIndex(i - 1)];
    }

    this->values[index] = value;
    ++this->length;

    return Bool(Byte(1));
}

template <typename T, unsigned long long Capacity>
Bool Vector<T, Capacity>::removeAt(const UInt64& index) {
    unsigned long long rawIndex = index.toUnsignedLongLong();
    unsigned long long rawLength = this->length.toUnsignedLongLong();

    if (rawIndex >= rawLength) {
        return Bool(Byte(0));
    }

    for (unsigned long long i = rawIndex; i + 1 < rawLength; ++i) {
        this->values[makeIndex(i)] = this->values[makeIndex(i + 1)];
    }

    --this->length;

    return Bool(Byte(1));
}

template <typename T, unsigned long long Capacity>
Bool Vector<T, Capacity>::set(const UInt64& index, const T& value) {
    if (index.toUnsignedLongLong() >= this->length.toUnsignedLongLong()) {
        return Bool(Byte(0));
    }

    this->values[index] = value;
    return Bool(Byte(1));
}

template <typename T, unsigned long long Capacity>
T& Vector<T, Capacity>::at(const UInt64& index) {
    if (index.toUnsignedLongLong() >= this->length.toUnsignedLongLong()) {
        throw std::out_of_range("Vector index out of range.");
    }

    return this->values[index];
}

template <typename T, unsigned long long Capacity>
const T& Vector<T, Capacity>::at(const UInt64& index) const {
    if (index.toUnsignedLongLong() >= this->length.toUnsignedLongLong()) {
        throw std::out_of_range("Vector index out of range.");
    }

    return this->values[index];
}

template <typename T, unsigned long long Capacity>
T& Vector<T, Capacity>::operator[](const UInt64& index) {
    return this->at(index);
}

template <typename T, unsigned long long Capacity>
const T& Vector<T, Capacity>::operator[](const UInt64& index) const {
    return this->at(index);
}

template <typename T, unsigned long long Capacity>
T& Vector<T, Capacity>::front() {
    if (this->empty().toByte().raw() != 0) {
        throw std::out_of_range("Cannot access front of empty Vector.");
    }

    return this->values[makeIndex(0)];
}

template <typename T, unsigned long long Capacity>
const T& Vector<T, Capacity>::front() const {
    if (this->empty().toByte().raw() != 0) {
        throw std::out_of_range("Cannot access front of empty Vector.");
    }

    return this->values[makeIndex(0)];
}

template <typename T, unsigned long long Capacity>
T& Vector<T, Capacity>::back() {
    if (this->empty().toByte().raw() != 0) {
        throw std::out_of_range("Cannot access back of empty Vector.");
    }

    return this->values[makeIndex(this->length.toUnsignedLongLong() - 1)];
}

template <typename T, unsigned long long Capacity>
const T& Vector<T, Capacity>::back() const {
    if (this->empty().toByte().raw() != 0) {
        throw std::out_of_range("Cannot access back of empty Vector.");
    }

    return this->values[makeIndex(this->length.toUnsignedLongLong() - 1)];
}

template <typename T, unsigned long long Capacity>
Bool Vector<T, Capacity>::contains(const T& value) const {
    UInt64 foundIndex;

    return this->indexOf(value, foundIndex);
}

template <typename T, unsigned long long Capacity>
Bool Vector<T, Capacity>::indexOf(const T& value, UInt64& outIndex) const {
    for (unsigned long long i = 0; i < this->length.toUnsignedLongLong(); ++i) {
        UInt64 index = makeIndex(i);

        if ((this->values[index] == value).toByte().raw() != 0) {
            outIndex = index;
            return Bool(Byte(1));
        }
    }

    outIndex = makeIndex(Capacity);
    return Bool(Byte(0));
}

template <typename T, unsigned long long Capacity>
Bool Vector<T, Capacity>::operator==(const Vector<T, Capacity>& other) const {
    if ((this->length != other.length).toByte().raw() != 0) {
        return Bool(Byte(0));
    }

    for (unsigned long long i = 0; i < this->length.toUnsignedLongLong(); ++i) {
        UInt64 index = makeIndex(i);

        if ((this->values[index] != other.values[index]).toByte().raw() != 0) {
            return Bool(Byte(0));
        }
    }

    return Bool(Byte(1));
}

template <typename T, unsigned long long Capacity>
Bool Vector<T, Capacity>::operator!=(const Vector<T, Capacity>& other) const {
    return !(*this == other);
}

template <typename T, unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os, const Vector<T, Capacity>& vector) {
    os << "[";

    for (unsigned long long i = 0; i < vector.size().toUnsignedLongLong(); ++i) {
        UInt64 index = Vector<T, Capacity>::makeIndex(i);

        os << vector[index];

        if (i + 1 < vector.size().toUnsignedLongLong()) {
            os << ", ";
        }
    }

    os << "]";

    return os;
}
