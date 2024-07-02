#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Dog
{
	private:
	protected:
	public:
		Dog();
		~Dog();
};
std::ostream& operator << (std::ostream & os, Dog& rhs);

#endif // DOG_HPP