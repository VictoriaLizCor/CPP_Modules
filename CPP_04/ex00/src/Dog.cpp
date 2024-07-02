#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" was Created", FGRAY, 0) << std::endl ;
}

Dog::~Dog()
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" was Destroyed", FGRAY, 0) << std::endl ;
}

void Dog::makeSound(void) const
{
	std::cout << "Bark\n";
}