#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iomanip>
#include <iostream>

static int getRandomNum(int num)
{
	static bool seeded = false;
	if (!seeded)
	{
		srand(static_cast<unsigned int>(time(0)));
		seeded = true;
	}
	return (rand() % num);
}

static AMateria *createRandomMateria(size_t i)
{
	AMateria	*m;
	std::string color;
	if (getRandomNum(2) == 0)
		m = new Ice();
	else
		m = new Cure();
	std::cout << getColorFmt(FMAGENTA)
	<< "[" << i + 1 << "] ";
	std::cout << *m;
	if (DEBUG)
		std::cout << " (" << m << ")\n";
	std::cout << std::string (C_END)<< "\n";
	return (m);
}

// Debug != 0
template<typename T>
void fillInventory(T& obj, size_t size, void (T::*action)(AMateria*))
{
	for (size_t i = 0 ; i <= size ; ++i)
	{	
		(obj.*action)(createRandomMateria(i));
		std::cerr << "----\n";
	}
}

// Debug == 0
static void fillInventory(void* obj, size_t size, std::string const& name)
{
	for (size_t i = 0 ; i <= size ; ++i)
	{
		if (DEBUG)
			std::cout << "Class: " << name << std::endl;
		if (name == "Character")
			static_cast<Character*>(obj)->equip(createRandomMateria(i));
		else if(name == "MateriaSource")
			static_cast<MateriaSource*>(obj)->learnMateria(createRandomMateria(i));
		std::cerr << "----\n";
	}
}

static void printTitle(std::string title)
{
	const int size = 60;
	std::string toPrint = " " + title + " "; 
	
	int len = static_cast<int>(toPrint.size());
	int padding = (size - len) / 2;

	if (len % 2 != 0 && size % 2 == 0)
		padding++;

	std::cout << std::setfill('=') << std::setw(padding) << "";
	std::cout << toPrint;
	std::cout << std::setfill('=') << std::setw(size - len - padding)
	<< "" << std::endl;
}

static void testSubject(void) // Default
{
	size_t size = Character::getInvetorySize();
	std::cout << "Character inventory size:" << size << "\n";
	printTitle("SUBJECT CODE");
	IMateriaSource* src = new MateriaSource();
	std::cerr << "----\n";
	src->learnMateria(new Ice());
	std::cerr << "----\n";
	src->learnMateria(new Cure());
	std::cerr << "----\n";
	{
		ICharacter*	me = new Character("me");
		std::cerr << "----\n";
		AMateria*	tmp;
		std::cerr << "----\n";
		tmp = src->createMateria("ice");
		me->equip(tmp);
		std::cerr << "----\n";
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cerr << "----\n";
		tmp = src->createMateria("unknown");
		std::cerr << "----\n";
		ICharacter* bob = new Character("bob");
		// bob->getInventory(size);
		std::cerr << "----\n";
		me->use(0, *bob);
		me->use(1, *bob);
		std::cerr << "----\n";
		delete bob;
		delete me;
	}
	std::cerr << "----\n";
	delete src;
	std::cerr << "----\n" << std::flush;
}

static void	testCharacter(void) // 1
{
	size_t size = Character::getInvetorySize();
	{
		{
			Character *c1 = new Character("");
			printTitle("CHARACTER Copy assigment operator");
			std::cerr << "----\n";
			c1->getInventory(size);
			if (DEBUG)
				fillInventory(*c1, size, &Character::equip);
			else
				fillInventory(c1, size, className(typeid(*c1).name()));
			c1->getInventory(size);
			std::cerr << "----\n";
			{
				Character c2 = *c1;
				std::cerr << "----\n";
				c2.getInventory(size);
				std::cerr << "----\n";
			}
			printTitle("AMATERIA Copy constructor");
			{
				Character c2(*c1);
				std::cerr << "----\n";
				c2.getInventory(size);
				std::cerr << "----\n";
				c1->use(0, c2);
				c2.use(1, *c1);
				std::cerr << "----\n";
			}
			std::cerr << "----\n";
			delete c1;
		}
	}
	printTitle("| END TEST CHARACTER |");
	std::cerr << "\n" << std::flush;
}

static void	testAMateria() //2
{
	{
		{
			printTitle("AMATERIA Copy assigment operator");
			Cure c1;
			{
				std::cerr << "----\n";
				Cure c2 = c1;
				std::cerr << "----\n";
			}
			printTitle("AMATERIA Copy constructor");
			{
				std::cerr << "----\n";
				Cure c2(c1);
				std::cerr << "----\n";
			}
			printTitle("AMATERIA Cloning");
			{
				AMateria *ptr = c1.clone();
				std::cerr << "----\n";
				std::cout << "Type AMateria: " << *ptr << "\n";
				std::cerr << "----\n";
				delete ptr;
				std::cerr << "----\n";
			}
			std::cerr << "----\n";
		}
		{
			printTitle("AMATERIA Copy assigment operator");
			Ice i1;
			{
				std::cerr << "----\n";
				Ice i2 = i1;
				std::cerr << "----\n";
			}
			printTitle("AMATERIA Copy constructor");
			{
				std::cerr << "----\n";
				Ice i2(i1);
				std::cerr << "----\n";
			}
			printTitle("AMATERIA Cloning");
			{
				AMateria *ptr = i1.clone();
				std::cerr << "----\n";
				std::cout << "Type AMateria: " << *ptr << "\n";
				std::cerr << "----\n";
				delete ptr;
				std::cerr << "----\n";
		
			}
		}
	}
	printTitle("| END TEST AMATERIA |");
	std::cerr << "\n" << std::flush;
}

