#include "Cure.hpp"
#include "ICharacter.hpp"

std::string const Cure::_colorIdStr = getColorFmt(FGREEN);

Cure::Cure():
AMateria(getColorStr(_colorIdStr, "cure"))
{
	if (DEBUG)
		std::cout << this << getColorStr(FGRAY, " was Created\n");
}


Cure&::Cure::operator=(AMateria const& rhs)
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	return (*this);
}

Cure::Cure(AMateria const&rhs):AMateria(rhs)
{
	*this = rhs;
}


Cure::~Cure(void)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
}


std::string const& Cure::getType() const{return (_type);}

Cure *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << this << " type use on " << target.getName() << "\n";
}

std::string Cure::getInfo(void) const
{
	return (this->_colorIdStr + this->getType() + toString(_objId) + std::string(C_END));
}

