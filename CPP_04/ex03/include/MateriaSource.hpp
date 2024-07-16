#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include "IMateriaSource.hpp"
# ifndef DEBUG
#  define DEBUG 0
# endif

class MateriaSource : public IMateriaSource
{
	private:
		static size_t const	_inventorySize = 4;
		static int			_instanceCount;
		int					_instanceId;
		AMateria*			_inventory[_inventorySize];
		std::string 		_colorIdStr;
	protected:
		
	public:
		MateriaSource(void);
		MateriaSource& operator=(MateriaSource const& rhs);
		MateriaSource(MateriaSource const& rhs);
		virtual ~MateriaSource(void);

		void			learnMateria(AMateria* aMateria);
		AMateria*		createMateria(std::string const & type);

		// Aditional member function
		std::string		getInfo(void) const;
		static size_t	getInvetorySize(void);
		void			getInventory(size_t idx) const;

};
std::ostream& operator << (std::ostream& os, MateriaSource const& rhs);
#endif // MATERIASOURCE_HPP