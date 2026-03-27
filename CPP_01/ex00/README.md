# CPP_01 / ex00 — BraiiiiiiinnnzzzZ

## Objective

Create a `Zombie` class and two free functions — `newZombie` and `randomChump` — to explore the difference between stack and heap memory allocation.

## What the Executable Does

The `zombie` binary:
- Creates `Zombie` objects on both the stack and the heap
- Prints the address of each zombie alongside a message showing whether it lives in stack or heap memory
- Demonstrates that heap-allocated zombies must be explicitly `delete`d, while stack zombies are destroyed automatically when they go out of scope
- Uses a static helper to compare pointer addresses against a known stack address

```
$ ./zombie
Heap1: BraiiiiiiinnnzzzZ
Address of i_stack:   140723...
Address start of HEAP: 21791...
Address of HEAP Heap1: 21791...
***Zombie Stack1 instance created in Stack memory
***Zombie Heap1 instance created in Heap memory
...
```

## Key Learning Objectives

- Stack vs. heap memory allocation
- `new` and `delete` for single objects
- When to use heap allocation (objects that must outlive their creating scope)
- Pointers and the concept of object lifetime

## Build and Usage

```bash
make
./zombie
```

## Files

| File | Description |
|------|-------------|
| `includes/Zombie.hpp` | `Zombie` class declaration |
| `src/Zombie.cpp` | Constructor, destructor, and `announce()` implementation |
| `src/newZombie.cpp` | `newZombie()` – allocates a `Zombie` on the heap and returns a pointer |
| `src/randomChump.cpp` | `randomChump()` – creates a `Zombie` on the stack and calls `announce()` |
| `src/main.cpp` | Test driver comparing stack and heap zombie addresses |
| `Makefile` | Build configuration; produces the `zombie` executable |
