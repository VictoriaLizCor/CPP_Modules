#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Bureaucrat
{
	private:
		std::string const	_name;
		size_t				_grade;

	protected:
		
	public:
		explicit Bureaucrat(std::string const& name, size_t grade);
		Bureaucrat& opertator=(Bureaucrat const& rhs);
		Bureaucrat(Bureaucrat const& rhs);
		virtual ~Bureaucrat();

		std::string		getName();
		size_t 			getGrade();

		class GradeTooHighException: public std::exception
		{
			
		};
		class GradeTooLowException: public std::exception
		{

		};
};

std::ostream& operator << (std::ostream& os, Bureaucrat const& rhs);

#endif // BUREAUCRAT_HPP