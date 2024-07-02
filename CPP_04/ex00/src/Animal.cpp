#include "Animal.hpp"

unsigned int Animal::_objectColor = FGRAY;

Animal::Animal(std::string const& type): _type(type), _color(setObjColor(++_objectColor))
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" was Created", FGRAY, 0) << std::endl ;
}


Animal::~Animal()
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" was Destroyed", FGRAY, 0) << std::endl ;
}

void Animal::makeSound(void) const
{
	std::cout << "...\n";
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
