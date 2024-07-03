#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <typeinfo>

# ifndef DEBUG
#  define DEBUG 0
# endif

class WrongCat : virtual public WrongAnimal
{
	private:
		std::string	_CLASS_ICON;
	protected:
		
	public:
		WrongCat();
		virtual ~WrongCat();
		void makeSound(void) const;

};

#endif // WRONGCAT_HPP