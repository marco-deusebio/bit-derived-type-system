//
//  Void.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/************
 * Void  (void)  *
 ************/

#include "Void.h"

#include <ostream>

Void::Void() {}

Bool Void::operator==(const Void& other) const {
    return Bool(Byte(1));
}

Bool Void::operator!=(const Void& other) const {
    return Bool(Byte(0));
}

std::ostream& operator<<(std::ostream& os, const Void& value) {
    os << "void";
    return os;
}
