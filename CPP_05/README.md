# CPP_05 — Exception Handling and More OOP Concepts

## Overview

**Focus:** Robust error handling and advanced OOP patterns.

This module covers error handling and design patterns:

- Try-catch-throw exception handling
- Standard exceptions (`std::exception`)
- Exception safety guarantees
- Nested classes
- Static members and static functions
- Friend classes and functions

**Key Concepts:** Exception handling, static members, friends, nested classes.

---

## Exercises

| Exercise | Executable | Description |
|----------|------------|-------------|
| [ex00](ex00/) | `ex00` | Implements a `Bureaucrat` class with grade validation; throws custom nested exceptions for out-of-range grades |
| [ex01](ex01/) | `ex01` | Adds a `Form` class that can be signed by a bureaucrat with sufficient grade; throws on invalid operations |
| [ex02](ex02/) | `ex02` | Introduces three concrete form types (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) inheriting from abstract `AForm` |
| [ex03](ex03/) | `ex03` | Adds an `Intern` class that acts as a factory, creating any of the three concrete forms by name |
