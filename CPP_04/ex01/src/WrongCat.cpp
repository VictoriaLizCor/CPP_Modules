#include "WrongCat.hpp"


WrongCat::WrongCat():WrongAnimal(className(typeid(*this).name())), _CLASS_ICON("🐯")
{
	std::cout << *this << getColorStr(FGRAY, " was Created") << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "[ "+ this->WrongAnimal::_CLASS_ICON + " ]";
	std::cout << "[ "+ _CLASS_ICON + " ]" + " :  Roars " + "\n";
}

WrongCat::~WrongCat()
{
	std::cout << *this << getColorStr(FGRAY, " was Destroyed") << std::endl;
}

std::string WrongCat::getClass(void)
{
	return (_color + className(typeid(*this).name()) + std::string(C_DEFAULT));
}
