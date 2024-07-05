#include "Animal.hpp"

int Animal::_objectColor = 0;

Animal::Animal(std::string const& type): _CLASS_ICON("🐾"), _type(type), _color(setObjColor(FGRAY + ++_objectColor))
{
	std::cout << *this << getColorStr(FGRAY, " was Created\n");
}

Animal&::Animal::operator=(Animal const& rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type; // Do i need it?
		_color = setObjColor(FGRAY + ++_objectColor);
	}
	std::cout << *this << getColorStr(FGRAY, " Copy was Created\n");
	return (*this);
}

Animal::Animal(Animal const& rhs){*this = rhs;}

Animal::~Animal()
{
	std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
}

void Animal::makeSound(void) const
{
	std::cout << getIcon() + "\t     : ... " + "\n";
}

std::string Animal::getType(void) const
{
	return (_color + _type + "\t" + getIcon());
}

std::string Animal::getIcon(void) const
{
	return ("[ "+ _CLASS_ICON + " ]");
}

std::string Animal::getClass(void)
{
	return (_color + className(typeid(*this).name()) + std::string(C_DEFAULT));
}

std::ostream& operator << (std::ostream& os, Animal& rhs)
{
	os << rhs.getClass();
	return (os);
}
