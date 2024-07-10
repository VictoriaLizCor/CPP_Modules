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

class ICharacter;
class AMateria
{
	private:

	protected:
		static int			_objId;
		std::string 		_colorIdStr;
		std::string			_type;

	public:
		AMateria(std::string const & type);
		AMateria& operator=(AMateria const& rhs);
		AMateria(AMateria const& rhs);
		virtual ~AMateria();

		std::string const&	getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);

		//*aditional function members
		void initColor(void);
		virtual std::string	getInfo(void) const;
};

std::ostream& operator << (std::ostream& os, AMateria& rhs);

#endif // AMATERIA_HPP