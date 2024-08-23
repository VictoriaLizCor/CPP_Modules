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

static void tree(std::stringstream& buffer)
{
	buffer << "⠀⠀⠀⠀⠀⠀⣀⡀⠀⢔⡋⠒⠂⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀" << "\n";
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

static void tree2(std::stringstream& buffer)
{
	buffer << "       _-_         " << "\n";
    buffer << "    /~~   ~~\\     " << "\n";
    buffer << " /~~         ~~\\  " << "\n";
    buffer << "{               }  " << "\n";
    buffer << " \\  _-     -_  /  " << "\n";
    buffer << "   ~  \\\\ //  ~   " << "\n";
    buffer << "       | |         " << "\n";
    buffer << "       | |         " << "\n";
    buffer << "      // \\        " << "\n";
}

size_t countNewlines(const std::string& str)
{
	size_t count = 0;
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (*it == '\n')
			++count;
	}
	return (count);
}

//	 // Get the position of the last character
//	 std::streampos lastPos = file.tellg();
void ShrubberyCreationForm::plantTree(Files& file, std::stringstream& treeBuffer) const
{
	std::string			fileLine;
	std::streampos 		fileLinePos = 0;
	std::string			treeLine;
	ssize_t				size = countNewlines(treeBuffer.str());
	
	std::getline(treeBuffer, treeLine);
	fileLinePos = file.startAtRowBeforeEnd(size);
	std::getline(file.getStream(), fileLine);
	treeBuffer.clear();
	treeBuffer.seekg(0, std::ios::beg);
	std::cout << "FileLinePos:" << fileLinePos << " FileLineLen:"
	<< fileLine.length() << "-" << std::endl;
	std::cout << "treeLineLen:" << (treeLine.length() * 3) << "-" << std::endl;
	if (fileLine.length() < (treeLine.length() * 3) - 1)
	{
		std::stringstream	ss;
		std::cout << getColorStr(FLGREEN, "less than three") << "\n";
		while (file.readFileAfterLinePos(fileLine, fileLinePos))
		{
			std::cout << "Pos:" << fileLinePos << " "
			<< fileLine.length() << " "
			<< fileLine << "-" << std::endl;
			if (std::getline(treeBuffer, treeLine))
			{
				ss << fileLine << treeLine << "\n";
			}
		}
		file.openFile(std::ios::in | std::ios::out); // do not use trunc
		fileLinePos = file.startAtRowBeforeEnd(size); // do not delete to use with writeAtPosition
		std::cout << getColorStr(FLBLUE, "fileLinePos: ") << fileLinePos << " FileLineLen:"
	<< fileLine.length() << "-" << std::endl;
		file.writeAtPosition(ss, fileLinePos);
	}
	else
	{
		file.closeFile();
		file.openFile(std::ios::app);
		file.write(treeBuffer);
	}
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	checkExeStatus(executor);
	try
	{
		std::string const fileName = _target + "_shrubbery";
		std::stringstream buffer;
		Files file(fileName,  std::ios::in | std::ios::out | std::ios::app);
		file.getPath(_target);
		tree(buffer);
		std::cout << "File ContentSizeX: " << file.contentSize() << "\n";
		if (file.contentSize() == 0)
			file.write(buffer);
		else
		{
			plantTree(file, buffer);
		}
		file.showContent(FGREEN);
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
