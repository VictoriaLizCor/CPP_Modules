#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <Utils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Data
{
	private:

	protected:
		
	public:
		Data();
		Data& operator=(Data const& rhs);
		Data(Data const& rhs);
		virtual ~Data();
};

// std::ostream& operator << (std::ostream& os, Data& rhs);

#endif // DATA_HPP