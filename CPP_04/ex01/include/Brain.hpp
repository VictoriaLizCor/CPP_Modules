#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>

class Brain
{
	private:
		static size_t const _size = 6;
		std::string			_ideas[_size];
	protected:
		
	public:
		Brain();
		Brain& operator=(Brain const& rhs);
		Brain(Brain const& rhs);
		virtual ~Brain();
		std::string		getClass(void);
		static size_t	getSize();

};
std::ostream& operator << (std::ostream& os, Brain& rhs);

#endif // BRAIN_HPP