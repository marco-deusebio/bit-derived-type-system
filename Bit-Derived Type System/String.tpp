//
//  String.tpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/********************
 * String<Capacity> *
 ********************/

#include <ostream>

template <unsigned long long Capacity>
String<Capacity>::String()
    : characters() {}

template <unsigned long long Capacity>
String<Capacity>::String(const char* text)
    : characters() {
    if (text == nullptr) {
        return;
    }

    unsigned long long i = 0;

    while (text[i] != '\0' && i < Capacity) {
        this->pushBack(Byte(static_cast<std::uint8_t>(text[i])));
        ++i;
    }
}

template <unsigned long long Capacity>
UInt64 String<Capacity>::makeIndex(unsigned long long value) {
    return Vector<Char, Capacity>::makeIndex(value);
}

template <unsigned long long Capacity>
UInt64 String<Capacity>::size() const {
    return this->characters.size();
}

template <unsigned long long Capacity>
UInt64 String<Capacity>::capacity() const {
    return this->characters.capacity();
}

template <unsigned long long Capacity>
Bool String<Capacity>::empty() const {
    return this->characters.empty();
}

template <unsigned long long Capacity>
Bool String<Capacity>::full() const {
    return this->characters.full();
}

template <unsigned long long Capacity>
void String<Capacity>::clear() {
    this->characters.clear();
}

template <unsigned long long Capacity>
Bool String<Capacity>::pushBack(const Char& value) {
    return this->characters.pushBack(value);
}

template <unsigned long long Capacity>
Bool String<Capacity>::pushBack(const Byte& byte) {
    return this->pushBack(Char(byte));
}

template <unsigned long long Capacity>
Bool String<Capacity>::popBack() {
    return this->characters.popBack();
}

template <unsigned long long Capacity>
Bool String<Capacity>::append(const char* text) {
    if (text == nullptr) {
        return Bool(Byte(0));
    }

    unsigned long long i = 0;

    while (text[i] != '\0') {
        if (this->pushBack(Byte(static_cast<std::uint8_t>(text[i]))).toByte().raw() == 0) {
            return Bool(Byte(0));
        }

        ++i;
    }

    return Bool(Byte(1));
}

template <unsigned long long Capacity>
Bool String<Capacity>::append(const String<Capacity>& other) {
    for (unsigned long long i = 0; i < other.size().toUnsignedLongLong(); ++i) {
        UInt64 index = makeIndex(i);

        if (this->pushBack(other[index]).toByte().raw() == 0) {
            return Bool(Byte(0));
        }
    }

    return Bool(Byte(1));
}

template <unsigned long long Capacity>
Bool String<Capacity>::append(const CString<Capacity>& other) {
    for (unsigned long long i = 0; i < other.size().toUnsignedLongLong(); ++i) {
        UInt64 index = makeIndex(i);

        if (this->pushBack(other[index]).toByte().raw() == 0) {
            return Bool(Byte(0));
        }
    }

    return Bool(Byte(1));
}

template <unsigned long long Capacity>
Char& String<Capacity>::at(const UInt64& index) {
    return this->characters.at(index);
}

template <unsigned long long Capacity>
const Char& String<Capacity>::at(const UInt64& index) const {
    return this->characters.at(index);
}

template <unsigned long long Capacity>
Char& String<Capacity>::operator[](const UInt64& index) {
    return this->at(index);
}

template <unsigned long long Capacity>
const Char& String<Capacity>::operator[](const UInt64& index) const {
    return this->at(index);
}

template <unsigned long long Capacity>
Bool String<Capacity>::operator==(const String<Capacity>& other) const {
    return this->characters == other.characters;
}

template <unsigned long long Capacity>
Bool String<Capacity>::operator!=(const String<Capacity>& other) const {
    return !(*this == other);
}

