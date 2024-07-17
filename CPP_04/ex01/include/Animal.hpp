#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>

class Animal
{
	private:
		
	protected:
		static int			_Id;
		std::string			_CLASS_ICON;
		std::string			_type;
		std::string			_color;

		virtual	std::string	getIcon() const;

	public:
		explicit Animal(std::string const& type = "Animal");
		Animal& operator=(Animal const& rhs);
		Animal(Animal const& rhs);
		virtual ~Animal(void);
		virtual std::string		getClass(void) const;
		virtual void		makeSound(void) const;
		int					getId() const;
		virtual std::string getType(void) const;

};
std::ostream& operator << (std::ostream & os, Animal const& rhs);

#endif // ANIMAL_HPP