# CPP_02 — Ad-Hoc Polymorphism and Operator Overloading

## Overview

**Focus:** Operator overloading to create intuitive interfaces.

This module teaches how to overload operators for custom types:

- Arithmetic operators (`+`, `-`, `*`, `/`)
- Comparison operators (`==`, `!=`, `<`, `>`, `<=`, `>=`)
- Assignment operator (`=`)
- Stream operators (`<<`, `>>`)
- The keyword `this` and member function behaviour
- Copy semantics and assignment
- Orthodox Canonical Form enforcement

**Key Concepts:** Operator overloading, the `this` pointer, const correctness.

---

## Exercises

| Exercise | Executable | Description |
|----------|------------|-------------|
| [ex00](ex00/) | `ex00` | First version of a fixed-point number class; enforces the Orthodox Canonical Form |
| [ex01](ex01/) | `ex01` | Extends `Fixed` with integer and float constructors plus stream output operator |
| [ex02](ex02/) | `ex02` | Full operator overloading for `Fixed`: arithmetic, comparison, increment/decrement, and `min`/`max` |
| [ex03](ex03/) | `ex03` | Uses the complete `Fixed` class to implement a Binary Space Partitioning (BSP) point-in-triangle test |
