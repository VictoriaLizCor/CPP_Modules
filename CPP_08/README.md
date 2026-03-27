# CPP_08 — Templated Containers and Iterators

## Overview

**Focus:** Working with Standard Template Library (STL) containers.

This module explores STL containers:

- `vector`, `list`, `map`, `set`, and other containers
- Iterators and iterator patterns
- Templated container operations
- Algorithms with templates (`find`, `sort`, etc.)
- Container adaptation (`stack`, `queue`)
- Memory management in containers

**Key Concepts:** STL containers, iterators, container algorithms, memory management.

---

## Exercises

| Exercise | Executable | Description |
|----------|------------|-------------|
| [ex00](ex00/) | `ex00` | `easyfind<T>`: a template function that searches any integer container for a value and returns an iterator |
| [ex01](ex01/) | `ex01` | `Span`: a class that stores up to N integers and can compute the shortest and longest spans between stored numbers |
| [ex02](ex02/) | `ex02` | `MutantStack<T>`: extends `std::stack` to expose iterators, allowing traversal of the stack's contents |
