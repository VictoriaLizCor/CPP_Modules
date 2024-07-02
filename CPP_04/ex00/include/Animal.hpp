#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Animal
{
	private:
		static unsigned int		_CLASS_COLOR;
	protected:
		std::string			_type;
		std::string			_color;
		static unsigned int	_objectColor;

	public:
		explicit Animal(std::string const& type = "Animal");
		virtual ~Animal();

		virtual void makeSound(void) const;
		std::string getType(void) const;

};
std::ostream& operator << (std::ostream & os, Animal& rhs);

#endif // ANIMAL_HPP