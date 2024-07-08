#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
}

IMateriaSource&::IMateriaSource::operator=(IMateriaSource const& rhs)
{

}

IMateriaSource::~IMateriaSource(void)
{
}

std::ostream& operator << (std::ostream& os, IMateriaSource& rhs)
{
	return (os);
}

void IMateriaSource::learnMateria(AMateria* aMateria)
{

}

IMateriaSource::AMateria* createMateria(std::string const & type)
{

}