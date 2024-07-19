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
		Bureaucrat();
		virtual ~Bureaucrat(void);

		std::string getName();
		int 		getGrade();

};

// std::ostream& operator << (std::ostream& os, Bureaucrat const& rhs);

#endif // BUREAUCRAT_HPP