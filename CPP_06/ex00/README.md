# CPP_06 / ex00 — Conversion of Scalar Types

## Objective

Implement a `ScalarConverter` class with a **static-only** `convert(std::string literal)` method that detects the type of the literal and converts it to `char`, `int`, `float`, and `double`, printing each result.

## What the Executable Does

```
$ ./ex00 42
char:  '*'
int:   42
float: 42.0f
double: 42.0

$ ./ex00 nan
char:  impossible
int:   impossible
float: nanf
double: nan

$ ./ex00 'a'
char:  'a'
int:   97
float: 97.0f
double: 97.0
```

Handles: single printable characters, integer literals, float literals (with `f` suffix), double literals, and pseudo-literals (`nan`, `inf`, `+inf`, `-inf`, `nanf`, `inff`).

## Key Learning Objectives

- `static_cast<>`: safe explicit conversion between numeric types
- Detecting the category of a string literal (char / int / float / double / pseudo)
- Overflow and non-displayable character detection
- Precision formatting with `std::fixed` / `std::setprecision`
- Non-instantiable utility class (private constructor)

## Build and Usage

```bash
make
./ex00 <literal>

# Examples
./ex00 0
./ex00 nan
./ex00 42.0f
./ex00 "'"
```

## Files

| File | Description |
|------|-------------|
| `include/ScalarConverter.hpp` | `ScalarConverter` class (static method only) |
| `include/ScalarConverter.tpp` | Template helpers for conversion |
| `include/Utils.hpp` | Utility helpers |
| `src/ScalarConverter.cpp` | `convert()` implementation |
| `src/Utils.cpp` | Utility implementations |
| `src/main.cpp` | Test driver |
| `Makefile` | Build configuration; produces the `ex00` executable |
