#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iomanip>
#include <iostream>

static int getRandomNum(int num){return (rand() % num);}

static AMateria *createRandomMateria(size_t i)
{
	AMateria	*m;
	std::string color;
	if (getRandomNum(2) == 0)
	{
		m = new Ice();
		color = getColorFmt(FLBLUE);
	}
	else
	{
		m = new Cure();
		color = getColorFmt(FLGREEN);
	}
	std::cout << getColorFmt(FMAGENTA)
	<< "[" << i + 1 << "] ";
	std::cout << color << *m;
	if (DEBUG)
		std::cout << " (" << m << ")\n";
	std::cout << std::string (C_END)<< "\n";
	return (m);
}

static void fillInventory(Character& c, size_t size)
{
	for (size_t i = 0 ; i <= size ; ++i)
	{
		c.equip(createRandomMateria(i));
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

static void testSubject(void)
{
	printTitle("SUBJECT");
	// IMateriaSource* src = new MateriaSource();

	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// ICharacter*	me = new Character("me");
	// AMateria*	tmp;

	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("unknown");
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);

	// delete bob;
	// delete me;
	// delete src;
}

static void	testCharacter(void)
{
	size_t size = Character::getInvetorySize();
	{
		{
			Character c1("");
			printTitle("CHARACTER Copy assigment operator");
			std::cerr << "----\n";
			c1.getInventory(size);
			fillInventory(c1, size);
			c1.getInventory(size);
			// std::cerr << "----\n";
			// {
			// 	Character c2 = c1;
			// 	std::cerr << "----\n";
			// 	c2.getInventory(size);
			// 	std::cerr << "----\n";
			// }
			// printTitle("AMATERIA Copy constructor");
			// {
			// 	Character c2(c1);
			// 	std::cerr << "----\n";
			// 	c2.getInventory(size);
			// 	std::cerr << "----\n";
			// }
			std::cerr << "----\n";
		}	
// 	ICharacter	*c1 = new Character("Char1");
// 	ICharacter	*c2 = new Character("Char2");
// 	AMateria	*ice = new Ice();

// 	c1->equip(new Ice());
// 	c1->equip(ice);
// 	c1->equip(new Cure());
// 	c1->equip(new Ice());
// 	c1->equip(new Ice());
// 	c2->equip(new Cure());
// 	c2->equip(new Cure());
// 	c2->equip(new Cure());

// 	c1->printInventory();
// 	c2->printInventory();

// 	c1->use(0, *c2);
// 	c1->use(1, *c2);
// 	c1->use(3, *c2);
// 	c2->use(2, *c1);

// 	c1->unequip(1);
// 	c1->printInventory();
// 	c1->use(1, *c2);

// 	c1->equip(new Cure());
// 	c1->printInventory();
// 	c1->use(1, *c2);

// 	delete c1;
// 	delete c2;
// 	delete ice;
	}
	printTitle("| END TEST CHARACTER |");
	std::cerr << "\n";
}

static void	testMateriaSource()
{
	printTitle("MATERIA_SOURCE Copy assigment operator");
	// IMateriaSource	*matSource = new MateriaSource();
	// ICharacter		*c1 = new Character("Char1");
	// ICharacter		*c2 = new Character("Char2");
	
	// matSource->learnMateria(new Ice());
	// matSource->learnMateria(new Cure());
	// matSource->learnMateria(new Cure());
	// matSource->learnMateria(new Cure());
	// matSource->learnMateria(new Cure());

	// c1->printInventory();
	// c1->equip(matSource->createMateria("ice"));
	// c1->equip(matSource->createMateria("cure"));
	// c1->equip(matSource->createMateria("cure"));
	// c1->equip(matSource->createMateria("ice"));
	// c1->printInventory();
	// c1->equip(matSource->createMateria("cure"));
	// c1->printInventory();

	// c1->use(0, *c2);
	// c1->use(2, *c2);

	// delete matSource;
	// delete c1;
	// delete c2;
}

static void	testAMateria()
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
				std::cout << "Info: " <<*ptr << "\n";
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
				std::cout << "Info: " <<*ptr << "\n";
				std::cerr << "----\n";
				delete ptr;
				std::cerr << "----\n";
		
			}
		}
	}
	printTitle("| END TEST AMATERIA |");
	std::cerr << "\n";
}

int	main(int ac, char* arg[])
{
	std::cout << "ac : " << ac;
	if (ac == 2)
	{	
		std::cout <<" | arg[1] : " << arg[1] << std::endl;
		switch (std::atoi(arg[1]))
		{
			case 1:
				testCharacter();
				break;
			case 2:
				testMateriaSource();
				break;
			case 3:
				testAMateria();
				break;
			default:
				testSubject();
		}
	}
	else
	{
		std::cout << std::endl;
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
*/