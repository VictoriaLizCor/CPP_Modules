# CPP_Modules

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


## REFERENCES

* https://en.cppreference.com/w/
* https://cplusplus.com/reference/string/string/
* http://www.cplusplus.com/reference/iomanip/
 