#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

class IMateriaSource
{
	private:

	protected:
		
	public:
		IMateriaSource();
		virtual ~IMateriaSource(void);

};

std::ostream& operator << (std::ostream& os, IMateriaSource& rhs);

#endif // IMATERIASOURCE_HPP