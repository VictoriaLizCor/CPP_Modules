#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include "Utils.hpp"
# include "GradeException.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

class Form;

class Bureaucrat
{
	private:
		// Debug attributes
		static int			_instanceCount;
		int					_instanceId;
		std::string const	_colorIdStr;
		// Subject specific
		std::string const	_name;
		size_t				_grade;

	protected:
		
	public:
		explicit Bureaucrat(std::string const& name, size_t grade);
		Bureaucrat& operator=(Bureaucrat const& rhs);
		Bureaucrat(Bureaucrat const& rhs);
		virtual ~Bureaucrat();

		std::string const&		getName() const;
		size_t const&			getGrade() const;
		void					incrementGrade(void);
		void					decrementGrade(void);
		void					signForm(Form& form);

		void					checkGrade(size_t grade);
		std::string 			getInfo() const;
		
		class GradeTooHighException : public GradeException
		{
			public:
				explicit GradeTooHighException(const std::string& msg);
		};
		class GradeTooLowException : public GradeException
		{
			public:
				explicit GradeTooLowException(const std::string& msg);
		};
};

std::ostream& operator << (std::ostream& os, Bureaucrat const& rhs);

#endif // BUREAUCRAT_HPP