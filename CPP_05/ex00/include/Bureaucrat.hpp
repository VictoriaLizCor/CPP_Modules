#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <Utils.hpp>
# include <exception>
# ifndef DEBUG
#  define DEBUG 0
# endif

class Bureaucrat
{
	private:
		static int			_instanceCount;
		int					_instanceId;
		std::string const	_colorIdStr;
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

		void					checkGrade(size_t grade);
		std::string 			getInfo() const;
		class GradeTooHighException: virtual public std::exception
		{
			private:
				std::string _msg;
			public:
				GradeTooHighException(std::string const& msg);
				virtual ~GradeTooHighException() throw() {}
				virtual const char* what() const throw();

		};
		class GradeTooLowException: virtual public std::exception
		{
			private:
				std::string _msg;
			public:
				GradeTooLowException(std::string const& msg);
				virtual ~GradeTooLowException() throw() {}
				virtual const char* what() const throw();
		};
};

std::ostream& operator << (std::ostream& os, Bureaucrat const& rhs);

#endif // BUREAUCRAT_HPP