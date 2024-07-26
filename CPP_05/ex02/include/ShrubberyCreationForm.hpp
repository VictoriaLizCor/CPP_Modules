#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

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

class ShrubberyCreationForm : public AForm
{
	private:
		std::string			_target;
		int					_instanceId;
		std::string			_colorIdStr;// FLCyan

		
	public:
		explicit ShrubberyCreationForm(std::string const& target="Unknown");
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);
		ShrubberyCreationForm(ShrubberyCreationForm const& rhs);
		virtual ~ShrubberyCreationForm();

		std::string			getTarget()const;
		std::string			getInfo() const;
		void				execute(Bureaucrat const& executor) const;

		class FileError : public std::runtime_error
		{
			public:
				explicit FileError(std::string const& msg);
		};
};


#endif // SHRUBBERYCREATIONFORM_HPP