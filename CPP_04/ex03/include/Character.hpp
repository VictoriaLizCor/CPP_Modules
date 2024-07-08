#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>
# include "AMateria.hpp"
# include "ICharacter.hpp"


class Character : public ICharacter
{
	private:
		AMateria *_inventory[4];

	protected:
		
	public:
		Character(std::string const& name);
		Character& operator=(Character const& rhs);
		Character(Character const& rhs);
		virtual ~Character(void);

};

std::ostream& operator << (std::ostream& os, Character& rhs);

#endif // CHARACTER_HPP