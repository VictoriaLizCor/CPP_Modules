#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include <iostream>
# include <typeinfo>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Dog : public Animal
{
	private:
	protected:
	public:
		explicit Dog();
		virtual ~Dog();
};
std::ostream& operator << (std::ostream & os, Dog& rhs);

#endif // DOG_HPP