#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
_colorIdStr(getRandomColorFmt(1)),
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
_colorIdStr(getRandomColorFmt(1)),
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
	std::ostringstream os;

	os << getInfo();
	if (grade == 0)
	{
		std::cout << getColorStr(FLRED, "\nAttention! \n");
		os << ", grade [" << grade
		<< "] is too high. Maximum value should be 1.\n";
		throw (Bureaucrat::GradeTooHighException(os.str()));
	}
	if (grade > 150)
	{
		std::cout << getColorStr(FLRED, "\nAttention! \n");
		os << ", grade [" << grade
		<< "] is too low. Minimum value should be 150.\n";
		throw  (Bureaucrat::GradeTooLowException(os.str()));
	}
}

std::string const& Bureaucrat::getName() const
{
	return (_name);
}

size_t const& Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
	--_grade;
	checkGrade(_grade);
}

void Bureaucrat::decrementGrade(void)
{
	++_grade;
	checkGrade(_grade);
}

void Bureaucrat::signForm(AForm& form)
{
	std:: ostringstream os;
	os << *this << " couldn't sign " << form <<  " because ";
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
		if (DEBUG)
			form.printStatus();
	}
	catch(const std::exception &e)
	{
		std::cout << os.str()  << e.what() << std::endl;
	}
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
	os << rhs.getInfo() << "(G:" 
	<< getColorStr(FLCYAN, (lsi)rhs.getGrade()) << ")";
	return (os);
}


Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg)
: std::out_of_range(msg) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg)
: std::out_of_range(msg) {}

//"Bureaucrat::" + std::string(__func__) + " \n" 