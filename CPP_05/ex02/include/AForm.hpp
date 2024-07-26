#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <fstream>
# include "Utils.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

class Bureaucrat;

class AForm
{
	protected:
		// Debug attributes:
		static int			_instanceCount;
		int					_instanceBase;

		void						checkGrade(size_t grade);

	private:
		// Debug attributes:
		// std::string const	_colorIdStr;
		// Subject specific:
		std::string const	_name;
		size_t const		_minimumGradeToSign;
		size_t const		_minimumGradeToExecute;
		bool				_signed;
		// Additional:
		static size_t const	_maxGradeLimit;
		static size_t const	_minGradeLimit;

	public:
		explicit AForm(	std::string const& name,
						size_t const& minimumGradeToSign=_maxGradeLimit,
						size_t const& minimumGradeToExecute=_maxGradeLimit);
		AForm& operator=(AForm const& rhs);
		AForm(AForm const& rhs);
		virtual ~AForm(void);

		std::string const&			getName() const;
		size_t const&				getMinimumGradeToSign() const;
		size_t const&				getMinimumGradeToExecute() const;
		bool const&					getSigned() const;
		virtual void				execute( Bureaucrat const& executor ) const = 0;
		virtual void				beSigned(Bureaucrat const& bureaucrat);

		virtual std::string			printStatus() const;
		virtual std::string 		getInfo() const = 0;

		void						checkExeStatus(Bureaucrat const& bureaucrat);
		//Class Exeptions
		class GradeTooHighException : public std::out_of_range
		{
			public:
				explicit GradeTooHighException(std::string const& msg);
		};
		class GradeTooLowException : public std::out_of_range
		{
			public:
				explicit GradeTooLowException(std::string const& msg);
		};
		class NoPrivilege : public std::runtime_error
		{
			public:
				explicit NoPrivilege();
		};
		class FormStatus : public std::runtime_error
		{
			public:
				explicit FormStatus(std::string const& msg);
		};

};

std::ostream& operator << (std::ostream& os, AForm const& rhs);

#endif // FORM_HPP

/**
 * @note: if the constructor is defined inline and does not have a
 * body, it is not considered a full function implementation.
 */