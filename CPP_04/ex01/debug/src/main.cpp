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

int main(void)
{
	// size_t const size = 4;
	size_t const size = Brain::getSize();
	// testBrain(size);
	{
		{
			Cat stray;
			for (size_t i = 0; i < size; ++i)
			{
				std::cout << i << "-";
				stray.makeSound();
				std::cout << "\n";
			}
			{
				Cat clone = stray;
				std::cout << "---\n";
				for (size_t i = 0; i < size; ++i)
				{
					std::cout << i << "-";
					clone.makeSound();
					std::cout << "\n";
				}
				std::cout << "---\n";
			}
			std::cout << "---\n";
		}
	}
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