#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Utils.hpp"
#include <map>
#include <vector>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Intern
{
	private:
		// Debug attributes
		static int			_instanceCount;
		int					_instanceId;
		std::string const	_colorIdStr;

		typedef AForm* (*FormCreator)(const std::string&);
		std::map<std::string, FormCreator> formCreationMap;
		Intern& operator=(Intern const& rhs);
		Intern(Intern const& rhs);
	public:
		Intern();
		~Intern();
		AForm* makeForm(const std::string& formName, const std::string& target);
		std::string getInfo(void) const;
};


std::ostream& operator << (std::ostream& os, Intern& rhs);

#endif // INTERN_HPP