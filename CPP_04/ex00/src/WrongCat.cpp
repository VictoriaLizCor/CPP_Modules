#include "WrongCat.hpp"


WrongCat::WrongCat():WrongAnimal(className(typeid(*this).name())), _CLASS_ICON("🐯")
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" was Created", FGRAY, 0) << std::endl ;
}

void WrongCat::makeSound(void) const
{
	std::cout << "[ "+ this->WrongAnimal::_CLASS_ICON + " ]";
	std::cout << "[ "+ _CLASS_ICON + " ]" + " :  Roars " + "\n";
}

WrongCat::~WrongCat()
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" was Destroyed", FGRAY, 0) << std::endl ;
}
