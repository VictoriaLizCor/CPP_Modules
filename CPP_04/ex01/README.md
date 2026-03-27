# CPP_04 / ex01 — I Don't Want to Set the World on Fire

## Objective

Add a `Brain` class that stores 100 ideas as strings. Assign a heap-allocated `Brain` to each `Dog` and `Cat`. Implement correct **deep copy** semantics so that copying an animal copies its brain — not just the pointer.

## What the Executable Does

```
$ ./ex01
---
Cat created (id:1)
Dog created (id:2)
...
Total Animals created: 10/10
---
Cat: Meow!
Dog: Woof!
...
---
(all deleted in reverse order)
```

A second test creates a `Dog`, copies it, modifies the copy's brain, and confirms the original's brain is unaffected — proving the deep copy is correct.

## Key Learning Objectives

- Heap allocation inside a class: `Brain* _brain = new Brain()`
- Copy constructor that allocates a new `Brain` and copies its contents
- Copy-assignment operator that replaces `_brain` with a freshly allocated copy
- Destructor that `delete`s the `Brain` pointer
- Polymorphic arrays: `const Animal* animals[N]` storing a mix of `Dog` and `Cat`

## Build and Usage

```bash
make
./ex01
```

## Files

| File | Description |
|------|-------------|
| `include/Animal.hpp` | Base class |
| `include/Brain.hpp` | `Brain` class (array of 100 `std::string` ideas) |
| `include/Dog.hpp` | `Dog` with `Brain* _brain` member |
| `include/Cat.hpp` | `Cat` with `Brain* _brain` member |
| `src/Animal.cpp` | Base class implementation |
| `src/Brain.cpp` | `Brain` OCF implementation |
| `src/Dog.cpp` | `Dog` with deep copy |
| `src/Cat.cpp` | `Cat` with deep copy |
| `src/main.cpp` | Polymorphic array + deep copy test |
| `Makefile` | Build configuration; produces the `ex01` executable |
