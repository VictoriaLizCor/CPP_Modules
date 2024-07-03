#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#if (DEBUG != 0)

int main(void)
{
	{
		std::cout << "---------------------\n";
		WrongAnimal wA;
		WrongAnimal* wC = new WrongCat();
		WrongCat wc;
		std::cout << "---\n";
		std::cout << std::endl;
		std::cout << wA.getType() << " " << std::endl;
		std::cout << wC->getType() << " " << std::endl;
		std::cout << wc.getType() << " " << std::endl;
		std::cout << std::endl;
		wA.makeSound(); // will output wA sound!
		wC->makeSound();    // will output wA sound!
		wc.makeSound();           // will output wC sound!
		std::cout << "---\n";
		delete wC;
	}
	std::cout << "\n";
	return (0);
}

#endif