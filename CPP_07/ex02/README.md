# CPP_07 / ex02 — Array

## Objective

Implement an `Array<T>` class template that provides a dynamically-sized, bounds-checked array with the Orthodox Canonical Form.

## What the Executable Does

```
$ ./ex02
(fills array with random values, copies it, verifies values match)
didn't save the same value!!  <- only if copy failed (should not appear)
Index out of bounds            <- thrown for negative/over-size indices
...
```

Tests:
- Creating an array with `N` elements
- Copying via copy constructor and copy-assignment operator
- Modifying a copy does **not** affect the original (deep copy)
- Accessing out-of-bounds indices throws `std::exception`

## Key Learning Objectives

- Class template syntax: `template<typename T> class Array`
- `new T[n]` allocation in the constructor; `delete[]` in the destructor
- Deep copy: copy constructor and assignment operator allocate a fresh array and copy elements
- Bounds checking: `operator[]` throws on invalid indices
- `size()` member function returns the number of elements as an `unsigned int`

## Build and Usage

```bash
make
./ex02
```

## Files

| File | Description |
|------|-------------|
| `include/Array.hpp` | `Array<T>` class template declaration |
| `include/Array.tpp` | `Array<T>` method implementations (included by `Array.hpp`) |
| `include/Mix.hpp` | Additional template utility helpers |
| `include/Utils.hpp` | Utility helpers |
| `include/Utils.tpp` | Template utility implementations |
| `src/Utils.cpp` | Utility implementations |
| `src/main.cpp` | Test driver: fill, copy, bounds-check |
| `Makefile` | Build configuration; produces the `ex02` executable |
