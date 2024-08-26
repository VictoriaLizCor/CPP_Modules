#include "Intern.hpp"

int Intern::_instanceCount = 0;

/**
 * @brief Creates a new ShrubberyCreationForm object.
 * 
 * This function creates a new ShrubberyCreationForm object and returns a pointer to it.
 * The ShrubberyCreationForm object is initialized with the given target.
 * 
 * @param target The target for the ShrubberyCreationForm.
 * @return A pointer to the newly created ShrubberyCreationForm object.
 */
static AForm* newShrubbery(std::string const&target)
{
	return (new ShrubberyCreationForm(target));
}

/**
 * @brief Creates a new RobotomyRequestForm object.
 * 
 * This function takes a target as a parameter and returns a pointer to a new RobotomyRequestForm object.
 * The target is used to initialize the RobotomyRequestForm object.
 * 
 * @param target The target for the RobotomyRequestForm.
 * @return A pointer to a new RobotomyRequestForm object.
 */
static AForm* newRobotomy(std::string const&target)
{
	return (new RobotomyRequestForm(target));
}

/**
 * @brief Creates a new instance of the PresidentialPardonForm.
 * 
 * This function creates a new instance of the PresidentialPardonForm class
 * and returns a pointer to it. The target parameter specifies the target
 * for the form.
 * 
 * @param target The target for the form.
 * @return A pointer to the newly created PresidentialPardonForm instance.
 */
static AForm* newPresidential(std::string const&target)
{
	return (new PresidentialPardonForm(target));
}

/**
 * @brief Default constructor for the Intern class.
 * 
 * This constructor initializes the instance of the Intern class.
 * It assigns a unique instance ID and generates a random color ID string.
 * It also initializes the formCreationMap with function pointers for different forms.
 * If the DEBUG flag is enabled, it prints a message indicating that the Intern object was created.
 */
Intern::Intern():
_instanceId(++_instanceCount),
_colorIdStr(getRandomColorFmt(1))
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
}

//Using map containers
// Intern::Intern():
// _instanceId(++_instanceCount),
// _colorIdStr(getRandomColorFmt(1))
// {
// 	formCreationMap["shrubbery creation"] = &newShrubbery;
// 	formCreationMap["robotomy request"] = &newRobotomy;
// 	formCreationMap["presidential pardon"] = &newPresidential;
// 	if (DEBUG)
// 		std::cout << *this << getColorStr(FGRAY, " was Created\n");
// }
/**
 * @brief Copy constructor for the Intern class.
 * 
 * @param rhs The Intern object to be copied.
 */
Intern::Intern(const Intern &rhs)
{
	*this = rhs;
}

/**
 * @brief Assignment operator for the Intern class.
 * 
 * This operator assigns the values of the right-hand side object to the left-hand side object.
 * 
 * @param rhs The right-hand side object to assign from.
 * @return A reference to the left-hand side object after assignment.
 */
Intern	&Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}


/**
 * @brief Destructor for the Intern class.
 * 
 * This destructor is responsible for destroying an instance of the Intern class.
 * It prints a debug message indicating that the object was destroyed.
 */
Intern::~Intern()
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
}

static std::string lower2Str(std::string const& str)
{
	std::string res;

	for (size_t it = 0; it < str.length(); ++it)
	{
		res += static_cast<char>(std::tolower(str[it]));
	}
	return (res);
}

static int		getFormIdx(const std::string formName)
{
	std::string		formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int				idx = -1;

	for (int i = 0; i < 3; i++)
	{
		if (lower2Str(formName) == formNames[i])
		{
			return (i);
		}
	}
	return (idx);
}


/**
 * @brief Creates a form based on the given form name and target.
 * 
 * This function creates a form based on the provided form name and target. It uses a map of form creators to find the appropriate creator function for the given form name. If a matching creator function is found, it calls the creator function to create the form and returns it. If no matching creator function is found, it displays an error message and returns nullptr.
 * 
 * @param formName The name of the form to create.
 * @param target The target of the form.
 * @return A pointer to the created form, or nullptr if the form creation fails.
 */
AForm* Intern::makeForm(std::string const& formName, std::string const& target)
{
	FormCreator forms[3] = {&newShrubbery, &newRobotomy, &newPresidential};
	int idx = getFormIdx(formName);

	if (idx >= 0)
	{
		AForm* form = forms[idx](target);
		std::cout << getColorStr(FLGREEN, "Action succesful:\n");
		std::cout << *this << "creates Form " << form->getInfo();
		nl(2);
		return (form);
	}
	else
	{
		std::cout << error("",0) << *this << "cannot create " << getColorStr(FMAGENTA, formName) << " form" << std::endl;
		return (NULL);
	}
}

// Using Maps
// AForm* Intern::makeForm(std::string const& formName, std::string const& target)
// {
// 	AForm* form;
// 	std::map<std::string, FormCreator>::const_iterator it = formCreationMap.find(lowerStr(formName));
// 	if (it != formCreationMap.end())
// 	{
// 		form = it->second(target);
// 		std::cout << getColorStr(FLGREEN, "Action succesful:\n");
// 		std::cout << *this << "creates Form " << form->getInfo();
// 		nl(2);
// 		return (form);
// 	}
// 	else
// 	{
// 		std::cout << error("",0) << *this << "cannot create " << getColorStr(FMAGENTA, formName) << " form" << std::endl;
// 		return (NULL);
// 	}
// }
/**
 * @brief Get the information about the Intern object.
 * 
 * @return std::string The information about the Intern object.
 */
std::string Intern::getInfo(void) const
{
	std::ostringstream os;

	os << _colorIdStr;
	if (DEBUG == 1)
		os << className(typeid(*this).name()) << _instanceId;
	else 
		os << className(typeid(*this).name());
	os << C_END;
	os << " " ;

	return (os.str());
}


/**
 * @brief Overloaded stream insertion operator for the Intern class.
 * 
 * This function allows an Intern object to be inserted into an output stream.
 * It calls the `getInfo()` member function of the Intern object to retrieve
 * the information to be inserted into the stream.
 * 
 * @param os The output stream to insert the Intern object into.
 * @param rhs The Intern object to be inserted into the output stream.
 * @return std::ostream& A reference to the output stream after the insertion.
 */
std::ostream& operator << (std::ostream& os, Intern& rhs)
{
	os << rhs.getInfo();
	return (os);
}
