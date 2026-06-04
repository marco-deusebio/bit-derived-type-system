//
//  CString.tpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/*********************
 * CString<Capacity> *
 *********************/

#include <ostream>
#include <stdexcept>

template <unsigned long long Capacity>
UInt64 CString<Capacity>::makeIndex(unsigned long long value) {
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

template <unsigned long long Capacity>
CString<Capacity>::CString()
    : characters(), length(UInt64()) {
    static_assert(Capacity > 0, "CString capacity must include room for a null terminator.");
    this->writeNullTerminator();
}

template <unsigned long long Capacity>
CString<Capacity>::CString(const char* text)
    : characters(), length(UInt64()) {
    static_assert(Capacity > 0, "CString capacity must include room for a null terminator.");

    this->writeNullTerminator();

    if (text == nullptr) {
        return;
    }

    unsigned long long i = 0;

    while (text[i] != '\0' && i + 1 < Capacity) {
        this->pushBack(Byte(static_cast<std::uint8_t>(text[i])));
        ++i;
    }
}

template <unsigned long long Capacity>
void CString<Capacity>::writeNullTerminator() {
    unsigned long long rawLength = this->length.toUnsignedLongLong();

    if (rawLength < Capacity) {
        this->characters[makeIndex(rawLength)] = Char(Byte(0));
    }
}

template <unsigned long long Capacity>
UInt64 CString<Capacity>::size() const {
    return this->length;
}

template <unsigned long long Capacity>
UInt64 CString<Capacity>::capacity() const {
    return makeIndex(Capacity);
}

template <unsigned long long Capacity>
Bool CString<Capacity>::empty() const {
    if (this->length.toUnsignedLongLong() == 0) {
        return Bool(Byte(1));
    }

    return Bool(Byte(0));
}

template <unsigned long long Capacity>
Bool CString<Capacity>::full() const {
    if (this->length.toUnsignedLongLong() + 1 >= Capacity) {
        return Bool(Byte(1));
    }

    return Bool(Byte(0));
}

template <unsigned long long Capacity>
Bool CString<Capacity>::isTerminated() const {
    unsigned long long rawLength = this->length.toUnsignedLongLong();

    if (rawLength >= Capacity) {
        return Bool(Byte(0));
    }

    if (this->characters[makeIndex(rawLength)].toByte().raw() == 0) {
        return Bool(Byte(1));
    }

    return Bool(Byte(0));
}

template <unsigned long long Capacity>
void CString<Capacity>::clear() {
    this->length = UInt64();
    this->writeNullTerminator();
}

template <unsigned long long Capacity>
Bool CString<Capacity>::pushBack(const Char& value) {
    if (this->full().toByte().raw() != 0) {
        return Bool(Byte(0));
    }

    if (value.toByte().raw() == 0) {
        return Bool(Byte(0));
    }

    this->characters[this->length] = value;
    ++this->length;

    this->writeNullTerminator();

    return Bool(Byte(1));
}

template <unsigned long long Capacity>
Bool CString<Capacity>::pushBack(const Byte& byte) {
    return this->pushBack(Char(byte));
}

template <unsigned long long Capacity>
Char& CString<Capacity>::at(const UInt64& index) {
    if (index.toUnsignedLongLong() >= this->length.toUnsignedLongLong()) {
        throw std::out_of_range("CString index out of range.");
    }

    return this->characters[index];
}

template <unsigned long long Capacity>
const Char& CString<Capacity>::at(const UInt64& index) const {
    if (index.toUnsignedLongLong() >= this->length.toUnsignedLongLong()) {
        throw std::out_of_range("CString index out of range.");
    }

    return this->characters[index];
}

template <unsigned long long Capacity>
Char& CString<Capacity>::operator[](const UInt64& index) {
    return this->at(index);
}

template <unsigned long long Capacity>
const Char& CString<Capacity>::operator[](const UInt64& index) const {
    return this->at(index);
}

template <unsigned long long Capacity>
Bool CString<Capacity>::operator==(const CString<Capacity>& other) const {
    if ((this->length != other.length).toByte().raw() != 0) {
        return Bool(Byte(0));
    }

    for (unsigned long long i = 0; i < this->length.toUnsignedLongLong(); ++i) {
        UInt64 index = makeIndex(i);

        if ((this->characters[index] != other.characters[index]).toByte().raw() != 0) {
            return Bool(Byte(0));
        }
    }

    return Bool(Byte(1));
}

template <unsigned long long Capacity>
Bool CString<Capacity>::operator!=(const CString<Capacity>& other) const {
    return !(*this == other);
}

template <unsigned long long Capacity>
Bool CString<Capacity>::operator<(const CString<Capacity>& other) const {
    unsigned long long thisLength = this->length.toUnsignedLongLong();
    unsigned long long otherLength = other.length.toUnsignedLongLong();

    unsigned long long smallerLength = thisLength;

    if (otherLength < smallerLength) {
        smallerLength = otherLength;
    }

    for (unsigned long long i = 0; i < smallerLength; ++i) {
        UInt64 index = makeIndex(i);

        if ((this->characters[index] < other.characters[index]).toByte().raw() != 0) {
            return Bool(Byte(1));
        }

        if ((this->characters[index] > other.characters[index]).toByte().raw() != 0) {
            return Bool(Byte(0));
        }
    }

    if (thisLength < otherLength) {
        return Bool(Byte(1));
    }

    return Bool(Byte(0));
}

template <unsigned long long Capacity>
Bool CString<Capacity>::operator>(const CString<Capacity>& other) const {
    return other < *this;
}

template <unsigned long long Capacity>
Bool CString<Capacity>::operator<=(const CString<Capacity>& other) const {
    return !(*this > other);
}

template <unsigned long long Capacity>
Bool CString<Capacity>::operator>=(const CString<Capacity>& other) const {
    return !(*this < other);
}

template <unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os, const CString<Capacity>& string) {
    for (unsigned long long i = 0; i < string.size().toUnsignedLongLong(); ++i) {
        UInt64 index = CString<Capacity>::makeIndex(i);
        os << string[index];
    }

    return os;
}
