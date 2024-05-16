
#include "Files.hpp"

bool _status = 0;
/**
 * @brief Sets the color of a message.
 *
 * This function takes a message and a color code as input and returns the
 * message with the specified color. The color code is an integer value that
 * represents a specific color. If the message is empty, only the color code is
 * returned.
 *
 * @param msg The message to be colored.
 * @param color The color code to be applied to the message.
 * @return The colored message.
 */
std::string	Files::setColor(std::string msg, int color, int err)
{
	std::ostringstream strColor;
	std::string	fmt;

	fmt = "\033[";
	if (color == DEFAULT)
		return (msg);
	if (err)
		 msg = "Error: " + msg;
	if (color >= FDEFAULT)
		fmt = fmt + "1;";
	strColor << fmt << color << "m" << msg << "\033[0m";
	return (strColor.str());
}

/**
 * @brief Default constructor for the Files class.
 *
 * This constructor initializes a new instance of the Files class. It does not
 * take any parameters and does not perform any operations.
 */
Files::Files()
{
	return ;
}

/**
 * @brief Constructs a Files object with the specified file name and open mode.
 *
 * @param fileName The name of the file to be opened.
 * @param mode The open mode for the file( std::ios::in | std::ios::out |
 * std::ios::app | std::ios::ate | std::ios::binary | std::ios::trunc).
 */
Files::Files(const char* fileName, std::ios_base::openmode mode): _file(fileName, mode), _fileName(fileName)
{
	_fileMode = mode;
	fileExists();
	return ;
}


/**
 * @brief Constructs a Files object with the given file name.
 *
 * @param fileName The name of the file to be associated with the Files object.
 */
Files::Files(const char* fileName): _file(), _fileName(fileName)
{
	openFile(std::ios::in | std::ios::out);
	return ;
}

/**
 * @brief Copy constructor for the Files class.
 * 
 * @param file The Files object to be copied.
 */
Files::Files(const Files &file): _file(), _fileName(file._fileName)
{
	return ;
}

/**
 * @brief Constructs a new Files object.
 *
 * This constructor initializes a `Files` object with the provided parameters.
 *
 * @param file The reference to the `Files` object to copy.
 * @param s1 The first string to search for in the file.
 * @param s2 The second string to replace `s1` with in the file.
 */
Files::Files(Files& file, const char* s1, const char* s2)
{
	_fileName = file._fileName + ".replace1";
	openFile(std::ios::out);
	replaceInFile(file, s1, s2);
	return ;
}


/**
 * @brief Destructor for the Files class.
 * 
 * This destructor is responsible for closing the file associated with the Files object.
 * It calls the closeFile() function to close the file.
 */
Files::~Files()
{
	closeFile();
	std:: cout << _fileName <<" Destructor called" << std::endl;
}

/**
 * @brief Closes the file if it is open.
 * 
 * This function checks if the file is open and closes it if it is. 
 * If the file is not open, this function does nothing.
 */
void Files::closeFile()
{
	if (_file.is_open() && _status != 0)
	{
		_file.close();
		_status = 0;
		if (_file.fail())
			std::cerr << setColor("Failed to close the file " + _fileName, FRED, 1) << std::endl;
	}
}

/**
 * @brief Opens a file with the specified mode.
 * 
 * This function opens a file with the specified mode. If a file is already open, it will be closed before opening the new file.
 * 
 * @param mode The mode to open the file in (e.g., std::ios_base::in, std::ios_base::out, std::ios_base::app, etc.).
 */
void Files::openFile(std::ios_base::openmode mode)
{
	_fileMode = mode;
	closeFile();
	_file.open(_fileName.c_str(), mode);
	_status = 1;
	fileExists();
}

/**
 * Checks if the file is open.
 * 
 * @return true if the file is open, false otherwise.
 */
bool Files::fileExists()
{
	if (_file.is_open() == false)
	{
		std::stringstream ss;
		ss << setColor("Failed to open the file " + _fileName, FRED, 1);
		std::cerr << ss.str() << std::endl;
	}
	else
	{
		_status = 1;
		if (_fileMode & std::ios::out)
			std::cout << setColor(_fileName + " file open to write.\n", FGREEN, 0);
		else if (_fileMode & std::ios::in)
			std::cout << setColor(_fileName + " file open to read.\n", FBLUE, 0);
	}
	return (0);
}

/**
 * Replaces all occurrences of a substring in a file with another substring.
 *
 * @param in The Files object representing the input file.
 * @param s1 The substring to be replaced.
 * @param s2 The substring to replace with.
 * find() returns the position of the first occurrence of the substring `s1` in
 * `std::string::npos`: This is a special value equal to the maximum value
 * representable by the type `size_t`. It's used by string methods to indicate
 * that a position or a character was not found during a search operation.

 */
void Files::replaceInFile(Files& in, const std::string &s1, const std::string &s2)
{
	std::string line;

	
	while (std::getline(in._file, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		_file << line << '\n';
	}
	in.closeFile();
	_status = 1;
	closeFile();
	std:: cout << "first close" << std::endl;
}

/**
 * @brief Replaces all occurrences of a string in a file with another string.
 *
 * @param s1 The string to be replaced.
 * @param s2 The string to replace s1 with.
 *
 * This function opens the file, reads it line by line, and replaces all
 * occurrences of s1 with s2 in each line. The modified lines are stored in a
 * buffer. The function then closes the file, appends ".replace2" to the file
 * name, reopens the file in write mode, and writes the contents of the buffer
 * to the file.
 */
void Files::replaceInFile(const std::string& s1, const std::string& s2)
{
	std::string			line;
	std::stringstream	buffer;
	
	_file.clear();
	_file.seekg(0);
	while (std::getline(_file, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s1.length();
		}
		buffer << line << '\n';
	}
	closeFile();
	std:: cout << "first close" << std::endl;
	// _fileName.append(".replace2");
	// openFile(_fileMode);
	// // _file.clear();
	// // _file.seekg(0);
	// std::cerr << buffer.str();
	// _file << buffer.str();
	// _status = OUT;
}

/**
 * @brief Copies the content of one file to another.
 *
 * @param in Reference to the file to be copied from.
 *
 * This function seeks to the beginning of the input file, copies its content
 * to the current file object, and then closes the current file.
 */
void Files::copyFile(Files& in)
{
	
	in._file.seekg(0); // Go to the beginning of the file
	_file << in._file.rdbuf(); // Copy the content to the new file
	_file.close();
}


// std::ofstream ofs("file.txt");
// std::streambuf* original_cout_buffer = std::cout.rdbuf();  // save original buffer
// std::cout.rdbuf(ofs.rdbuf());  // redirect cout to file.txt
// std::cout << "This will be written to file.txt";
// std::cout.rdbuf(original_cout_buffer);  // restore original buffer

