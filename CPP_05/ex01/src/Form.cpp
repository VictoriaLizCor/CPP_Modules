#include "Form.hpp"
#include "Bureaucrat.hpp"

int Form::_instanceCount = 0;

static std::string checkName(std::string const&name)
{	
	if (name.empty())
		return ("emptyForm");
	else
		return (name);
}


Form::Form(std::string const& name, size_t const& minimumGradeToSign, size_t const& minimumGradeToExecute):
_instanceId(++_instanceCount),
_colorIdStr(getRandomColorFmt(1)),
_name(checkName(name)),
_minimumGradeToSign(minimumGradeToSign),
_minimumGradeToExecute(minimumGradeToExecute),
_signed(0)
{
	checkGrade(_minimumGradeToSign);
	checkGrade(_minimumGradeToExecute);
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
}

Form& Form::operator=(Form const& rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " Copy was Created\n");
	return (*this);
}

Form::Form(Form const& rhs):
_instanceId(++_instanceCount),
_colorIdStr(getRandomColorFmt(1)),
_name(checkName(rhs.getName())),
_minimumGradeToSign(rhs.getMinimumGradeToSign()),
_minimumGradeToExecute(rhs.getMinimumGradeToExecute())
{
	*this = rhs;
}

Form::~Form(void)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
	_instanceCount--;
}

void Form::checkGrade(size_t grade)
{
	std::ostringstream os;

	os << getInfo();
	if (grade == 0)
	{
		std::cout << getColorStr(FLRED, "\nAttention! \n");
		os << ", grade [" << grade
		<< "] is too high. Maximum value should be 1.\n";
		throw (GradeTooHighException(os.str()));
	}
	else if (grade > 150)
	{
		std::cout << getColorStr(FLRED, "\nAttention! \n");
		os << ", grade [" << grade
		<< "] is too low. Minimum value should be 150.\n";
		throw (GradeTooLowException(os.str()));
	}
	if (_minimumGradeToExecute < _minimumGradeToSign)
	{	
		std::cout << getColorStr(FLRED, "\nAttention!\n");
		os << " Sign grade [ " << _minimumGradeToSign << " ] "
		<< "must be higher than Execution grade [ " 
		<< _minimumGradeToExecute << " ] \n";
		throw (GradeTooLowException(os.str()));
	}
}


void Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > _minimumGradeToSign)
	{
		std::string str;
		str = "privilege level is lower than required";
		throw (Form::GradeTooLowException(str));
	}
	_signed = true;
}

bool const& Form::getSigned() const
{
	return (_signed);
}

std::string const& Form::getName() const
{
	return (_name);
}

size_t const& Form::getMinimumGradeToSign() const
{
	return (_minimumGradeToSign);
}

size_t const& Form::getMinimumGradeToExecute() const
{
	return (_minimumGradeToExecute);
}

std::string Form::printStatus(void) const
{
	std::ostringstream os;
	os << std::string(C_END) << " [ Signed: " 
	<< (getSigned() ? getColorStr(FGREEN,"1") : getColorStr(FLGREEN, "0"))
	<< ", MinGrade: " << getColorStr(FLCYAN, (lsi)getMinimumGradeToSign())
	<< ", ExeGrade: " << getColorStr(FLYELLOW, (lsi)getMinimumGradeToExecute())
	<< " ]";
	return (os.str());
}

std::string Form::getInfo() const
{
	std::ostringstream os;

	os << _colorIdStr;
	if (DEBUG == 1)
		os << getName() << _instanceId << printStatus();
	else 
		os << getName() << printStatus();
	os << C_END;
	return (os.str());
}


std::ostream& operator << (std::ostream& os, Form const& rhs)
{
	os << rhs.getInfo();
	return (os);
}

Form::GradeTooHighException::GradeTooHighException(const std::string& msg)
: GradeException(msg) {}

Form::GradeTooLowException::GradeTooLowException(const std::string& msg)
: GradeException(msg) {}
//"Form::" + std::string(__func__) + 