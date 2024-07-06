#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Ice
{
	private:

	protected:
		
	public:
		Ice();
		virtual ~Ice(void);

};

std::ostream& operator << (std::ostream& os, Ice& rhs);

#endif // ICE_HPP