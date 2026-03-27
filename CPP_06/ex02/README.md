# CPP_06 / ex02 — Identify Real Type

## Objective

Implement three empty classes `A`, `B`, `C` that all derive from `Base`. Write functions `generate()` (returns a randomly typed `Base*`) and `identify()` (determines the actual type via `dynamic_cast`) in both pointer and reference forms.

## What the Executable Does

```
$ ./ex02
A generated
----Pointer----
A pointer
----Reference----
A reference
(repeated for random types)
```

Demonstrates:
- `dynamic_cast<A*>(p)` returns a non-null pointer only if `p` actually points to an `A` — otherwise `nullptr`
- `dynamic_cast<A&>(r)` throws `std::bad_cast` if the reference does not actually refer to an `A`

## Key Learning Objectives

- `dynamic_cast<>` requires the base class to be polymorphic (at least one virtual function / virtual destructor)
- Pointer form: returns `nullptr` on failure — safe to check with `if`
- Reference form: throws `std::bad_cast` on failure — must use `try/catch`
- Runtime type identification without `typeid`
- When to use `dynamic_cast` vs. redesigning to avoid it

## Build and Usage

```bash
make
./ex02
```

## Files

| File | Description |
|------|-------------|
| `include/Base.hpp` | `Base` class with `virtual ~Base()` |
| `include/A.hpp` | Empty class inheriting `Base` |
| `include/B.hpp` | Empty class inheriting `Base` |
| `include/C.hpp` | Empty class inheriting `Base` |
| `include/Utils.hpp` | Utility helpers |
| `src/Base.cpp` | `Base` destructor implementation |
| `src/Utils.cpp` | Utility implementations |
| `src/main.cpp` | `generate()`, `identify(Base*)`, `identify(Base&)`, test loop |
| `Makefile` | Build configuration; produces the `ex02` executable |
