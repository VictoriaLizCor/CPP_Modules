#include "AMateria.hpp"
# include "ICharacter.hpp"

AMateria::AMateria(std::string const & type):_type(type)
{

}

AMateria&::AMateria::operator=(AMateria const& rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

AMateria::~AMateria(void)
{
}


std::string const& AMateria::getType() const{return (_type);}

void AMateria::use(ICharacter& target)
{
	std::cout << this << " type use on " << target << "\n";
}

std::string AMateria::getClass(void) const
{
	return (_colorIdStr + getType() + std::string(C_END));
}

std::ostream& operator << (std::ostream& os, AMateria& rhs)
{
	os << rhs.getClass();
	return (os);
}
