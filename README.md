# Bit-Derived Built-In Type System (C++)

This project implements a bit-oriented, header-only type system that mirrors many built-in C/C++ primitive types and containers using custom, composable types.

---

## Overview

This project includes:

- Bitwise-friendly `Byte`
- Integer families: `UInt8`, `Int8`, `UInt16`, `Int16`, `UInt32`, `Int32`, `UInt64`, `Int64`, plus convenience aliases `UInt`, `Int`, `ULongInt`, `LongInt`, etc.
- Floating-point families: `Float32`, `Float64`, plus convenience `Float`, `Double`
- Logical `Bool`
- Character `Char`
- Fixed-capacity strings: `String<N>` and null-terminated `CString<N>`
- Fixed-size `Array<T, N>` and `Array2D<T, R, C>`
- Small-vector `Vector<T, N>`
- Memory and pointer abstractions: `Memory<T, N>`, `Pointer<T, N>`, `UniquePtr<T, N>`, `SharedMemory<T, N>`, `SharedPtr<T, N>`, `NullPtr`, `Reference<T, N>`
- `Enum` with bounded ranges
- Helpers for math, algorithms, conversions, and limits
- Streaming and I/O support for all custom types

The file `main.cpp` acts as a comprehensive test harness demonstrating usage and validating behavior of the entire type system.

---

## Project Layout

- `main.cpp`: Test framework that exercises all custom types and helpers.
- `TypeSystem.h`: Header that defines all custom types, operators, helpers, and I/O.

Note: The project is designed to be header-only for the type system; only `main.cpp` contains executable test code.

---

## Building and Running

You can build this project with any modern C++ compiler (C++17 or later recommended).

Using clang++ or g++ on the command line:

```sh
# From the project root
clang++ -std=c++17 -O2 -Wall -Wextra -pedantic main.cpp -o TypeSystemDemo
./TypeSystemDemo
```
Or, open the Xcode project/workspace and build/run the C++ Variable Types scheme.

---

## Test Harness

`main.cpp` prints labeled sections and runs through a battery of tests:

-  `Byte` bitwise operations: `&`, `|`, `^`, shifts, and stream output
-  Unsigned and signed integers (`UInt8`, `Int8`, `UInt16`, `Int16`, `UInt32`, `Int32`, `UInt64`, `Int64`) each composed of 8, 16, 32, and 64 bits: arithmetic, comparisons, increment/decrement, sign detection
- `Float` and `Double`: creation from raw IEEE-754 bytes, sign bit, infinity/NaN detection
- Logical `Bool`: logical ops, comparisons
- `Char`: ASCII conversion, classification (`isAlpha`, `isDigit`), increment
- `String<N>` and `CString<N>`: `capacity`/`size`, `push`/`pop`, `append`, comparisons, indexing, clear, termination checks
- `Array<T,N>` and `Array2D<T,R,C>`: initialization, indexing, size reporting, streaming
- `Vector<T,N>`: `push`/`pop`, equality/inequality, indexing, clear, `capacity`/`size`
- `Memory` and `Pointer` abstractions: allocate/get/set/deallocate, pointer equality, `UniquePtr` semantics (`make`/`reset`/`release`), `SharedPtr` semantics (`share`/`reset`/`useCount`/`unique`)
- `NullPtr`: comparisons and null checks
- `Reference`: binding and mutation that reflects in underlying memory
- `Void`: equality and streaming
- Type aliases (`TypeSystem`) usage: constructing with native literals and mixing helpers
- Type helpers (`TypeHelpers`) supports these factory functions: `makeBool`, `makeChar`, `makeUInt8`, `makeInt8`, `makeUInt16`, `makeInt16`, `makeUInt`, `makeInt`, `makeULongInt`, `makeLongInt`, `makeFloat`, `makeDouble`, `makeIndex`, etc.
- Type limits: `TypeLimits<T>`::`min`/`max`/`lowest`/`epsilon`/`zero`/`one`
- `Math` helpers: `absol`, `clamp`, `max`
- `Algorithms` supports helpers: `find`, `count`, `sortAscending`, `sortDescending`, `reverse`
- Conversions: `numeric` <-> `numeric`, `toByte`, `toChar`, `toBool`, `toFloat`, `toDouble`, `toInt`, `toUInt`, `toLongInt`
- String conversions and parsing (`StringConversions` and `StringParsing`): `toString<N>`, `toStdString`, `toInt(String)`, `toBool(String)`, `toDouble(String)`, `toChar(String)`, `tryToInt`
- Type I/O (`TypeIO`): formatted extraction/insertion for `Int`, `Double`, `Bool`, `Char`, `String<N>`

Each section ends with a summary line like "... tests completed" and the program finishes with:
```
********** ALL TESTS PASSED ***********
```
---

