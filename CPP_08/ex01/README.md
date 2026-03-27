# CPP_08 / ex01 — Span

## Objective

Implement a `Span` class that stores up to `N` integers and provides `shortestSpan()` and `longestSpan()` methods, plus a range-based `addRange()` to add multiple numbers at once.

## What the Executable Does

```
$ ./ex01
(adds 10 random integers to a Span of size 10)
Span: [342, 8901, 1234, ...]
shortestSpan: 47
longestSpan:  8559

(exception tests)
Span is full                    <- adding to a full Span
No span possible (< 2 elements) <- calling shortestSpan on 0-1 elements
```

## Key Learning Objectives

- Wrapping a `std::vector<int>` inside a custom class
- `addNumber(int)` with capacity checking (throws when full)
- `addRange(InputIterator first, InputIterator last)` using `std::copy` and `std::back_inserter`
- `shortestSpan()`: sort a copy, find minimum adjacent difference
- `longestSpan()`: `max - min` of stored values using `std::max_element` / `std::min_element`
- Custom exception classes for overflow and insufficient elements

## Build and Usage

```bash
make
./ex01
```

## Files

| File | Description |
|------|-------------|
| `include/Span.hpp` | `Span` class declaration |
| `include/Utils.hpp` | Utility helpers |
| `include/Utils.tpp` | Template utility implementations |
| `src/Span.cpp` | `Span` implementation |
| `src/Utils.cpp` | Utility implementations |
| `src/main.cpp` | Capacity, span computation, and exception tests |
| `Makefile` | Build configuration; produces the `ex01` executable |
