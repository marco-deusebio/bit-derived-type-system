//
//  Char.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/****************
 * Char  (from Byte)  *
 ****************/

#include "Char.h"
#include "Bool.h"

#include <ostream>

Char::Char(const Byte& byte)
    : value(byte) {}

Char::Char(char c)
    : value(Byte(static_cast<std::uint8_t>(c))) {}

Char::operator Byte() const {
    return this->value;
}

Byte Char::toByte() const {
    return this->value;
}

int Char::toAscii() const {
    return static_cast<int>(this->value.raw());
}

void Char::set(const Byte& byte) {
    this->value = byte;
}

void Char::set(char c) {
    this->value = Byte(static_cast<std::uint8_t>(c));
}

Bool Char::isAlpha() const {
    int ascii = this->toAscii();
    
    if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122)) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Bool Char::isDigit() const {
    int ascii = this->toAscii();
    
    if (ascii >= 48 && ascii <= 57) {
        return Bool(Byte(1));
    }
    
    return Bool(Byte(0));
}

Char& Char::operator++() {
    this->value.set(static_cast<std::uint8_t>(this->value.raw() + 1));
    return *this;
}

Char Char::operator++(int) {
    Char oldValue = *this;
    ++(*this);
    return oldValue;
}

Char& Char::operator--() {
    this->value.set(static_cast<std::uint8_t>(this->value.raw() - 1));
    return *this;
}

Char Char::operator--(int) {
    Char oldValue = *this;
    --(*this);
    return oldValue;
}

Bool Char::operator==(const Char& other) const {
    return Bool(Byte(this->value.raw() == other.value.raw()));
}

Bool Char::operator!=(const Char& other) const {
    return Bool(Byte(this->value.raw() != other.value.raw()));
}

Bool Char::operator<(const Char& other) const {
    return Bool(Byte(this->value.raw() < other.value.raw()));
}

Bool Char::operator>(const Char& other) const {
    return Bool(Byte(this->value.raw() > other.value.raw()));
}

Bool Char::operator<=(const Char& other) const {
    return Bool(Byte(this->value.raw() <= other.value.raw()));
}

Bool Char::operator>=(const Char& other) const {
    return Bool(Byte(this->value.raw() >= other.value.raw()));
}

std::ostream& operator<<(std::ostream& os, const Char& value) {
    os << static_cast<char>(value.toByte().raw());
    return os;
}