## Quick Usage Examples

### Create and use integers:
```
UInt8 u1(Byte(200));
UInt8 u2(Byte(25));
auto sum = u1 + u2; // wrapping or widening semantics as defined in TypeSystem.h
```

### Signed integers from native values:
```
Int16 a = Int16::fromSignedValue(300);
Int16 b = Int16::fromSignedValue(-50);
a += b;
```

### Floats from raw bytes (IEEE-754, little-endian):
```
Float32 one = Float32::fromBytes(Byte(0x00), Byte(0x00), Byte(0x80), Byte(0x3F));
```

### Fixed-capacity string and append:
```
String<20> first("Marco");
CString<20> tail(" Test");
first.append(tail);
```

### Vector push/pop and compare:
```
Vector<Char, 10> letters;
letters.pushBack('A');
letters.pushBack('B');
letters.popBack();
```

### Memory and smart pointers:
```
Memory<Char, 5> mem;
UniquePtr<Char, 5> up = UniquePtr<Char, 5>::make(mem, 'A');
up.set(mem, 'Z');
Pointer<Char, 5> raw = up.release();
mem.deallocate(raw);
```
---

## Requirements

- C++17 or later
- A standard library with iostream support

---

## Notes and Conventions

- Many operations rely on fixed-size Byte composition; pay attention to endianness when constructing multi-byte numbers or floating-point values from raw bytes.
- The containers (`String`, `CString`, `Array`, `Array2D`, `Vector`) are fixed-capacity by design. Check `size()`, `capacity()`, `empty()`, and `full()` to avoid overflows.
- The I/O demonstrations in `main.cpp` read from `std::cin`. When running non-interactively, you can redirect input or skip that section.

---

## Files Included

This section outlines per-type APIs, common operations, and typical complexity notes. For exact signatures and semantics, see the headers included by `TypeSystem.h`.

### Byte

- Core: `Byte(uint8_t)`, `.raw()`, `.set(uint8_t)`
- Bitwise: `~`, `&`, `|`, `^`, `<<`, `>>`
- Streaming: `operator<<`
- Complexity: All operations are O(1).


### Bool

- Core: construct from bool or Byte
- Conversion: `.toByte()`
- Logical: `!`, `&&`, `||`
- Comparisons and streaming supported
- Complexity: O(1).


### Char

- Core: construct from char or Byte
- Conversion: `.toAscii()`, `.toByte()`
- Classification: `.isAlpha()`, `.isDigit()`
- Increment: `++`
- Comparisons and streaming supported
- Complexity: O(1).


### Integer Types (fixed-width): UInt(8/16/32/64) and Int(8/16/32/64)

- Construction: from Byte components or native values (e.g., IntX::fromSignedValue)
- Arithmetic: `+`, `-`, `*`, `/`, `%`
- Increment/decrement: `++`, `--`
- Comparisons: `<`, `<=`, `>`, `>=`, `==`, `!=`
- Conversion helpers:
   - UInt8:`.toInt()`
   - Int8: `.toInt()`
   - UInt16: `.toUnsignedInt()`
   - Int16: `.toInt()`
   - UInt32: `.toUnsignedLongLong()`
   - Int32: `.toLongLong()`
   - UInt64: `.toUnsignedLongLong()`
   - Int64: `.toLongLong()`
- Complexity: O(1) for arithmetic/comparisons.


### Float32 / Float64

- Construction from raw IEEE-754 bytes: `Float32::fromBytes(b0,b1,b2,b3)`, `Float64::fromBytes(b0..b7)`
- Introspection: `.signBit()`, `.isInfinity()`, `.isNaN()`
- Conversion: `.toFloat()` / `.toDouble()`
- Comparisons and streaming supported
- Complexity: O(1).

Bit layout (conceptual):
```
Float32:  [sign:1][exponent:8][fraction:23]
Float64:  [sign:1][exponent:11][fraction:52]
```
Little-endian byte ordering is used when constructing from bytes in `main.cpp`.


### String<N>

- Construction: from C string literal (`const char*`)
- Capacity/size: `.capacity()`, `.size()`, `.empty()`, `.full()`
- Mutation: `.pushBack(Char)`, `.popBack()`, `.append(String)`, `.append(CString)`
- Indexing: `operator[]` with `String<N>::makeIndex(i)`
- Housekeeping: `.clear()`
- Comparisons and streaming supported
- Complexity: `pushBack`/`popBack` O(1) until `capacity`; `append` O(m); comparisons O(n).


### CString<N>

- Similar to `String<N>` but null-terminated semantics
- Additional: `.isTerminated()`
- Complexity: like `String<N>`; termination checks O(1).


### Array<T, N>

