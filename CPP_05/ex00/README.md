# CPP_05 / ex00 — Mommy, When I Grow Up, I Want to Be a Bureaucrat!

## Objective

Implement a `Bureaucrat` class with a `const` name and a grade in the range **1 (highest) to 150 (lowest)**. The class throws custom nested exception classes when the grade goes out of range.

## What the Executable Does

```
$ ./ex00
------testBasic------
Bureaucrat test, grade 6
Bureaucrat test, grade 7
...
------testExceptionLow------
Bureaucrat::GradeTooLowException
------testExceptionHigh------
Bureaucrat::GradeTooHighException
------testDecrementGrade------
...
```

Tests cover:
- Normal increment/decrement of grade
- Construction with an invalid grade (throws immediately)
- Incrementing/decrementing past the boundaries

## Key Learning Objectives

- Custom exception classes as **nested classes** inside `Bureaucrat`
- `Bureaucrat::GradeTooHighException` and `Bureaucrat::GradeTooLowException` inheriting from `std::exception`
- Throwing exceptions with `throw`
- Catching exceptions with `try { ... } catch (std::exception& e) { ... }`
- `const` member: name cannot change after construction
- Overloaded `<<` for formatted Bureaucrat output

## Build and Usage

```bash
make
./ex00
```

## Files

| File | Description |
|------|-------------|
| `include/Bureaucrat.hpp` | `Bureaucrat` class with nested exception classes |
| `include/Utils.hpp` | Utility helpers (formatting, print functions) |
| `src/Bureaucrat.cpp` | Bureaucrat OCF + `incrementGrade()`/`decrementGrade()` |
| `src/Utils.cpp` | Utility implementations |
| `src/main.cpp` | Test driver with multiple exception scenarios |
| `Makefile` | Build configuration; produces the `ex00` executable |
