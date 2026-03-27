# CPP_03 / ex00 — Aaaaand… OPEN!

## Objective

Implement the `ClapTrap` class — the base robot for the CPP_03 series — with hit points, energy points, attack damage, and the ability to attack and self-repair.

## What the Executable Does

The `ex00` binary creates two `ClapTrap` objects that fight each other. Each turn one either attacks or repairs based on its current health, until one runs out of hit points or both exhaust their energy:

```
$ ./ex00
ClapTrap Obj_1 has been created! (HP:10 EP:10 AD:0)
ClapTrap Obj_2 has been created! (HP:10 EP:10 AD:0)
ClapTrap Obj_1 attacks Obj_2, causing 0 points of damage!
...
ClapTrap Obj_1 has been destroyed!
ClapTrap Obj_2 has been destroyed!
```

## Key Learning Objectives

- Class design with private/protected attributes (`_name`, `_hitPoints`, `_energyPoints`, `_attackDamage`)
- Constructor/destructor logging to observe object lifetime
- Member functions: `attack()`, `takeDamage()`, `beRepaired()`
- Protecting against taking actions with 0 hit points or 0 energy points

## Build and Usage

```bash
make
./ex00
```

## Files

| File | Description |
|------|-------------|
| `include/ClapTrap.hpp` | `ClapTrap` class declaration |
| `src/ClapTrap.cpp` | OCF constructors and destructor |
| `src/ClapTrapMemberFunctions.cpp` | `attack()`, `takeDamage()`, `beRepaired()` |
| `src/main.cpp` | Battle simulation test driver |
| `Makefile` | Build configuration; produces the `ex00` executable |
