#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(std::string const& name, size_t grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;

}

Bureaucrat& Bureaucrat::opertator=(Bureaucrat const& rhs)
{

}
Bureaucrat::~Bureaucrat(void)
{
}


std::ostream& operator << (std::ostream& os, Bureaucrat const& rhs)
{
	return (os);
}
