# CPP_01 / ex06 — Harl Filter

## Objective

Extend the `Harl` class with a `switch`-based filter: given a minimum log level, print all messages **from that level onward** (inclusive), ignoring lower-priority levels.

## What the Executable Does

```
$ ./harlFilter <level>
```

Accepts one argument (a log level string) and prints all Harl messages from that level through `ERROR`:

```
$ ./harlFilter WARNING
[ WARNING ]
I think I deserve to have some extra bacon for free...

[ ERROR ]
This is unacceptable! I want to speak to the manager now.
```

If an unrecognised level is passed, all messages are suppressed and a usage hint is shown.

## Key Learning Objectives

- `switch` statement with fall-through to implement range filtering
- Mapping a runtime string to an integer case label
- Reuse of the `Harl` class from ex05 with extended behaviour
- Command-line argument validation

## Build and Usage

```bash
make
./harlFilter DEBUG
./harlFilter INFO
./harlFilter WARNING
./harlFilter ERROR
./harlFilter unknownLevel
```

## Files

| File | Description |
|------|-------------|
| `includes/Harl.hpp` | `Harl` class declaration (adds `checkType()` helper) |
| `src/Harl.cpp` | Complaint methods + `complain()` dispatcher with switch filter |
| `src/main.cpp` | Entry point: reads one argument and calls `harl.complain()` |
| `Makefile` | Build configuration; produces the `harlFilter` executable |
