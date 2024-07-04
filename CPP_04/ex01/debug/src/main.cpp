#include "Cat.hpp"
#include "Dog.hpp"
#if (DEBUG != 0)

#include <iostream>

int main(void)
{
	size_t const size = 4;
	// size_t const size = Brain::getSize();
	// size_t i;
	{
		// Animal test[size];
		// for( i = 0; i < size; ++i )
		// 	test[i].makeSound();
	}
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "---\n";
		delete j;//should not create a leak
		delete i;
		std::cout << "---\n";
		Dog	Scooby;
	
		std::cout << "---\n";
	}
	std::cout << "\n";
	return (0);
}

#endif