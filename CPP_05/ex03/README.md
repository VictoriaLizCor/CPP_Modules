# CPP_05 / ex03 — At Least This Beats Coffee-Making

## Objective

Add an `Intern` class that acts as a **factory**: given a form name and target, it creates and returns a pointer to the appropriate concrete `AForm` subclass.

## What the Executable Does

```
$ ./ex03
Intern creates robotomy request
(form created and executed)
Intern creates shrubbery creation
(form created and executed)
Intern creates presidential pardon
(form created and executed)
Intern cannot create unknown form
```

The intern uses an array-of-function-pointers (or equivalent) technique to avoid a long `if/else` chain when mapping form names to constructors.

## Key Learning Objectives

- Factory method pattern: `Intern::makeForm(std::string type, std::string target)`
- Using an array of function-pointer pairs to dispatch construction
- Throws (or prints an error) when an unrecognised form name is supplied
- Clean memory management: caller owns the returned `AForm*` and must `delete` it

## Build and Usage

```bash
make
./ex03
```

## Files

| File | Description |
|------|-------------|
| `include/Intern.hpp` | `Intern` class declaration |
| `include/AForm.hpp` | Abstract base |
| `include/ShrubberyCreationForm.hpp` | Concrete form |
| `include/RobotomyRequestForm.hpp` | Concrete form |
| `include/PresidentialPardonForm.hpp` | Concrete form |
| `include/Bureaucrat.hpp` | Used to sign/execute returned forms |
| `src/Intern.cpp` | `makeForm()` factory implementation |
| `src/AForm.cpp` | Abstract base |
| `src/ShrubberyCreationForm.cpp` | Shrubbery execution |
| `src/RobotomyRequestForm.cpp` | Robotomy execution |
| `src/PresidentialPardonForm.cpp` | Pardon execution |
| `src/Bureaucrat.cpp` | Bureaucrat implementation |
| `src/main.cpp` | Test driver |
| `Makefile` | Build configuration; produces the `ex03` executable |
