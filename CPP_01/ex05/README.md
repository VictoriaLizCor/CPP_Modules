# CPP_01 / ex05 — Harl 2.0

## Objective

Implement the `Harl` class whose `complain(std::string level)` method uses an **array of member-function pointers** to dispatch to the appropriate complaint function without any `if`/`else` chain.

## What the Executable Does

The `harl` binary randomly invokes `Harl::complain()` a number of times with one of four log levels (`DEBUG`, `INFO`, `WARNING`, `ERROR`) or a random unknown string:

```
$ ./harl
This will run Harl::complain for 5 times
...
[ DEBUG ]
I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger...

[ INFO ]
I cannot believe adding extra bacon costs more money...

[ WARNING ]
...

[ ERROR ]
...
```

Unknown strings produce no output (or a default message).

## Key Learning Objectives

- Member-function pointers: declaring, storing in an array, and calling them
- Mapping string keys to functions without `if`/`else` chains
- Encapsulation of dispatch logic inside a class
- `std::string` comparison for lookup

## Build and Usage

```bash
make
./harl
```

## Files

| File | Description |
|------|-------------|
| `includes/Harl.hpp` | `Harl` class declaration with member-function pointer typedef |
| `src/Harl.cpp` | Four private complaint methods + `complain()` dispatcher |
| `src/main.cpp` | Randomly calls `complain()` with various levels |
| `Makefile` | Build configuration; produces the `harl` executable |
