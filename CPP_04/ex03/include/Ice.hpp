#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>
# include "AMateria.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

class Ice: public AMateria
{
	private:
		
	protected:

	public:
		explicit Ice(std::string const& type = "ice");
		Ice& operator=(Ice const& rhs);
		Ice(Ice const& rhs);
		virtual ~Ice();

		std::string const&	getType(void) const;
		Ice*		clone(void) const;
		void		use(ICharacter& target);

		//*aditional function members
		std::string	getInfo(void) const;

};


#endif // ICE_HPP