#include "Intern.hpp"

int Intern::_instanceCount = 0;

static AForm* newShrubbery(std::string const&target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm* newRobotomy(std::string const&target)
{
	return (new RobotomyRequestForm(target));
}

static AForm* newPresidential(std::string const&target)
{
	return (new PresidentialPardonForm(target));
}

Intern::Intern():
_instanceId(++_instanceCount),
_colorIdStr(getRandomColorFmt(1))
{
	formCreationMap["shrubbery creation"] = &newShrubbery;
	formCreationMap["robotomy request"] = &newRobotomy;
	formCreationMap["presidential pardon"] = &newPresidential;
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
}

Intern::Intern(const Intern &rhs)
{
	*this = rhs;
}

Intern	&Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}


Intern::~Intern()
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
}

static std::string lowerStr(std::string const& str)
{
	std::string res;

	for (size_t it = 0; it < str.length(); ++it)
	{
		res += static_cast<char>(std::tolower(str[it]));
	}
	return (res);
}

AForm* Intern::makeForm(std::string const& formName, std::string const& target)
{
	AForm* form;
	std::map<std::string, FormCreator>::const_iterator it = formCreationMap.find(lowerStr(formName));
	if (it != formCreationMap.end())
	{
		form = it->second(target);
		std::cout << *this << " creates Form " << form->getInfo();
		nl(3);
		return (form);
	}
	else
	{
		std::cout << error("",0) << *this << "cannot create " << getColorStr(FMAGENTA, formName) << " form" << std::endl;
		return (NULL);
	}
}

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


std::ostream& operator << (std::ostream& os, Intern& rhs)
{
	os << rhs.getInfo();
	return (os);
}
