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
		int							_Id;
		std::string					_CLASS_ICON;
		Brain*						_brain;
		static size_t const 		_IDEAS = 20;
		static std::string const	_THOUGHTS[_IDEAS];
		
		std::string	getIcon(void) const;

	protected:

	public:
		explicit Cat(void);
		Cat& operator=(Cat const& rhs);
		Cat(Cat const& rhs);
		~Cat(void);
		std::string	getClass(void) const;
		void 		makeSound(void) const;
};

#endif // CAT_HPP