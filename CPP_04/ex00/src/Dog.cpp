#include "Dog.hpp"

Dog::Dog():Animal(className(typeid(*this).name())), _CLASS_ICON("🐶")
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" was Created", FGRAY, 0) << std::endl ;
}

Dog::~Dog()
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" was Destroyed", FGRAY, 0) << std::endl ;
}

void Dog::makeSound(void) const
{
	std::cout << this->Animal::getIcon();
	std::cout << "[ "+ _CLASS_ICON + " ]" + " : Barks " + "\n";
}

std::string Dog::getIcon(void) const
{
	return ("[ "+ _CLASS_ICON + " ]");
}