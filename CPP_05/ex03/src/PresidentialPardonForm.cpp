#include "PresidentialPardonForm.hpp"

/**
 * @brief Constructs a PresidentialPardonForm object.
 * 
 * @param target The target of the robotomy request.
 */
PresidentialPardonForm::PresidentialPardonForm(std::string const& target):
AForm(className(typeid(*this).name()).c_str(), 25, 5),
_target(target),
_instanceId(_instanceCount),
_colorIdStr(getColorShade(FWHITE))
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
}

/**
 * @brief Assignment operator for the PresidentialPardonForm class.
 * 
 * This operator assigns the values of the right-hand side object to the left-hand side object.
 * It first checks if the objects are not the same, then calls the assignment operator of the base class AForm.
 * It then assigns the target of the right-hand side object to the target of the left-hand side object.
 * 
 * @param rhs The right-hand side object to assign from.
 * @return A reference to the left-hand side object after assignment.
 */
PresidentialPardonForm&::PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs.getTarget();
	}
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " Copy was Created\n");
	return (*this);
}

/**
 * @brief Constructs a new PresidentialPardonForm object by copying another PresidentialPardonForm object.
 * 
 * @param rhs The PresidentialPardonForm object to be copied.
 */
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& rhs):
AForm(className(typeid(this).name())),
_target(rhs.getTarget()),
_instanceId(++_instanceCount),
_colorIdStr(getColorShade(BWHITE))
{
	*this = rhs;
}

/**
 * @brief Destructor for the PresidentialPardonForm class.
 * 
 * This destructor is responsible for destroying an instance of the PresidentialPardonForm class.
 * It prints a message indicating that the object was destroyed if the DEBUG flag is set.
 */
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
}

/**
 * Executes the PresidentialPardonForm.
 * 
 * @param executor The bureaucrat who is executing the form.
 * @throws FormStatus If the execution fails.
 */
void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	// checkExeStatus(executor);
	try
	{
		checkExeStatus(executor);
		_succesful << "\n\t" << getColorStr(FMAGENTA, _target) << " has been pardoned by Zaphod Beeblebrox 🗳  ✨";
	}
	catch(std::exception const &e)
	{
		throw (FormStatus(e.what()));
	}
	std::cout << getColorStr(FLGREEN, "Execution succesful:\n");
}

/**
 * @brief Get the target of the PresidentialPardonForm.
 * 
 * @return std::string The target of the PresidentialPardonForm.
 */
std::string PresidentialPardonForm::getTarget() const{return (_target);}

/**
 * @brief Get the information about the PresidentialPardonForm.
 * 
 * This function returns a string containing the information about the PresidentialPardonForm.
 * The information includes the color ID, the name, the instance ID, the status, and any successful messages.
 * 
 * @return std::string The information about the PresidentialPardonForm.
 */
std::string PresidentialPardonForm::getInfo()
{
	std::ostringstream os;

	os << _colorIdStr;
	if (DEBUG == 2)
		os << "RF" << _instanceBase << "::";
	os << getName();
	if (DEBUG >= 1)
		os << _instanceId;
	os << printStatus();
	os << _succesful.str();
	_succesful.clear();
	_succesful.str("");
	os << C_END;
	return (os.str());
}
