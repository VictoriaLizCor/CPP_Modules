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
		size_t				_index;
		std::string			_ideas[_size];
	protected:
		
	public:
		Brain();
		Brain& operator=(Brain const& rhs);
		Brain(Brain const& rhs);
		virtual ~Brain();
		void			setIdea(std::string const idea);
		std::string		getIdea(size_t i) const;
		size_t			getRandomIdea(size_t size) const;
		std::string		getClass(void);
		static size_t	getSize();

};

std::ostream& operator << (std::ostream& os, Brain& rhs);

#endif // BRAIN_HPP