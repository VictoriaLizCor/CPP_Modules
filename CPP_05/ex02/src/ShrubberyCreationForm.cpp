#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target):
AForm(className(typeid(*this).name()).c_str(), 145, 137),
_target(target),
_instanceId(_instanceCount),
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

static void writeTree(std::stringstream& buffer)
{
	buffer << "⠀⠀⠀⠀⠀⠀⣀⡀⠀⢔⡋⠒⠂⠀⢀⣀⠀⠀⠀⠀"	 << "\n";
	buffer << "⠀⠀⠀⠀⠀⡴⠀⠈⠈⠱⠆⠀⠰⠈⠉⠉⠹⠀⠀⠀⠀⠀⠀" << "\n";
	buffer << "⠀⠀⢀⡀⠀⠫⣀⡠⠀⠂⡠⢈⠄⠂⣥⢴⡞⡀⡀⠀⠀⠀⠀" << "\n";
	buffer << "⣠⠐⡡⠬⢉⡃⠐⠕⡠⣉⡔⣡⠾⠟⡿⠿⣭⢳⢻⡆⠀⠀⠀" << "\n";
	buffer << "⡙⠈⣆⢑⢢⠐⠴⣈⣶⣍⣿⣷⣚⢮⡝⣣⣇⡏⣞⣳⢆⠀⠀" << "\n";
	buffer << "⠘⡾⢆⢸⣆⢛⣶⣾⣿⠾⣿⠻⣿⣟⣿⣿⣿⣾⣿⡷⢿⣷⡀" << "\n";
	buffer << "⠀⠀⠀⣄⣆⡼⣟⣯⠶⡿⣧⢿⣟⣿⣿⣿⣟⣿⡦⡝⢦⢫⡿" << "\n";
	buffer << "⠀⠘⠾⡿⣿⣷⣫⣝⣾⣱⡭⣾⢳⣖⡮⣽⡿⣋⢶⣽⣓⠋⠀" << "\n";
	buffer << "⠀⠀⠀⠐⠛⠋⢯⣿⢏⠓⠀⣎⠏⠀⠲⠵⣎⡷⠎⠊⠃⠀⠀" << "\n";
	buffer << "⠀⠀⠀⠀⠀⠀⠈⠉⠈⠀⠀⢽⡃⠀⠀⠀⠙⠁⠀⠀⠀⠀⠀" << "\n";
	buffer << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣷⣣⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	checkExeStatus(executor);
	try
	{
		std::string const fileName = _target + "_shrubbery";
		std::stringstream buffer;
		Files file;

		writeTree(buffer);
		file.write(buffer);
	}
	catch(std::exception const &e)
	{
		throw (FormStatus(e.what()));
	}
	std::cout << getColorStr(FLGREEN, "Action succesful:\n");
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
}

std::string ShrubberyCreationForm::getTarget() const{return (_target);}

std::string ShrubberyCreationForm::getInfo()
{
	std::ostringstream os;

	os << _colorIdStr;
	if (DEBUG == 2)
		os << "AF" << _instanceBase << "::";
	os << getName();
	if (DEBUG >= 1)
		os << _instanceId;
	os << printStatus();
	os << C_END;
	return (os.str());
}
