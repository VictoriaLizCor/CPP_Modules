#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(std::string const& type):
AMateria(type)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
}


Ice&::Ice::operator=(Ice const& rhs)
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	return (*this);
}

Ice::Ice(Ice const& rhs): AMateria(rhs)
{
	*this = rhs;
}


Ice::~Ice(void)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
}


std::string const& Ice::getType() const{return (_type);}

Ice *Ice::clone(void) const
{
	if (DEBUG)
	{
		std::cout << getInfo() << " " +std::string(__func__) + "()"
		<< getColorStr(FGRAY," used\n");
	}
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << *this << " type use on " << target.getName() << "\n";
}

std::string Ice::getInfo(void) const
{
	std::ostringstream os;

	os << _colorIdStr << className(typeid(*this).name()) << "::"
	<< _type << toString(_objId) << std::string(C_END);
	return (os.str());
}

