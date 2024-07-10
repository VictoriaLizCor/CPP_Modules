#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>
# include "AMateria.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

class ICharacter;
class Cure: public AMateria
{
	private:
		
	protected:

	public:
		explicit Cure(std::string const& type = "cure");
		Cure& operator=(Cure const& rhs);
		Cure(Cure const& rhs);
		virtual ~Cure();

		std::string const&	getType(void) const;
		Cure*		clone(void) const;
		void		use(ICharacter& target);

		//*aditional function members
		std::string	getInfo(void) const;

};


#endif // CURE_HPP