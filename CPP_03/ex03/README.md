# CPP_03 / ex03 — Now It's Getting Weird

## Objective

Create `DiamondTrap`, which inherits **publicly** from both `ScavTrap` and `FragTrap`. This introduces the **diamond inheritance problem** and its solution via **virtual inheritance** in C++.

## What the Executable Does

```
$ ./ex03
ClapTrap (virtual base) has been created!
ScavTrap Obj1_scav has been created!
FragTrap Obj1_frag has been created!
DiamondTrap Obj1 has been created! (HP:100 EP:50 AD:30)
DiamondTrap Obj1: High Five, guys!
DiamondTrap Obj1 is now in Gate keeper mode.
...
DiamondTrap Obj1 has been destroyed!
FragTrap Obj1_frag has been destroyed!
ScavTrap Obj1_scav has been destroyed!
ClapTrap (virtual base) has been destroyed!
```

`DiamondTrap` takes `ScavTrap`'s HP (100), `FragTrap`'s AD (30), `ScavTrap`'s EP (50), and has both `guardGate()` and `highFivesGuys()`.  
It also has a separate `ClapTrap` name (prefixed with `_clap_name`).

## Key Learning Objectives

- The diamond problem: `ClapTrap` data would be duplicated without virtual inheritance
- `virtual public ClapTrap` in both `ScavTrap` and `FragTrap` to share one `ClapTrap` sub-object
- `DiamondTrap`'s constructor must directly call the `ClapTrap` constructor
- `whoAmI()` method that prints both `DiamondTrap`'s name and the `ClapTrap` sub-object's name

## Build and Usage

```bash
make
./ex03
```

## Files

| File | Description |
|------|-------------|
| `include/ClapTrap.hpp` | Base class (used as virtual base) |
| `include/ScavTrap.hpp` | First parent (`virtual public ClapTrap`) |
| `include/FragTrap.hpp` | Second parent (`virtual public ClapTrap`) |
| `include/DiamondTrap.hpp` | `DiamondTrap` class declaration |
| `src/ClapTrap.cpp` | Base OCF |
| `src/ClapTrapMemberFunctions.cpp` | Base member functions |
| `src/ScavTrap.cpp` | `ScavTrap` implementation |
| `src/FragTrap.cpp` | `FragTrap` implementation |
| `src/DiamondTrap.cpp` | `DiamondTrap` constructors, `whoAmI()` |
| `src/main.cpp` | Test driver |
| `Makefile` | Build configuration; produces the `ex03` executable |
