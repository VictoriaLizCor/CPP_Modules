#include "AMateria.hpp"
#include "ICharacter.hpp"

int AMateria::_objId = 0;

AMateria::AMateria(std::string const & type):
_type(type)
{
	_objId++;
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
}

AMateria&::AMateria::operator=(AMateria const& rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " Copy was Created\n");
	return (*this);
}

AMateria::AMateria(AMateria const&rhs){*this = rhs;}

AMateria::~AMateria(void)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
	--_objId;
}


std::string const& AMateria::getType() const{return (_type);}


void AMateria::use(ICharacter& target)
{
	std::cout << *this << " type use on " << target.getName() << "\n";
}

std::string AMateria::getInfo(void) const
{
	return ("");
}


std::ostream& operator << (std::ostream& os, AMateria& rhs)
{
	if (DEBUG)
		os << rhs.getInfo();
	else
		os << rhs.getType();
	return (os);
}
