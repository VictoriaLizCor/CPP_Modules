#include "Animal.hpp"

Animal::Animal()
{
}

Animal::~Animal()
{
}

std::ostream& operator << (std::ostream & os, Animal& rhs)
{
	return os;
}
