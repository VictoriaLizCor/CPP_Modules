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
		Brain*		_brain;

		std::string	getIcon(void) const;

	protected:

	public:
		explicit Cat(void);
		~Cat(void);
		std::string	getClass(void);
		void 		makeSound(void) const;
};

#endif // CAT_HPP