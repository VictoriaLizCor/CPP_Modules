#include "AMateria.hpp"
#include "ICharacter.hpp"

int AMateria::_objId = 0;

void AMateria::initColor(void)
{
	if (_type == "cure")
		_colorIdStr = getColorFmt(FGREEN);
	else if (_type == "ice")
		_colorIdStr = getColorFmt(FBLUE);
}

AMateria::AMateria(std::string const & type):
_type(type)
{
	_objId++;
	initColor();
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
}

AMateria&::AMateria::operator=(AMateria const& rhs)
{
	if (this != &rhs)
	{
		if (_colorIdStr.empty())
		{
			_objId++;
			_colorIdStr = rhs._colorIdStr;
		}
		// this->_type = rhs._type;
	}
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


std::string const& AMateria::getType() const
{
	return (_type);
}


void AMateria::use(ICharacter& target)
{
	std::cout << *this << " type use on " << target.getName() << "\n";
}

std::string AMateria::getInfo(void) const
{
	std::ostringstream os;

	os << _colorIdStr << className(typeid(*this).name()) << "::"
	<< _type << toString(_objId) << std::string(C_END);
	return (os.str());
}



std::ostream& operator << (std::ostream& os, AMateria& rhs)
{
	if (DEBUG)
		os << rhs.getInfo();
	else
		os << rhs.getType();
	return (os);
}
