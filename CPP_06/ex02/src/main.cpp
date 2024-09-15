/**
 * @file main.cpp
 * @author lilizarr (lilizarr@student.42wolfsburg.de)
 * @brief 
 * @version 0.1
 * @date 2024-09-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "Utils.hpp"
#include <iostream>

Base *generate(void)
{
	int	randInt = getRandomNum<int>(3);
	if (randInt == 0)
		return (std::cout << getColorStr(FCYAN, "A generated") << std::endl, new A());
	if (randInt == 1)
		return (std::cout << getColorStr(FGREEN, "B generated") << std::endl, new B());
	return (std::cout << getColorStr(FYELLOW, "C generated") << std::endl, new C());
}

void identify(Base* p)
{
	printTitle("Pointer", 20, '-');
	try
	{
		if(dynamic_cast<A*>(p))
			std::cout << getColorStr(FCYAN, "A pointer") << std::endl;
		else if(dynamic_cast<B*>(p))
			std::cout << getColorStr(FGREEN, "B pointer") << std::endl;
		else if(dynamic_cast<C*>(p))
			std::cout << getColorStr(FYELLOW, "C pointer") << std::endl;
		else
			std::cout << getColorStr(FWHITE, "Unknown pointer") << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void identify(Base& p)
{
	printTitle("Reference", 20, '-');
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << getColorStr(FCYAN, "A reference") << std::endl;
		return;
	}
	catch(const std::bad_cast&){}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << getColorStr(FGREEN, "B reference") << std::endl;
		return;
	} catch(const std::bad_cast&){}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << getColorStr(FYELLOW, "C reference") << std::endl;
		return;
	} catch(const std::bad_cast&){}
	std::cout << getColorStr(FWHITE, "Unknown reference") << std::endl;
}

int main(void)
{
	Base* b = NULL;
	while(1)
	{
		if (getRandomNum<int>(4) < 3)
			b = generate();
		else
			b = NULL;
		identify(b);
		identify(*b);
		printTitle("", 40, '=');
		if (b)
			delete b;
		else
			break ;
	}

	return (0);
}


/**
 * RTTI stands for Run-Time Type Information. It is a mechanism
 * provided by C++ that allows the type of an object to be determined
 * during program execution. RTTI is particularly useful in situations
 * where you need to work with polymorphic objects and need to know
 * their actual derived types at runtime.
 *
 * **[`dynamic_cast`] Operator**:
 * - The [`dynamic_cast`] operator is used to safely convert pointers
 *   and references to classes up, down, and sideways along the
 *   inheritance hierarchy.
 * - It performs a runtime check to ensure that the cast is valid. If
 *   the cast is invalid, it returns `nullptr` for pointers or throws
 *   a `std::bad_cast` exception for references.
 *
 * ### How RTTI Works:
 * - RTTI relies on the presence of virtual functions in the base
 *   class. When a class has at least one virtual function, the
 *   compiler generates additional information to support RTTI.
 * - This information typically includes a virtual table (vtable) and
 *   type information that allows the runtime system to determine the
 *   actual type of an object.
 *
 * ### Use Cases for RTTI:
 * - **Type-Safe Downcasting**: Using [`dynamic_cast`] to safely cast
 *   a base class pointer or reference to a derived class type.
 * - **Type Identification**: Using `typeid` to get the type
 *   information of an object at runtime.
 * - **Polymorphic Behavior**: Enabling polymorphic behavior by
 *   allowing functions to operate on objects of different types
 *   through base class pointers or references.

 * ### Limitations and Considerations:
 * - RTTI introduces some runtime overhead due to the additional type
     information and checks.
 * - It requires the use of virtual functions, which means it cannot
     be used with non-polymorphic types.
 * - Overuse of RTTI can lead to less maintainable code. It's often
 *   better to design your classes and functions to avoid the need for
 *   explicit type checks.

 */
