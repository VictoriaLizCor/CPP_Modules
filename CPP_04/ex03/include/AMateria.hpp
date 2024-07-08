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
		std::string			_type;
		std::string const	_colorIdStr;
	protected:
		
	public:
		AMateria(std::string const & type);
		AMateria& operator=(AMateria const& rhs);
		virtual ~AMateria();

		std::string const& getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		//*aditional function members
		std::string getClass(void) const;

};

std::ostream& operator << (std::ostream& os, AMateria& rhs);

#endif // AMATERIA_HPP