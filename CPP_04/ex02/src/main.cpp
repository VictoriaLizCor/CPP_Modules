#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#if (DEBUG == 0)

#include <iostream>

int main(void)
{
	// size_t const size = 10;
	// {
	// 	size_t i;
	// 	const Animal* animals[size];
	// 	std::cout << "---\n";
	// 	for( i = 0; i < size; ++i )
	// 	{
	// 		if( i < size / 2 )
	// 			animals[i] = new Cat();
	// 		else
	// 			animals[i] = new Dog();
	// 	}
	// 	std::cout << "---\n";
	// 	std::cout << "Total Animals created: "
	// 	<< animals[i - 1]->getId() << "/" << i << "\n";
	// 	std::cout << "---\n";
	// 	for( i = 0; i < size; ++i )
	// 	{
	// 		animals[i]->makeSound();
	// 	}
	// 	std::cout << "---\n";
	// 	while (--i <= size)
	// 		delete animals[i];
	// }
	std::cout << "\n------------MORE TESTS----------\n";
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "---\n";
		i->makeSound();
		j->makeSound();
		std::cout << "---\n";
		delete j;
		delete i;
		std::cout << "-------------\n";
		{
			Dog stray;
			std::cout << "---\n";
			{
				Dog clone = stray;
				stray.makeSound();
				clone.makeSound();
				std::cout << "---\n";
			}
			std::cout << "---\n";
		}
		std::cout << "---\n";
	}
	std::cout << "\n";
	return (0);
}


#endif