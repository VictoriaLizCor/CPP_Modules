#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

class AMateria
{
	private:

	protected:
		
	public:
		AMateria();
		virtual ~AMateria(void);

};

std::ostream& operator << (std::ostream& os, AMateria& rhs);

#endif // AMATERIA_HPP