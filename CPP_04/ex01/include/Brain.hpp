#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Brain
{
	private:
		static size_t const _size = 50;
	protected:
		
	public:
		Brain();
		virtual ~Brain();
		static size_t	getSize();

};
std::ostream& operator << (std::ostream& os, Brain& rhs);

#endif // BRAIN_HPP