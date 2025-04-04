# CPP Module 06 - C++ Casts

## 🔍 Overview
This module explores C++ **type casting** mechanisms, **serialization**, and **dynamic type identification**. It includes three exercises that demonstrate the power and flexibility of C++ casting operators.

## Exercises
### Exercise 00: Scalar Conversion
A program that converts a literal representation of a scalar type (`char`, `int`, `float`, or `double`) to the three other types.

### 📝Features:
- Automatic type detection
- Proper handling of special cases (non-displayable characters, impossible conversions)
- Support for special values (`nan`, `inf`)
- Uses explicit C++ casting operators

### 📐Usage:
```sh
./convert <literal>
```
### Examples:
```sh
./convert 42
./convert 4.2f
./convert 'a'
./convert nan
```
### Exercise 01: Serialization
Demonstrates pointer-to-integer serialization and deserialization using `reinterpret_cast`.

### 📝Features:
- Serialization of a pointer to `uintptr_t`
- Deserialization of a `uintptr_t` back to a pointer
- Maintains pointer identity through the conversion

### 📐Usage:
```sh
./serializer
```
The program creates a Data object, serializes its address to an integer, deserializes it back to a pointer, and verifies they point to the same memory location.

### Exercise 02: Type Identification
Implements runtime type identification without using `typeid` or the `<typeinfo>` header.

### 📝Features:
- Random object generation
- Type identification through `dynamic_cast`
- Two different identification approaches (pointer-based and reference-based)
- Exception handling for type identification

### 📐Usage:
```sh
./identify
```
The program randomly generates an object of class A, B, or C, then identifies its type using two different methods.

## 🤖Technical Details
- Compiled with C++98 standard (`-std=c++98`)
- All exercises follow Orthodox Canonical Form where required
- Uses explicit casting operators (`static_cast`, `dynamic_cast`, `reinterpret_cast`) rather than C-style casts
- Proper memory management (no leaks)
- Error handling through exceptions

## Compilation and Testing
Each exercise can be compiled using the provided Makefile:
```sh
cd exXX
make
```
The resulting executable can then be run according to the instructions for each exercise.

## ✍️Learning Objectives
- Understanding and implementing different C++ casting operators
- Converting between different scalar types
- Working with pointer address serialization
- Dynamic type identification at runtime without using typeid
- Exception-based control flow for type identification
- Proper memory management with new/delete
This module provides practical experience with some of C++'s more advanced features relating to type manipulation and runtime type information.

## 👥 Author
[**Tudor Ursescu**](https://github.com/Tudor-Ursescu)
## 📜 License
This is an open-source project, and you are free to use, modify, and distribute it as you see fit.