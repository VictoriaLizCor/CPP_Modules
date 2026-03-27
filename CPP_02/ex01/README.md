# CPP_02 / ex01 — Towards a More Useful Fixed-Point Number Class

## Objective

Extend the `Fixed` class with constructors that accept `int` and `float` values, conversion functions (`toInt`, `toFloat`), and an overloaded `<<` stream operator.

## What the Executable Does

```
$ ./ex01
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
```

The binary constructs `Fixed` objects from integers and floats, prints their fixed-point representation via `<<`, and converts them back to integer and float.

## Key Learning Objectives

- Converting `int` to fixed-point: left-shift by 8 bits (`value << 8`)
- Converting `float` to fixed-point: `roundf(value * (1 << 8))`
- `toFloat()` and `toInt()` conversion functions
- Overloading `operator<<` as a non-member `friend` function
- Understanding fractional bit representation and its precision limits

## Build and Usage

```bash
make
./ex01
```

## Files

| File | Description |
|------|-------------|
| `includes/Fixed.hpp` | Updated `Fixed` class with new constructor signatures |
| `src/Fixed.cpp` | All constructors, conversion functions, and stream operator |
| `src/main.cpp` | Test driver |
| `Makefile` | Build configuration; produces the `ex01` executable |
