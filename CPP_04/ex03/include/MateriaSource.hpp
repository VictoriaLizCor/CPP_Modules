#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

class MateriaSource
{
	private:

	protected:
		
	public:
		MateriaSource();
		virtual ~MateriaSource(void);

};

std::ostream& operator << (std::ostream& os, MateriaSource& rhs);

#endif // MATERIASOURCE_HPP