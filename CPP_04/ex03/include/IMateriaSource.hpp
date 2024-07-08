#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>
# include "AMateria.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

class IMateriaSource
{
	private:

	protected:
		
	public:
		IMateriaSource();
		virtual ~IMateriaSource() {}
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;

};

std::ostream& operator << (std::ostream& os, IMateriaSource& rhs);

#endif // IMATERIASOURCE_HPP