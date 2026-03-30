# CPP_02 / ex02 — Fixed‑Point Operations (with optional Debug Driver)

## Description

This exercise implements a `Fixed` fixed‑point number class and demonstrates operator overloading for:

- Arithmetic: `+`, `-`, `*`, `/`
- Comparisons: `<`, `>`, `<=`, `>=`, `==`, `!=`
- Pre/Post increment & decrement: `++a`, `a++`, `--a`, `a--`
- Static helpers: `Fixed::min()`, `Fixed::max()` (const + non‑const overloads)

The project has two ways to run:

1. **Normal mode (`DEBUG=0`)** — prints the standard subject test output (simple numeric results).
2. **Debug mode (`DEBUG!=0`)** — uses `src/debug/main.cpp` to print deeper inspection output.

---

## Normal mode (no debugging) — `DEBUG=0`

### Build & run

```bash
make
./ex02
```

### What it prints

Normal mode compiles `src/main.cpp` (it is guarded by `#if (DEBUG == 0)`).

That main runs:

```cpp
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
```

So the output is:

- `a` starts at `0`
- each increment changes the value by the smallest representable step  
  (with 8 fractional bits, that step is `1/256 = 0.00390625`)
- `b` is `5.05 * 2` (≈ `10.1016` with this fixed‑point rounding)
- final line prints `max(a, b)` → `b`

Example output (format typically seen for this subject):

```
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
```

(Exact decimals depend on iostream formatting/precision.)

---

## Debug mode — `DEBUG!=0` (uses `src/debug/main.cpp`)

### Build & run with debug enabled

```bash
make fclean
make CXXFLAGS+=" -DDEBUG=1"
make
./ex02
```

You can replace `1` with `2`, `3`, or `4` to change the debug “depth”.

> Important: `src/main.cpp` is only compiled when `DEBUG == 0`.  
> When `DEBUG != 0`, the intention is to build/run the debug driver in `src/debug/main.cpp`.
> If your Makefile does not automatically switch the main file, you’ll need a `make debug`
> rule or you must compile `src/debug/main.cpp` instead of `src/main.cpp`.

---

## What debug mode prints (by DEBUG level)

All formats below come directly from the logic in `CPP_02/ex02/src/debug/main.cpp`.

### DEBUG = 1 — Fixed operation trace (best for “printed fixed��point operations”)

This mode performs a scripted sequence of operations on `Fixed foo(0.5f)` and prints:

- operation labels (`foo;`, `foo++;`, `foo = foo * 2;`, etc.)
- `toInt()` / `toFloat()`
- raw fixed‑point storage (`getRawBits()`) in decimal + binary
- IEEE‑754 float breakdown for the same value

For each operation step, the output looks like:

```
foo;
Number (float)         : 0.5000000000
toInt                  : 0
toFloat                : 0.5000000000
------------------------
Raw                    : <raw_decimal> : <raw_32bit_binary>
fNumber                : 0.5000000000 : <float_32bit_binary>
Exponent bias in b^10  : <stored_exp> - <bias> = <real_exp>
sign|exponen|franction : <S> <exp_bits> <fraction_bits>
Representation         :(-1)^<S> * 2^<E> * 1.<fraction_bits>
------------------------------------------------
```

It then prints additional labeled sections, including:
- division by `4.2f` twice (to show rounding/precision loss)
- `PRECISION LOST`
- a summary block similar to the normal subject test, plus comparisons.

---

### DEBUG = 2 — Float inspection presets (IEEE‑754 blocks only)

Prints `floatPoint(...)` output for preset float values (epsilon, max, INT_MAX, NaN, -inf…).

Repeated block format:

```
fNumber                : <number> : <32-bit pattern>
Exponent bias in b^10  : <...>
sign|exponen|franction : <...>
Representation         :(-1)^<S> * 2^<E> * 1.<mantissa>
------------------------------------------------
```

---

### DEBUG = 3 — Verbose float inspection (DEBUG=2 + intermediate steps)

Same as DEBUG=2, but `floatPoint()` also prints intermediate normalization steps:

```
		1 number: <...>
		2 number: <...>
...
```

---

### DEBUG = 4 — Limit exploration (Fixed range + stepping)

1) Prints “Epsilon …” floatPoint blocks.

2) Then prints Fixed min/max and steps raw values near the limit:

```
Max Value:		<max_value>
Min Value:		<min_value>
1 f: <a_as_float> raw: <raw_int> <raw_32bit_binary>
2 f: <a_as_float> raw: <raw_int> <raw_32bit_binary>
...
19 f: <a_as_float> raw: <raw_int> <raw_32bit_binary>
```

---

## Files

| File | Description |
|------|-------------|
| `includes/Fixed.hpp` | `Fixed` class declaration (contains default `DEBUG` macro) |
| `src/Fixed.cpp` | Constructors / assignment / destructor + `operator<<` |
| `src/FixedArithmeticOperators.cpp` | Arithmetic + increment/decrement operators |
| `src/FixedBooleanOperators.cpp` | Comparison operators |
| `src/FixedMemberFunctions.cpp` | `toFloat`, `toInt`, raw accessors, `min`/`max` (+ debug-only helpers) |
| `src/main.cpp` | Normal subject test*
