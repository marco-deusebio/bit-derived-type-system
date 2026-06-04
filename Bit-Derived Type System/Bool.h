//
//  Bool.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/****************
 * Bool  (from Byte)  *
 ****************/

#ifndef BOOL_H
#define BOOL_H

#include <iosfwd>

#include "Byte.h"

class Bool {
private:
    Byte value;
    
    static Byte normalize(const Byte& byte);
    
public:
    Bool(const Byte& byte = Byte(0));
    Bool(bool v);

    operator Byte() const;
    explicit operator bool() const;
    
    Byte toByte() const;
    int toInt() const;
    
    void set(const Byte& byte);
    void set(bool v);

    Bool operator!() const;
    
    Bool operator&&(const Bool& other) const;
    Bool operator||(const Bool& other) const;
    
    Bool operator==(const Bool& other) const;
    Bool operator!=(const Bool& other) const;
};

std::ostream& operator<<(std::ostream& os, const Bool& value);

#endif  // BOOL_H
