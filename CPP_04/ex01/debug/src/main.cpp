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
int main(void)
{
	size_t const size = 10;
	testBrain(size);
	// testCat(size);
	// testDog(size);
	testRandom();
	// {
	// 	const Animal* j = new Dog();
	// 	const Animal* i = new Cat();
	// 	std::cout << "---\n";
	// 	delete j;//should not create a leak
	// 	delete i;
	// 	std::cout << "---\n";
	// 	{
	// 		Dog stray;
	// 		{
	// 			Dog clone = stray;
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