#include "Cure.hpp"
#include "ICharacter.hpp"


Cure::Cure(std::string const& type):
AMateria(type)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
}


Cure&::Cure::operator=(Cure const& rhs)
{
	(void)rhs;
	// if (this != &rhs)
	// 	AMateria::operator=(rhs);
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
	return (*this);
}

Cure::Cure(Cure const& rhs): AMateria(rhs.getType())
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
	if (DEBUG)
	{
		std::cout << getInfo() << " " + std::string(__func__) + "()"
		<< getColorStr(FGRAY," used\n");
	}
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "\n";
}

std::string Cure::getInfo(void) const
{
	std::ostringstream os;

	os << _colorIdStr << className(typeid(*this).name()) << "::"
	<< _type << toString(_objId) << std::string(C_END);
	return (os.str());
}

