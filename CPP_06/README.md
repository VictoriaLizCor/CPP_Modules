# CPP_06 — Type Casting

## Overview

**Focus:** Different casting mechanisms in C++.

This module explains C++'s casting system:

- C-style casting and its dangers
- `static_cast<>` for safe, compile-time casts
- `dynamic_cast<>` for polymorphic type checking at runtime
- `const_cast<>` for removing `const`
- `reinterpret_cast<>` for low-level bit-level casting
- When and why to use each cast type

**Key Concepts:** Type safety, compile-time vs. runtime casting, polymorphic type checking.

---

## Exercises

| Exercise | Executable | Description |
|----------|------------|-------------|
| [ex00](ex00/) | `ex00` | `ScalarConverter`: converts a string literal to `char`, `int`, `float`, and `double` using `static_cast` |
| [ex01](ex01/) | `ex01` | `Serializer`: converts a `Data*` pointer to `uintptr_t` and back using `reinterpret_cast` |
| [ex02](ex02/) | `ex02` | Runtime type identification: generates a random `Base*` (pointing to `A`, `B`, or `C`) and identifies the actual type using `dynamic_cast` |
