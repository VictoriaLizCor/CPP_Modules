#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" was Created", FGRAY, 0) << std::endl ;
}

Cat::~Cat()
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0)<< setColor(" was Destroyed", FGRAY, 0) << std::endl ;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow\n";
}
