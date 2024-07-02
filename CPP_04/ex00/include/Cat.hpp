#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include <iostream>
# include <typeinfo>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Cat : public Animal
{
	private:
	protected:
	public:
		explicit Cat();
		virtual ~Cat();
};
std::ostream& operator << (std::ostream & os, Cat& rhs);

#endif // CAT_HPP