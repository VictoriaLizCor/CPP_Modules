# CPP_05 / ex01 — Form Up, Maggots!

## Objective

Add a `Form` class that has a `const` name, a `bool` signed status, a minimum grade required to sign it, and a minimum grade required to execute it. Bureaucrats can attempt to sign forms using `signForm()`.

## What the Executable Does

```
$ ./ex01
------testBasic------
Bureaucrat Bureaucrat, grade 11
Bureaucrat Bureaucrat couldn't sign Form  because Bureaucrat::GradeTooLowException
Bureaucrat incremented to grade 10
Bureaucrat Bureaucrat signed Form
Form already signed
...
```

Exercises `signForm()` on a `Bureaucrat` that:
1. Initially has too low a grade to sign
2. After incrementing, signs successfully
3. Attempts to sign an already-signed form

## Key Learning Objectives

- `Form` class with `const` members (name, minimum grades)
- `beSigned(Bureaucrat const&)` throws `GradeTooLowException` when the bureaucrat's grade is too low
- `signForm()` on `Bureaucrat` wraps the sign attempt and prints a success or failure message
- Exception propagation across classes

## Build and Usage

```bash
make
./ex01
```

## Files

| File | Description |
|------|-------------|
| `include/Bureaucrat.hpp` | `Bureaucrat` with `signForm()` |
| `include/Form.hpp` | `Form` class declaration |
| `include/GradeException.hpp` | Custom exception helpers |
| `include/Utils.hpp` | Utility helpers |
| `src/Bureaucrat.cpp` | Bureaucrat implementation |
| `src/Form.cpp` | `Form` OCF + `beSigned()` |
| `src/GradeException.cpp` | Exception implementation |
| `src/Utils.cpp` | Utility implementations |
| `src/main.cpp` | Test driver |
| `Makefile` | Build configuration; produces the `ex01` executable |
