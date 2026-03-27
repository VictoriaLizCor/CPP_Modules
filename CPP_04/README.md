# CPP_04 — Subtype Polymorphism and Virtual Functions

## Overview

**Focus:** Polymorphic behaviour through virtual functions and abstract classes.

This module explores runtime polymorphism:

- Virtual functions and method overriding
- Pure virtual functions and abstract classes
- Upcasting and downcasting in inheritance hierarchies
- Virtual destructors
- Polymorphic containers
- Interface design patterns

**Key Concepts:** Virtual functions, abstract classes, polymorphism, vtable.

---

## Exercises

| Exercise | Executable | Description |
|----------|------------|-------------|
| [ex00](ex00/) | `ex00` | Introduces `Animal`, `Dog`, and `Cat` with a virtual `makeSound()` method; contrasts correct polymorphism with a `WrongAnimal`/`WrongCat` pair that lacks virtual dispatch |
| [ex01](ex01/) | `ex01` | Adds a `Brain` class to `Dog` and `Cat`; focuses on deep copy semantics when derived classes own heap-allocated members |
| [ex02](ex02/) | `ex02` | Makes `Animal` abstract by declaring `makeSound()` pure virtual, preventing direct instantiation |
| [ex03](ex03/) | `ex03` | Implements an RPG-style interface system: `ICharacter`, `IMateriaSource`, `AMateria`, `Ice`, `Cure`, `Character`, and `MateriaSource` |
