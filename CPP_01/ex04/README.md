# CPP_01 / ex04 — Sed Is for Losers

## Objective

Implement a program that opens a file, replaces every occurrence of a given string `s1` with `s2`, and writes the modified content to a new file — **without using `std::string::replace`**.

## What the Executable Does

The `replace` binary:

```
$ ./replace <filename> <s1> <s2>
```

- Opens `<filename>` for reading
- Creates a new file `<filename>.replace` with every occurrence of `s1` substituted by `s2`
- Uses only `std::string::find` and string concatenation; never `std::string::replace`
- Handles errors: file not found, empty `s1`/`s2`, read/write failures

```
$ ./replace docs/test.txt hello world
# creates docs/test.txt.replace with "hello" replaced by "world"
```

The implementation shows four variants of the replacement strategy (used internally for pedagogical comparison).

## Key Learning Objectives

- Opening and reading files with `std::ifstream`
- Writing files with `std::ofstream`
- Manual string search and substitution (`std::string::find`, substring extraction)
- File error handling with exceptions (`std::runtime_error`)
- Dynamic string construction without in-place replacement

## Build and Usage

```bash
make
./replace <filename> <s1> <s2>

# Example
./replace docs/test.txt foo bar
```

## Files

| File | Description |
|------|-------------|
| `includes/Files.hpp` | `Files` class declaration (wraps file I/O and replacement logic) |
| `src/Files.cpp` | `Files` class implementation |
| `src/main.cpp` | Entry point: argument parsing, invokes `Files` replacement |
| `docs/test.txt` | Sample input file for testing |
| `docs/funny` | Additional test input |
| `docs/longText` | Additional test input |
| `Makefile` | Build configuration; produces the `replace` executable |
