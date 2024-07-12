#include "Character.hpp"

Character::Character(std::string const& name)
{
}

Character::~Character(void)
{
}

void Character::equip(AMateria* m)
{

}

void Character::unequip(int idx)
{

}
void Character::use(int idx, ICharacter& target)
{

}
std::ostream& operator << (std::ostream& os, Character& rhs)
{
	return (os);
}
