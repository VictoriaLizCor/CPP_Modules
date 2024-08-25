#include "Bureaucrat.hpp"
// #include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int Bureaucrat::_instanceCount = 0;

static std::string checkName(std::string const&name)
{	
	if (name.empty())
		return ("Anon");
	else
		return (name);
}

/**
 * @brief Constructs a new Bureaucrat object with the given name and grade.
 * 
 * @param name The name of the bureaucrat.
 * @param grade The grade of the bureaucrat.
 */
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

/**
 * @brief Assignment operator for the Bureaucrat class.
 * 
 * This operator assigns the grade of the right-hand side object to the left-hand side object.
 * If the objects are not the same, the grade is assigned.
 * 
 * @param rhs The right-hand side object to assign from.
 * @return A reference to the left-hand side object after assignment.
 */
Bureaucrat&::Bureaucrat::operator=(Bureaucrat const& rhs)
{
	if (this != &rhs)
		_grade = rhs.getGrade();
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " Copy was Created\n");
	return (*this);
}

/**
 * @brief Constructs a new Bureaucrat object by copying another Bureaucrat object.
 *
 * @param rhs The Bureaucrat object to be copied.
 */
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

/**
 * @brief Checks the grade of the bureaucrat.
 * 
 * This function checks if the given grade is within the valid range for a bureaucrat.
 * If the grade is too high (greater than 1), it throws a Bureaucrat::GradeTooHighException.
 * If the grade is too low (less than 150), it throws a Bureaucrat::GradeTooLowException.
 * 
 * @param grade The grade to be checked.
 * @throws Bureaucrat::GradeTooHighException If the grade is too high.
 * @throws Bureaucrat::GradeTooLowException If the grade is too low.
 */
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

/**
 * @brief Get the name of the Bureaucrat.
 * 
 * @return const std::string& The name of the Bureaucrat.
 */
std::string const& Bureaucrat::getName() const
{
	return (_name);
}

/**
 * @brief Get the grade of the bureaucrat.
 * 
 * @return const size_t& The grade of the bureaucrat.
 */
size_t const& Bureaucrat::getGrade() const
{
	return (_grade);
}

/**
 * @brief Decreases the grade of the bureaucrat by 1 and checks if the new grade is valid.
 * 
 * This function decrements the grade of the bureaucrat by 1 and then calls the `checkGrade` function
 * to ensure that the new grade is within the valid range.
 */
void Bureaucrat::incrementGrade(void)
{
	--_grade;
	checkGrade(_grade);
}

/**
 * @brief Decrements the grade of the bureaucrat by one.
 *
 * This function increments the `_grade` member variable of the `Bureaucrat` class by one and then checks if the new grade is still within the valid range using the `checkGrade` function.
 */
void Bureaucrat::decrementGrade(void)
{
	++_grade;
	checkGrade(_grade);
}

/**
 * Signs a given form.
 *
 * @param form The form to be signed.
 */
void Bureaucrat::signForm(AForm& form)
{
	std:: ostringstream os;
	os << *this << " couldn't sign " << form <<  " because ";
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch(std::exception const& e)
	{
		std::cout << os.str()  << e.what() << std::endl;
	}
	nl(1);
}

/**
 * Executes a given form by a bureaucrat.
 * 
 * @param form The form to be executed.
 * @throws GradeTooHighException if the bureaucrat's grade is too high to execute the form.
 */
void Bureaucrat::executeForm(AForm const& form)
{
	std:: ostringstream os;
	AForm& tmpForm = const_cast<AForm&>(form); // necessary to use overloaded stream operator and Form class Info, as it is overrided

	os << *this << " couldn't execute " << tmpForm <<  " because ";
	try
	{
		tmpForm.execute(*this);
		std::cout << *this << " executed " << tmpForm << std::endl;
	}
	catch(std::exception const& e)
	{
		bool errorForm = false;

		if (typeid(e) == typeid(AForm::NoPrivilege))
			errorForm = true;
		if (typeid(e) == typeid(AForm::FormStatus))
			errorForm = true;
		if (errorForm)
		{
			std::cout << os.str()  << e.what() << std::endl;
			return ;
		}
		if (typeid(e) == typeid(GradeTooHighException))
			throw(GradeTooHighException(os.str() + e.what()));
		else
			throw(GradeTooLowException(os.str() + e.what()));
	}
	nl(1);
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
	<< getColorStr(BBLUE, (lsi)rhs.getGrade()) << ")";
	return (os);
}


Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg)
: std::out_of_range(msg) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg)
: std::out_of_range(msg) {}

