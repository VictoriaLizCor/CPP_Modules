#include "WrongAnimal.hpp"

int WrongAnimal::_objectColor = FLBLACK;

WrongAnimal::WrongAnimal(std::string const& type): _CLASS_ICON("⛔"), _type(type), _color(setObjColor(++_objectColor))
{
	std::cout << *this << getColorStr(FGRAY, " was Created") << std::endl;
}

WrongAnimal&::WrongAnimal::operator=(WrongAnimal const& rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type;
		_color = setObjColor(++_objectColor);
	}
	std::cout << *this << getColorStr(FGRAY, " Copy was Created") << std::endl;
	return (*this);
}

WrongAnimal::WrongAnimal(WrongAnimal const& rhs){*this=rhs;}

WrongAnimal::~WrongAnimal()
{
	std::cout << *this << getColorStr(FGRAY, " was Destroyed") << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "[ "+ _CLASS_ICON + " ]" + "\t     : ... " + "\n";
}

std::string WrongAnimal::getType(void) const
{
	return (_color + _type + std::string(C_DEFAULT) + "\t" + "[ "+ _CLASS_ICON + " ]");
}

std::string WrongAnimal::getClass(void)
{
	return (_color + className(typeid(*this).name()) + std::string(C_DEFAULT));
}

std::ostream& operator << (std::ostream& os, WrongAnimal& rhs)
{
	os << rhs.getClass();
	return (os);
}
