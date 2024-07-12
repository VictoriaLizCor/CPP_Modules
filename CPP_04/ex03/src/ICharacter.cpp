#include "ICharacter.hpp"
#include "AMateria.hpp"

ICharacter::ICharacter()
{
}

ICharacter::~ICharacter(void)
{
}

std::ostream& operator << (std::ostream& os, ICharacter const& rhs)
{
	return (os);
}
