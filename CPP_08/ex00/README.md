# CPP_08 / ex00 — Easy Find

## Objective

Write a function template `easyfind<T>` that accepts any integer container and a value, and returns an iterator to the first occurrence of that value. Throws if not found.

## What the Executable Does

```
$ ./ex00
Vector: found 3 at position 3
Vector: found 3 at position 1 (after duplicate inserted)
Vector: element -1 not found
...
(also tests Deque and List containers)
```

## Key Learning Objectives

- Function template working with any container that provides `begin()` / `end()` iterators
- `std::find()` algorithm from `<algorithm>`
- Iterator return type: `typename T::iterator` (or `const_iterator`)
- Throwing a standard exception when the element is not found
- Testing the template with `std::vector`, `std::deque`, and `std::list`

## Build and Usage

```bash
make
./ex00
```

## Files

| File | Description |
|------|-------------|
| `include/easyfind.hpp` | `easyfind<T>` template definition |
| `include/Utils.hpp` | Utility helpers |
| `include/Utils.tpp` | Template utility implementations |
| `src/Utils.cpp` | Utility implementations |
| `src/main.cpp` | Tests with `std::vector`, `std::deque`, and `std::list` |
| `Makefile` | Build configuration; produces the `ex00` executable |
