#include "ICharacter.hpp"

ICharacter::ICharacter()
{
}

ICharacter::~ICharacter(void)
{
}

std::ostream& operator << (std::ostream& os, ICharacter& rhs)
{
	return (os);
}
