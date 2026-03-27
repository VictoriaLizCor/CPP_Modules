# CPP_04 / ex02 — Abstract Class

## Objective

Make `Animal` an **abstract class** by declaring `makeSound()` as a pure virtual function, preventing direct instantiation of `Animal` objects.

## What the Executable Does

```
$ ./ex02
------------MORE TESTS----------
---
Cat: Meow!
Dog: Woof!
---
Dog destroyed (with Brain)
Cat destroyed (with Brain)
---
Dog (stray) created
Dog (clone) created
Brain of clone matches original? No (deep copy confirmed)
...
```

The binary tests that:
- `Animal` cannot be instantiated directly (compile-time enforcement)
- `Dog` and `Cat` still work correctly through base-class pointers
- Deep copy semantics from ex01 are preserved

## Key Learning Objectives

- Pure virtual functions: `virtual void makeSound() const = 0;`
- Abstract classes: a class with at least one pure virtual function cannot be instantiated
- The compiler enforces that derived classes override pure virtual functions
- Combining abstract base classes with deep copy and polymorphic containers

## Build and Usage

```bash
make
./ex02
```

## Files

| File | Description |
|------|-------------|
| `include/Animal.hpp` | Abstract `Animal` (pure virtual `makeSound()`) |
| `include/Brain.hpp` | `Brain` class |
| `include/Dog.hpp` | Concrete `Dog` |
| `include/Cat.hpp` | Concrete `Cat` |
| `src/Animal.cpp` | Abstract base implementation |
| `src/Brain.cpp` | `Brain` OCF |
| `src/Dog.cpp` | `Dog` with deep copy |
| `src/Cat.cpp` | `Cat` with deep copy |
| `src/main.cpp` | Test driver |
| `Makefile` | Build configuration; produces the `ex02` executable |
