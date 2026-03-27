# CPP_09 / ex00 — Bitcoin Exchange

## Objective

Implement a Bitcoin exchange rate program (`btc`) that reads a historical price CSV file into a `std::map<std::string, float>` and evaluates an input file of `date | value` pairs, printing the value multiplied by the Bitcoin price on (or just before) that date.

## What the Executable Does

```
$ ./btc data/input.txt
2011-01-03 => 1 = 0.29
2011-01-11 => 1 = 0.29
2011-09-19 => 0.5 = 2.97
2012-01-11 => 1 = 7.10
...
Error: bad input => 2001-42-42
Error: not a positive number.
Error: too large a number.
```

- Parses `data/data.csv` (historical Bitcoin prices) into a `std::map`
- For each line in the input file, uses `std::map::lower_bound` to find the closest earlier date
- Validates dates and values; prints descriptive errors for malformed lines

## Key Learning Objectives

- `std::map<std::string, float>` for ordered key-value storage
- `std::map::lower_bound` / `upper_bound` for range queries
- CSV parsing and date validation
- File I/O with `std::ifstream`
- Handling edge cases: missing dates, out-of-range values, malformed lines

## Build and Usage

```bash
make
./btc <input_file>

# Example
./btc data/input.txt
```

## Files

| File | Description |
|------|-------------|
| `include/BitcoinExchange.hpp` | `BitcoinExchange` class declaration |
| `include/DateUtils.hpp` | Date parsing and validation utilities |
| `include/Utils.hpp` | General utility helpers |
| `src/BitcoinExchange.cpp` | Exchange rate lookup and output logic |
| `src/CheckFile.cpp` | Input file validation |
| `src/DateUtils.cpp` | Date utility implementations |
| `src/Utils.cpp` | Utility implementations |
| `src/main.cpp` | Entry point |
| `data/data.csv` | Historical Bitcoin price database |
| `data/input.txt` | Sample input for testing |
| `Makefile` | Build configuration; produces the `btc` executable |
