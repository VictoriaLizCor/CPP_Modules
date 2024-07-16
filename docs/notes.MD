# toDo:
	* Keep track of AMaterias created objects * Keep track of Cure
	created objects * Keep track of Ice created objects * Do the same
	for characters * Increase and decrease Instance counters 

# FORWARD DECLARATION
A forward declaration in C++ is a declaration of an identifier (for
example, a function, class, or variable) before giving it a complete
definition. It tells the compiler about the existence of an entity
before you fully define it. This is particularly useful in situations
where two or more entities refer to each other; without forward
declarations, it would be impossible to compile such code due to
circular dependencies.

### How Forward Declarations Work:

1. **Classes and Structs**: When you forward declare a class or
   struct, you are informing the compiler that a class or struct of
   this name exists, without specifying its details (members, methods,
   etc.). This allows you to use pointers or references to the
   forward-declared class in other classes or functions before the
   class is fully defined.
   ```cpp
   class MyClass; // Forward declaration of the class
   ```

2. **Functions**: Forward declaring a function involves declaring the
   function's signature without its implementation. This allows the
   function to be used before its definition.
   ```cpp
   int myFunction(int, double); // Forward declaration of a function
   ```

3. **Variables**: Similarly, you can forward declare external
   variables (though this is less common) using the `extern` keyword,
   indicating that its memory allocation and initialization will be
   done elsewhere.
   ```cpp
   extern int myVariable; // Forward declaration of an external variable
   ```

### How the Compiler Handles It:

- **Type Checking**: For classes and structs, the compiler uses
  forward declarations to perform type checking in subsequent code. It
  knows the name and type (class/struct) but not the size or members.
  This is enough to use pointers or references to the type because
  their sizes are constant, regardless of the actual size of the
  objects they point to.

- **Linkage**: For functions and external variables, forward
  declarations tell the compiler about their existence and types. The
  actual linkage (connecting the declaration with its definition) is
  done during the linking phase, not the compilation phase.

- **Memory Allocation**: Since the compiler doesn't know the size of a
  forward-declared class (because its definition is not yet
  available), it cannot allocate memory for objects of that class
  directly. However, it can allocate memory for pointers or references
  to such objects because the size of a pointer or reference is known
  and constant.

- **Compilation Order Independence**: Forward declarations make the
  order of file compilation less critical. As long as the full
  definitions are provided somewhere in the project before the linking
  phase, the compiler can work with just the forward declarations
  during the compilation of individual files.

In summary, forward declarations are a tool in C++ that allows the
compiler to handle entities that are used before they are fully
defined. They enable the separation of interface (declaration) from
implementation (definition), circular references among classes, and
can improve compilation times by reducing the need for including
header files.

# EXPLICIT CONVERTION
Explicit conversion in C++ refers to a type conversion that requires
explicit notation in the code to perform, indicating the programmer's
intention to convert a value from one type to another. This is in
contrast to implicit conversions, which the compiler performs
automatically without any specific notation needed from the
programmer.

There are several ways to perform explicit conversions in C++,
including:

1. **C-style casting**: This is the traditional C way of converting
   types, using parentheses with the target type before the variable
   or value to be converted.
   ```cpp
   double pi = 3.14159;
   int integerPart = (int)pi; // C-style cast to convert double to int
   ```

2. **Functional notation**: Similar to C-style casting but uses the
   target type as if it were a function call.
   ```cpp
   double pi = 3.14159;
   int integerPart = int(pi); // Functional notation to convert double to int
   ```

3. **Static cast**: A C++-style cast that performs a compile-time type
   check, making it safer than C-style casts. It can be used for
   conversions between related types (e.g., between base and derived
   classes).
   ```cpp
   double pi = 3.14159;
   int integerPart = static_cast<int>(pi); // Static cast to convert double to int
   ```

4. **Dynamic cast**: Used for safe downcasting in class hierarchies,
   checking at runtime if the conversion is valid. It's used primarily
   with pointers or references to polymorphic classes.
   ```cpp
   Base* basePtr = new Derived;
   Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // Dynamic cast for downcasting
   ```

5. **Const cast**: Used to add or remove the `const` qualifier from a
   variable.
   ```cpp
   const int x = 10;
   int* nonConstXPtr = const_cast<int*>(&x); // Const cast to remove const qualifier
   ```

6. **Reinterpret cast**: Provides a low-level reinterpreting of the
   bit pattern. It's a powerful but dangerous tool that should be used
   sparingly.
   ```cpp
   long long address = 0x12345678;
   void* ptr = reinterpret_cast<void*>(address); // Reinterpret cast to convert integer to pointer
   ```

Explicit conversions are necessary when you need to convert types in a
way that is not automatically supported by implicit conversions, or
when you want to make the conversion intentions clear in the code for
readability and maintainability.

# IMPLICIT CONVERION

Implicit conversion, also known as automatic type conversion, is a
process where the compiler automatically converts one data type to
another without the programmer having to specify the conversion
explicitly. This feature is designed to make C++ code more readable
and to allow for more generic programming by reducing the amount of
boilerplate code required for type conversions.

