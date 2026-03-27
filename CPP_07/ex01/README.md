# CPP_07 / ex01 — Iter

## Objective

Implement an `iter` function template that takes an array, its length, and a function, then applies the function to each element.

## What the Executable Does

```
$ ./ex01
int array:   [3, 1, 4, 1, 5]  (after some transformation)
float array: [3.14, 2.71, ...]
...
```

The binary runs the `iter` template over arrays of `int`, `float`, `double`, `char`, and `std::string`, applying a transformation or print function to each element.

## Key Learning Objectives

- Function template with multiple template parameters (element type + function type)
- Passing a function / function object as a template argument
- Template argument deduction for the callable parameter
- The relationship between template functions and the Liskov Substitution Principle: `iter` works for any type that satisfies the callable's requirements

## Build and Usage

```bash
make
./ex01
```

## Files

| File | Description |
|------|-------------|
| `include/iter.hpp` | `iter<T, F>(T* array, size_t len, F func)` template definition |
| `include/Utils.hpp` | Utility helpers |
| `src/Utils.cpp` | Utility implementations |
| `src/main.cpp` | Tests `iter` with multiple types and functions |
| `Makefile` | Build configuration; produces the `ex01` executable |
