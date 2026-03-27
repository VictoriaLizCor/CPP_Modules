# CPP_07 / ex00 — Start with a Few Functions

## Objective

Write three function templates — `swap<T>`, `min<T>`, and `max<T>` — that work with any type supporting the `<` comparison operator and assignment.

## What the Executable Does

```
$ ./ex00
a = 3, b = 2
a = 2, b = 3
min( a, b ) = 2
max( a, b ) = 3
c = chaine2, d = chaine1
c = chaine1, d = chaine2
min( c, d ) = chaine1
max( c, d ) = chaine2
```

Tests both `int` and `std::string` types through the same template instantiation.

## Key Learning Objectives

- Function template syntax: `template<typename T>`
- Template type deduction from function arguments
- Writing type-generic algorithms that rely only on operator contracts
- `swap<T>`: exchanges two values; `min<T>` and `max<T>` return a reference to the smaller/larger

## Build and Usage

```bash
make
./ex00
```

## Files

| File | Description |
|------|-------------|
| `include/whatever.hpp` | `swap`, `min`, `max` template definitions (header-only) |
| `include/Utils.hpp` | Utility helpers |
| `src/Utils.cpp` | Utility implementations |
| `src/main.cpp` | Test driver for `int` and `std::string` |
| `Makefile` | Build configuration; produces the `ex00` executable |
