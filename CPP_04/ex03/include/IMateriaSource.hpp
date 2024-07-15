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

class AMateria;

class IMateriaSource
{
	private:

	protected:
		
	public:
		virtual ~IMateriaSource() {}
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;

		// additional function members for DEBUG=1;
		virtual void getInventory(size_t idx) const = 0;
};

#endif // IMATERIASOURCE_HPP