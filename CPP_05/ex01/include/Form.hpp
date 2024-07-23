#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include "Utils.hpp"
# include "GradeExceptions.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

class Bureaucrat;

class Form
{
	private:
		// Debug attributes
		static int			_instanceCount;
		int					_instanceId;
		std::string const	_colorIdStr;
		// Subject specific
		std::string const	_name;
		size_t const		_minimumGradeToSign;
		size_t const		_minimumGradeToExecute;
		bool				_signed;

	protected:
		
	public:
		explicit Form(std::string const& name, size_t const& minimumGradeToSign, size_t const& minimumGradeToExecute);
		Form& operator=(Form const& rhs);
		Form(Form const& rhs);
		virtual ~Form(void);

		std::string const&		getName() const;
		size_t const&			getMinimumGradeToSign() const;
		size_t const&			getMinimumGradeToExecute() const;
		void					beSigned(Bureaucrat const& bureaucrat);

		void					checkGrade(size_t grade);
		std::string 			getInfo() const;
		
		typedef TooHighException GradeTooHighException;
		typedef TooHighException GradeTooLowException;
};

std::ostream& operator << (std::ostream& os, Form const& rhs);

#endif // FORM_HPP