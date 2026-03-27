# CPP_05 / ex02 — No, You Need Form 28B, Not 28C…

## Objective

Rename `Form` to `AForm` (abstract), add a pure virtual `execute()` method, and implement three concrete form types, each with specific execution behaviour.

## What the Executable Does

```
$ ./ex02
------testShrubberyBasic------
BureaucratA couldn't execute ShrubberyCreationForm because: Form not signed
BureaucratB couldn't execute ShrubberyCreationForm because: GradeTooLowException
BureaucratB signed ShrubberyCreationForm
BureaucratB executed ShrubberyCreationForm
(creates <target>_shrubbery file with ASCII trees)

------testRobotomy------
** DRILLING NOISES **
<target> has been robotomised!   (50% chance)

------testPresidentialPardon------
<target> has been pardoned by Zaphod Beeblebrox.
```

## Key Learning Objectives

- Renaming a concrete class to an abstract base class (`AForm`)
- Pure virtual `execute(Bureaucrat const&)` — derived classes must implement it
- Three distinct execution side-effects:
  - `ShrubberyCreationForm`: writes ASCII trees to `<target>_shrubbery`
  - `RobotomyRequestForm`: 50% chance of successful robotomisation
  - `PresidentialPardonForm`: announces a presidential pardon
- `executeForm()` on `Bureaucrat` attempts execution and reports success/failure

## Build and Usage

```bash
make
./ex02
```

## Files

| File | Description |
|------|-------------|
| `include/AForm.hpp` | Abstract `AForm` base class |
| `include/ShrubberyCreationForm.hpp` | Writes ASCII tree file |
| `include/RobotomyRequestForm.hpp` | 50% robotomisation |
| `include/PresidentialPardonForm.hpp` | Presidential pardon |
| `include/Bureaucrat.hpp` | Adds `executeForm()` |
| `include/Files.hpp` | File I/O helper |
| `src/AForm.cpp` | Abstract base implementation |
| `src/ShrubberyCreationForm.cpp` | Shrubbery execution |
| `src/RobotomyRequestForm.cpp` | Robotomy execution |
| `src/PresidentialPardonForm.cpp` | Pardon execution |
| `src/Bureaucrat.cpp` | Adds `executeForm()` |
| `src/main.cpp` | Test driver |
| `Makefile` | Build configuration; produces the `ex02` executable |
