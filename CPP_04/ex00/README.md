# CPP_04 / ex00 — Polymorphism

## Objective

Build an `Animal` base class with a virtual `makeSound()` method and two derived classes (`Dog`, `Cat`) that override it. Contrast this correct polymorphic hierarchy with a broken one (`WrongAnimal`, `WrongCat`) where the method is **not** virtual.

## What the Executable Does

```
$ ./ex00
Animal
Dog
Cat
---
Animal sound
Dog: Woof!
Cat: Meow!
---
WrongAnimal sound    <- WrongCat also plays WrongAnimal sound (no virtual dispatch)
WrongAnimal sound
Meow (direct call)
```

The key demonstration: when calling `makeSound()` through a `WrongAnimal*` pointing to a `WrongCat`, the base-class version runs instead of the derived class version.

## Key Learning Objectives

- Declaring `virtual` member functions in the base class
- How the vtable enables runtime dispatch to the correct override
- Virtual destructors — why the base class destructor must be `virtual`
- The effect of omitting `virtual`: static (compile-time) dispatch
- Upcasting: storing derived-class pointers in base-class pointer variables

## Build and Usage

```bash
make
./ex00
```

## Files

| File | Description |
|------|-------------|
| `include/Animal.hpp` | `Animal` base class with `virtual makeSound()` and `virtual ~Animal()` |
| `include/Dog.hpp` | `Dog` derived class |
| `include/Cat.hpp` | `Cat` derived class |
| `include/WrongAnimal.hpp` | Non-virtual base (for contrast) |
| `include/WrongCat.hpp` | Derived from `WrongAnimal` |
| `src/Animal.cpp` | `Animal` implementation |
| `src/Dog.cpp` | `Dog` implementation |
| `src/Cat.cpp` | `Cat` implementation |
| `src/WrongAnimal.cpp` | `WrongAnimal` implementation |
| `src/WrongCat.cpp` | `WrongCat` implementation |
| `src/main.cpp` | Polymorphism demonstration |
| `Makefile` | Build configuration; produces the `ex00` executable |
