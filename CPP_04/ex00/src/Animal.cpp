#include "Animal.hpp"

Animal::Animal():_type(className(typeid(*this).name()))
{
	std::cout << _type << setColor(" was Created", FGRAY, 0) << std::endl ;
}

Animal::~Animal()
{
	std::cout << _type << setColor(" was Destroyed", FGRAY, 0) << std::endl ;
}

void Animal::makeSound(void)
{
	std::cout << "Bark\n";
}

std::string Animal::getType(void) const
{
	return (_type);
}


std::ostream& operator << (std::ostream& os, Animal& rhs)
{
	os << typeid(rhs).name();
	return (os);
}
