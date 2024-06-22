```cpp
#include <iostream>

// Base case for the recursive template, to stop the recursion
void print(std::ostream& os) {
    // End the line after all arguments are processed
    os << std::endl;
}

// Template function to handle at least one argument
template<typename T, typename... Args>
void print(std::ostream& os, const T& value, const Args&... args) {
    os << value << " "; // Print the first argument followed by a space
    print(os, args...); // Recurse with the rest of the arguments
}

// XFunction that takes an ostream and any number of additional arguments
template<typename... Args>
void XFunction(std::ostream& os, const Args&... args) {
    print(os, args...); // Delegate to the print function
}

int main() {
    // Example usage
    XFunction(std::cout, "This", "is", "a", "test", 123, 45.67);
    return 0;
}
```