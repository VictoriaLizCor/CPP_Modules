#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Character
{
	private:

	protected:
		
	public:
		Character();
		virtual ~Character(void);

};

std::ostream& operator << (std::ostream& os, Character& rhs);

#endif // CHARACTER_HPP