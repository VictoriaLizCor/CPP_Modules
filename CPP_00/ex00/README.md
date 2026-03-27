# CPP_00 / ex00 — Megaphone

## Objective

Implement a simple program that converts its command-line arguments to uppercase and prints them.  
If no argument is supplied the program prints a default loud noise message.

## What the Executable Does

The `megaphone` binary:
- Accepts zero or more string arguments on the command line.
- Converts every character of every argument to uppercase using `std::toupper`.
- Prints all arguments on a single line separated by spaces.
- When called with no arguments it outputs: `* LOUD AND UNBEARABLE FEEDBACK NOISE *`

```
$ ./megaphone Hello World
 HELLO WORLD
$ ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

## Key Learning Objectives

- Basic use of `std::string` and character manipulation
- Iterating over command-line arguments (`argc` / `argv`)
- Standard output with `std::cout`
- Scope resolution operator (`::`) and standard library usage

## Build and Usage

```bash
# Build
make

# Run with arguments
./megaphone Damnit "!" "Sorry students, I thought this thing was off."

# Run without arguments
./megaphone
```

## Files

| File | Description |
|------|-------------|
| `megaphone.cpp` | Single-file implementation: argument processing and uppercase conversion |
| `Makefile` | Build configuration; produces the `megaphone` executable |