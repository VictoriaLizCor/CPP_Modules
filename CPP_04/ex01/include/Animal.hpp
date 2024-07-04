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
		std::string			_CLASS_ICON;
		std::string			_type;
		std::string			_color;
		static int			_objectColor;
		virtual	std::string	getIcon() 
		const;

	public:
		explicit Animal(std::string const& type = "Animal");
		Animal& operator=(Animal const& rhs);
		Animal(Animal const& rhs);
		virtual ~Animal(void);
		virtual std::string		getClass(void);
		virtual void	makeSound(void) const;
		virtual std::string getType(void) const;

};
std::ostream& operator << (std::ostream & os, Animal& rhs);

#endif // ANIMAL_HPP