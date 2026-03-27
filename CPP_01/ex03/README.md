# CPP_01 / ex03 — Unnecessary Violence

## Objective

Contrast using a **reference member** (`HumanA`) versus a **pointer member** (`HumanB`) to hold a `Weapon`, illustrating when each approach is appropriate.

## What the Executable Does

The `unnecesary_violence` binary creates two humans and demonstrates weapon interaction:

- `HumanA` is **always armed** — it holds a reference to a `Weapon` that must be provided at construction time
- `HumanB` **may or may not be armed** — it holds a pointer to a `Weapon` that can be set or changed at any time (including `nullptr`)

```
$ ./unnecesary_violence
Bob attacks with his crude spiked club
Bob attacks with his some other type of club
Jim attacks with no weapon
Jim attacks with his crude spiked club
Jim attacks with his some other type of club
Jim attacks with his some other type of club
Jim attacks with no weapon
```

## Key Learning Objectives

- Reference members: must be initialised in the constructor's initialiser list; cannot be reseated
- Pointer members: can be `nullptr`, can be reassigned at runtime
- Choosing between references and pointers based on optionality and lifetime
- `Weapon::setType()` — changing the weapon affects all holders simultaneously

## Build and Usage

```bash
make
./unnecesary_violence
```

## Files

| File | Description |
|------|-------------|
| `includes/Weapon.hpp` | `Weapon` class (stores type string; `getType()` returns `const std::string&`) |
| `includes/HumanA.hpp` | `HumanA` class (reference member `Weapon&`) |
| `includes/HumanB.hpp` | `HumanB` class (pointer member `Weapon*`) |
| `src/Weapon.cpp` | `Weapon` implementation |
| `src/HumanA.cpp` | `HumanA::attack()` implementation |
| `src/HumanB.cpp` | `HumanB::attack()` and `setWeapon()` implementation |
| `src/main.cpp` | Test driver; exercises both human types |
| `Makefile` | Build configuration; produces the `unnecesary_violence` executable |
