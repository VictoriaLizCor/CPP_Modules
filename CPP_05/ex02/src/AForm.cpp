#include "AForm.hpp"
#include "Bureaucrat.hpp"

int AForm::_instanceCount = 0;
size_t const AForm::_maxGradeLimit = 150;
size_t const AForm::_minGradeLimit = 1;



AForm::AForm(std::string const& name, size_t const& minimumGradeToSign, size_t const& minimumGradeToExecute):
_instanceBase(++_instanceCount),
_name(name),
_minimumGradeToSign(minimumGradeToSign),
_minimumGradeToExecute(minimumGradeToExecute),
_signed(0)
{
	checkGrade(_minimumGradeToSign);
	checkGrade(_minimumGradeToExecute);
	if (DEBUG == 2)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
}

AForm& AForm::operator=(AForm const& rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " Copy was Created\n");
	return (*this);
}

AForm::AForm(AForm const& rhs):
_instanceBase(++_instanceCount),
_name(rhs.getName()),
_minimumGradeToSign(rhs.getMinimumGradeToSign()),
_minimumGradeToExecute(rhs.getMinimumGradeToExecute())
{
	*this = rhs;
}

AForm::~AForm(void)
{
	if (DEBUG == 2)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
	_instanceCount--;
}

void AForm::checkGrade(size_t grade)
{
	std::ostringstream os;

	os << getInfo();
	if (grade < _minGradeLimit)
	{
		std::cout << getColorStr(FLRED, "\nAttention! \n");
		os << ", grade [" << grade
		<< "] is too high. Maximum value should be "
		<< _minGradeLimit << ".\n";
		throw (GradeTooHighException(os.str()));
	}
	else if (grade > _maxGradeLimit)
	{
		std::cout << getColorStr(FLRED, "\nAttention! \n");
		os << ", grade [" << grade
		<< "] is too low. Minimum value should be "
		<< _maxGradeLimit << ".\n";
		throw (GradeTooLowException(os.str()));
	}
}

void AForm::throwExeption(std::exception const& exception) const
{
	std::cout << getColorStr(FLRED, "Action failed\n");
	// std::cout << exception.what() << std::endl;
	// throw;
	throw std::runtime_error(exception.what());
}

void AForm::checkExeStatus(Bureaucrat const& bureaucrat) const
{
	if (!getSigned())
		throwExeption(FormStatus("Form is not signed"));
	if (bureaucrat.getGrade() > getMinimumGradeToExecute())
		throwExeption(NoPrivilege());
}

void AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > getMinimumGradeToSign())
		throwExeption(AForm::NoPrivilege());
	if (_signed)
		throwExeption(AForm::FormStatus("Form already signed"));
	_signed = true;
	std::cout << getColorStr(FLGREEN, "Action succesful:\n");
}

bool const& AForm::getSigned() const
{
	return (_signed);
}

std::string const& AForm::getName() const
{
	return (_name);
}

size_t const& AForm::getMinimumGradeToSign() const
{
	return (_minimumGradeToSign);
}

size_t const& AForm::getMinimumGradeToExecute() const
{
	return (_minimumGradeToExecute);
}

std::string AForm::printStatus(void) const
{
	std::ostringstream os;
	os << std::string(C_END) << " [ Signed: " 
	<< (getSigned() ? getColorStr(FGREEN,"1") : getColorStr(FLGREEN, "0"))
	<< ", MinGrade: " << getColorStr(BBLUE, (lsi)getMinimumGradeToSign())
	<< ", ExeGrade: " << getColorStr(FLYELLOW, (lsi)getMinimumGradeToExecute())
	<< " ]";
	return (os.str());
}

std::string AForm::getInfo()
{
	std::ostringstream os;

	if (DEBUG > 0)
		os << className(typeid(*this).name());
	else
		os << "AF" << _instanceBase << "::";
	os << C_END;
	return (os.str());
}

std::ostream& operator << (std::ostream& os, AForm& rhs)
{
	os << rhs.getInfo();
	return (os);
}

AForm::GradeTooHighException::GradeTooHighException(const std::string& msg)
: std::out_of_range(msg) {}

AForm::GradeTooLowException::GradeTooLowException(const std::string& msg)
: std::out_of_range(msg) {}

AForm::NoPrivilege::NoPrivilege()
: std::runtime_error("privilege grade level is lower than Form grade required") {}

AForm::FormStatus::FormStatus(std::string const& msg)
: std::runtime_error(msg) {}