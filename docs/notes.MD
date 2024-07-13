# toDo:
	* Keep track of AMaterias created objects
	* Keep track of Cure created objects
	* Keep track of Ice created objects
	* Do the same for characters
	* Increase and decrease Instance counters 

# Implicit convertion
Explicit conversion in C++ refers to a type conversion that requires explicit notation in the code to perform, indicating the programmer's intention to convert a value from one type to another. This is in contrast to implicit conversions, which the compiler performs automatically without any specific notation needed from the programmer.

There are several ways to perform explicit conversions in C++, including:

1. **C-style casting**: This is the traditional C way of converting types, using parentheses with the target type before the variable or value to be converted.
   ```cpp
   double pi = 3.14159;
   int integerPart = (int)pi; // C-style cast to convert double to int
   ```

2. **Functional notation**: Similar to C-style casting but uses the target type as if it were a function call.
   ```cpp
   double pi = 3.14159;
   int integerPart = int(pi); // Functional notation to convert double to int
   ```

3. **Static cast**: A C++-style cast that performs a compile-time type check, making it safer than C-style casts. It can be used for conversions between related types (e.g., between base and derived classes).
   ```cpp
   double pi = 3.14159;
   int integerPart = static_cast<int>(pi); // Static cast to convert double to int
   ```

4. **Dynamic cast**: Used for safe downcasting in class hierarchies, checking at runtime if the conversion is valid. It's used primarily with pointers or references to polymorphic classes.
   ```cpp
   Base* basePtr = new Derived;
   Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // Dynamic cast for downcasting
   ```

5. **Const cast**: Used to add or remove the `const` qualifier from a variable.
   ```cpp
   const int x = 10;
   int* nonConstXPtr = const_cast<int*>(&x); // Const cast to remove const qualifier
   ```

6. **Reinterpret cast**: Provides a low-level reinterpreting of the bit pattern. It's a powerful but dangerous tool that should be used sparingly.
   ```cpp
   long long address = 0x12345678;
   void* ptr = reinterpret_cast<void*>(address); // Reinterpret cast to convert integer to pointer
   ```

Explicit conversions are necessary when you need to convert types in a way that is not automatically supported by implicit conversions, or when you want to make the conversion intentions clear in the code for readability and maintainability.


