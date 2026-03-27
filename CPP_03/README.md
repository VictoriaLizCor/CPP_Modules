# CPP_03 — Inheritance

## Overview

**Focus:** Class hierarchies and inheritance relationships.

This module introduces object-oriented inheritance:

- Base classes and derived classes
- Access modifiers in inheritance (`public`, `protected`, `private`)
- Constructor and destructor chaining
- Method overriding
- Multiple inheritance and the diamond problem
- The Orthodox Canonical Form in inherited classes

**Key Concepts:** Inheritance, virtual functions, constructor chaining, method overriding.

---

## Exercises

| Exercise | Executable | Description |
|----------|------------|-------------|
| [ex00](ex00/) | `ex00` | Implements the base `ClapTrap` robot class with hit points, energy points, and attack/repair actions |
| [ex01](ex01/) | `ex01` | Adds `ScavTrap`, a class derived from `ClapTrap` with overridden stats and a unique `guardGate()` ability |
| [ex02](ex02/) | `ex02` | Adds `FragTrap`, another `ClapTrap` derivative with different stats and a `highFivesGuys()` ability |
| [ex03](ex03/) | `ex03` | Introduces `DiamondTrap`, which inherits from **both** `ScavTrap` and `FragTrap`, demonstrating the diamond problem and virtual inheritance |
