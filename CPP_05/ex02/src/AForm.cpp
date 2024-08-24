#include "AForm.hpp"
#include "Bureaucrat.hpp"

int AForm::_instanceCount = 0;
size_t const AForm::_maxGradeLimit = 150;
size_t const AForm::_minGradeLimit = 1;



/**
 * @brief Constructs an instance of the AForm class.
 *
 * This constructor initializes the AForm object with the provided name, minimum grade to sign,
 * minimum grade to execute, and sets the signed status to 0.
 *
 * @param name The name of the AForm.
 * @param minimumGradeToSign The minimum grade required to sign the AForm.
 * @param minimumGradeToExecute The minimum grade required to execute the AForm.
 */
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

/**
 * @brief Assignment operator for AForm class.
 * 
 * This operator assigns the values of the right-hand side object to the left-hand side object.
 * It checks for self-assignment and updates the "_signed" member variable.
 * 
 * @param rhs The right-hand side object to be assigned.
 * @return A reference to the left-hand side object after assignment.
 */
AForm& AForm::operator=(AForm const& rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " Copy was Created\n");
	return (*this);
}

/**
 * @brief Copy constructor for the AForm class.
 *
 * This constructor creates a new AForm object by copying the contents of another AForm object.
 *
 * @param rhs The AForm object to be copied.
 */
AForm::AForm(AForm const& rhs):
_instanceBase(++_instanceCount),
_name(rhs.getName()),
_minimumGradeToSign(rhs.getMinimumGradeToSign()),
_minimumGradeToExecute(rhs.getMinimumGradeToExecute())
{
	*this = rhs;
}

/**
 * @brief Destructor for the AForm class.
 * 
 * This destructor is responsible for destroying an instance of the AForm class.
 * It decrements the instance count and prints a debug message if the DEBUG flag is set to 2.
 * 
 * @return None.
 */
AForm::~AForm(void)
{
	if (DEBUG == 2)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
	_instanceCount--;
}

/**
 * @brief Checks the grade and throws an exception if it is out of range.
 * 
 * This function checks the given grade against the minimum and maximum grade limits.
 * If the grade is lower than the minimum grade limit, a GradeTooHighException is thrown.
 * If the grade is higher than the maximum grade limit, a GradeTooLowException is thrown.
 * 
 * @param grade The grade to be checked.
 * @throws GradeTooHighException If the grade is lower than the minimum grade limit.
 * @throws GradeTooLowException If the grade is higher than the maximum grade limit.
 */
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

/**
 * @brief Throws an exception and prints an error message.
 *
 * This function throws the provided exception and prints an error message using the `getColorStr` function.
 *
 * @param exception The exception to be thrown.
 * @throws std::runtime_error The provided exception.
 */
void AForm::throwExeption(std::exception const& exception) const
{
	std::cout << getColorStr(FLRED, "Action failed\n");
	throw std::runtime_error(exception.what());
}

/**
 * Checks the execution status of the form.
 *
 * This function checks if the form is signed and if the bureaucrat has the privilege to execute it.
 * If the form is not signed, it throws a FormStatus exception.
 * If the bureaucrat does not have the privilege, it throws a NoPrivilege exception.
 *
 * @param bureaucrat The bureaucrat object to check against.
 * @throws FormStatus If the form is not signed.
 * @throws NoPrivilege If the bureaucrat does not have the privilege to execute the form.
 */
void AForm::checkExeStatus(Bureaucrat const& bureaucrat) const
{
	if (!getSigned())
		throwExeption(FormStatus(getColorStr(FYELLOW, "Form is not signed")));
	if (bureaucrat.getGrade() > getMinimumGradeToExecute())
		throwExeption(NoPrivilege());
}

/**
 * @brief Signs the form if the bureaucrat has sufficient privilege.
 * 
 * @param bureaucrat The bureaucrat who wants to sign the form.
 * @throws AForm::NoPrivilege if the bureaucrat's grade is higher than the minimum grade required to sign the form.
 * @throws AForm::FormStatus if the form is already signed.
 */
void AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > getMinimumGradeToSign())
		throwExeption(AForm::NoPrivilege());
	if (_signed)
		throwExeption(AForm::FormStatus(getColorStr(FYELLOW, "Form is already signed")));
	_signed = true;
	std::cout << getColorStr(FLGREEN, "Action succesful:\n");
}

/**
 * @brief Get the signed status of the form.
 * 
 * @return const bool& The signed status of the form.
 */
bool const& AForm::getSigned() const
{
	return (_signed);
}

/**
 * @brief Get the name of the AForm object.
 * 
 * @return const std::string& The name of the AForm object.
 */
std::string const& AForm::getName() const
{
	return (_name);
}

/**
 * @brief Get the minimum grade required to sign the form.
 * 
 * @return const size_t& The minimum grade required to sign the form.
 */
size_t const& AForm::getMinimumGradeToSign() const
{
	return (_minimumGradeToSign);
}

/**
 * @brief Get the minimum grade required to execute the form.
 * 
 * @return const size_t& The minimum grade required to execute the form.
 */
size_t const& AForm::getMinimumGradeToExecute() const
{
	return (_minimumGradeToExecute);
}

/**
 * @brief Prints the status of the AForm object.
 * 
 * This function returns a string representation of the AForm object's status.
 * The status includes whether the form is signed or not, the minimum grade required to sign the form,
 * and the grade required to execute the form.
 * 
 * @return A string representation of the AForm object's status.
 */
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

/**
 * @brief Retrieves information about the AForm object.
 * 
 * This function returns a string containing information about the AForm object.
 * If the DEBUG flag is greater than 0, the class name of the object is included in the string.
 * Otherwise, the string starts with "AF" followed by the instance base number.
 * 
 * @return A string containing information about the AForm object.
 */
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

/**
 * @brief Overloaded stream insertion operator for AForm objects.
 * 
 * This function allows an AForm object to be inserted into an output stream.
 * It calls the `getInfo()` member function of the AForm object to retrieve
 * the information to be inserted into the stream.
 * 
 * @param os The output stream to insert the AForm object into.
 * @param rhs The AForm object to be inserted into the output stream.
 * @return std::ostream& A reference to the output stream after the insertion.
 */
std::ostream& operator << (std::ostream& os, AForm& rhs)
{
	os << rhs.getInfo();
	return (os);
}


/**
 * @brief Constructs a GradeTooHighException object with the given message.
 * 
 * @param msg The error message associated with the exception.
 */
AForm::GradeTooHighException::GradeTooHighException(const std::string& msg)
: std::out_of_range(msg) {}

/**
 * @brief Constructs a GradeTooLowException object with the given error message.
 * 
 * @param msg The error message associated with the exception.
 */
AForm::GradeTooLowException::GradeTooLowException(const std::string& msg)
: std::out_of_range(msg) {}

/**
 * @brief Constructs a new NoPrivilege object.
 *
 * This constructor is used to create an exception object of type NoPrivilege.
 * It inherits from std::runtime_error and sets the error message to
 * "privilege grade level is lower than Form grade required".
 */
AForm::NoPrivilege::NoPrivilege()
: std::runtime_error(getColorStr(FYELLOW, "privilege grade level is lower than Form grade required")) {}

/**
 * @brief Constructor for the FormStatus class.
 * 
 * @param msg The error message associated with the exception.
 */
AForm::FormStatus::FormStatus(std::string const& msg)
: std::runtime_error(msg) {}