template <unsigned long long Capacity>
Bool String<Capacity>::operator<(const String<Capacity>& other) const {
    unsigned long long thisLength = this->size().toUnsignedLongLong();
    unsigned long long otherLength = other.size().toUnsignedLongLong();

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
Bool String<Capacity>::operator>(const String<Capacity>& other) const {
    return other < *this;
}

template <unsigned long long Capacity>
Bool String<Capacity>::operator<=(const String<Capacity>& other) const {
    return !(*this > other);
}

template <unsigned long long Capacity>
Bool String<Capacity>::operator>=(const String<Capacity>& other) const {
    return !(*this < other);
}

template <unsigned long long Capacity>
String<Capacity>& String<Capacity>::operator+=(const String<Capacity>& other) {
    this->append(other);
    return *this;
}

template <unsigned long long Capacity>
String<Capacity>& String<Capacity>::operator+=(const CString<Capacity>& other) {
    this->append(other);
    return *this;
}

template <unsigned long long Capacity>
String<Capacity>& String<Capacity>::operator+=(const char* text) {
    this->append(text);
    return *this;
}

template <unsigned long long Capacity>
String<Capacity> String<Capacity>::operator+(const String<Capacity>& other) const {
    String<Capacity> result = *this;
    result.append(other);
    return result;
}

template <unsigned long long Capacity>
String<Capacity> String<Capacity>::operator+(const CString<Capacity>& other) const {
    String<Capacity> result = *this;
    result.append(other);
    return result;
}

template <unsigned long long Capacity>
String<Capacity> String<Capacity>::operator+(const char* text) const {
    String<Capacity> result = *this;
    result.append(text);
    return result;
}

template <unsigned long long Capacity>
Bool String<Capacity>::startsWith(const String<Capacity>& prefix) const {
    if (prefix.size().toUnsignedLongLong() > this->size().toUnsignedLongLong()) {
        return Bool(Byte(0));
    }

    for (unsigned long long i = 0; i < prefix.size().toUnsignedLongLong(); ++i) {
        UInt64 index = makeIndex(i);

        if ((this->characters[index] != prefix.characters[index]).toByte().raw() != 0) {
            return Bool(Byte(0));
        }
    }

    return Bool(Byte(1));
}

template <unsigned long long Capacity>
Bool String<Capacity>::endsWith(const String<Capacity>& suffix) const {
    unsigned long long thisLength = this->size().toUnsignedLongLong();
    unsigned long long suffixLength = suffix.size().toUnsignedLongLong();

    if (suffixLength > thisLength) {
        return Bool(Byte(0));
    }

    unsigned long long offset = thisLength - suffixLength;

    for (unsigned long long i = 0; i < suffixLength; ++i) {
        UInt64 thisIndex = makeIndex(offset + i);
        UInt64 suffixIndex = makeIndex(i);

        if ((this->characters[thisIndex] != suffix.characters[suffixIndex]).toByte().raw() != 0) {
            return Bool(Byte(0));
        }
    }

    return Bool(Byte(1));
}

template <unsigned long long Capacity>
Bool String<Capacity>::contains(const String<Capacity>& text) const {
    UInt64 foundIndex;

    return this->indexOf(text, foundIndex);
}

template <unsigned long long Capacity>
Bool String<Capacity>::indexOf(const Char& value, UInt64& outIndex) const {
    for (unsigned long long i = 0; i < this->size().toUnsignedLongLong(); ++i) {
        UInt64 index = makeIndex(i);

        if ((this->characters[index] == value).toByte().raw() != 0) {
            outIndex = index;
            return Bool(Byte(1));
        }
    }

    outIndex = makeIndex(Capacity);
    return Bool(Byte(0));
}

template <unsigned long long Capacity>
Bool String<Capacity>::indexOf(const String<Capacity>& text, UInt64& outIndex) const {
    unsigned long long thisLength = this->size().toUnsignedLongLong();
    unsigned long long textLength = text.size().toUnsignedLongLong();

    if (textLength == 0) {
        outIndex = makeIndex(0);
        return Bool(Byte(1));
    }

    if (textLength > thisLength) {
        outIndex = makeIndex(Capacity);
        return Bool(Byte(0));
    }

    for (unsigned long long start = 0; start <= thisLength - textLength; ++start) {
        Bool found = Bool(Byte(1));

        for (unsigned long long i = 0; i < textLength; ++i) {
            UInt64 thisIndex = makeIndex(start + i);
            UInt64 textIndex = makeIndex(i);

            if ((this->characters[thisIndex] != text.characters[textIndex]).toByte().raw() != 0) {
                found = Bool(Byte(0));
                break;
            }
        }

        if (found.toByte().raw() != 0) {
            outIndex = makeIndex(start);
            return Bool(Byte(1));
        }
    }

    outIndex = makeIndex(Capacity);
    return Bool(Byte(0));
}

template <unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os, const String<Capacity>& string) {
    for (unsigned long long i = 0; i < string.size().toUnsignedLongLong(); ++i) {
        UInt64 index = String<Capacity>::makeIndex(i);
        os << string[index];
    }

    return os;
}
