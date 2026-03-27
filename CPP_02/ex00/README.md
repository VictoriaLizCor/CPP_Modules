# CPP_02 / ex00 — My First Class in Orthodox Canonical Form

## Objective

Create the first version of a `Fixed` class representing a fixed-point number. The class must strictly follow the **Orthodox Canonical Form** (default constructor, copy constructor, copy-assignment operator, destructor) and store the value as a raw integer with 8 fractional bits.

## What the Executable Does

The `ex00` binary instantiates several `Fixed` objects, uses the copy constructor and assignment operator, and prints the raw integer value stored in each:

```
$ ./ex00
Default constructor called
Copy constructor called
Copy assignment operator called
Default constructor called
Copy assignment operator called
0
0
0
Destructor called
Destructor called
Destructor called
```

Every canonical function logs a message, confirming it is being called correctly.

## Key Learning Objectives

- Orthodox Canonical Form: default constructor, copy constructor, copy-assignment operator, destructor
- Private integer member (`_value`) with 8 fractional bits
- `getRawBits()` and `setRawBits()` accessors
- Const member functions
- The `this` pointer in the assignment operator

## Build and Usage

```bash
make
./ex00
```

## Files

| File | Description |
|------|-------------|
| `includes/Fixed.hpp` | `Fixed` class declaration |
| `src/Fixed.cpp` | Constructor, copy, assignment, destructor + accessor implementations |
| `src/main.cpp` | Test driver |
| `Makefile` | Build configuration; produces the `ex00` executable |
