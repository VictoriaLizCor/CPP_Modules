#include "Cat.hpp"

Cat::Cat():Animal(className(typeid(*this).name())),
_CLASS_ICON("🐱")
{
	std::cout << *this << getColorStr(FGRAY, " was Created") << std::endl;
}

Cat::~Cat()
{
	std::cout << *this << getColorStr(FGRAY, " was Destroyed") << std::endl;
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

std::string Cat::getClass(void)
{
	return (_color + className(typeid(*this).name()) + std::string(C_DEFAULT));
}