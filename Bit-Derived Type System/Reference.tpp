//
//  Reference.tpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/**************************
 * Reference<T, Capacity> *
 **************************/

#include <ostream>
#include <stdexcept>

template <typename T, unsigned long long Capacity>
Reference<T, Capacity>::Reference(const Pointer<T, Capacity>& pointerValue)
    : pointer(pointerValue) {
    if (this->pointer.isNull().toByte().raw() != 0) {
        throw std::invalid_argument("Reference cannot bind to null Pointer.");
    }
}

template <typename T, unsigned long long Capacity>
Reference<T, Capacity> Reference<T, Capacity>::bind(
    const Pointer<T, Capacity>& pointerValue) {
    return Reference<T, Capacity>(pointerValue);
}

template <typename T, unsigned long long Capacity>
Pointer<T, Capacity> Reference<T, Capacity>::getPointer() const {
    return this->pointer;
}

template <typename T, unsigned long long Capacity>
T& Reference<T, Capacity>::get(Memory<T, Capacity>& memory) {
    return memory.get(this->pointer);
}

template <typename T, unsigned long long Capacity>
const T& Reference<T, Capacity>::get(const Memory<T, Capacity>& memory) const {
    return memory.get(this->pointer);
}

template <typename T, unsigned long long Capacity>
Bool Reference<T, Capacity>::set(Memory<T, Capacity>& memory, const T& value) {
    return memory.set(this->pointer, value);
}

template <typename T, unsigned long long Capacity>
Bool Reference<T, Capacity>::operator==(
    const Reference<T, Capacity>& other) const {
    return this->pointer == other.pointer;
}

template <typename T, unsigned long long Capacity>
Bool Reference<T, Capacity>::operator!=(
    const Reference<T, Capacity>& other) const {
    return !(*this == other);
}

template <typename T, unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os,
                         const Reference<T, Capacity>& reference) {
    os << "Reference(" << reference.getPointer() << ")";
    return os;
}