Here's how implicit conversion works and how the compiler handles it:

1. **Compatibility and Hierarchy**: The compiler performs implicit
   conversions when it encounters an expression requiring a type
   different from the actual type of the data. This usually happens in
   assignments, function calls, and expressions. The conversion is
   only performed if the target type can represent the value of the
   source type without loss of information (e.g., converting from
   `int` to `double`).

2. **Standard Conversions**: C++ defines a set of standard conversions
   that can happen implicitly, including:
   - **Integral promotions**: Smaller integer types (like `char` and
     `short`) can be converted to larger integer types (`int`,
     `long`).
   - **Floating-point promotions**: A `float` can be promoted to
     `double`.
   - **Numeric conversions**: Conversions between different numeric
     types (e.g., `int` to `float`, `double` to `int`). These may
     involve rounding or truncation.
   - **Pointer conversions**: Conversion from `nullptr` to any pointer
     type, or from a derived class pointer to a base class pointer.

3. **Conversion Operators and Constructors**: Classes in C++ can
   define conversion operators and constructors that allow implicit
   conversions. For example, a class might define a constructor that
   takes an `int`, allowing objects of that class to be implicitly
   constructed from integers.

4. **Compiler Decisions**: The compiler decides when to apply implicit
   conversions based on the context. It follows the rules of the C++
   language standard to determine the best match for overloads, the
   need for conversions in expressions, and whether a conversion is
   safe and lossless.

5. **Avoiding Ambiguity**: The compiler ensures that implicit
   conversions do not lead to ambiguous situations. If a conversion
   could be interpreted in multiple ways, the compiler will generate
   an error, requiring the programmer to make the conversion explicit.

Implicit conversions simplify code by reducing the need for explicit
type casts and conversions. However, they can also lead to unexpected
behavior if not carefully managed, especially in complex expressions
or when dealing with user-defined types that have conversion operators
or constructors allowing implicit conversions.

# DYNAMIC CAST
In C++, `dynamic_cast` is used for safe downcasting at runtime. It converts a pointer or reference of a base class to a pointer or reference of a derived class, with runtime type checking. It's particularly useful in hierarchies with polymorphic classes, where you need to determine the actual derived type of an object pointed to by a base pointer or reference.

Here's a step-by-step explanation of how `dynamic_cast` works and what it means in the context of your code:

1. **Type Safety**: `dynamic_cast` ensures type safety by checking at runtime if the cast is valid. It uses the runtime type information (RTTI) of the object to verify that the conversion is possible.

2. **Downcasting**: Downcasting refers to casting a pointer or reference from a base class to a derived class. This is the opposite of upcasting, which is always safe and implicit in C++. Downcasting is not inherently safe because not all base class pointers may actually point to a derived class object.

3. **Runtime Check**: When you use `dynamic_cast` to downcast a pointer, if the object pointed to is not actually of the target derived type (or a type derived from the target type), the result of the cast will be `nullptr`. For references, if the cast fails, a [`std::bad_cast`] exception is thrown.

4. **Usage**: `dynamic_cast` is used in situations where the type of the object is not known at compile time and you need to perform operations specific to its derived type. It's commonly used in polymorphic class hierarchies.

5. **Syntax**:
   - For pointers: `DerivedClass* ptr = dynamic_cast<DerivedClass*>(basePtr);`
   - For references: `DerivedClass& ref = dynamic_cast<DerivedClass&>(baseRef);`

6. **Requirements**: For `dynamic_cast` to work, the base class must have at least one virtual function, which is usually the virtual destructor if no other virtual functions are present. This requirement is necessary for the runtime type information (RTTI) to be available.


<!-- To erase Visual Studio Code (VS Code) cache data on a Linux machine, you can follow these steps. This process involves deleting or renaming directories where VS Code stores its cache and workspace data. Please note that doing this might reset some of your VS Code preferences and extensions.

1. **Close VS Code** to ensure that no instances are running.

2. **Clear the Editor Cache**: The cache data for VS Code is stored in the `~/.config/Code` directory. You can remove this directory to clear the cache. Open a terminal and run:
   ```bash
   rm -rf ~/.config/Code
   ```

3. **Clear the Extensions**: Extensions and their data are stored in `~/.vscode`. If you want to clear extensions along with the cache, run:
   ```bash
   rm -rf ~/.vscode
   ```

4. **Workspace Storage**: VS Code also stores workspace-specific data (like recently opened files and workspaces) in `~/.config/Code - User/workspaceStorage`. To clear this data, run:
   ```bash
   rm -rf ~/.config/Code\ -\ User/workspaceStorage
   ```

5. **Restart VS Code** after clearing the desired data. VS Code will recreate necessary files and directories but you might need to reinstall your extensions and reconfigure your settings.

**Important**: Be cautious when using `rm -rf` commands, as they can permanently delete data. Consider backing up your settings and extensions list before proceeding.

This process will help in resetting VS Code to a "clean" state by removing cached data, extensions, and workspace information.
 -->




