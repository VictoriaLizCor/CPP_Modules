# CPP_02 / ex02 — Now We're Talking

## Objective

Complete the `Fixed` class with a full suite of overloaded operators: arithmetic (`+`, `-`, `*`, `/`), six comparison operators, pre/post increment and decrement, and static `min`/`max` member functions.

## What the Executable Does

```
$ ./ex02
0
0.00390625
0.00390625
0.00781250
0.00390625
10.1016
10.1016
```

The binary exercises every operator and confirms that arithmetic, comparison, and increment operators work correctly on fixed-point values.

## Key Learning Objectives

- Implementing all six comparison operators (`<`, `>`, `<=`, `>=`, `==`, `!=`)
- Arithmetic operators that preserve fixed-point precision
- Pre-increment (`++a`) vs. post-increment (`a++`) operator signatures
- Static overloaded `min()` and `max()` functions (const and non-const variants)
- Operator chaining and const-correctness

## Build and Usage

```bash
make
./ex02
```

## Files

| File | Description |
|------|-------------|
| `includes/Fixed.hpp` | Complete `Fixed` class declaration |
| `src/Fixed.cpp` | Core OCF implementation |
| `src/FixedArithmeticOperators.cpp` | `+`, `-`, `*`, `/` operator overloads |
| `src/FixedBooleanOperators.cpp` | Six comparison operator overloads |
| `src/FixedMemberFunctions.cpp` | Increment/decrement operators and `min`/`max` |
| `src/main.cpp` | Test driver |
| `Makefile` | Build configuration; produces the `ex02` executable |
