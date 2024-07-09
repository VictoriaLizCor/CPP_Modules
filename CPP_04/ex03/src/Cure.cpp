#include "Cure.hpp"
#include "ICharacter.hpp"


Cure::Cure():
AMateria("cure")
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
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
	std::cout << *this << " type use on " << target.getName() << "\n";
}

std::string Cure::getInfo(void) const
{
	std::ostringstream os;

	os << _colorIdStr << className(typeid(*this).name()) << "::"
	<< _type << toString(_objId) << std::string(C_END);
	return (os.str());
}

