#include "Character.hpp"

Character::Character(std::string const& name)
{
}

Character::~Character(void)
{
}

std::ostream& operator << (std::ostream& os, Character& rhs)
{
	return (os);
}
