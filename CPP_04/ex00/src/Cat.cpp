#include "Cat.hpp"

Cat::Cat():Animal(className(typeid(*this).name())),
_CLASS_ICON("🐱")
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" was Created", FGRAY, 0) << std::endl ;
}

Cat::~Cat()
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" was Destroyed", FGRAY, 0) << std::endl ;
}

void Cat::makeSound(void) const
{
	std::cout << this->Animal::getIcon();
	std::cout << "[ "+ _CLASS_ICON + " ]" + " : Meows " + "\n";
}

std::string Cat::getIcon(void) const
{
	return ("[ "+ _CLASS_ICON + " ]");
}