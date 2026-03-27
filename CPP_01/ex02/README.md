# CPP_01 / ex02 — HI THIS IS BRAIN

## Objective

Demonstrate the relationship between a variable, a pointer to it, and a reference to it — showing that a reference is simply an alias sharing the same memory address as the original variable.

## What the Executable Does

The `hi` binary:
- Declares a `std::string` variable `str`
- Creates a pointer `stringPTR` pointing to `str`
- Creates a reference `stringREF` aliasing `str`
- Prints the **memory address** held by each and the **value** accessed through each

```
$ ./hi
Memory addres of str variable:          0x7fff...
Memory addres held by stringPTR:        0x7fff...
Memory addres held by stringPTR:        0x7fff...

Value of str variable:          HI THIS IS BRAIN
Value pointed by stringPTR:     HI THIS IS BRAIN
Value pointed by stringREF:     HI THIS IS BRAIN
```

All three addresses are identical, confirming that the reference and the pointer both refer to the same underlying object.

## Key Learning Objectives

- References as aliases: same address, different syntax
- Dereferencing a pointer (`*stringPTR`) vs. using a reference (`stringREF`)
- The key difference: a reference cannot be reseated after initialisation, whereas a pointer can
- When to prefer references over pointers in C++

## Build and Usage

```bash
make
./hi
```

## Files

| File | Description |
|------|-------------|
| `main.cpp` | Single-file implementation demonstrating pointer vs. reference semantics |
| `Makefile` | Build configuration; produces the `hi` executable |
