#include "ShrubberyCreationForm.hpp"

/**
 * @brief Constructs a new ShrubberyCreationForm object.
 *
 * @param target The target of the form.
 */
ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target):
AForm(className(typeid(*this).name()).c_str(), 145, 137),
_target(target),
_instanceId(_instanceCount),
_colorIdStr(getColorShade(FLCYAN))
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
}

/**
 * @brief Assignment operator for ShrubberyCreationForm.
 * 
 * This operator assigns the values of the right-hand side ShrubberyCreationForm object to the left-hand side object.
 * It first checks if the objects are not the same, then calls the assignment operator of the base class AForm.
 * It then assigns the target of the right-hand side object to the target of the left-hand side object.
 * 
 * @param rhs The right-hand side ShrubberyCreationForm object to assign.
 * @return A reference to the left-hand side ShrubberyCreationForm object after assignment.
 */
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

/**
 * @brief Constructs a new ShrubberyCreationForm object by copying another ShrubberyCreationForm object.
 * 
 * @param rhs The ShrubberyCreationForm object to be copied.
 */
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& rhs):
AForm(className(typeid(this).name())),
_target(rhs.getTarget()),
_instanceId(++_instanceCount),
_colorIdStr(getColorShade(FLCYAN))
{
	*this = rhs;
}

/**
 * @brief Prints a tree shape using ASCII art.
 * 
 * This function takes a reference to a `std::stringstream` object and appends the ASCII art representation of a tree to it.
 * The tree shape is created using a series of string concatenations.
 * 
 * @param buffer A reference to a `std::stringstream` object to store the ASCII art representation of the tree.
 */
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


/**
 * @brief Plants a tree by copying the contents of a tree buffer into
 * a file.
 *
 * This function takes a `Files` object and a `std::stringstream`
 * object as parameters. It reads the contents of the tree buffer and
 * copies them into the file. If the length of the first line in the
 * file is less than three times the length of the first line in the
 * tree buffer, it appends the contents of the tree buffer to the end
 * of the file. Otherwise, it replaces the contents of the file
 * starting from a specific position with the contents of the tree
 * buffer.
 *
 * @param file The `Files` object representing the file to write the
 * tree to.
 * @param treeBuffer The `std::stringstream` object containing the
 * contents of the tree.
 */
void ShrubberyCreationForm::plantTree(Files& file, std::stringstream& treeBuffer) const
{
	std::string			fileLine, treeLine;
	std::streampos 		fileLinePos = 0;
	size_t				size = countNewlines(treeBuffer.str());
	
	std::getline(treeBuffer, treeLine);
	fileLinePos = file.startAtRowBeforeEnd(size);
	std::getline(file.getStream(), fileLine);
	treeBuffer.clear();
	treeBuffer.seekg(0, std::ios::beg);
	if (fileLine.length() < (treeLine.length() * 3) - 1)
	{
		std::stringstream	ss;
		while (file.readFileAfterLinePos(fileLine, fileLinePos))
		{
			if (std::getline(treeBuffer, treeLine))
				ss << fileLine << treeLine << "\n";
		}
		file.openFile(std::ios::in | std::ios::out); // do not use trunc
		fileLinePos = file.startAtRowBeforeEnd(size); // used with writeAtPosition
		file.writeAtPosition(ss, fileLinePos);
	}
	else
	{
		file.closeFile();
		file.openFile(std::ios::app);
		file.write(treeBuffer);
	}
}

/**
 * Executes the ShrubberyCreationForm.
 * 
 * @param executor The bureaucrat who is executing the form.
 * @throws FormStatus If an error occurs during execution.
 */
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
		if (file.contentSize() == 0)
			file.write(buffer);
		else
			plantTree(file, buffer);
		file.showContent(FGREEN);
	}
	catch(std::exception const &e)
	{
		throw (FormStatus(e.what()));
	}
}

/**
 * @brief Destructor for the ShrubberyCreationForm class.
 * 
 * This destructor is responsible for destroying an instance of the ShrubberyCreationForm class.
 * It prints a debug message if the DEBUG flag is set, indicating that the object has been destroyed.
 */
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
}

/**
 * @brief Get the target of the ShrubberyCreationForm.
 * 
 * @return std::string The target of the ShrubberyCreationForm.
 */
std::string ShrubberyCreationForm::getTarget() const{return (_target);}

/**
 * @brief Retrieves information about the ShrubberyCreationForm.
 * 
 * This function returns a string containing information about the ShrubberyCreationForm.
 * The information includes the color ID, the name, the instance ID, and the status.
 * 
 * @return A string containing the information about the ShrubberyCreationForm.
 */
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
