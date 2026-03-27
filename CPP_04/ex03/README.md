# CPP_04 / ex03 — Interface and Recap

## Objective

Design an RPG-style system using **pure-virtual interfaces** (`ICharacter`, `IMateriaSource`), an **abstract class** (`AMateria`), and concrete implementations (`Ice`, `Cure`, `Character`, `MateriaSource`).

## What the Executable Does

```
$ ./ex03
[1] ice (created)
[2] cure (created)
...
src learns ice
src learns cure
bob equips ice
bob equips cure
bob uses ice on eve  -> * shoots an ice bolt at eve *
bob uses cure on eve -> + heals eve of her wounds +
...
```

The program:
- Creates a `MateriaSource`, teaches it materia types
- Creates a `Character`, equips materia from the source (up to 4 slots)
- Characters use materia on each other
- Dropped materia is tracked in a `DoubleLinkedList` to prevent memory leaks

## Key Learning Objectives

- Pure-virtual interface classes (`ICharacter`, `IMateriaSource`) with no data members
- Abstract class `AMateria` with pure virtual `clone()` and `use()` methods
- Shallow vs. deep copy considerations with polymorphic objects
- Memory management: a custom doubly-linked list tracks all dropped materia
- Factory pattern: `MateriaSource::createMateria(type)` instantiates the right subtype

## Build and Usage

```bash
make
./ex03
```

## Files

| File | Description |
|------|-------------|
| `include/ICharacter.hpp` | `ICharacter` interface |
| `include/IMateriaSource.hpp` | `IMateriaSource` interface |
| `include/AMateria.hpp` | Abstract `AMateria` base class |
| `include/Ice.hpp` | Concrete `Ice` materia |
| `include/Cure.hpp` | Concrete `Cure` materia |
| `include/Character.hpp` | `Character` implementing `ICharacter` |
| `include/MateriaSource.hpp` | `MateriaSource` implementing `IMateriaSource` |
| `include/DoubleLinkedList.hpp` | Custom list for dropped materia tracking |
| `src/AMateria.cpp` | Abstract base implementation |
| `src/Ice.cpp` | `Ice::clone()` and `Ice::use()` |
| `src/Cure.cpp` | `Cure::clone()` and `Cure::use()` |
| `src/Character.cpp` | `Character` equip/unequip/use logic |
| `src/MateriaSource.cpp` | `MateriaSource` learn/create logic |
| `src/main.cpp` | Test driver |
| `Makefile` | Build configuration; produces the `ex03` executable |
