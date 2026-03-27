# CPP_09 / ex02 — PmergeMe

## Objective

Implement the **Ford-Johnson merge-insert sort** algorithm on two STL containers — `std::vector<int>` and `std::deque<int>` — and report the time taken by each, demonstrating the performance difference between container types.

## What the Executable Does

```
$ ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of 5 elements with std::vector : 0.00031 us
Time to process a range of 5 elements with std::deque  : 0.00039 us

$ ./PmergeMe 1 -2
Error: invalid value
```

- Accepts a sequence of **positive integers** as command-line arguments
- Sorts the sequence using the Ford-Johnson algorithm on both containers independently
- Prints "Before" and "After" sequences
- Measures and prints the processing time in microseconds for each container

## Key Learning Objectives

- Ford-Johnson (merge-insert) sort: pairs elements, sorts pairs, then binary-searches insertion positions using Jacobsthal numbers
- `std::vector` vs. `std::deque` performance characteristics
- `std::clock()` / `gettimeofday` for high-resolution timing
- Input validation: only positive integers accepted
- Template-based implementation to avoid code duplication between the two containers

## Build and Usage

```bash
make
./PmergeMe <integer1> <integer2> ... <integerN>

# Examples
./PmergeMe 3 5 9 7 4
./PmergeMe $(shuf -i 1-100 -n 50 | tr '\n' ' ')
```

## Files

| File | Description |
|------|-------------|
| `include/PmergeMe.hpp` | `PmergeMe` class declaration |
| `include/Utils.hpp` | Utility helpers |
| `include/Utils.tpp` | Template utility implementations |
| `src/PmergeMe.cpp` | Ford-Johnson sort on `std::vector` and `std::deque` |
| `src/Utils.cpp` | Utility implementations |
| `src/main.cpp` | Argument parsing, timing, and output |
| `Makefile` | Build configuration; produces the `PmergeMe` executable |
