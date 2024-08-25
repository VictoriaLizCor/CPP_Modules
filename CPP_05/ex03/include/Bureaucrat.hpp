#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include "Utils.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

class AForm;

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

		void					checkGrade(size_t grade);
	protected:
		
	public:
		explicit Bureaucrat(std::string const& name ="Anon", size_t grade = 150);
		Bureaucrat& operator=(Bureaucrat const& rhs);
		Bureaucrat(Bureaucrat const& rhs);
		virtual ~Bureaucrat();

		std::string const&		getName() const;
		size_t const&			getGrade() const;
		void					incrementGrade(void);
		void					decrementGrade(void);
		void					signForm(AForm& form);
		void					executeForm(AForm const& form);
		std::string 			getInfo() const;
		
		class GradeTooHighException : public std::out_of_range
		{
			public:
				explicit GradeTooHighException(const std::string& msg);
		};
		class GradeTooLowException : public std::out_of_range
		{
			public:
				explicit GradeTooLowException(const std::string& msg);
		};
};

std::ostream& operator << (std::ostream& os, Bureaucrat const& rhs);

#endif // BUREAUCRAT_HPP