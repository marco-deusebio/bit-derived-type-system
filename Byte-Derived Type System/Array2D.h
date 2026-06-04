//
//  Array2D.h
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/*************************
 * Array2D<T, Rows, Cols>   *
 *************************/

#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <iosfwd>

#include "Array.h"
#include "Bool.h"
#include "UInt64.h"

template <typename T, unsigned long long Rows, unsigned long long Cols>
class Array2D {
private:
    Array<T, Rows * Cols> values;
    
public:
    Array2D();
    
    static UInt64 makeIndex(unsigned long long value);
    
    T& at(const UInt64& row, const UInt64& col);
    const T& at(const UInt64& row, const UInt64& col) const;
    
    T& operator()(const UInt64& row, const UInt64& col);
    const T& operator()(const UInt64& row, const UInt64& col) const;
    
    UInt64 rowCount() const;
    UInt64 colCount() const;
    UInt64 size() const;
    
    Bool empty() const;
    
    void fill(const T& value);
    
    Bool operator==(const Array2D<T, Rows, Cols>& other) const;
    Bool operator!=(const Array2D<T, Rows, Cols>& other) const;
};

template <typename T, unsigned long long Rows, unsigned long long Cols>
std::ostream& operator<<(std::ostream& os,
                         const Array2D<T, Rows, Cols>& array);

#include "Array2D.tpp"

#endif  // ARRAY2D_H
