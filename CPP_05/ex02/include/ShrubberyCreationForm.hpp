#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <sys/stat.h>
# include "Utils.hpp"
# include "AForm.hpp"
# include "Files.hpp"
# ifndef DEBUG
#  define DEBUG 0
# endif

class ShrubberyCreationForm : public AForm
{
	private:
		std::string			_target;
		int					_instanceId;
		std::string			_colorIdStr;

		void	plantTree(Files& file, std::stringstream& treeBuffer) const;

	public:
		explicit ShrubberyCreationForm(std::string const& target="Unknown");
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);
		ShrubberyCreationForm(ShrubberyCreationForm const& rhs);
		~ShrubberyCreationForm();

		std::string			getTarget()const;
		std::string			getInfo();
		void				execute(Bureaucrat const& executor) const;
};

#endif // SHRUBBERYCREATIONFORM_HPP