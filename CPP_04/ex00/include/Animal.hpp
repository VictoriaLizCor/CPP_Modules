#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Animal
{
	private:
	protected:
	public:
		Animal();
		~Animal();
};
std::ostream& operator << (std::ostream & os, Animal& rhs);

#endif // ANIMAL_HPP