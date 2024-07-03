#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "stringUtils.hpp"

#if (DEBUG == 0)

#include <iostream>

int main(void)
{
	size_t const size = Brain::getSize();
	size_t i;
	{
		const Animal* animals[size];
		// const Animal* dog = new Dog();
		// const Animal* cat = new Cat();
		std::cout << "---\n";
		std::cout << Brain::getSize() << "\n";
		std::cout << "---\n";
		 for( i = 0; i < size; ++i )
		 {
			if( i < size / 2 )
				animals[i] = new Cat();
			else
				animals[i] = new Dog();

			std::cout << std::endl;
		}
		for( i = 0; i < size; ++i )
		{
			animals[i]->makeSound();
		}
		std::cout << "---\n";
		for (i = 0; i < size; ++i)
		{
			delete animals[i];
		}
		// delete[] animal;
	}
	std::cout << "\n";
	return (0);
}


#endif