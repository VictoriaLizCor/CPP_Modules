#include "Animal.hpp"
#include "Brain.hpp"
#if (DEBUG != 0)

#include <iostream>

int main(void)
{
	size_t const size = 100;
	// size_t const size = Brain::getSize();
	size_t i;
	{
			Animal test[size];
			for( i = 0; i < size; ++i )
				test[i].makeSound();
	}
	{
		
	}
	std::cout << "\n";
	return (0);
}

#endif