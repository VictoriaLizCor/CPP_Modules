#include "Brain.hpp"

Brain::Brain()
{
}

Brain::~Brain()
{
}

std::ostream& operator << (std::ostream& os, Brain& rhs)
{
	return (os);
}

size_t Brain::getSize(){return (_size);}