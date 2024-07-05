#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <typeinfo>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Dog : virtual public Animal
{
	private:
		private:
		std::string	_CLASS_ICON;
		std::string getIcon(void) const;
		Brain*		_brain;
		static size_t const _IDEAS = 20;
		static const std::string _THOUGHTS[_IDEAS]; 
	protected:

	public:
		explicit Dog();
		Dog& operator=(Dog const& rhs);
		Dog(Dog const& rhs);
		~Dog();

		std::string	getClass(void) const;
		void		makeSound(void) const;

};

#endif // DOG_HPP