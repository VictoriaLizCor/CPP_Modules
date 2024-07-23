#ifndef GRADEEXCEPTIONS_HPP
# define GRADEEXCEPTIONS_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <Utils.hpp>
# include <exception>

# ifndef DEBUG
#  define DEBUG 0
# endif

class TooHighException: virtual public std::exception
{
	private:
		std::string _msg;
	public:
		TooHighException(std::string const& msg);
		virtual ~TooHighException() throw();
		virtual const char* what() const throw();

};

class TooLowException: virtual public std::exception
{
	private:
		std::string _msg;
	public:
		TooLowException(std::string const& msg);
		virtual ~TooLowException() throw();
		virtual const char* what() const throw();
};


#endif // GRADEEXCEPTIONS_HPP