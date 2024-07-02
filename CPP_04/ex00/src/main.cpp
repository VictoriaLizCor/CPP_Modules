#include "Cat.hpp"
#include "Dog.hpp"

#if (DEBUG == 0)

#include <iostream>

int main(void)
{
	{
		const Animal* animal = new Animal();
		// const Animal* dog = new Dog();
		// const Animal* cat = new Cat();

		std::cout << animal->getType() << " " << std::endl;
		// std::cout << dog->getType() << " " << std::endl;
		// std::cout << cat->getType() << " " << std::endl;

		// animal->makeSound();
		// dog->makeSound(); //will output the cat sound!
		// cat->makeSound();
		// std::cout << "\n\n";
		delete animal;
		// delete dog;
		// delete cat;
	}
	return (0);
}

#endif