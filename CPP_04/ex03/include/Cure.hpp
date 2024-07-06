#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Cure
{
	private:

	protected:
		
	public:
		Cure();
		virtual ~Cure(void);

};

std::ostream& operator << (std::ostream& os, Cure& rhs);

#endif // CURE_HPP