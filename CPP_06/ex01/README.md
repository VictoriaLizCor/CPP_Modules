# CPP_06 / ex01 — Serialization

## Objective

Implement a `Serializer` class with two **static-only** methods that convert a `Data*` pointer to a `uintptr_t` integer (`serialize`) and back to a `Data*` (`deserialize`) using `reinterpret_cast`.

## What the Executable Does

```
$ ./ex01
Serialization and deserialization successful!
Original:     { c='a', i=42, f=3.14, d=2.718 }
Deserialized: { c='a', i=42, f=3.14, d=2.718 }
------------------------------------------------------------
(corruption test)
serialization failed
Deserialized: { c='a', i=... (garbage) }
```

The binary:
1. Serializes a `Data*` to an integer
2. Deserializes it back and verifies the pointer is identical to the original
3. Attempts a corruption test by adding 1 to the serialized value, confirming failure

## Key Learning Objectives

- `reinterpret_cast<uintptr_t>(ptr)` — treating a pointer as an integer
- `reinterpret_cast<Data*>(uintptr_t)` — converting back without undefined behaviour
- The `uintptr_t` type: guaranteed to hold a pointer value
- When `reinterpret_cast` is appropriate (serialization, low-level memory) and when to avoid it

## Build and Usage

```bash
make
./ex01
```

## Files

| File | Description |
|------|-------------|
| `include/Data.hpp` | `Data` struct (simple aggregate) |
| `include/Serializer.hpp` | `Serializer` class with static `serialize`/`deserialize` |
| `include/Utils.hpp` | Utility helpers |
| `src/Data.cpp` | `Data` implementation |
| `src/Serializer.cpp` | `serialize()` and `deserialize()` |
| `src/Utils.cpp` | Utility implementations |
| `src/main.cpp` | Serialization and corruption tests |
| `Makefile` | Build configuration; produces the `ex01` executable |
