#include "Dog.hpp"

Dog::Dog():Animal(className(typeid(*this).name())), _CLASS_ICON("🐶")
{
	std::cout << *this << getColorStr(FGRAY, " was Created") << std::endl;
}

Dog::~Dog()
{
	std::cout << *this << getColorStr(FGRAY, " was Destroyed") << std::endl;
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

std::string Dog::getClass(void)
{
	return (_color + className(typeid(*this).name()) + std::string(C_DEFAULT));
}