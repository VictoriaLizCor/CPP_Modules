#include "Form.hpp"
#include "Bureaucrat.hpp"

int Form::_instanceCount = 0;

static std::string checkName(std::string const&name)
{	
	if (name.empty())
		return ("EmptyForm");
	else
		return (name);
}

static size_t initMinimumGradeToExecute(size_t grade)
{
	if (grade > 150)
		return 150;
}

Form::Form(std::string const& name, size_t const& minimumGradeToSign, size_t const& minimumGradeToExecute):
_instanceId(++_instanceCount),
_colorIdStr(getRandomColorFmt(1)),
_name(checkName(name)),
_minimumGradeToSign(minimumGradeToSign),
_minimumGradeToExecute(initMinimumGradeToExecute(minimumGradeToExecute)),
_signed(0)
{
	checkGrade(_minimumGradeToSign);
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
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
		std::cout << getColorStr(FRED, "Attention! \n");
		os << ", grade [" << grade
		<< "] is too high. Maximum value should be 1.\n";
		throw GradeTooHighException(os.str());
	}
	if (grade > 150)
	{
		std::cout << getColorStr(FRED, "Attention! \n");
		os << ", grade [" << grade
		<< "] is too low. Minimum value should be 150.\n";
		throw GradeTooLowException(os.str());
	}
}


void Form::beSigned(Bureaucrat const& bureaucrat)
{
	(void)bureaucrat;
	if (_signed)
	{
		std::cout << *this << " form already signed." << std::endl;
		return; //?
	}
	if (bureaucrat.getGrade() > _minimumGradeToSign)
		throw Form::GradeTooLowException();
	// _signed = true;
	// if (bureaucrat.getGrade() <= getGrade)
	// bureaucrat.signForm(this);
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
	return (_minimumGradeToSign);
}

std::string Form::getInfo() const
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


std::ostream& operator << (std::ostream& os, Form const& rhs)
{
	os << rhs.getInfo();
	return (os);
}
