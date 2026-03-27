# CPP_00 / ex01 — My Awesome PhoneBook

## Objective

Build an interactive phonebook application using two classes: `Contact` and `PhoneBook`.  
The exercise introduces class design, encapsulation, and the Orthodox Canonical Form in C++98.

## What the Executable Does

The `phonebook` binary runs an interactive loop that accepts three commands:

| Command | Action |
|---------|--------|
| `ADD` | Prompts for a contact's first name, last name, nickname, phone number, and darkest secret, then stores it |
| `SEARCH` | Displays the stored contacts in a formatted table and lets the user look up a specific entry by index |
| `EXIT` | Exits the program |

The phonebook holds a maximum of **8 contacts**. When full, the oldest contact is replaced by the newest one.

```
$ ./phonebook
> ADD
First name: John
...
> SEARCH
     Index|First name| Last name|  Nickname|
         0|      John|      ....|      ....|
> EXIT
```

## Key Learning Objectives

- Class definition with private and public members
- Constructor and destructor implementation
- The Orthodox Canonical Form (default constructor, copy constructor, copy-assignment operator, destructor)
- `std::string` input/output and formatting with `std::setw` / `std::right`
- Namespace usage and code organisation across multiple files

## Build and Usage

```bash
# Build
make

# Run
./phonebook

# Build with debug output
make debug
```

## Files

| File | Description |
|------|-------------|
| `includes/Contact.hpp` | `Contact` class declaration (stores one contact's fields) |
| `includes/Phonebook.hpp` | `PhoneBook` class declaration (manages up to 8 contacts) |
| `includes/phonebookUtils.hpp` | Utility declarations for menu and display helpers |
| `includes/stringUtils.hpp` | String utility declarations |
| `src/Contact.cpp` | `Contact` class implementation |
| `src/Phonebook.cpp` | `PhoneBook` class implementation |
| `src/phonebookUtils.cpp` | Menu and display helper implementations |
| `src/stringUtils.cpp` | String utility implementations |
| `src/main.cpp` | Entry point; instantiates `PhoneBook` and calls the menu loop |
| `Makefile` | Build configuration; produces the `phonebook` executable |