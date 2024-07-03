#include "WrongAnimal.hpp"

unsigned int WrongAnimal::_objectColor = FLBLACK;

WrongAnimal::WrongAnimal(std::string const& type): _CLASS_ICON("⛔"), _type(type), _color(setObjColor(++_objectColor))
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" was Created", FGRAY, 0) << std::endl ;
}

WrongAnimal&::WrongAnimal::operator=(WrongAnimal const& rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type;
		_color = setObjColor(++_objectColor);
	}
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" Copy was Created", FGRAY, 0) << std::endl ;
	return (*this);
}

WrongAnimal::WrongAnimal(WrongAnimal const& rhs){*this=rhs;}

WrongAnimal::~WrongAnimal()
{
	std::cout << setColor(className(typeid(*this).name()), _color, 0) << setColor(" was Destroyed", FGRAY, 0) << std::endl ;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "[ "+ _CLASS_ICON + " ]" + "\t     : ... " + "\n";
}

std::string WrongAnimal::getType(void) const
{
	return (setColor(_type, _color, 0) + "\t" + "[ "+ _CLASS_ICON + " ]");
}

std::ostream& operator << (std::ostream& os, WrongAnimal& rhs)
{
	os << typeid(rhs).name();
	return (os);
}
