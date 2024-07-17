#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#if (DEBUG != 0)

#include <iostream>

static void testBrain(size_t const& size)
{
	std::cout << "********* BRAIN OBJECT TEST *********\n";
	{
		Brain b1;
		std::cout << "---\n";
		for (size_t i = 0; i < size; ++i)
			b1.setIdea(getRandString());
		for (size_t i = 0; i < size; ++i)
		{
			std::cout << i << " " << b1.getIdea(i) << "\n";
		}
		std::cout << "---\n";
		{
			Brain b2= b1;
			for (size_t i = 0; i < size; ++i)
			{
				std::cout << i << " " << b1.getIdea(i) << "\n";
			}
			std::cout << "---\n";
		}
	}
	std::cout << "********* BRAIN OBJECT TEST END *********\n";
}

static void testCat(size_t const& size)
{
	{
		{
			Cat stray;
			for (size_t i = 0; i < size; ++i)
			{
				stray.makeSound();
			}
			{
				Cat clone = stray;
				std::cout << "---\n";
				for (size_t i = 0; i < size; ++i)
				{
					clone.makeSound();
				}
				std::cout << "---\n";
			}
			std::cout << "---\n";
		}
		std::cout << "---\n";
	}
}

static void testDog(size_t const& size)
{
	{
		{
			Dog stray;
			for (size_t i = 0; i < size; ++i)
			{
				stray.makeSound();
			}
			std::cout << "---\n";
			{
				Dog clone(stray);
				std::cout << "---\n";
				for (size_t i = 0; i < size; ++i)
				{
					clone.makeSound();
				}
				std::cout << "---\n";
			}
			std::cout << "---\n";
		}
	}
}

static void testRandom(void)
{
	size_t const size = 10;
	size_t i;
	{
		const Animal* animals[size];
		std::cout << "---\n";
		for( i = 0; i < size; ++i )
		{
			if( i < size / 2 )
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
		}
		std::cout << "---\n";
		std::cout << "Total Animals created: "
		<< animals[i - 1]->getId() << "/" << i << "\n";
		std::cout << "---\n";
		{
			Brain inVitro;
			for( i = 0; i < size; ++i )
			{
				size_t ran = inVitro.getRandomIdea(size);
				animals[ran]->makeSound();
			}
		}
		std::cout << "---\n";
		while (--i <= size)
			delete animals[i];
	}
	std::cout << "\n";
}

// static void testAnimal(void)
// {
// 	// test abstract class
// 	const Animal *abstract = new Animal();
	
// 	std::cout << "Hi, I am class " << abstract->getType() << std::endl;
// 	abstract->makeSound();
// 	std::cout << "---\n";
// 	delete abstract;
// 	std::cout << "---\n";
// 	const Cat* j = new Dog();
// 	const Dog* i = new Cat();
// 	std::cout << "---\n";
// 	i->makeSound();
// 	j->makeSound();
// }

int main(void)
{
	size_t const size = 10;
	// testAnimal();
	testBrain(size);
	testCat(size);
	// testDog(size);
	// testRandom();
	// {
	// 	const Cat* j = new Cat();
	// 	const Dog* i = new Dog();
	// 	std::cout << "---\n";
	// 	i->makeSound();
	// 	j->makeSound();
	// 	std::cout << "---\n";
	// 	delete j;//should not create a leak
	// 	delete i;
	// 	std::cout << "-------------\n";
	// 	{
	// 		Dog stray;
	// 		std::cout << "---\n";
	// 		{
	// 			Dog clone = stray;
	// 			stray.makeSound();
	// 			clone.makeSound();
	// 			std::cout << "---\n";
	// 		}
	// 		std::cout << "---\n";
	// 	}
	// 	std::cout << "---\n";
	// }
	std::cout << "\n";
	return (0);
}

#endif

/** NOTES: Pointers of abstract classes.......................................
 *
 *  It is possible even though `Animal` is an abstract class because in C++, an
 *  abstract class can be used as a base class pointer or reference to point to
 *  or reference objects of derived classes. `Cat` is a derived class of
 *  `Animal`. The key point here is it is not possible to instantiate an
 *  abstract class directly (i.e., you cannot create objects of an abstract
 *  class because it contains at least one pure virtual function), you can use
 *  pointers or references of an abstract class type to point to objects of its
 *  derived classes. This is a fundamental concept in polymorphism, allowing you
 *  to use a unified interface (`Animal` in this case) to work with objects of
 *  any class derived from that interface.
 *
 * In the specific case of `Cat`, it is derived from `Animal` and presumably
 * implements all pure virtual functions declared in `Animal`, making it a
 * concrete class that can be instantiated. The pointer of type `const Animal*`
 * is able to point to a `Cat` object because `Cat` is an `Animal` due to
 * inheritance. This is a common practice in C++ to achieve runtime
 * polymorphism, where the decision about which function to call is made at
 * runtime based on the actual type of the object that the base class pointer
 * points to, not the type of the pointer itself.
 * */