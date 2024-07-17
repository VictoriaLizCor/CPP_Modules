#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		static size_t const	_inventorySize = 4;
		static int			_instanceCount;
		int					_instanceId;
		AMateria*			_inventory[_inventorySize];
		std::string 		_colorIdStr;
		std::string 		_name;

	protected:
		
	public:
		explicit Character(std::string const& name);
		Character& operator=(Character const& rhs);
		Character(Character const& rhs);
		virtual ~Character(void);

		std::string const&	getName(void) const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

		// Aditional member function
		std::string			getInfo(void) const;
		static size_t		getInvetorySize(void);
		void				getInventory(size_t idx) const;
};

std::ostream& operator << (std::ostream& os, Character const& rhs);

#endif // CHARACTER_HPP