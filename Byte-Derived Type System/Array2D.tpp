//
//  Array2D.tpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/**************************
 * Array2D<T, Rows, Cols> *
 **************************/

#include <ostream>
#include <stdexcept>

template <typename T, unsigned long long Rows, unsigned long long Cols>
Array2D<T, Rows, Cols>::Array2D()
    : values() {
    static_assert(Rows > 0, "Array2D must have at least one row.");
    static_assert(Cols > 0, "Array2D must have at least one column.");
}

template <typename T, unsigned long long Rows, unsigned long long Cols>
UInt64 Array2D<T, Rows, Cols>::makeIndex(unsigned long long value) {
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

template <typename T, unsigned long long Rows, unsigned long long Cols>
T& Array2D<T, Rows, Cols>::at(const UInt64& row, const UInt64& col) {
    unsigned long long rawRow = row.toUnsignedLongLong();
    unsigned long long rawCol = col.toUnsignedLongLong();

    if (rawRow >= Rows) {
        throw std::out_of_range("Array2D row index out of range.");
    }

    if (rawCol >= Cols) {
        throw std::out_of_range("Array2D column index out of range.");
    }

    unsigned long long linearIndex = rawRow * Cols + rawCol;

    return this->values[makeIndex(linearIndex)];
}

template <typename T, unsigned long long Rows, unsigned long long Cols>
const T& Array2D<T, Rows, Cols>::at(const UInt64& row,
                                    const UInt64& col) const {
    unsigned long long rawRow = row.toUnsignedLongLong();
    unsigned long long rawCol = col.toUnsignedLongLong();

    if (rawRow >= Rows) {
        throw std::out_of_range("Array2D row index out of range.");
    }

    if (rawCol >= Cols) {
        throw std::out_of_range("Array2D column index out of range.");
    }

    unsigned long long linearIndex = rawRow * Cols + rawCol;

    return this->values[makeIndex(linearIndex)];
}

template <typename T, unsigned long long Rows, unsigned long long Cols>
T& Array2D<T, Rows, Cols>::operator()(const UInt64& row,
                                      const UInt64& col) {
    return this->at(row, col);
}

template <typename T, unsigned long long Rows, unsigned long long Cols>
const T& Array2D<T, Rows, Cols>::operator()(const UInt64& row,
                                            const UInt64& col) const {
    return this->at(row, col);
}

template <typename T, unsigned long long Rows, unsigned long long Cols>
UInt64 Array2D<T, Rows, Cols>::rowCount() const {
    return makeIndex(Rows);
}

template <typename T, unsigned long long Rows, unsigned long long Cols>
UInt64 Array2D<T, Rows, Cols>::colCount() const {
    return makeIndex(Cols);
}

template <typename T, unsigned long long Rows, unsigned long long Cols>
UInt64 Array2D<T, Rows, Cols>::size() const {
    return makeIndex(Rows * Cols);
}

template <typename T, unsigned long long Rows, unsigned long long Cols>
Bool Array2D<T, Rows, Cols>::empty() const {
    if (Rows * Cols == 0) {
        return Bool(Byte(1));
    }

    return Bool(Byte(0));
}

template <typename T, unsigned long long Rows, unsigned long long Cols>
void Array2D<T, Rows, Cols>::fill(const T& value) {
    this->values.fill(value);
}

template <typename T, unsigned long long Rows, unsigned long long Cols>
Bool Array2D<T, Rows, Cols>::operator==(
    const Array2D<T, Rows, Cols>& other) const {
    for (unsigned long long i = 0; i < Rows * Cols; ++i) {
        UInt64 index = makeIndex(i);

        if ((this->values[index] != other.values[index]).toByte().raw() != 0) {
            return Bool(Byte(0));
        }
    }

    return Bool(Byte(1));
}

template <typename T, unsigned long long Rows, unsigned long long Cols>
Bool Array2D<T, Rows, Cols>::operator!=(
    const Array2D<T, Rows, Cols>& other) const {
    return !(*this == other);
}

template <typename T, unsigned long long Rows, unsigned long long Cols>
std::ostream& operator<<(std::ostream& os,
                         const Array2D<T, Rows, Cols>& array) {
    os << "[\n";

    for (unsigned long long row = 0; row < Rows; ++row) {
        os << "  [";

        for (unsigned long long col = 0; col < Cols; ++col) {
            os << array(Array2D<T, Rows, Cols>::makeIndex(row),
                        Array2D<T, Rows, Cols>::makeIndex(col));

            if (col + 1 < Cols) {
                os << ", ";
            }
        }

        os << "]";

        if (row + 1 < Rows) {
            os << ",";
        }

        os << '\n';
    }

    os << "]";

    return os;
}