- Fixed-size container
- Access: `operator[]` with `String<N>::makeIndex(i)` style index
- Introspection: `.size()`
- Streaming supported
- Complexity: indexing O(1).


### Array2D<T, R, C>

- 2D fixed-size container
- Access: `operator()(rowIndex, colIndex)` using `Array2D<...>::makeIndex(i)` for each dimension
- Introspection: `.rowCount()`, `.colCount()`, `.size()`
- Streaming supported
- Complexity: indexing O(1).

Row-major mapping (conceptual):
```
linearIndex = row * C + col
```

### Vector<T, Capacity>

- Capacity/size: `.capacity()`, `.size()`, `.empty()`, `.full()`, `.clear()`
- Index helpers: `static makeIndex(ull)`
- Element ops: `.pushBack`, `.popBack`, `.insertAt`, `.removeAt`, `.set`
- Access: `.at`, `operator[]`, `.front`, `.back`
- Search: `.contains`, `.indexOf`
- Equality: `operator==`, `operator!=`
- Streaming supported
- Complexity: `pushBack`/`popBack`/`front`/`back` O(1); `insertAt`/`removeAt` O(n); `contains`/`indexOf` O(n).

Layout (conceptual):
```
[0][1][2] ... [size-1] [unused ... capacity-1]
```

### Memory<T, N> and Pointer<T, N>

- Memory introspection: `.empty()`, `.full()`
- Allocation: `.allocate(value)` → `Pointer`
- Access: `.get(Pointer)`, `.set(Pointer, value)`
- Lifetime: `.deallocate(Pointer)`, `.contains(Pointer)`
- Streaming supported for memory and pointer
- Pointer helpers: `.isNull()`, `.isNotNull()`, equality/inequality
- Complexity: allocation/deallocation may scan for free slots → O(N) worst case; get/set O(1).

Visualization:
```
Memory slots: [0] [1] [2] [3] [4]
Pointers:      ^A  ^B  ^C
```

### UniquePtr<T, N>

- Factory: `UniquePtr::make(memory, value)`
- Access/mutation: `.get(memory)`, `.set(memory, value)`
- Reset/release: `.reset(memory, newValue)`, `.release()` → raw `Pointer`
- Null state: `.isNull()`
- Complexity: O(1) operations; underlying memory actions as above.


### SharedMemory<T, N> and SharedPtr<T, N>

- Factory: `SharedPtr::make(sharedMemory, value)`
- Sharing: `.share(sharedMemory)`
- Access/mutation: `.get(sharedMemory)`, `.set(sharedMemory, value)`
- Lifetime: `.reset(sharedMemory)`
- Ref counting: `.useCount(sharedMemory)`, `.unique(sharedMemory)`
- Complexity: O(1) for ref-count changes and access.

Ref-count concept:
```
[object] <— count: 2
   ^               ^
sharedA         sharedB
```

### Reference<T, N>

- Bind: `Reference::bind(Pointer)`
- Access/mutation: `.get(memory)`, `.set(memory, value)`
- Equality/inequality supported
- Complexity: O(1).


### Enum

- Construction: `Enum::fromRange(value, min, max)`
- Increment/decrement: prefix and postfix `++`/`--` within bounds
- Assignment within range: `.setValue(Int32)` returns success Bool
- Range compatibility: `.sameRange(other)`
- Equality/inequality supported
- Complexity: O(1).


### TypeLimits<T>

- Numeric bounds: `.min()`, `.max()`
- Floating-point extras: `.lowest()`, `.epsilon()`
- Constants: `.zero()`, `.one()`
- Complexity: O(1).


### Helpers Overview

- Type helpers (factory functions): `makeBool`, `makeChar`, `makeUInt8`, `makeInt8`, `makeUInt16`, `makeInt16`, `makeUInt`, `makeInt`, `makeULong`, `makeLong`, `makeFloat`, `makeDouble`, `makeIndex`
- Math: `absol`, `clamp`, `max`
- Algorithms: `find`, `count`, `sortAscending`, `sortDescending`, `reverse` (typical complexities: find/count O(n), Sort* depends on implementation; see `Algorithms.h`)
- Conversions: `toDouble`, `toInt`, `toLongInt`, `toUInt`, `toByte`, `toChar`, `toBool`, `toFloat`
- String conversions: `toString<N>(value)`, `toStdString(String)`, `toStdString(CString)`
- String parsing: `toInt`, `tryToInt`, `toBool`, `tryToBool`, `toDouble`, `tryToDouble`, `toChar`, `tryToChar` for custom `String`/`CString` and `std::string`
- Type I/O: stream insertion/extraction for core types (`Int`, `Double`, `Bool`, `Char`, `String<N>`, `CString<N>`, etc.)

---

## License

MIT-licensed for educational/demo purposes.
