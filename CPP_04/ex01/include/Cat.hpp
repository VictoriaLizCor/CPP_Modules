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
		static const std::string thoughts[20];
		std::string	getIcon(void) const;

	protected:

	public:
		explicit Cat(void);
		Cat& operator=(Cat const& rhs);
		Cat(Cat const& rhs);
		~Cat(void);
		std::string	getClass(void);
		void 		makeSound(void) const;
};

#endif // CAT_HPP