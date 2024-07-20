#include "Bureaucrat.hpp"

int Bureaucrat::_instanceCount = 0;

static std::string checkName(std::string const&name)
{	
	if (name.empty())
		return ("Anon");
	else
		return (name);
}

Bureaucrat::Bureaucrat(std::string const& name, size_t grade):
_instanceId(++_instanceCount),
_colorIdStr(std::string(C_FMT256B) + "50" + "m"),
_name(checkName(name))
{
	checkGrade(grade);
	_grade = grade;
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");

}

Bureaucrat&::Bureaucrat::operator=(Bureaucrat const& rhs)
{
	if (this != &rhs)
		_grade = rhs.getGrade();
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " Copy was Created\n");
	return (*this);
}

Bureaucrat::Bureaucrat(Bureaucrat const& rhs):
_instanceId(++_instanceCount),
_colorIdStr(std::string(C_FMT256B) + toStr(50) + "m"),
_name(checkName(rhs.getName()))
{
	checkGrade(rhs.getGrade());
	*this = rhs;
}

Bureaucrat::~Bureaucrat(void)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
	_instanceCount--;
}

void Bureaucrat::checkGrade(size_t grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

std::string const& Bureaucrat::getName() const
{
	return (_name);
}

size_t const& Bureaucrat::getGrade() const
{
	return (_grade);
}
void Bureaucrat::upGrade(void)
{
	checkGrade(--_grade);
}

void Bureaucrat::downGrade(void)
{
	checkGrade(++_grade);
}

std::string Bureaucrat::getInfo() const
{
	std::ostringstream os;

	os << _colorIdStr;
	if (DEBUG == 1)
		os << getName() << _instanceId;
	else 
		os << getName();
	os << C_END;

	return (os.str());
}

std::ostream& operator << (std::ostream& os, Bureaucrat const& rhs)
{
	os << rhs.getInfo();
	return (os);
}
