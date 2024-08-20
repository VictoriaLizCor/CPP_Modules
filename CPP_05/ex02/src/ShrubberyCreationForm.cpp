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

// // Move to the end of the file
//	 file.seekg(0, std::ios::end);

//	 // Get the position of the last character
//	 std::streampos lastPos = file.tellg();
void ShrubberyCreationForm::plantTree(Files& file, std::stringstream& treeBuffer) const
{
	std::string			fileLine;
	std::streampos		fileLinePos = 0;
	std::string			treeLine;
	std::string*		buffer;
	std::streampos		start = 0;
	ssize_t				size = countNewlines(treeBuffer.str());
	
	buffer = readLinesBeforeEnd(file, size, start);
	std::getline(treeBuffer, treeLine);
	if (buffer[size].length() >= (treeLine.length() * 3))
	// if (fileLine.length() >= (treeLine.length() * 3))
	{
		// fileLinePos = size * ((treeLine.length() + 1) * 3);
		std::cout << error("Line too loong", 0) << std::endl;
		std::cout << "Pos:" << fileLinePos << " "
		<< fileLine.length()  << std::endl;
		std::cout << "Pos:" << fileLinePos << " "
		<< fileLine.length()  << std::endl;
		printTitle("===", 20);
	}
	else
		fileLinePos = 0;
	treeBuffer.clear();
	treeBuffer.seekg(0, std::ios::beg);
	file.getFile().clear();
	file.getFile().seekg(0, std::ios::beg);
	// delete[] buffer;
	if (!file.getFile().is_open())
	{
		std::cerr << "**Error: File is not open" << std::endl;
		return;
	}
	std::cout << error("Changing line pos:", 0) << std::endl;
	std::cout << "fileLinePos:" << fileLinePos << "\n" ;
	// if (!fileLinePos)
	std::cout << "buffer line size:" << buffer[size].length() << "\n" ;
	std::cout << "tree line size" << ((treeLine.length()) * 3) << "\n" ;
	if (buffer[0].length() < ((treeLine.length()) * 3))
	{
		std::stringstream	ss;
		while (file.readLineInFile(fileLine, fileLinePos))
		{
			std::cout << "Pos:" << fileLinePos << " "
			<< fileLine.length() << " "
			<< fileLine << "-" << std::endl;
			if (std::getline(treeBuffer, treeLine))
			{
				fileLine += treeLine + "\n";
				ss << fileLine;
			}
		}
		file.closeFile();
		// file.openFile( std::ios::app);
		file.openFile( std::ios::out | std::ios::trunc);
		file.write(ss);
	}
	else
	{
		std::cout << error("Pos != 0", 0) << std::endl;
		std::cout << "Pos:" << fileLinePos << " "
		<< fileLine.length()  << std::endl;
		file.closeFile();
		file.openFile( std::ios::app);
		std::cout << "FILE\n";
		// file.writeAtPosition(treeBuffer.str(), start);
		file.write(treeBuffer);
	}
}

std::string* ShrubberyCreationForm::readLinesBeforeEnd(Files& file, size_t const& size, std::streampos& start) const
{
	if (!file.getFile().is_open())
	{
		std::cerr << "Failed to open the file: " << file << std::endl;
		return (NULL);
	}
	std::string		line;
	std::streampos	pos;
	std::string* 	buffer = new std::string[size];
	size_t			count = 0;
	while (file.readLineInFile(line, pos))
	{
		buffer[count % size] = line;
		count++;
	}
	// file.getFile().close(); ->> do not close
	start = pos;
	return (buffer);
	// std::cout << buffer[(start + i) % numLines] << std::endl;
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
		writeTree(buffer);
		std::cout << "File ContentSizeX: " << file.contentSize() << "\n";
		if (file.contentSize() == 0)
			file.write(buffer);
		else
		{
			plantTree(file, buffer);
		}
		file.closeFile();
		file.showContent();
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
