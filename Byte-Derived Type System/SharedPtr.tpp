//
//  SharedPtr.tpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/**************************
 * SharedPtr<T, Capacity> *
 **************************/

#include <ostream>

template <typename T, unsigned long long Capacity>
SharedPtr<T, Capacity>::SharedPtr()
    : pointer(Pointer<T, Capacity>::null()) {}

template <typename T, unsigned long long Capacity>
SharedPtr<T, Capacity>::SharedPtr(const Pointer<T, Capacity>& pointerValue)
    : pointer(pointerValue) {}

template <typename T, unsigned long long Capacity>
SharedPtr<T, Capacity>::SharedPtr(SharedPtr<T, Capacity>&& other) noexcept
    : pointer(other.pointer) {
    other.pointer = Pointer<T, Capacity>::null();
}

template <typename T, unsigned long long Capacity>
SharedPtr<T, Capacity>& SharedPtr<T, Capacity>::operator=(
    SharedPtr<T, Capacity>&& other) noexcept {
    if (this != &other) {
        this->pointer = other.pointer;
        other.pointer = Pointer<T, Capacity>::null();
    }

    return *this;
}

template <typename T, unsigned long long Capacity>
SharedPtr<T, Capacity> SharedPtr<T, Capacity>::make(
    SharedMemory<T, Capacity>& memory,
    const T& value) {
    return SharedPtr<T, Capacity>(memory.allocate(value));
}

template <typename T, unsigned long long Capacity>
SharedPtr<T, Capacity> SharedPtr<T, Capacity>::share(
    SharedMemory<T, Capacity>& memory) const {
    if (memory.acquire(this->pointer).toByte().raw() == 0) {
        return SharedPtr<T, Capacity>();
    }

    return SharedPtr<T, Capacity>(this->pointer);
}

template <typename T, unsigned long long Capacity>
Pointer<T, Capacity> SharedPtr<T, Capacity>::getPointer() const {
    return this->pointer;
}

template <typename T, unsigned long long Capacity>
UInt64 SharedPtr<T, Capacity>::useCount(
    const SharedMemory<T, Capacity>& memory) const {
    return memory.useCount(this->pointer);
}

template <typename T, unsigned long long Capacity>
Bool SharedPtr<T, Capacity>::unique(
    const SharedMemory<T, Capacity>& memory) const {
    if (this->useCount(memory).toUnsignedLongLong() == 1) {
        return Bool(Byte(1));
    }

    return Bool(Byte(0));
}

template <typename T, unsigned long long Capacity>
Bool SharedPtr<T, Capacity>::isNull() const {
    return this->pointer.isNull();
}

template <typename T, unsigned long long Capacity>
Bool SharedPtr<T, Capacity>::isNotNull() const {
    return this->pointer.isNotNull();
}

template <typename T, unsigned long long Capacity>
T& SharedPtr<T, Capacity>::get(SharedMemory<T, Capacity>& memory) {
    return memory.get(this->pointer);
}

template <typename T, unsigned long long Capacity>
const T& SharedPtr<T, Capacity>::get(
    const SharedMemory<T, Capacity>& memory) const {
    return memory.get(this->pointer);
}

template <typename T, unsigned long long Capacity>
Bool SharedPtr<T, Capacity>::set(SharedMemory<T, Capacity>& memory,
                                 const T& value) {
    return memory.set(this->pointer, value);
}

template <typename T, unsigned long long Capacity>
Bool SharedPtr<T, Capacity>::reset(SharedMemory<T, Capacity>& memory) {
    if (this->pointer.isNull().toByte().raw() != 0) {
        return Bool(Byte(0));
    }

    Bool result = memory.release(this->pointer);
    this->pointer = Pointer<T, Capacity>::null();

    return result;
}

template <typename T, unsigned long long Capacity>
Bool SharedPtr<T, Capacity>::operator==(
    const SharedPtr<T, Capacity>& other) const {
    return this->pointer == other.pointer;
}

template <typename T, unsigned long long Capacity>
Bool SharedPtr<T, Capacity>::operator!=(
    const SharedPtr<T, Capacity>& other) const {
    return !(*this == other);
}

template <typename T, unsigned long long Capacity>
std::ostream& operator<<(std::ostream& os,
                         const SharedPtr<T, Capacity>& sharedPtr) {
    os << "SharedPtr(" << sharedPtr.getPointer() << ")";
    return os;
}
