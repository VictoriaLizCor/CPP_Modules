#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>
// # include "AMateria.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

class AMateria;

class ICharacter
{
	private:

	protected:
		
	public:
		virtual ~ICharacter() {}
		virtual std::string const& getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;

		// Adtional member function
		virtual std::string const&  getInfo( void ) const = 0;
		

};

std::ostream& operator << (std::ostream& os, ICharacter const& rhs);

#endif // ICHARACTER_HPP