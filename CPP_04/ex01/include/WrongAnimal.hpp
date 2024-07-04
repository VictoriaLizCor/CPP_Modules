#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

class WrongAnimal
{
	private:

	protected:
		std::string		_CLASS_ICON;
		std::string		_type;
		std::string		_color;
		static int		_objectColor;

	public:
		explicit WrongAnimal(std::string const& type = "WrongAnimal");
		WrongAnimal& operator=(WrongAnimal const& rhs);
		WrongAnimal(WrongAnimal const& rhs);
		virtual 	~WrongAnimal();

		std::string	getClass(void);
		void		makeSound(void) const;
		std::string	getType(void) const;
};
std::ostream& operator << (std::ostream & os, WrongAnimal& rhs);

#endif // WRONGANIMAL_HPP