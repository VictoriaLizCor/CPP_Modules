# CPP_01 / ex01 — Moar Brainz!

## Objective

Implement `zombieHorde(int N, std::string name)` which allocates an array of `N` zombies with a **single** `new[]` call, demonstrating array allocation on the heap.

## What the Executable Does

The `zombieHorde` binary:
- Calls `zombieHorde(N, "Cersei")` to allocate an array of `N` zombies on the heap
- Iterates through the array and calls `announce()` on each zombie
- Deletes the entire array with a single `delete[]` call

```
$ ./zombieHorde
********** Z1 ************
Cersei: BraiiiiiiinnnzzzZ
Cersei: BraiiiiiiinnnzzzZ
Cersei: BraiiiiiiinnnzzzZ
************************
```

## Key Learning Objectives

- `new[]` for allocating arrays on the heap
- `delete[]` for releasing array allocations (vs. `delete`)
- The difference between allocating individual objects and arrays
- Why a single allocation is preferred over multiple `new` calls for homogeneous groups

## Build and Usage

```bash
make
./zombieHorde
```

## Files

| File | Description |
|------|-------------|
| `includes/Zombie.hpp` | `Zombie` class declaration |
| `src/Zombie.cpp` | Constructor, destructor, and `announce()` implementation |
| `src/zombieHorde.cpp` | `zombieHorde()` – single `new[]` allocation of N zombies |
| `src/main.cpp` | Test driver: calls horde allocation and iterates over zombies |
| `Makefile` | Build configuration; produces the `zombieHorde` executable |
