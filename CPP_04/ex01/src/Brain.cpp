#include "Brain.hpp"

Brain::Brain()
{
	std::cout << *this << getColorStr(FGRAY, " was Created") << std::endl;
}

Brain::~Brain()
{
	std::cout << *this << getColorStr(FGRAY, " was Destroyed") << std::endl;
}

std::string Brain::getClass(void)
{
	return (getColorStr(FLMAGENTA, className(typeid(*this).name())));
}

std::ostream& operator << (std::ostream& os, Brain& rhs)
{
	os << rhs.getClass();
	return (os);
}

size_t Brain::getSize(){return (_size);}