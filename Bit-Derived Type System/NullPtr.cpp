//
//  NullPtr.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/***************
 * NullPtr  (nullptr)  *
 ***************/

#include "NullPtr.h"

#include <ostream>

NullPtr::NullPtr()
: marker(Bool(Byte(1))) {}

Bool NullPtr::isNull() const {
    return this->marker;
}

Bool NullPtr::operator==(const NullPtr& other) const {
    return this->marker == other.marker;
}

Bool NullPtr::operator!=(const NullPtr& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const NullPtr& value) {
    os << "nullptr";
    return os;
}
