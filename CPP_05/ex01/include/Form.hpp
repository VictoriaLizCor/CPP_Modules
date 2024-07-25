#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include "Utils.hpp"
# include "GradeException.hpp"

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

		void					checkGrade(size_t grade);

	protected:
		
	public:
		explicit Form(	std::string const& name="EmtyForm",
						size_t const& minimumGradeToSign=150,
						size_t const& minimumGradeToExecute=150);
		Form& operator=(Form const& rhs);
		Form(Form const& rhs);
		virtual ~Form(void);

		std::string const&		getName() const;
		size_t const&			getMinimumGradeToSign() const;
		size_t const&			getMinimumGradeToExecute() const;
		bool const&				getSigned() const;
		void					beSigned(Bureaucrat const& bureaucrat);

		std::string				printStatus() const;
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

std::ostream& operator << (std::ostream& os, Form const& rhs);

#endif // FORM_HPP

/**
 * @note: if the constructor is defined inline and does not have a
 * body, it is not considered a full function implementation.
 */