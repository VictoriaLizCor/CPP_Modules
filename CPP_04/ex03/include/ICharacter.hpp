#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>

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
		virtual std::string const&	getName() const = 0;
		virtual void 				equip(AMateria* m) = 0;
		virtual void 				unequip(int idx) = 0;
		virtual void 				use(int idx, ICharacter& target) = 0;


		// additional function members for DEBUG=1;
		// virtual void				getInventory(size_t idx) const = 0;
		// virtual std::string 		getInfo() const = 0;
};


#endif // ICHARACTER_HPP