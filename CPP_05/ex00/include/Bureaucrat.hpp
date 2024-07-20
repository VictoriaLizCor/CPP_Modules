#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <Utils.hpp>

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
		void					upGrade(void);
		void					downGrade(void);

		void					checkGrade(size_t grade);
		std::string 			getInfo() const;
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Bureaucrat::exception : Grade is too high");
				}

		};
		class GradeTooLowException: public std::exception
		{

		};
};

std::ostream& operator << (std::ostream& os, Bureaucrat const& rhs);

#endif // BUREAUCRAT_HPP