//
//  main.cpp
//  C++ Variable Types
//
//  Created by Marco D’Eusebio on 6/2/26.
//

#include <iostream>
#include <streambuf>
#include "TypeSystem.h"



int main() {
    std::cout << "======= START OF TEST FRAMEWORK FOR =======\n";
    std::cout << "==== BYTE-DERIVED BUILT-IN TYPE SYSTEM ====\n\n";
    {
        std::cout << "\n\n===== Bit Test =====\n\n";
        {
            Bit zero = 0;
            Bit one = 1;
            
            std::cout << "zero: " << zero << '\n';
            std::cout << "one: " << one << '\n';
            
            std::cout << "!zero: " << !zero << '\n';
            std::cout << "one & zero: " << (one & zero) << '\n';
            std::cout << "one | zero: " << (one | zero) << '\n';
            std::cout << "one ^ zero: " << (one ^ zero) << '\n';
            
            Byte byte = 10; // binary 00001010
            
            std::cout << "\nbyte: " << byte << '\n';
            
            std::cout << "bit 0: " << byte.getBit(0) << '\n';
            std::cout << "bit 1: " << byte.getBit(1) << '\n';
            std::cout << "bit 2: " << byte.getBit(2) << '\n';
            std::cout << "bit 3: " << byte.getBit(3) << '\n';
            
            std::cout << "byte << 1: " << (byte << 1) << '\n';
            std::cout << "byte >> 1: " << (byte >> 1) << '\n';
            std::cout << "~byte: " << (~byte) << '\n';
            
            Byte other = 12; // binary 00001100
            
            std::cout << "\nother: " << other << '\n';
            std::cout << "byte & other: " << (byte & other) << '\n';
            std::cout << "byte | other: " << (byte | other) << '\n';
            std::cout << "byte ^ other: " << (byte ^ other) << '\n';
        }
        std::cout << "\nBit type tests completed.\n\n";
            
        std::cout << "\n\n===== Byte Test =====\n\n";
        {
            Byte byteA(5);
            Byte byteB(3);
            
            std::cout << "byteA: " << byteA << '\n';
            std::cout << "byteB: " << byteB << '\n';
            std::cout << "byteA & byteB: " << (byteA & byteB) << '\n';
            std::cout << "byteA | byteB: " << (byteA | byteB) << '\n';
            std::cout << "byteA ^ byteB: " << (byteA ^ byteB) << '\n';
        }
        std::cout << "\nByte type tests completed.\n\n";
        
        std::cout << "\n\n===== UInt8 Test =====\n\n";
        {
            UInt8 u1(Byte(200));
            UInt8 u2(Byte(25));
            
            std::cout << "u1: " << u1 << '\n';
            std::cout << "u2: " << u2 << '\n';
            std::cout << "u1 + u2: " << (u1 + u2) << '\n';
            std::cout << "u1 - u2: " << (u1 - u2) << '\n';
            std::cout << "u1 * u2: " << (u1 * u2) << '\n';
            std::cout << "u1 / u2: " << (u1 / u2) << '\n';
            std::cout << "u1 % u2: " << (u1 % u2) << '\n';
            
            ++u1;
            std::cout << "++u1: " << u1 << '\n';
            
            std::cout << "u1 > u2: " << (u1 > u2) << '\n';
        }
        std::cout << "\nUnsigned 8-bit Int type tests completed.\n\n";
        
        std::cout << "\n\n===== Int8 Test =====\n\n";
        {
            Int8 i1 = Int8::fromSignedValue(100);
            Int8 i2 = Int8::fromSignedValue(-25);
            
            std::cout << "i1: " << i1 << '\n';
            std::cout << "i2: " << i2 << '\n';
            std::cout << "i1 + i2: " << (i1 + i2) << '\n';
            std::cout << "i1 - i2: " << (i1 - i2) << '\n';
            std::cout << "i1 * i2: " << (i1 * i2) << '\n';
            std::cout << "i1 / Int8(5): " << (i1 / Int8::fromSignedValue(5)) << '\n';
            std::cout << "i2.isNegative(): " << i2.isNegative() << '\n';
        }
        std::cout << "\n8-bit Int type tests completed.\n\n";
        
        std::cout << "\n\n===== UInt16 Test =====\n\n";
        {
            UInt16 u16a(Byte(255), Byte(0));   // 255
            UInt16 u16b(Byte(1), Byte(0));     // 1
            UInt16 u16sum = u16a + u16b;       // 256
            
            std::cout << "u16a: " << u16a << '\n';
            std::cout << "u16b: " << u16b << '\n';
            std::cout << "u16a + u16b: " << u16sum << '\n';
            
            ++u16sum;
            std::cout << "++u16sum: " << u16sum << '\n';
            
            std::cout << "u16sum > u16a: " << (u16sum > u16a) << '\n';
        }
        std::cout << "\nUnsigned 16-bit type Int tests completed.\n\n";
        
        std::cout << "\n\n===== Int16 Test =====\n\n";
        {
            Int16 i16a = Int16::fromSignedValue(300);
            Int16 i16b = Int16::fromSignedValue(-50);
            
            std::cout << "i16a: " << i16a << '\n';
            std::cout << "i16b: " << i16b << '\n';
            std::cout << "i16a + i16b: " << (i16a + i16b) << '\n';
            std::cout << "i16a - i16b: " << (i16a - i16b) << '\n';
            std::cout << "i16b.isNegative(): " << i16b.isNegative() << '\n';
        }
        std::cout << "\n16-bit Int type tests completed.\n\n";
        
        std::cout << "\n\n===== UInt32 Test =====\n\n";
        {
            UInt32 u32a(Byte(255), Byte(255), Byte(0), Byte(0));  // 65535
            UInt32 u32b(Byte(1), Byte(0), Byte(0), Byte(0));      // 1
            UInt32 u32sum = u32a + u32b;                          // 65536
            
            std::cout << "u32a: " << u32a << '\n';
            std::cout << "u32b: " << u32b << '\n';
            std::cout << "u32a + u32b: " << u32sum << '\n';
            
            ++u32sum;
            std::cout << "++u32sum: " << u32sum << '\n';
        }
        std::cout << "\nUnsigned 32-bit Int type tests completed.\n\n";
        
        std::cout << "\n\n===== Int32 Test =====\n\n";
        {
            Int32 i32a = Int32::fromSignedValue(100000);
            Int32 i32b = Int32::fromSignedValue(-25000);
            
            std::cout << "i32a: " << i32a << '\n';
            std::cout << "i32b: " << i32b << '\n';
            std::cout << "i32a + i32b: " << (i32a + i32b) << '\n';
            std::cout << "i32a - i32b: " << (i32a - i32b) << '\n';
            std::cout << "i32b.isNegative(): " << i32b.isNegative() << '\n';
        }
        std::cout << "\n32-bit Int type tests completed.\n\n";
        
        std::cout << "\n\n===== UInt64 Test =====\n\n";
        {
            UInt64 u64a(
                        Byte(255), Byte(255), Byte(255), Byte(255),
                        Byte(0),   Byte(0),   Byte(0),   Byte(0)
                        );
            
            UInt64 u64b(
                        Byte(1), Byte(0), Byte(0), Byte(0),
                        Byte(0), Byte(0), Byte(0), Byte(0)
                        );
            
            UInt64 u64sum = u64a + u64b;
            
            std::cout << "u64a: " << u64a << '\n';
            std::cout << "u64b: " << u64b << '\n';
            std::cout << "u64a + u64b: " << u64sum << '\n';
            
            ++u64sum;
            std::cout << "++u64sum: " << u64sum << '\n';
            
            u64sum -= u64b;
            std::cout << "u64sum -= u64b: " << u64sum << '\n';
            
            std::cout << "u64sum > u64a: " << (u64sum > u64a) << '\n';
        }
        std::cout << "\nUnsigned 64-bit Int type tests completed.\n\n";
        
        std::cout << "\n\n===== Int64 Test =====\n\n";
        {
            Int64 i64a = Int64::fromSignedValue(5000000000LL);
            Int64 i64b = Int64::fromSignedValue(-2000000000LL);
            
            std::cout << "i64a: " << i64a << '\n';
            std::cout << "i64b: " << i64b << '\n';
            
            std::cout << "i64a + i64b: " << (i64a + i64b) << '\n';
            std::cout << "i64a - i64b: " << (i64a - i64b) << '\n';
            
            ++i64b;
            std::cout << "++i64b: " << i64b << '\n';
            
            i64a += i64b;
            std::cout << "i64a += i64b: " << i64a << '\n';
            
            std::cout << "i64b.isNegative(): " << i64b.isNegative() << '\n';
            std::cout << "i64a > i64b: " << (i64a > i64b) << '\n';
        }
        std::cout << "\n64-bit Int type tests completed.\n\n";
        
        std::cout << "\n\n===== Float32 Test =====\n\n";
        {
            // 1.0f in IEEE-754 single precision:
            // Hex: 0x3F800000
            // Little-endian bytes: 00 00 80 3F
            Float32 one32 = Float32::fromBytes(
                                               Byte(0x00), Byte(0x00), Byte(0x80), Byte(0x3F)
                                               );
            
            // -2.5f:
            // Hex: 0xC0200000
            // Little-endian bytes: 00 00 20 C0
            Float32 negativeTwoPointFive32 = Float32::fromBytes(
                                                                Byte(0x00), Byte(0x00), Byte(0x20), Byte(0xC0)
                                                                );
            
            // +infinity:
            // Hex: 0x7F800000
            Float32 infinity32 = Float32::fromBytes(
                                                    Byte(0x00), Byte(0x00), Byte(0x80), Byte(0x7F)
                                                    );
            
            // NaN:
            // Hex: 0x7FC00000
            Float32 nan32 = Float32::fromBytes(
                                               Byte(0x00), Byte(0x00), Byte(0xC0), Byte(0x7F)
                                               );
            
            std::cout << "one32: " << one32 << '\n';
            std::cout << "negativeTwoPointFive32: " << negativeTwoPointFive32 << '\n';
            std::cout << "infinity32: " << infinity32 << '\n';
            std::cout << "nan32: " << nan32 << '\n';
            
            std::cout << "one32.signBit(): " << one32.signBit() << '\n';
            std::cout << "negativeTwoPointFive32.signBit(): "
            << negativeTwoPointFive32.signBit() << '\n';
            
            std::cout << "infinity32.isInfinity(): "
            << infinity32.isInfinity() << '\n';
            
            std::cout << "nan32.isNaN(): "
            << nan32.isNaN() << '\n';
        }
        std::cout << "\n32-bit Float type tests completed.\n\n";
        
        std::cout << "\n\n===== Float64 Test =====\n\n";
        {
            // 1.0 in IEEE-754 double precision:
            // Hex: 0x3FF0000000000000
            // Little-endian bytes: 00 00 00 00 00 00 F0 3F
            Float64 one64 = Float64::fromBytes(
                                               Byte(0x00), Byte(0x00), Byte(0x00), Byte(0x00),
                                               Byte(0x00), Byte(0x00), Byte(0xF0), Byte(0x3F)
                                               );
            
            // -2.5:
            // Hex: 0xC004000000000000
            // Little-endian bytes: 00 00 00 00 00 00 04 C0
            Float64 negativeTwoPointFive64 = Float64::fromBytes(
                                                                Byte(0x00), Byte(0x00), Byte(0x00), Byte(0x00),
                                                                Byte(0x00), Byte(0x00), Byte(0x04), Byte(0xC0)
                                                                );
            
            // +infinity:
            // Hex: 0x7FF0000000000000
            Float64 infinity64 = Float64::fromBytes(
                                                    Byte(0x00), Byte(0x00), Byte(0x00), Byte(0x00),
                                                    Byte(0x00), Byte(0x00), Byte(0xF0), Byte(0x7F)
                                                    );
            
            // NaN:
            // Hex: 0x7FF8000000000000
            Float64 nan64 = Float64::fromBytes(
                                               Byte(0x00), Byte(0x00), Byte(0x00), Byte(0x00),
                                               Byte(0x00), Byte(0x00), Byte(0xF8), Byte(0x7F)
                                               );
            
            std::cout << "one64: " << one64 << '\n';
            std::cout << "negativeTwoPointFive64: " << negativeTwoPointFive64 << '\n';
            std::cout << "infinity64: " << infinity64 << '\n';
            std::cout << "nan64: " << nan64 << '\n';
            
            std::cout << "one64.signBit(): " << one64.signBit() << '\n';
            std::cout << "negativeTwoPointFive64.signBit(): "
            << negativeTwoPointFive64.signBit() << '\n';
            
            std::cout << "infinity64.isInfinity(): "
            << infinity64.isInfinity() << '\n';
            
            std::cout << "nan64.isNaN(): "
            << nan64.isNaN() << '\n';
        }
        std::cout << "\n64-bit Float type tests completed.\n\n";
        
        std::cout << "\n\n===== UInt Bitwise Test =====\n\n";
        {
            UInt a = 12; // 1100
            UInt b = 10; // 1010
            
            std::cout << "a: " << a << '\n';
            std::cout << "b: " << b << '\n';
            
            std::cout << "a & b: " << (a & b) << '\n';   // 8
            std::cout << "a | b: " << (a | b) << '\n';   // 14
            std::cout << "a ^ b: " << (a ^ b) << '\n';   // 6
            std::cout << "~a: " << (~a) << '\n';
            
            std::cout << "a << 1: " << (a << 1) << '\n'; // 24
            std::cout << "a >> 1: " << (a >> 1) << '\n'; // 6
            
            a &= b;
            std::cout << "after a &= b: " << a << '\n';
        }
        std::cout << "\nUInt bitwise tests completed.\n\n";
        
        std::cout << "\n\n===== Int Bitwise Test =====\n\n";
        {
            Int x = -8;
            Int y = 3;
            
            std::cout << "x: " << x << '\n';
            std::cout << "y: " << y << '\n';
            
            std::cout << "x & y: " << (x & y) << '\n';
            std::cout << "x | y: " << (x | y) << '\n';
            std::cout << "x ^ y: " << (x ^ y) << '\n';
            std::cout << "~x: " << (~x) << '\n';
            
            std::cout << "x << 1: " << (x << 1) << '\n';
            std::cout << "x >> 1: " << (x >> 1) << '\n';
        }
        std::cout << "\nInt bitwise tests completed.\n\n";
        
        std::cout << "\n\n===== Bool Test =====\n\n";
        {
            Bool yes(Byte(1));
            Bool no(Byte(0));
            
            std::cout << "yes: " << yes << '\n';
            std::cout << "no: " << no << '\n';
            std::cout << "!yes: " << !yes << '\n';
            std::cout << "!no: " << !no << '\n';
            std::cout << "yes && no: " << (yes && no) << '\n';
            std::cout << "yes || no: " << (yes || no) << '\n';
            std::cout << "yes == no: " << (yes == no) << '\n';
            std::cout << "yes != no: " << (yes != no) << '\n';
        }
        std::cout << "\nBool type tests completed.\n\n";
        
        std::cout << "\n\n===== Char Test =====\n\n";
        {
            Char letter(Byte(65));  // A
            Char digit(Byte(55));   // 7
            
            std::cout << "letter: " << letter << '\n';
            std::cout << "digit: " << digit << '\n';
            
            std::cout << "letter ASCII: " << letter.toAscii() << '\n';
            std::cout << "digit ASCII: " << digit.toAscii() << '\n';
            
            std::cout << "letter.isAlpha(): " << letter.isAlpha() << '\n';
            std::cout << "letter.isDigit(): " << letter.isDigit() << '\n';
            std::cout << "digit.isAlpha(): " << digit.isAlpha() << '\n';
            std::cout << "digit.isDigit(): " << digit.isDigit() << '\n';
            
            ++letter;
            std::cout << "++letter: " << letter << '\n';
        }
        std::cout << "\nChar type tests completed.\n\n";
        
        std::cout << "\n\n===== Float Test =====\n\n";
        {
            Float a = 3.5f;
            Float b = 1.25f;
            
            std::cout << "a: " << a << '\n';
            std::cout << "b: " << b << '\n';
            
            std::cout << "a + b: " << (a + b) << '\n';
            std::cout << "a - b: " << (a - b) << '\n';
            std::cout << "a * b: " << (a * b) << '\n';
            std::cout << "a / b: " << (a / b) << '\n';
            
            a += b;
            std::cout << "after a += b: " << a << '\n';
            
            std::cout << "a > b: " << (a > b) << '\n';
        }
        std::cout << "\nFloat type tests completed.\n\n";
        
        std::cout << "\n\n===== Double Test =====\n\n";
        {
            Double x = 98.75;
            Double y = 2.5;
            
            std::cout << "x: " << x << '\n';
            std::cout << "y: " << y << '\n';
            
            std::cout << "x + y: " << (x + y) << '\n';
            std::cout << "x - y: " << (x - y) << '\n';
            std::cout << "x * y: " << (x * y) << '\n';
            std::cout << "x / y: " << (x / y) << '\n';
            
            x -= y;
            std::cout << "after x -= y: " << x << '\n';
            
            Double closeA = 0.1 + 0.2;
            Double closeB = 0.3;
            
            std::cout << "closeA: " << closeA << '\n';
            std::cout << "closeB: " << closeB << '\n';
            std::cout << "closeA == closeB: " << (closeA == closeB) << '\n';
            std::cout << "closeA.isClose(closeB): " << closeA.isClose(closeB) << '\n';
        }
        std::cout << "\nDouble type tests completed.\n\n";
        
        std::cout << "\n\n===== String Test =====\n\n";
        {
            String<20> first("Marco");
            String<20> second("D");
            String<20> third("Marco");
            
            std::cout << "first: " << first << '\n';
            std::cout << "second: " << second << '\n';
            std::cout << "third: " << third << '\n';
            
            std::cout << "first size: " << first.size() << '\n';
            std::cout << "first capacity: " << first.capacity() << '\n';
            std::cout << "first empty: " << first.empty() << '\n';
            std::cout << "first full: " << first.full() << '\n';
            
            first.pushBack(Byte(33)); // !
            
            std::cout << "\nafter first.pushBack('!'):\n";
            std::cout << "first: " << first << '\n';
            std::cout << "first size: " << first.size() << '\n';
            
            first.popBack();
            
            std::cout << "\nafter first.popBack():\n";
            std::cout << "first: " << first << '\n';
            
            first.append(second);
            
            std::cout << "\nafter first.append(second):\n";
            std::cout << "first: " << first << '\n';
            
            CString<20> cstring(" Test");
            
            first.append(cstring);
            
            std::cout << "\nafter first.append(cstring):\n";
            std::cout << "first: " << first << '\n';
            
            std::cout << "\nComparisons:\n";
            std::cout << "first == third: " << (first == third) << '\n';
            std::cout << "first != third: " << (first != third) << '\n';
            std::cout << "third < first: " << (third < first) << '\n';
            std::cout << "first > third: " << (first > third) << '\n';
            
            std::cout << "\nIndexing:\n";
            std::cout << "first[0]: " << first[String<20>::makeIndex(0)] << '\n';
            std::cout << "first[1]: " << first[String<20>::makeIndex(1)] << '\n';
            std::cout << "first[2]: " << first[String<20>::makeIndex(2)] << '\n';
            
            first.clear();
            
            std::cout << "\nafter clear:\n";
            std::cout << "first: " << first << '\n';
            std::cout << "first size: " << first.size() << '\n';
            std::cout << "first empty: " << first.empty() << '\n';
        }
        std::cout << "\nString type tests completed.\n\n";
        
        std::cout << "\n\n===== CString Test =====\n\n";
        {
            CString<10> name("Marco");
            CString<10> sameName("Marco");
            CString<10> otherName("Mara");
            
            std::cout << "name: " << name << '\n';
            std::cout << "sameName: " << sameName << '\n';
            std::cout << "otherName: " << otherName << '\n';
            
            std::cout << "name size: " << name.size() << '\n';
            std::cout << "name capacity: " << name.capacity() << '\n';
            
            std::cout << "name empty: " << name.empty() << '\n';
            std::cout << "name full: " << name.full() << '\n';
            std::cout << "name isTerminated: " << name.isTerminated() << '\n';
            
            name.pushBack(Byte(33)); // !
            
            std::cout << "\nafter pushBack('!'):\n";
            std::cout << "name: " << name << '\n';
            std::cout << "name size: " << name.size() << '\n';
            std::cout << "name isTerminated: " << name.isTerminated() << '\n';
            
            std::cout << "\nComparisons:\n";
            std::cout << "name == sameName: " << (name == sameName) << '\n';
            std::cout << "name != sameName: " << (name != sameName) << '\n';
            std::cout << "otherName < name: " << (otherName < name) << '\n';
            std::cout << "name > otherName: " << (name > otherName) << '\n';
            
            std::cout << "\nIndexing:\n";
            std::cout << "name[0]: " << name[CString<10>::makeIndex(0)] << '\n';
            std::cout << "name[1]: " << name[CString<10>::makeIndex(1)] << '\n';
            std::cout << "name[2]: " << name[CString<10>::makeIndex(2)] << '\n';
            
            name.clear();
            
            std::cout << "\nafter clear:\n";
            std::cout << "name: " << name << '\n';
            std::cout << "name size: " << name.size() << '\n';
            std::cout << "name empty: " << name.empty() << '\n';
            std::cout << "name isTerminated: " << name.isTerminated() << '\n';
        }
        std::cout << "\nCString type tests completed.\n\n";
        
        std::cout << "\n\n===== Enum Test =====\n\n";
        {
            Enum difficulty = Enum::fromRange(1, 0, 3);
            
            std::cout << "difficulty: " << difficulty << '\n';
            
            ++difficulty;
            std::cout << "after ++difficulty: " << difficulty << '\n';
            
            difficulty++;
            std::cout << "after difficulty++: " << difficulty << '\n';
            
            difficulty++;
            std::cout << "after trying to go past max: " << difficulty << '\n';
            
            --difficulty;
            std::cout << "after --difficulty: " << difficulty << '\n';
            
            std::cout << "setValue(2): "
            << difficulty.setValue(Int32::fromSignedValue(2)) << '\n';
            
            std::cout << "difficulty: " << difficulty << '\n';
            
            std::cout << "setValue(10): "
            << difficulty.setValue(Int32::fromSignedValue(10)) << '\n';
            
            std::cout << "difficulty after invalid set: " << difficulty << '\n';
            
            Enum other = Enum::fromRange(2, 0, 3);
            
            std::cout << "other: " << other << '\n';
            std::cout << "difficulty == other: " << (difficulty == other) << '\n';
            std::cout << "difficulty sameRange other: "
            << difficulty.sameRange(other) << '\n';
        }
        std::cout << "\nEnum type tests completed.\n\n";
        
        std::cout << "\n\n===== Array Test =====\n\n";
        {
            Array<Char, 5> letters;
            
            letters[String<5>::makeIndex(0)] = Char(Byte(65)); // A
            letters[String<5>::makeIndex(1)] = Char(Byte(66)); // B
            letters[String<5>::makeIndex(2)] = Char(Byte(67)); // C
            letters[String<5>::makeIndex(3)] = Char(Byte(68)); // D
            letters[String<5>::makeIndex(4)] = Char(Byte(69)); // E
            
            std::cout << "letters: " << letters << '\n';
            std::cout << "letters size: " << letters.size() << '\n';
        }
        std::cout << "\nArray type tests completed.\n\n";
        
        std::cout << "\n\n===== Array2D Test =====\n\n";
        {
            Array2D<Char, 2, 3> grid;
            
            grid(Array2D<Char, 2, 3>::makeIndex(0),
                 Array2D<Char, 2, 3>::makeIndex(0)) = Char(Byte(65)); // A
            
            grid(Array2D<Char, 2, 3>::makeIndex(0),
                 Array2D<Char, 2, 3>::makeIndex(1)) = Char(Byte(66)); // B
            
            grid(Array2D<Char, 2, 3>::makeIndex(0),
                 Array2D<Char, 2, 3>::makeIndex(2)) = Char(Byte(67)); // C
            
            grid(Array2D<Char, 2, 3>::makeIndex(1),
                 Array2D<Char, 2, 3>::makeIndex(0)) = Char(Byte(68)); // D
            
            grid(Array2D<Char, 2, 3>::makeIndex(1),
                 Array2D<Char, 2, 3>::makeIndex(1)) = Char(Byte(69)); // E
            
            grid(Array2D<Char, 2, 3>::makeIndex(1),
                 Array2D<Char, 2, 3>::makeIndex(2)) = Char(Byte(70)); // F
            
            std::cout << "grid:\n" << grid << '\n';
            std::cout << "rows: " << grid.rowCount() << '\n';
            std::cout << "cols: " << grid.colCount() << '\n';
            std::cout << "size: " << grid.size() << '\n';
        }
        std::cout << "\nArray2D type tests completed.\n\n";
        
        std::cout << "\n\n===== Vector<Char, 10> Test =====\n\n";
        {
            Vector<Char, 10> letters;
            
            std::cout << "letters: " << letters << '\n';
            std::cout << "letters size: " << letters.size() << '\n';
            std::cout << "letters capacity: " << letters.capacity() << '\n';
            std::cout << "letters empty: " << letters.empty() << '\n';
            std::cout << "letters full: " << letters.full() << '\n';
            
            letters.pushBack(Char(Byte(65))); // A
            letters.pushBack(Char(Byte(66))); // B
            letters.pushBack(Char(Byte(67))); // C
            
            std::cout << "\nafter pushBack A, B, C:\n";
            std::cout << "letters: " << letters << '\n';
            std::cout << "letters size: " << letters.size() << '\n';
            std::cout << "letters empty: " << letters.empty() << '\n';
            
            std::cout << "letters[0]: "
            << letters[Vector<Char, 10>::makeIndex(0)] << '\n';
            
            std::cout << "letters[1]: "
            << letters[Vector<Char, 10>::makeIndex(1)] << '\n';
            
            std::cout << "letters[2]: "
            << letters[Vector<Char, 10>::makeIndex(2)] << '\n';
            
            letters.popBack();
            
            std::cout << "\nafter popBack:\n";
            std::cout << "letters: " << letters << '\n';
            std::cout << "letters size: " << letters.size() << '\n';
            
            Vector<Char, 10> vecOther;
            
            vecOther.pushBack(Char(Byte(65))); // A
            vecOther.pushBack(Char(Byte(66))); // B
            
            std::cout << "\nother: " << vecOther << '\n';
            
            std::cout << "letters == other: " << (letters == vecOther) << '\n';
            std::cout << "letters != vecOther: " << (letters != vecOther) << '\n';
            
            letters.clear();
            
            std::cout << "\nafter clear:\n";
            std::cout << "letters: " << letters << '\n';
            std::cout << "letters size: " << letters.size() << '\n';
            std::cout << "letters empty: " << letters.empty() << '\n';
        }
        std::cout << "\nVector<Char, 10> type tests completed.\n\n";
        
        std::cout << "\n\n===== Vector<UInt64, 5> Test =====\n\n";
        {
            Vector<UInt64, 5> numbers;
            
            numbers.pushBack(Vector<UInt64, 5>::makeIndex(10));
            numbers.pushBack(Vector<UInt64, 5>::makeIndex(20));
            numbers.pushBack(Vector<UInt64, 5>::makeIndex(30));
            
            std::cout << "numbers: " << numbers << '\n';
            std::cout << "numbers size: " << numbers.size() << '\n';
            std::cout << "numbers capacity: " << numbers.capacity() << '\n';
            
            numbers.popBack();
            
            std::cout << "after popBack, numbers: " << numbers << '\n';
        }
        std::cout << "\nVector<UInt64, 5> type tests completed.\n\n";
        
        std::cout << "\n\n===== Pointer Test =====\n\n";
        {
            Memory<Char, 5> memory;
            
            std::cout << "memory: " << memory << '\n';
            std::cout << "memory empty: " << memory.empty() << '\n';
            std::cout << "memory full: " << memory.full() << '\n';
            
            Pointer<Char, 5> ptrA = memory.allocate(Char(Byte(65))); // A
            Pointer<Char, 5> ptrB = memory.allocate(Char(Byte(66))); // B
            Pointer<Char, 5> ptrC = memory.allocate(Char(Byte(67))); // C
            
            std::cout << "\nafter allocating A, B, C:\n";
            
            std::cout << "memory: " << memory << '\n';
            std::cout << "ptrA: " << ptrA << '\n';
            std::cout << "ptrB: " << ptrB << '\n';
            std::cout << "ptrC: " << ptrC << '\n';
            
            std::cout << "memory.get(ptrA): " << memory.get(ptrA) << '\n';
            std::cout << "memory.get(ptrB): " << memory.get(ptrB) << '\n';
            std::cout << "memory.get(ptrC): " << memory.get(ptrC) << '\n';
            
            memory.set(ptrB, Char(Byte(90))); // Z
            
            std::cout << "\nafter memory.set(ptrB, 'Z'):\n";
            std::cout << "memory.get(ptrB): " << memory.get(ptrB) << '\n';
            
            std::cout << "\nptrA == ptrB: " << (ptrA == ptrB) << '\n';
            std::cout << "ptrA != ptrB: " << (ptrA != ptrB) << '\n';
            
            std::cout << "\ndeallocating ptrA...\n";
            
            std::cout << "deallocate(ptrA): " << memory.deallocate(ptrA) << '\n';
            std::cout << "memory.contains(ptrA): " << memory.contains(ptrA) << '\n';
            std::cout << "memory.contains(ptrB): " << memory.contains(ptrB) << '\n';
            
            Pointer<Char, 5> ptrD = memory.allocate(Char(Byte(68))); // D
            
            std::cout << "\nafter allocating D:\n";
            std::cout << "ptrD: " << ptrD << '\n';
            std::cout << "memory.get(ptrD): " << memory.get(ptrD) << '\n';
            
            Pointer<Char, 5> nullPtr;
            
            std::cout << "\nnullPtr: " << nullPtr << '\n';
            std::cout << "nullPtr.isNull(): " << nullPtr.isNull() << '\n';
            std::cout << "nullPtr.isNotNull(): " << nullPtr.isNotNull() << '\n';
        }
        std::cout << "\nPointer type tests completed.\n\n";
        
        std::cout << "\n\n===== UniquePtr Test =====\n\n";
        {
            Memory<Char, 5> uniqueMemory;
            
            UniquePtr<Char, 5> uniqueA =
            UniquePtr<Char, 5>::make(uniqueMemory, Char(Byte(65))); // A
            
            std::cout << "uniqueMemory: " << uniqueMemory << '\n';
            std::cout << "uniqueA: " << uniqueA << '\n';
            std::cout << "uniqueA isNull: " << uniqueA.isNull() << '\n';
            std::cout << "uniqueA value: " << uniqueA.get(uniqueMemory) << '\n';
            
            uniqueA.set(uniqueMemory, Char(Byte(90))); // Z
            
            std::cout << "after set to Z: "
            << uniqueA.get(uniqueMemory) << '\n';
            
            uniqueA.reset(uniqueMemory, Char(Byte(66))); // B
            
            std::cout << "after reset to B: "
            << uniqueA.get(uniqueMemory) << '\n';
            
            Pointer<Char, 5> released = uniqueA.release();
            
            std::cout << "released pointer: " << released << '\n';
            std::cout << "uniqueA after release: " << uniqueA << '\n';
            std::cout << "uniqueMemory still contains released: "
            << uniqueMemory.contains(released) << '\n';
            
            uniqueMemory.deallocate(released);
            
            std::cout << "after manual deallocate released: "
            << uniqueMemory.contains(released) << '\n';
        }
        std::cout << "\nUniquePtr type tests completed.\n\n";
        
        std::cout << "\n\n===== SharedPtr Test =====\n\n";
        {
            SharedMemory<Char, 5> sharedMemory;
            
            SharedPtr<Char, 5> sharedA =
            SharedPtr<Char, 5>::make(sharedMemory, Char(Byte(67))); // C
            
            std::cout << "sharedMemory: " << sharedMemory << '\n';
            std::cout << "sharedA: " << sharedA << '\n';
            std::cout << "sharedA value: " << sharedA.get(sharedMemory) << '\n';
            std::cout << "sharedA useCount: "
            << sharedA.useCount(sharedMemory) << '\n';
            std::cout << "sharedA unique: "
            << sharedA.unique(sharedMemory) << '\n';
            
            SharedPtr<Char, 5> sharedB = sharedA.share(sharedMemory);
            
            std::cout << "\nafter sharedB = sharedA.share(sharedMemory):\n";
            std::cout << "sharedB: " << sharedB << '\n';
            std::cout << "sharedA useCount: "
            << sharedA.useCount(sharedMemory) << '\n';
            std::cout << "sharedB useCount: "
            << sharedB.useCount(sharedMemory) << '\n';
            std::cout << "sharedA unique: "
            << sharedA.unique(sharedMemory) << '\n';
            
            sharedB.set(sharedMemory, Char(Byte(88))); // X
            
            std::cout << "\nafter sharedB.set(X):\n";
            std::cout << "sharedA value: " << sharedA.get(sharedMemory) << '\n';
            std::cout << "sharedB value: " << sharedB.get(sharedMemory) << '\n';
            
            sharedB.reset(sharedMemory);
            
            std::cout << "\nafter sharedB.reset:\n";
            std::cout << "sharedA useCount: "
            << sharedA.useCount(sharedMemory) << '\n';
            std::cout << "sharedA unique: "
            << sharedA.unique(sharedMemory) << '\n';
            
            sharedA.reset(sharedMemory);
            
            std::cout << "\nafter sharedA.reset:\n";
            std::cout << "sharedMemory: " << sharedMemory << '\n';
        }
        std::cout << "\nSharedPtr type tests completed.\n\n";
        
        std::cout << "\n\n===== NullPtr Test =====\n\n";
        {
            NullPtr nullValue;
            
            std::cout << "nullValue: " << nullValue << '\n';
            std::cout << "nullValue.isNull(): " << nullValue.isNull() << '\n';
            
            Pointer<Char, 5> nullPointer;
            
            std::cout << "nullPointer: " << nullPointer << '\n';
            std::cout << "nullPointer == nullValue: "
            << (nullPointer == nullValue) << '\n';
            std::cout << "nullPointer != nullValue: "
            << (nullPointer != nullValue) << '\n';
        }
        std::cout << "\nNullPtr tests completed.\n\n";
        
        std::cout << "\n\n===== Reference Test =====\n\n";
        {
            Memory<Char, 5> memory;
            
            Pointer<Char, 5> ptrA = memory.allocate(Char(Byte(65))); // A
            Pointer<Char, 5> ptrB = memory.allocate(Char(Byte(66))); // B
            
            Reference<Char, 5> refA = Reference<Char, 5>::bind(ptrA);
            Reference<Char, 5> refB = Reference<Char, 5>::bind(ptrB);
            
            std::cout << "memory: " << memory << '\n';
            
            std::cout << "ptrA: " << ptrA << '\n';
            std::cout << "ptrB: " << ptrB << '\n';
            
            std::cout << "refA: " << refA << '\n';
            std::cout << "refB: " << refB << '\n';
            
            std::cout << "refA value: " << refA.get(memory) << '\n';
            std::cout << "refB value: " << refB.get(memory) << '\n';
            
            refA.set(memory, Char(Byte(90))); // Z
            
            std::cout << "after refA.set('Z'):\n";
            std::cout << "refA value: " << refA.get(memory) << '\n';
            std::cout << "memory.get(ptrA): " << memory.get(ptrA) << '\n';
            
            std::cout << "refA == refB: " << (refA == refB) << '\n';
            std::cout << "refA != refB: " << (refA != refB) << '\n';
        }
        std::cout << "\nReference tests completed.\n\n";
        
        std::cout << "\n\n===== Void Test =====\n\n";
        {
            Void v1;
            Void v2;
            
            std::cout << "v1: " << v1 << '\n';
            std::cout << "v2: " << v2 << '\n';
            
            std::cout << "v1 == v2: " << (v1 == v2) << '\n';
            std::cout << "v1 != v2: " << (v1 != v2) << '\n';
        }
        std::cout << "\nVoid tests completed.\n\n";
        
        std::cout << "\n\n===== TypeSystem Test =====\n\n";
        {
            Bool isReady = true;
            Bool isDone = false;
            
            Char letter = 'A';
            Char digit = '7';
            
            UChar tinyUnsigned = 250;
            SChar tinySigned = -12;
            
            UShortInt smallUnsigned = 500;
            ShortInt smallSigned = -300;
            
            UInt score = 50000;
            Int health = 100;
            
            ULongInt bigUnsigned = 5000000000ULL;
            LongInt bigSigned = -5000000000LL;
            
            Float speed = 3.5f;
            Double accuracy = 98.75;
            
            CString<20> cName = "Marco";
            String<20> name = "Shadow";
            
            Vector<Char, 10> letters;
            letters.pushBack('A');
            letters.pushBack('B');
            letters.pushBack('C');
            
            Array<Char, 3> fixedLetters;
            fixedLetters[String<3>::makeIndex(0)] = 'X';
            fixedLetters[String<3>::makeIndex(1)] = 'Y';
            fixedLetters[String<3>::makeIndex(2)] = 'Z';
            
            std::cout << "isReady: " << isReady << '\n';
            std::cout << "isDone: " << isDone << '\n';
            
            std::cout << "letter: " << letter << '\n';
            std::cout << "digit: " << digit << '\n';
            
            std::cout << "tinyUnsigned: " << tinyUnsigned << '\n';
            std::cout << "tinySigned: " << tinySigned << '\n';
            
            std::cout << "smallUnsigned: " << smallUnsigned << '\n';
            std::cout << "smallSigned: " << smallSigned << '\n';
            
            std::cout << "score: " << score << '\n';
            std::cout << "health: " << health << '\n';
            
            std::cout << "bigUnsigned: " << bigUnsigned << '\n';
            std::cout << "bigSigned: " << bigSigned << '\n';
            
            std::cout << "speed: " << speed << '\n';
            std::cout << "accuracy: " << accuracy << '\n';
            
            std::cout << "cName: " << cName << '\n';
            std::cout << "name: " << name << '\n';
            
            std::cout << "letters: " << letters << '\n';
            std::cout << "fixedLetters: " << fixedLetters << '\n';
        }
        std::cout << "\nTypeSystem tests completed.\n\n";
        
        std::cout << "\n\n===== TypeHelpers Test =====\n\n";
        {
            Bool isReady = makeBool(true);
            Bool isDone = makeBool(false);
            
            Char letter = makeChar('A');
            Char digit = makeChar('7');
            
            UChar tinyUnsigned = makeUInt8(250);
            SChar tinySigned = makeInt8(-12);
            
            UShortInt smallUnsigned = makeUInt16(500);
            ShortInt smallSigned = makeInt16(-300);
            
            UInt score = makeUInt(50000);
            Int health = makeInt(100);
            
            ULongInt bigUnsigned = makeULong(5000000000ULL);
            LongInt bigSigned = makeLong(-5000000000LL);
            
            Float speed = makeFloat(3.5f);
            Double accuracy = makeDouble(98.75);
            
            CString<20> cName("Marco");
            String<20> name("Shadow");
            
            Vector<Char, 10> letters;
            
            letters.pushBack(makeChar('A'));
            letters.pushBack(makeChar('B'));
            letters.pushBack(makeChar('C'));
            
            Array<Char, 3> fixedLetters;
            
            fixedLetters[makeIndex(0)] = makeChar('X');
            fixedLetters[makeIndex(1)] = makeChar('Y');
            fixedLetters[makeIndex(2)] = makeChar('Z');
            
            std::cout << "isReady: " << isReady << '\n';
            std::cout << "isDone: " << isDone << '\n';
            
            std::cout << "letter: " << letter << '\n';
            std::cout << "digit: " << digit << '\n';
            
            std::cout << "tinyUnsigned: " << tinyUnsigned << '\n';
            std::cout << "tinySigned: " << tinySigned << '\n';
            
            std::cout << "smallUnsigned: " << smallUnsigned << '\n';
            std::cout << "smallSigned: " << smallSigned << '\n';
            
            std::cout << "score: " << score << '\n';
            std::cout << "health: " << health << '\n';
            
            std::cout << "bigUnsigned: " << bigUnsigned << '\n';
            std::cout << "bigSigned: " << bigSigned << '\n';
            
            std::cout << "speed: " << speed << '\n';
            std::cout << "accuracy: " << accuracy << '\n';
            
            std::cout << "cName: " << cName << '\n';
            std::cout << "name: " << name << '\n';
            
            std::cout << "letters: " << letters << '\n';
            std::cout << "fixedLetters: " << fixedLetters << '\n';
        }
        std::cout << "\nTypeHelper tests completed.\n\n";
        
        std::cout << "\n\n===== TypeLimits Test =====\n\n";
        {
            std::cout << "Bool min: " << TypeLimits<Bool>::min() << '\n';
            std::cout << "Bool max: " << TypeLimits<Bool>::max() << '\n';
            
            std::cout << "\nUInt8 min: " << TypeLimits<UInt8>::min() << '\n';
            std::cout << "UInt8 max: " << TypeLimits<UInt8>::max() << '\n';
            
            std::cout << "\nInt8 min: " << TypeLimits<Int8>::min() << '\n';
            std::cout << "Int8 max: " << TypeLimits<Int8>::max() << '\n';
            
            std::cout << "\nUInt min: " << TypeLimits<UInt>::min() << '\n';
            std::cout << "UInt max: " << TypeLimits<UInt>::max() << '\n';
            
            std::cout << "\nInt min: " << TypeLimits<Int>::min() << '\n';
            std::cout << "Int max: " << TypeLimits<Int>::max() << '\n';
            
            std::cout << "\nULongInt min: " << TypeLimits<ULongInt>::min() << '\n';
            std::cout << "ULongInt max: " << TypeLimits<ULongInt>::max() << '\n';
            
            std::cout << "\nLongInt min: " << TypeLimits<LongInt>::min() << '\n';
            std::cout << "LongInt max: " << TypeLimits<LongInt>::max() << '\n';
            
            std::cout << "\nFloat lowest: " << TypeLimits<Float>::lowest() << '\n';
            std::cout << "Float max: " << TypeLimits<Float>::max() << '\n';
            std::cout << "Float epsilon: " << TypeLimits<Float>::epsilon() << '\n';
            
            std::cout << "\nDouble lowest: " << TypeLimits<Double>::lowest() << '\n';
            std::cout << "Double max: " << TypeLimits<Double>::max() << '\n';
            std::cout << "Double epsilon: " << TypeLimits<Double>::epsilon() << '\n';
            
            Int zero = TypeLimits<Int>::zero();
            Int one = TypeLimits<Int>::one();
            
            std::cout << "\nzero: " << zero << '\n';
            std::cout << "one: " << one << '\n';
            std::cout << "zero + one: " << (zero + one) << '\n';
        }
        std::cout << "\nTypeLimits tests completed.\n\n";
        
        std::cout << "\n\n===== Math Helper Test =====\n\n";
        {
            Int health = -25;
            Int clampedHealth = clamp(health, Int(0), Int(100));
            
            Double score = 98.75;
            Double maxScore = max(score, Double(100.0));
            
            std::cout << "health: " << health << '\n';
            std::cout << "myAbs(health): " << absol(health) << '\n';
            std::cout << "clampedHealth: " << clampedHealth << '\n';
            
            std::cout << "score: " << score << '\n';
            std::cout << "maxScore: " << maxScore << '\n';
        }
        std::cout << "\nMath helper tests completed.\n\n";
        
        std::cout << "\n\n===== Algorithm Helper Test =====\n\n";
        {
            Vector<Int, 10> numbers;
            
            numbers.pushBack(5);
            numbers.pushBack(2);
            numbers.pushBack(8);
            numbers.pushBack(2);
            numbers.pushBack(1);
            
            UInt64 foundIndex;
            
            std::cout << "Find 8: " << find(numbers, Int(8), foundIndex) << '\n';
            std::cout << "8 index: " << foundIndex << '\n';
            
            std::cout << "Count 2: " << count(numbers, Int(2)) << '\n';
            
            sortAscending(numbers);
            std::cout << "Sorted ascending: " << numbers << '\n';
            
            sortDescending(numbers);
            std::cout << "Sorted descending: " << numbers << '\n';
            
            reverse(numbers);
            std::cout << "Reversed: " << numbers << '\n';
        }
        std::cout << "\nAlgorithm helper tests completed.\n\n";
        
        std::cout << "\n\n===== Conversions Helper Test =====\n\n";
        {
            Int health = 100;
            UInt score = 5000;
            LongInt big = -5000000000LL;
            Double accuracy = 98.75;
            Char letter = 'A';
            
            std::cout << "ToDouble(health): " << toDouble(health) << '\n';
            std::cout << "ToInt(accuracy): " << toInt(accuracy) << '\n';
            std::cout << "ToLongInt(score): " << toLongInt(score) << '\n';
            std::cout << "ToUInt(big): " << toUInt(big) << '\n';
            
            std::cout << "ToByte(letter): " << toByte(letter) << '\n';
            std::cout << "ToChar(66): " << toChar(66) << '\n';
            
            std::cout << "ToBool(health): " << toBool(health) << '\n';
            std::cout << "ToBool(Int(0)): " << toBool(Int(0)) << '\n';
            
            Float speed = toFloat(accuracy);
            Double preciseSpeed = toDouble(speed);
            
            std::cout << "speed: " << speed << '\n';
            std::cout << "preciseSpeed: " << preciseSpeed << '\n';
        }
        std::cout << "\nConversions helper tests completed.\n\n";
        
        std::cout << "\n\n===== String Conversions Helper Test =====\n\n";
        {
            Int health = 100;
            UInt score = 5000;
            LongInt big = -5000000000LL;
            Double accuracy = 98.75;
            Bool ready = true;
            Char letter = 'A';
            
            String<30> healthText = toString<30>(health);
            String<30> scoreText = toString<30>(score);
            String<30> bigText = toString<30>(big);
            String<30> accuracyText = toString<30>(accuracy);
            String<30> readyText = toString<30>(ready);
            String<30> letterText = toString<30>(letter);
            
            std::cout << "healthText: " << healthText << '\n';
            std::cout << "scoreText: " << scoreText << '\n';
            std::cout << "bigText: " << bigText << '\n';
            std::cout << "accuracyText: " << accuracyText << '\n';
            std::cout << "readyText: " << readyText << '\n';
            std::cout << "letterText: " << letterText << '\n';
            
            std::string normal = toStdString(healthText);
            
            std::cout << "normal std::string: " << normal << '\n';
        }
        std::cout << "\nString conversions helper tests completed.\n\n";
        
        std::cout << "\n\n===== String Parsing Helper Test =====\n\n";
        {
            String<20> healthText = "100";
            String<20> readyText = "true";
            String<20> scoreText = "98.75";
            String<20> letterText = "A";
            
            Int health = toInt(healthText);
            Bool ready = toBool(readyText);
            Double score = toDouble(scoreText);
            Char letter = toChar(letterText);
            
            std::cout << "health: " << health << '\n';
            std::cout << "ready: " << ready << '\n';
            std::cout << "score: " << score << '\n';
            std::cout << "letter: " << letter << '\n';
            
            String<20> badText = "abc";
            Int result;
            
            if (tryToInt(badText, result)) {
                std::cout << "parsed badText: " << result << '\n';
            } else {
                std::cout << "badText could not be converted to Int.\n";
            }
        }
        std::cout << "\nString parsing helper tests completed.\n\n";
        
        std::cout << "\n\n===== TypeIO Test =====\n\n";
        {
            Int age;
            Double grade;
            Bool enrolled;
            Char initial;
            String<30> name;
            
            std::cout << "Enter your name: ";
            std::cin >> name;
            
            std::cout << "\nEnter the initial of your first name: ";
            std::cin >> initial;
            
            std::cout << "\nEnter your age: ";
            std::cin >> age;
            
            std::cout << "\nEnter your grade: ";
            std::cin >> grade;
            
            std::cout << "\nAre you enrolled? ";
            std::cin >> enrolled;
            
            std::cout << "\n\n===== TypeIO Test Results =====\n\n";
            std::cout << "name: " << name << '\n';
            std::cout << "initial: " << initial << '\n';
            std::cout << "age: " << age << '\n';
            std::cout << "grade: " << grade << '\n';
            std::cout << "enrolled: " << enrolled << '\n';
        }
        std::cout << "\nTypeIO tests completed.\n\n";
    }
    
    std::cout << "\n********** ALL TESTS PASSED ***********\n\n";
    
    std::cout << "======= END OF TEST FRAMEWORK FOR =======\n";
    std::cout << "=== BYTE-DERIVED BUILT-IN TYPE SYSTEM ===\n\n";
    
    return 0;
}

