//
//  UniquePtr.tpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/**************************
 * UniquePtr<T, Capacity> *
 **************************/

#include <ostream>

template <typename T, unsigned long long Capacity>
UniquePtr<T, Capacity>::UniquePtr()
    : pointer(Pointer<T, Capacity>::null()) {}

template <typename T, unsigned long long Capacity>
UniquePtr<T, Capacity>::UniquePtr(const Pointer<T, Capacity>& pointerValue)
    : pointer(pointerValue) {}

template <typename T, unsigned long long Capacity>
UniquePtr<T, Capacity>::UniquePtr(UniquePtr<T, Capacity>&& other) noexcept
    : pointer(other.pointer) {
    other.pointer = Pointer<T, Capacity>::null();
}

template <typename T, unsigned long long Capacity>
UniquePtr<T, Capacity>& UniquePtr<T, Capacity>::operator=(
    UniquePtr<T, Capacity>&& other) noexcept {
    if (this != &other) {
        this->pointer = other.pointer;
        other.pointer = Pointer<T, Capacity>::null();
    }

    return *this;
}

template <typename T, unsigned long long Capacity>
UniquePtr<T, Capacity> UniquePtr<T, Capacity>::make(
    Memory<T, Capacity>& memory,
    const T& value) {
    return UniquePtr<T, Capacity>(memory.allocate(value));
}

template <typename T, unsigned long long Capacity>
Pointer<T, Capacity> UniquePtr<T, Capacity>::getPointer() const {
    return this->pointer;
}

template <typename T, unsigned long long Capacity>
Bool UniquePtr<T, Capacity>::isNull() const {
    return this->pointer.isNull();
}

template <typename T, unsigned long long Capacity>
Bool UniquePtr<T, Capacity>::isNotNull() const {
    return this->pointer.isNotNull();
}

template <typename T, unsigned long long Capacity>
T& UniquePtr<T, Capacity>::get(Memory<T, Capacity>& memory) {
    return memory.get(this->pointer);
}

template <typename T, unsigned long long Capacity>
const T& UniquePtr<T, Capacity>::get(const Memory<T, Capacity>& memory) const {
    return memory.get(this->pointer);
}

template <typename T, unsigned long long Capacity>
Bool UniquePtr<T, Capacity>::set(Memory<T, Capacity>& memory, const T& value) {
    return memory.set(this->pointer, value);
}

template <typename T, unsigned long long Capacity>
Bool UniquePtr<T, Capacity>::reset(Memory<T, Capacity>& memory) {
    if (this->pointer.isNull().toByte().raw() != 0) {
        return Bool(Byte(0));
    }

    Bool result = memory.deallocate(this->pointer);
    this->pointer = Pointer<T, Capacity>::null();

    return result;
}

template <typename T, unsigned long long Capacity>
Bool UniquePtr<T, Capacity>::reset(Memory<T, Capacity>& memory,
                                   const T& value) {
    this->reset(memory);

    this->pointer = memory.allocate(value);

    return this->pointer.isNotNull();
}

template <typename T, unsigned long long Capacity>
Pointer<T, Capacity> UniquePtr<T, Capacity>::release() {
    Pointer<T, Capacity> oldPointer = this->pointer;
    this->pointer = Pointer<T, Capacity>::null();

    return oldPointer;
}

template <typename T, unsigned long long Capacity>
Bool UniquePtr<T, Capacity>::operator==(
    const UniquePtr<T, Capacity>& other) const {
    return this->pointer == other.pointer;
}

template <typename T, unsigned long long Capacity>
Bool UniquePtr<T, Capacity>::operator!=(
    const UniquePtr<T, Capacity>& other) const {
    return !(*this == other);
}

template <typename T, unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os,
                         const UniquePtr<T, Capacity>& uniquePtr) {
    os << "UniquePtr(" << uniquePtr.getPointer() << ")";
    return os;
}
