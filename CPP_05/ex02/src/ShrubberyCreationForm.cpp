#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target):
AForm(className(typeid(this).name()), 145, 137),
_target(target),
_instanceId(++_instanceCount),
_colorIdStr(getColorShade(FLCYAN))
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
}

ShrubberyCreationForm&::ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
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

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& rhs):
AForm(className(typeid(this).name())),
_target(rhs.getTarget()),
_instanceId(++_instanceCount),
_colorIdStr(getColorShade(FLCYAN))
{
	*this = rhs;
}

static bool fileExists(const std::string& fileName)
{
	struct stat buffer;
	return (stat(fileName.c_str(), &buffer) == 0);
}

static bool createFile(const std::string& fileName)
{
	std::ofstream file;
	if (fileExists(fileName))
		file.open(fileName.c_str(), std::ios_base::app);
	else
		file.open(fileName.c_str());

	if (!file.is_open())
		return (1);
	return (0);
}



void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	std::string const fileName = _target + "_shrubbery";
	(void)executor;
	if (createFile(fileName))
		throw(FileError("Failed to create or open file: " + fileName));
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
}

std::string ShrubberyCreationForm::getTarget() const{return (_target);}

std::string ShrubberyCreationForm::getInfo() const
{
	std::ostringstream os;

	os << _colorIdStr;
	if (DEBUG == 2)
		os << "AM" << _instanceBase << "::";
	os << getName();
	if (DEBUG >= 1)
		os << _instanceId;
	else 
		os << printStatus();
	os << C_END;
	return (os.str());
}

ShrubberyCreationForm::FileError::FileError(std::string const& msg)
: std::runtime_error(msg) {}
