# CPP_03 / ex02 — Repetita Iuvant

## Objective

Add a second `ClapTrap` subclass, `FragTrap`, with its own stats and the unique `highFivesGuys()` method. Demonstrates a second inheritance branch alongside `ScavTrap`.

## What the Executable Does

The `ex02` binary runs battles involving both `ScavTrap` and `FragTrap` objects:

```
$ ./ex02
ClapTrap (base) has been created!
ScavTrap Obj_1 has been created! (HP:100 EP:50 AD:20)
ClapTrap (base) has been created!
FragTrap Obj_2 has been created! (HP:100 EP:100 AD:30)
FragTrap Obj_2: High Five, guys!
...
```

`FragTrap` stats: 100 HP, 100 EP, 30 AD.

## Key Learning Objectives

- Creating a second independent inheritance branch from the same base
- Each derived class defines its own constructor with distinct default values
- `highFivesGuys()` as a unique method available only on `FragTrap`
- Reviewing constructor/destructor ordering in both branches

## Build and Usage

```bash
make
./ex02
```

## Files

| File | Description |
|------|-------------|
| `include/ClapTrap.hpp` | Base class |
| `include/ScavTrap.hpp` | First derived class |
| `include/FragTrap.hpp` | `FragTrap` class declaration |
| `src/ClapTrap.cpp` | Base OCF |
| `src/ClapTrapMemberFunctions.cpp` | Base member functions |
| `src/ScavTrap.cpp` | `ScavTrap` implementation |
| `src/FragTrap.cpp` | `FragTrap` constructors, destructor, `highFivesGuys()` |
| `src/main.cpp` | Test driver |
| `Makefile` | Build configuration; produces the `ex02` executable |
