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
		explicit Character(std::string const& name);
		Character& operator=(Character const& rhs);
		Character(Character const& rhs);
		virtual ~Character(void);

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};


#endif // CHARACTER_HPP