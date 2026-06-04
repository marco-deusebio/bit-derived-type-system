//
//  NullPtr.tpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

/*********************
 * NullPtr (nullptr) *
 *********************/

template <typename T, unsigned long long Capacity>
Bool operator==(const Pointer<T, Capacity>& pointer, const NullPtr& nullPtr) {
    return pointer.isNull();
}

template <typename T, unsigned long long Capacity>
Bool operator==(const NullPtr& nullPtr, const Pointer<T, Capacity>& pointer) {
    return pointer.isNull();
}

template <typename T, unsigned long long Capacity>
Bool operator!=(const Pointer<T, Capacity>& pointer, const NullPtr& nullPtr) {
    return pointer.isNotNull();
}

template <typename T, unsigned long long Capacity>
Bool operator!=(const NullPtr& nullPtr, const Pointer<T, Capacity>& pointer) {
    return pointer.isNotNull();
}
