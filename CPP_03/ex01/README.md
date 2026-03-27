# CPP_03 / ex01 — Serena My Love

## Objective

Derive `ScavTrap` from `ClapTrap`, overriding its stats and introducing a unique `guardGate()` action. Demonstrates single inheritance, constructor/destructor chaining, and method overriding.

## What the Executable Does

The `ex01` binary pits a `ClapTrap` against a `ScavTrap`:

```
$ ./ex01
ClapTrap Obj_1 has been created! (HP:10 EP:10 AD:0)
ScavTrap Obj_2 has been created! (HP:100 EP:50 AD:20)
ScavTrap Obj_2 is now in Gate keeper mode.
...
ScavTrap Obj_2 has been destroyed!
ClapTrap Obj_1 has been destroyed!
```

Key observations:
- `ScavTrap` constructor calls `ClapTrap` constructor first; `ScavTrap` destructor runs before `ClapTrap`'s
- `ScavTrap` has different base stats (100 HP, 50 EP, 20 AD)
- The `attack()` message differs from `ClapTrap`'s

## Key Learning Objectives

- Single inheritance: `ScavTrap : public ClapTrap`
- Constructor chaining — base class constructor called before derived
- Destructor chaining — derived destructor called before base
- Method overriding (`attack()`)
- `protected` vs `private` member access in derived classes

## Build and Usage

```bash
make
./ex01
```

## Files

| File | Description |
|------|-------------|
| `include/ClapTrap.hpp` | Base class declaration |
| `include/ScavTrap.hpp` | `ScavTrap` class declaration |
| `src/ClapTrap.cpp` | Base class OCF |
| `src/ClapTrapMemberFunctions.cpp` | Base member functions |
| `src/ScavTrap.cpp` | `ScavTrap` constructors, destructor, `attack()`, `guardGate()` |
| `src/main.cpp` | Test driver |
| `Makefile` | Build configuration; produces the `ex01` executable |
