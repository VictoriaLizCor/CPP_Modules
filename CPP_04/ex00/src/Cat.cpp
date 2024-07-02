#include "Cat.hpp"

Cat::Cat()
{
}

Cat::~Cat()
{
}

std::ostream& operator << (std::ostream & os, Cat& rhs)
{
	return os;
}
