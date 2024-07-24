#ifndef GRADEEXCEPTION_HPP
# define GRADEEXCEPTION_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <Utils.hpp>
# include <exception>

# ifndef DEBUG
#  define DEBUG 0
# endif

class GradeException: public std::exception
{
	protected:
		std::string _msg;
	public:
		explicit GradeException(std::string const& msg);
		virtual ~GradeException() throw();
		virtual const char* what() const throw();

};


#endif // GRADEEXCEPTIONS_HPP