// compiler slows down as it runs safety check
//dynamic_cast<MateriaSource*>(ms)->getInventory(size);
static void	testMateriaSource() //3
{
	size_t size = Character::getInvetorySize();
	std::cout << "Character inventory size:" << size << "\n";
	printTitle("MATERIA_SOURCE Copy assigment operator");
	IMateriaSource	*ms = new MateriaSource();
	std::cout << "----\n";
	if (DEBUG)
		fillInventory(*ms, size, &IMateriaSource::learnMateria);
	else
		fillInventory(&*ms, size, className(typeid(*ms).name()));
	std::cout << "----\n";
	static_cast<MateriaSource*>(ms)->getInventory(size);
	std::cout << "----\n";
	{
		printTitle("MATERIA_SOURCE Copy assigment operator");
		/* Downcasting to derived class from Base class with pointer */
		MateriaSource* derived = static_cast<MateriaSource*>(ms);
		if (derived != 0)
		{
			MateriaSource newMS = *derived;
			std::cout << "----\n";
			newMS.getInventory(size);
			std::cout << "----\n";
		}
		std::cout << "----\n";
		std::cout << "----\n" << std::flush;
	}
	delete ms;
	std::cerr << "\n" << std::flush;
}

static void testICharacter(void)
{
	size_t size = Character::getInvetorySize();
	std::cout << "********************\n";
	{
		printTitle("ICHARACTER Copy assigment operator");
		ICharacter		*c1 = new Character("c1");
		ICharacter		*c2;
		if (DEBUG)
			fillInventory(*c1, size, &ICharacter::equip);
		else
			fillInventory(&*c1, size, className(typeid(*c1).name()));
		std::cout << "****\n";
		c2 = new Character(*(static_cast<Character*>(c1)));
		{
			std::cout << "****\n\n";
			static_cast<Character*>(c1)->getInventory(size);
			static_cast<Character*>(c2)->getInventory(size);
			std::cout << "----\n";
		}
		c1->use(0, *c2);
		c2->use(2, *c1);
		c2->use(6, *c1);
		std::cout << "----\n";
		delete c2;
		delete c1;
	}
	std::cerr << "\n" << std::flush;
}
/*
To run main from terminal
$> make D=0 S=1 re test i=#
or
$> make D=0 S=1 re test
where
	D-> debug information
	S-> sanatizer information
	i-> switch case [1-4]
*/
int	main(int ac, char* arg[])
{
	if (DEBUG)
		std::cout << "ac : " << ac;
	if (ac == 2)
	{	
		if (DEBUG)
			std::cout <<" | arg[1] : " << arg[1] << std::endl;
		switch (std::atoi(arg[1]))
		{
			case 1:
				testCharacter();
				break;
			case 2:
				testAMateria();
				break;
			case 3:
				testMateriaSource();
				break;
			case 4:
				testICharacter();
				break;
			default:
				testSubject();
		}
		std::cout << std::endl << std::flush;
	}
	else
	{
		std::cout << std::endl << std::flush;
		testSubject();
	}
	return (0);
}


/**
 * @note: Forward declaration in C++ is a technique where you declare
 * a class, function, or variable without providing its definition.
 * It's used to inform the compiler about the existence of an entity
 * before it is fully defined. This technique is particularly
 * important and necessary in several scenarios:
 *
 * 1. **Resolving Circular Dependencies**: Circular dependencies occur
 *	when two or more classes depend on each other. For instance, if
 *	class A has a member that is a pointer or reference to class B,
 *	and class B, in turn, needs to refer to class A. Without forward
 *	declarations, this situation would result in a compilation error
 *	because each class's full definition requires the other to be
 *	defined first. By forward declaring one of the classes, you
 *	break this cycle, allowing both classes to be compiled
 *	successfully.
 *
 *	```cpp
 *	// Forward declaration of class B
 *	class B;
 *
 *	class A {
 *		B* b; // Pointer to B is allowed with forward declaration
 *	};
 *
 *	class B {
 *		A a; // B can now include A without issues
 *	};
 *	```
 *
 * 2. **Reducing Compilation Time**: Including header files increases
 *	compilation time because the compiler has to process more
 *	information. If a header file changes, every source file that
 *	includes it must be recompiled. By using forward declarations,
 *	you can avoid including headers in other headers when full class
 *	definitions are not needed, thus reducing compilation time.
 *
 *	```cpp
 *	// Forward declaration of class MyClass
 *	class MyClass;
 *
 *	void functionTakingPointer(MyClass* mc);
 *	```
 *
 *	In this example, the full definition of `MyClass` is not needed
 *	by `functionTakingPointer`, so we can forward declare `MyClass`
 *	instead of including its header file. This reduces the need to
 *	recompile files that include this header whenever `MyClass` is
 *	modified.
 *
 * 3. **Hiding Implementation Details**: Forward declarations can be
 *	used to hide the implementation details of a class from the
 *	users of a header file. This can make the interface of a library
 *	cleaner and reduce the risk of breaking user code when internal
 *	implementations change.
 *
 * Forward declarations are a powerful tool in C++, but they should be
 * used judiciously. They are not suitable for all situations,
 * especially when the size or layout of the class is needed (e.g.,
 * when creating instances, using member functions, or accessing
 * member variables). In such cases, a full class definition is
 * required, and the corresponding header file must be included.
*/