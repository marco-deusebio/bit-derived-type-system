//
//  Void.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/************
 * Void  (void)  *
 ************/

#ifndef VOID_H
#define VOID_H

#include <iosfwd>

#include "Bool.h"

class Void {
public:
    Void();
    
    Bool operator==(const Void& other) const;
    Bool operator!=(const Void& other) const;
};

std::ostream& operator<<(std::ostream& os, const Void& value);

#endif  // VOID_H
