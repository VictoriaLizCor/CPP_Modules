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

class ICharacter
{
	private:

	protected:
		
	public:
		ICharacter();
		virtual ~ICharacter(void);

};

std::ostream& operator << (std::ostream& os, ICharacter& rhs);

#endif // ICHARACTER_HPP