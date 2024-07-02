#include "Dog.hpp"

Dog::Dog()
{
}

Dog::~Dog()
{
}

std::ostream& operator << (std::ostream & os, Dog& rhs)
{
	return os;
}
