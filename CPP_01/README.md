# CPP_01 — Memory Allocation and Pointers

## Overview

**Focus:** Dynamic memory management and understanding memory allocation.

This module dives deep into memory management:

- Difference between stack and heap memory allocation
- Pointers and pointer arithmetic
- `new` and `delete` operators for dynamic allocation
- Memory leaks and how to prevent them
- References vs. pointers
- String manipulation with dynamic memory
- Member function pointers

**Key Concepts:** Pointers, dynamic allocation, memory safety, references.

---

## Exercises

| Exercise | Executable | Description |
|----------|------------|-------------|
| [ex00](ex00/) | `zombie` | Demonstrates stack vs. heap allocation with a `Zombie` class |
| [ex01](ex01/) | `zombieHorde` | Allocates an array of zombies on the heap with a single `new[]` call |
| [ex02](ex02/) | `hi` | Compares pointers and references using a `std::string` |
| [ex03](ex03/) | `unnecesary_violence` | Contrasts reference vs. pointer members with `HumanA` and `HumanB` |
| [ex04](ex04/) | `replace` | Opens a file, replaces every occurrence of a string, and writes the result to a new file |
| [ex05](ex05/) | `harl` | Uses an array of member-function pointers to dispatch complaint levels |
| [ex06](ex06/) | `harlFilter` | Extends Harl with a `switch`-based filter that prints from a given level onward |
