# CPP_09 / ex01 — Reverse Polish Notation

## Objective

Implement an RPN (Reverse Polish Notation) expression evaluator that takes a mathematical expression as a single command-line argument and prints the result, using a `std::stack` internally.

## What the Executable Does

```
$ ./RPN "3 4 +"
7
$ ./RPN "5 1 2 + 4 * + 3 -"
14
$ ./RPN "8 9 * 9 - 1 1 + 2 2 + * -"
51
$ ./RPN "(1 + 1)"
Error: invalid token
```

Supports operators `+`, `-`, `*`, `/`. Operands are single-digit integers (0–9). The program builds an expression tree, evaluates it, and prints the result.

## Key Learning Objectives

- RPN evaluation using a `std::stack`
- Building an expression tree from a postfix expression
- Error handling for malformed expressions (invalid tokens, insufficient operands, division by zero)
- `std::stack<T>` push/pop/top operations
- Command-line argument parsing and validation

## Build and Usage

```bash
make
./RPN "<expression>"

# Examples
./RPN "3 4 +"
./RPN "5 1 2 + 4 * + 3 -"
./RPN "7 7 * 7 -"
```

## Files

| File | Description |
|------|-------------|
| `include/RPN.hpp` | `RPN` class and `Node` struct declaration |
| `include/Utils.hpp` | Utility helpers |
| `src/RPN.cpp` | Tree build, evaluation, and cleanup |
| `src/Utils.cpp` | Utility implementations |
| `src/main.cpp` | Entry point: parses argument and runs evaluator |
| `test.sh` | Shell script with multiple test cases |
| `Makefile` | Build configuration; produces the `RPN` executable |
