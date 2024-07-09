#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#if (DEBUG == 0)

#include <iostream>

int main(void)
{
	// {
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());

	// 	ICharacter* me = new Character("me");
	// 	AMateria* tmp;

	// 	tmp = src->createMateria("ice");
	// 	me->equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	me->equip(tmp);
		
	// 	ICharacter* bob = new Character("bob");
	// 	me->use(0, *bob);
	// 	me->use(1, *bob);
	// 	delete bob;
	// 	delete me;
	// 	delete src;
	// }
	std::cout << "----\n";
	return (0);
}

#endif

/**
 * NOTES: Forward declaration in C++ is a technique where you declare
 * a class, function, or variable without providing its definition.
 * It's used to inform the compiler about the existence of an entity
 * before it is fully defined. This technique is particularly
 * important and necessary in several scenarios:
 *
 * 1. **Resolving Circular Dependencies**: Circular dependencies occur
 *    when two or more classes depend on each other. For instance, if
 *    class A has a member that is a pointer or reference to class B,
 *    and class B, in turn, needs to refer to class A. Without forward
 *    declarations, this situation would result in a compilation error
 *    because each class's full definition requires the other to be
 *    defined first. By forward declaring one of the classes, you
 *    break this cycle, allowing both classes to be compiled
 *    successfully.
 *
 *    ```cpp
 *    // Forward declaration of class B
 *    class B;
 *
 *    class A {
 *        B* b; // Pointer to B is allowed with forward declaration
 *    };
 *
 *    class B {
 *        A a; // B can now include A without issues
 *    };
 *    ```
 *
 * 2. **Reducing Compilation Time**: Including header files increases
 *    compilation time because the compiler has to process more
 *    information. If a header file changes, every source file that
 *    includes it must be recompiled. By using forward declarations,
 *    you can avoid including headers in other headers when full class
 *    definitions are not needed, thus reducing compilation time.
 *
 *    ```cpp
 *    // Forward declaration of class MyClass
 *    class MyClass;
 *
 *    void functionTakingPointer(MyClass* mc);
 *    ```
 *
 *    In this example, the full definition of `MyClass` is not needed
 *    by `functionTakingPointer`, so we can forward declare `MyClass`
 *    instead of including its header file. This reduces the need to
 *    recompile files that include this header whenever `MyClass` is
 *    modified.
 *
 * 3. **Hiding Implementation Details**: Forward declarations can be
 *    used to hide the implementation details of a class from the
 *    users of a header file. This can make the interface of a library
 *    cleaner and reduce the risk of breaking user code when internal
 *    implementations change.
 *
 * Forward declarations are a powerful tool in C++, but they should be
 * used judiciously. They are not suitable for all situations,
 * especially when the size or layout of the class is needed (e.g.,
 * when creating instances, using member functions, or accessing
 * member variables). In such cases, a full class definition is
 * required, and the corresponding header file must be included.
 *  */