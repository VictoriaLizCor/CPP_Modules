#include "RobotomyRequestForm.hpp"

/**
 * @brief Constructs a RobotomyRequestForm object.
 * 
 * @param target The target of the robotomy request.
 */
RobotomyRequestForm::RobotomyRequestForm(std::string const& target):
AForm(className(typeid(*this).name()).c_str(), 72, 45),
_target(target),
_instanceId(_instanceCount),
_colorIdStr(getColorShade(FWHITE))
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
}

/**
 * @brief Assignment operator for the RobotomyRequestForm class.
 * 
 * This operator assigns the values of the right-hand side object to the left-hand side object.
 * It first checks if the objects are not the same, then calls the assignment operator of the base class AForm.
 * It then assigns the target of the right-hand side object to the target of the left-hand side object.
 * 
 * @param rhs The right-hand side object to assign from.
 * @return A reference to the left-hand side object after assignment.
 */
RobotomyRequestForm&::RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
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
 * @brief Constructs a new RobotomyRequestForm object by copying another RobotomyRequestForm object.
 * 
 * @param rhs The RobotomyRequestForm object to be copied.
 */
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& rhs):
AForm(className(typeid(this).name())),
_target(rhs.getTarget()),
_instanceId(++_instanceCount),
_colorIdStr(getColorShade(BWHITE))
{
	*this = rhs;
}

/**
 * @brief Destructor for the RobotomyRequestForm class.
 * 
 * This destructor is responsible for destroying an instance of the RobotomyRequestForm class.
 * It prints a message indicating that the object was destroyed if the DEBUG flag is set.
 */
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
}

/**
 * Executes the RobotomyRequestForm.
 * 
 * @param executor The bureaucrat who is executing the form.
 * @throws FormStatus If the execution fails.
 */
void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	// checkExeStatus(executor);
	try
	{
		checkExeStatus(executor);
		{
			bool RomotomizedSuccesfull = getRandomNum(2);
			
			if (RomotomizedSuccesfull)
			{
				std::string str = "\t🔩 🛠️  rizzz, bzzzzzz";
				_succesful << str << " 🤖 " <<getColorStr(FMAGENTA, _target) << " has been Robotomized";
			}
			else
			{
				throwExeption(FormStatus(getColorStr(FYELLOW, "Robotomy failed")));
			}
		}
	}
	catch(std::exception const &e)
	{
		throw (FormStatus(e.what()));
	}
	std::cout << getColorStr(FLGREEN, "Execution succesful:\n");
}

/**
 * @brief Get the target of the RobotomyRequestForm.
 * 
 * @return std::string The target of the RobotomyRequestForm.
 */
std::string RobotomyRequestForm::getTarget() const{return (_target);}

/**
 * @brief Get the information about the RobotomyRequestForm.
 * 
 * This function returns a string containing the information about the RobotomyRequestForm.
 * The information includes the color ID, the name, the instance ID, the status, and any successful messages.
 * 
 * @return std::string The information about the RobotomyRequestForm.
 */
std::string RobotomyRequestForm::getInfo()
{
	std::ostringstream os;

	os << _colorIdStr;
	if (DEBUG == 2)
		os << "RF" << _instanceBase << "::";
	os << getName();
	if (DEBUG >= 1)
		os << _instanceId;
	os << printStatus();
	if (!_succesful.str().empty())
	{
		os << "\n" + _succesful.str();
		_succesful.clear();
		_succesful.str("");
	}
	os << C_END;
	return (os.str());
}
