# CPP_08 / ex02 — Mutant Stack

## Objective

Create `MutantStack<T>`, a class template that inherits from `std::stack<T>` and adds iterator support, allowing iteration over the stack's elements without popping them.

## What the Executable Does

```
$ ./ex02
MutantStack: [34, 91, 22, 78, 5, ...]
Copy:        [34, 91, 22, 78, 5, ...]
(modifies copy, original unchanged)
---test push_front vs push---
MutantStack with push_front(100) and push(101): [100, 34, ..., 101]

(list comparison test)
list: [5, 17, 3, 5, 737, 0]   <- matches expected output from subject
```

## Key Learning Objectives

- Inheriting from an STL container adapter (`std::stack`)
- Exposing the underlying container (`std::deque`) via `getContainer()`
- Adding `begin()` / `end()` and `rbegin()` / `rend()` methods that delegate to the protected `c` member
- Typedef for `iterator` and `const_iterator`
- Verifying that `MutantStack` can be used with range-based algorithms and standard iteration patterns

## Build and Usage

```bash
make
./ex02
```

## Files

| File | Description |
|------|-------------|
| `include/MutantStack.hpp` | `MutantStack<T>` class template declaration |
| `include/MutantStack.tpp` | `MutantStack<T>` method implementations |
| `include/Utils.hpp` | Utility helpers |
| `include/Utils.tpp` | Template utility implementations |
| `src/Utils.cpp` | Utility implementations |
| `src/main.cpp` | Copy, iteration, and list-comparison tests |
| `Makefile` | Build configuration; produces the `ex02` executable |
