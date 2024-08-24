#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <sys/stat.h>
# include "Utils.hpp"
# include "AForm.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

class PresidentialPardonForm : public AForm
{
	private:
		std::string					_target;
		mutable std::ostringstream	_succesful;
		int							_instanceId;
		std::string					_colorIdStr;
	protected:
		
	public:
		explicit PresidentialPardonForm(std::string const& target="Unknown");
		PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);
		PresidentialPardonForm(PresidentialPardonForm const& rhs);
		~PresidentialPardonForm();

		std::string		getTarget()const;
		std::string		getInfo();
		void			execute(Bureaucrat const& executor) const;

};


// std::ostream& operator << (std::ostream& os, PresidentialPardonForm& rhs);

#endif // PRESIDENTIALPARDONFORM_HPP