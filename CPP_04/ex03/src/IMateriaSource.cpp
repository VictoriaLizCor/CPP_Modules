#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
}

IMateriaSource::~IMateriaSource(void)
{
}

std::ostream& operator << (std::ostream& os, IMateriaSource& rhs)
{
	return (os);
}
