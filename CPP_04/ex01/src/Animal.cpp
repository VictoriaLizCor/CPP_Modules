#include "Animal.hpp"

unsigned int Animal::_objectColor = FGRAY;

Animal::Animal(std::string const& type): _CLASS_ICON("🐾"), _type(type), _color(setObjColor(++_objectColor))
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" was Created", FGRAY, 0) << std::endl ;
}


Animal&::Animal::operator=(Animal const& rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type;
		_color = setObjColor(++_objectColor);
	}
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" Copy was Created", FGRAY, 0) << std::endl ;
	return (*this);
}

Animal::Animal(Animal const& rhs){*this=rhs;}

Animal::~Animal()
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" was Destroyed", FGRAY, 0) << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << "[ "+ _CLASS_ICON + " ]" + "\t     : ... " + "\n";
}

std::string Animal::getType(void) const
{
	return (setColor(_type, _color, 0) + "\t" + getIcon());
}

std::string Animal::getIcon(void) const
{
	return ("[ "+ _CLASS_ICON + " ]");
}


std::ostream& operator << (std::ostream& os, Animal& rhs)
{
	os << typeid(rhs).name();
	return (os);
}
