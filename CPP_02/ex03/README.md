# CPP_02 / ex03 — BSP

## Objective

Use the fully-featured `Fixed` class to implement a **Binary Space Partitioning** function `bsp()` that determines whether a point lies strictly inside a triangle.

## What the Executable Does

The `ex03` binary defines a triangle `abc` and tests several points:

```
$ ./ex03
       b(0, 20)
       * *
       *  *
       *   *
       *    *   p1(20, 0)
       *     *
       *  p2  *
p3     *(10, 3)*
a(0, 0) ******** c( 15 , 0)

Is p inside of abc?
p1: 0
p2: 1
p3: 0
```

- `p1` (20, 0) — outside the triangle → `false`
- `p2` (10, 3) — inside the triangle → `true`
- `p3` (0, 0) — on a vertex → `false` (BSP returns false for edge/vertex cases)

## Key Learning Objectives

- Practical application of the overloaded `Fixed` operators
- Cross-product sign test for point-in-triangle: each sub-triangle formed by the point and an edge must have the same sign
- Fixed-point arithmetic precision in geometric computations
- `Point` class with `const Fixed` members (set only at construction)

## Build and Usage

```bash
make
./ex03
```

## Files

| File | Description |
|------|-------------|
| `includes/Fixed.hpp` | Complete `Fixed` class |
| `includes/Point.hpp` | `Point` class with `const Fixed x, y` members |
| `src/Fixed.cpp` | Core OCF + conversions |
| `src/FixedArithmeticOperators.cpp` | Arithmetic operators |
| `src/FixedBooleanOperators.cpp` | Comparison operators |
| `src/FixedMemberFunctions.cpp` | Increment/decrement, `min`/`max` |
| `src/Point.cpp` | `Point` constructors |
| `src/bsp.cpp` | `bsp()` implementation |
| `src/main.cpp` | Test driver with triangle visualisation |
| `Makefile` | Build configuration; produces the `ex03` executable |
