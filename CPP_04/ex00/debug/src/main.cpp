#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#if (DEBUG != 0)

#include <iostream>

int main(void)
{
	{
		std::cout << "---------------------\n";
		WrongAnimal wrongAnimal;
		const WrongAnimal* wrongCat = new WrongCat();
		WrongCat wc;
		std::cout << "---\n";
		std::cout << std::endl;
		std::cout << wrongAnimal.getType() << " " << std::endl;
		std::cout << wrongCat->getType() << " " << std::endl;
		std::cout << wc.getType() << " " << std::endl;
		std::cout << std::endl;
		wrongAnimal.makeSound(); // output wrong animal sound
		wrongCat->makeSound();    // output wrong animal sound
		wc.makeSound();           // output wrong cat    sound
		std::cout << std::endl;
		delete wrongCat;
	}
	return (0);
}

#endif