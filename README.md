# CPP_Modules

## Table of Contents
- [Object-Oriented Programming](#object-oriented-programming)
- [C++98 Standard](#c98-standard)
- [Orthodox Canonical Form](#orthodox-canonical-form)
- [CPP Modules Overview](#cpp-modules-overview)
- [References](#references)

## Object-Oriented Programming

OOP is a programming paradigm that uses "objects" to design software. Here are some fundamental principles or rules of OOP:

1. **Encapsulation**: This is the practice of keeping fields within a class private, then providing access to them via public methods. It's a protective barrier that keeps the data and code safe within the class itself.

2. **Inheritance**: This is a process in which one class acquires the properties (methods and fields) of another. With the use of inheritance, the information is made manageable in a hierarchical order.

3. **Polymorphism**: This allows methods to be used in the same way for different types. The method can behave differently in different contexts. It provides a single interface to entities of different types.

4. **Abstraction**: Abstraction is a process of hiding the implementation details from the user, only the functionality will be provided to the user. It helps to reduce programming complexity and effort.

5. **Class**: A class is a blueprint for creating objects (a particular data structure), providing initial values for state (member variables or attributes), and implementations of behavior (member functions or methods).

6. **Object**: An object is an instance of a class. When a class is defined, no memory is allocated but when it is instantiated (i.e., an object is created) memory is allocated.

7. **Method**: Methods are functions defined inside the body of a class. They are used to perform operations with the attributes of our objects.

8. **Message Passing**: Objects communicate with one another by sending and receiving information to each other. A message for an object is a call to a method of that object.

These principles, when used together, make it possible for a programmer to create software that are easy to maintain and modify, have a clear and intuitive interface, and adhere to design principles such as modularity and information hiding.

*****************************************************************

## C++98 Standard

This project adheres to the **C++98 (ISO/IEC 14882:1998)** standard, also known as C++03. All code is compiled with the `-std=c++98` flag to ensure compatibility and avoid modern C++ features introduced in later standards.

### Why C++98?

- **Legacy Compatibility**: C++98 is the foundation of modern C++ and many production systems still rely on it.
- **Fundamental Learning**: Understanding C++98 teaches core concepts without the complexity of newer features.
- **Constraint-Based Learning**: Working within limitations of C++98 encourages better design practices and deeper understanding of language mechanics.
- **Predictable Behavior**: The language specification is stable and well-documented.

### Key Constraints of C++98

- No auto keyword type deduction
- No range-based for loops
- No nullptr (use NULL or 0)
- No move semantics or rvalue references
- Limited template features compared to modern C++
- No variadic templates
- No lambda functions
- Standard Library limited to older containers and algorithms

### Compilation

All modules are compiled with:
```
g++ -Wall -Wextra -Werror -std=c++98
```

This ensures strict adherence to C++98 standards and catches potential compatibility issues early.

*****************************************************************

## "Orthodox Canonical Form"

The term "Orthodox Canonical Form" or "Canonical Class Form" in C++ refers to a set of rules or best practices for designing classes. These rules ensure that classes behave correctly and predictably, especially in relation to memory management and object copying. Here are the rules:

1. **Rule of Three**: If a class defines any of the following, it should probably explicitly define all three:
   - destructor
   - copy constructor
   - copy assignment operator

2. **Destructor**: If your class manages a resource (like memory or a file), it should have a destructor to release that resource when objects of the class are destroyed.

3. **Copy Constructor**: If your class manages a resource, it should have a copy constructor to correctly copy the resource. The copy constructor should create a new object that is a copy of an existing object.

4. **Copy Assignment Operator**: If your class manages a resource, it should have a copy assignment operator to correctly copy the resource. The copy assignment operator should copy the resource from one object to another.

5. **Consistent Interface**: The class should provide a consistent interface. For example, if a `get` function is provided for a property, a corresponding `set` function should also be provided.

6. **Encapsulation**: The class should hide its implementation details from the user, exposing only what's necessary through its interface. This is typically achieved by making data members private.

7. **Initialization of Members**: Class members should be properly initialized. This can be done in the constructor.

8. **Avoiding Resource Leaks**: The class should avoid resource leaks. This means that any resource acquired by the class should be released when it is no longer needed.

These rules help to ensure that your classes are robust, predictable, and easy to use and maintain.

*****************************************************************

## CPP Modules Overview

### [CPP_00](./CPP_00) - Namespaces, Classes, and Member Functions
**Focus**: Introduction to basic C++ class structure and the Orthodox Canonical Form.

This module covers the fundamentals of creating classes in C++98 without OOP inheritance. Students learn:
- How to define classes with private and public members
- Constructor and destructor implementation
- Member functions (methods)
- The Orthodox Canonical Form basics (Rule of Three)
- Namespaces and code organization
- Basic I/O operations with std::cout and std::endl

**Key Concepts**: Class definition, encapsulation, constructors, destructors.

---

### [CPP_01](./CPP_01) - Memory Allocation and Pointers
**Focus**: Dynamic memory management and understanding memory allocation.

This module dives deep into memory management:
- Difference between stack and heap memory allocation
- Pointers and pointer arithmetic
- `new` and `delete` operators for dynamic allocation
- Memory leaks and how to prevent them
- References vs. pointers
- String manipulation with dynamic memory

**Key Concepts**: Pointers, dynamic allocation, memory safety, references.

---

### [CPP_02](./CPP_02) - Ad-Hoc Polymorphism and Operator Overloading
**Focus**: Operator overloading to create intuitive interfaces.

This module teaches how to overload operators for custom types:
- Arithmetic operators (+, -, *, /)
- Comparison operators (==, !=, <, >, <=, >=)
- Assignment operator (=)
- Stream operators (<<, >>)
- The keyword `this` and member function behavior
- Copy semantics and assignment
- Orthodox Canonical Form enforcement

**Key Concepts**: Operator overloading, the this pointer, const correctness.

---

### [CPP_03](./CPP_03) - Inheritance
**Focus**: Class hierarchies and inheritance relationships.

This module introduces object-oriented inheritance:
- Base classes and derived classes
- Access modifiers in inheritance (public, protected, private)
- Constructor and destructor chaining
- Method overriding
- Multiple inheritance and diamond problem
- The Orthodox Canonical Form in inheritance

**Key Concepts**: Inheritance, virtual functions, constructor chaining, method overriding.

---

### [CPP_04](./CPP_04) - Subtype Polymorphism and Virtual Functions
**Focus**: Polymorphic behavior through virtual functions and abstract classes.

This module explores runtime polymorphism:
- Virtual functions and method overriding
- Pure virtual functions and abstract classes
- Upcasting and downcasting in inheritance hierarchies
- Virtual destructors
- Polymorphic containers
- Interface design patterns

**Key Concepts**: Virtual functions, abstract classes, polymorphism, vtable.

---

### [CPP_05](./CPP_05) - Exception Handling and More OOP Concepts
**Focus**: Robust error handling and advanced OOP patterns.

This module covers error handling and design patterns:
- Try-catch-throw exception handling
- Standard exceptions
- Exception safety guarantees
- Nested classes
- Static members and static functions
- Friend classes and functions

**Key Concepts**: Exception handling, static members, friends, nested classes.

---

### [CPP_06](./CPP_06) - Type Casting
**Focus**: Different casting mechanisms in C++.

This module explains C++'s casting system:
- C-style casting and its dangers
- `static_cast<>` for safe, compile-time casts
- `dynamic_cast<>` for polymorphic type checking
- `const_cast<>` for removing const
- `reinterpret_cast<>` for low-level casting
- When and why to use each cast type

**Key Concepts**: Type safety, compile-time vs. runtime casting, polymorphic type checking.

---

### [CPP_07](./CPP_07) - Templates
**Focus**: Generic programming with templates.

This module introduces templates for code reuse:
- Function templates
- Class templates
- Template specialization
- Template instantiation and compilation model
- Template parameters and arguments
- The Liskov Substitution Principle with templates

**Key Concepts**: Templates, generic programming, template specialization, template parameters.

---

### [CPP_08](./CPP_08) - Templated Containers and Iterators
**Focus**: Working with Standard Template Library (STL) containers.

This module explores STL containers:
- Vector, list, map, set, and other containers
- Iterators and iterator patterns
- Templated container operations
- Algorithms with templates (find, sort, etc.)
- Container adaptation (stack, queue)
- Memory management in containers

**Key Concepts**: STL containers, iterators, container algorithms, memory management.

---

### [CPP_09](./CPP_09) - Standard Template Library (STL) Comprehensive Study
**Focus**: Deep dive into STL components and advanced programming techniques.

This module provides comprehensive coverage of the STL:
- All major containers and their complexities
- Algorithms and function objects
- The iterator hierarchy
- Functors and predicates
- STL string operations
- Advanced container usage patterns
- Best practices for STL usage

**Key Concepts**: STL comprehensiveness, functors, algorithms, container selection, performance considerations.

*****************************************************************

## REFERENCES

* https://en.cppreference.com/w/
* https://cplusplus.com/reference/string/string/
* http://www.cplusplus.com/reference/iomanip/
* https://en.cppreference.com/w/cpp/language/history