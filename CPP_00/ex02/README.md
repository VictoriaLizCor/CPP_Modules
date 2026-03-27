# CPP_00 / ex02 — The Job Of Your Dreams

## Objective

Reconstruct the implementation of a pre-defined `Account` class that simulates a bank account system with deposits, withdrawals, and detailed transaction logging.

## What the Executable Does

The `account` binary runs a set of predefined tests against the `Account` class:

- Creates multiple bank accounts with initial deposit amounts
- Performs deposits and withdrawals on each account
- Prints a timestamped log line for every account creation, deposit, withdrawal, and destruction
- Validates the output against a reference log (`docs/intra.log`)

Sample output:
```
[19920104_091532] index:0;amount:42;created
[19920104_091532] index:1;amount:54;created
...
[19920104_091532] index:0;p_amount:42;amount:47;deposit
[19920104_091532] index:0;p_amount:47;amount:43;withdrawal
...
```

## Key Learning Objectives

- Implementing a class from a given header file without modifying it
- Static member variables and static member functions
- Constructors and destructors with logging side-effects
- Formatted output with `std::cout` and timestamp handling
- The Orthodox Canonical Form in practice

## Build and Usage

```bash
# Build
make

# Run tests
./account

# Compare output with reference log
make diff
```

## Files

| File | Description |
|------|-------------|
| `includes/Account.hpp` | Pre-defined `Account` class header (must not be modified) |
| `src/Account.cpp` | `Account` class implementation (deposit, withdrawal, logging) |
| `src/tests.cpp` | Test driver that exercises the `Account` class |
| `docs/intra.log` | Reference log for output validation |
| `Makefile` | Build configuration; produces the `account` executable |
