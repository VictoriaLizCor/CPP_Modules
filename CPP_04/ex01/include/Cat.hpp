#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

class Cat : virtual public Animal
{
	private:
		private:
		std::string	_CLASS_ICON;
		std::string getIcon(void) const;
		Brain*		_brain;

	protected:

	public:
		explicit Cat();
		~Cat();
		void makeSound(void) const;
};

#endif // CAT_HPP