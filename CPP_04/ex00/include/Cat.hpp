#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Cat
{
	private:
	protected:
	public:
		Cat();
		~Cat();
};
std::ostream& operator << (std::ostream & os, Cat& rhs);

#endif // CAT_HPP