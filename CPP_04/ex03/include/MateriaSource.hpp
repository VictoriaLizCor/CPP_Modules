#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>
# include "IMateriaSource.hpp"
# ifndef DEBUG
#  define DEBUG 0
# endif

class MateriaSource : public IMateriaSource
{
	private:

	protected:
		
	public:
		MateriaSource();
		MateriaSource& operator=(MateriaSource const& rhs);
		virtual ~MateriaSource(void);

		void		learnMateria(AMateria* aMateria) = 0;
		AMateria*	createMateria(std::string const & type) = 0;

};

#endif // MATERIASOURCE_HPP