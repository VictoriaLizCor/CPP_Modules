#include "Character.hpp"

Character::Character(std::string const& name):
_instanceId(++_instanceCount), _colorIdStr(getRandomColorFmt(1))
{
	if (name.empty())
		_name = "Anonymous";
	else
		_name = name;
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
}

Character&::Character::operator=(Character const& rhs)
{
	
}

Character::Character(Character const&rhs):
_instanceId(++_instanceCount), _colorIdStr(getRandomColorFmt(1))
{*this = rhs;}

Character::~Character(void)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
	_instanceCount--;
}

std::string const& Character::getName(void) const {return(_name);}

void Character::equip(AMateria* m)
{

}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter& target)
{

}

std::string Character::getInfo(void) const
{
	std::ostringstream os;

	os << _colorIdStr;
	if (DEBUG)
		os << className(typeid(*this).name()) << _instanceCount << "::"
	<< getName();
	else 
		os << getName();
	os << std::string(C_END);

	return (os.str());
}

std::ostream& operator << (std::ostream& os, Character& rhs)
{
	return (os);
}
