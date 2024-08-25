#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

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

class RobotomyRequestForm : public AForm
{
	private:
		std::string					_target;
		mutable std::ostringstream	_succesful;
		int							_instanceId;
		std::string					_colorIdStr;
	protected:
		
	public:
		explicit RobotomyRequestForm(std::string const& target="Unknown");
		RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);
		RobotomyRequestForm(RobotomyRequestForm const& rhs);
		~RobotomyRequestForm();

		std::string		getTarget()const;
		std::string		getInfo();
		void			execute(Bureaucrat const& executor) const;

};


#endif // ROBOTOMYREQUESTFORM_HPP